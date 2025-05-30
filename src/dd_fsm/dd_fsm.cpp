#include "dd_fsm.h"

static fsm_t button_led_fsm[] = 
{
    {LED_OFF,   PRESSED,    0,              {STATE_5, STATE_2}}, 
    {LED_ON,    PRESSED,    TIMEOUT,        {STATE_1, STATE_3}},
    {LED_HALF,  PRESSED,    TIMEOUT,        {STATE_1, STATE_4}},
    {LED_BLINK, PRESSED,    0,              {STATE_1, STATE_1}},
    {LED_SOS,   PRESSED,    SOS_TIMEOUT,    {STATE_1, STATE_1}}, 
};

static fsm_t *current_state = STATE_RESET;

void fsm_init(void)
{
    current_state = STATE_RESET;

    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void fsm_event_handler(void)
{
    static uint32_t last_time_debounce = 0;
    static uint32_t state_entry_time = 0;
    static uint32_t button_press_start = 0;
    static bool button_held = false;

    if (digitalRead(BUTTON_PIN) == PRESSED)
    {
        if (!button_held)
        {
            button_held = true;
            button_press_start = millis();  // Start hold timer
        }

        if ((millis() - last_time_debounce) >= DEBOUNCE_TIME)
        {
            last_time_debounce = millis();

            // Determine timeout condition
            bool timeout_passed = (millis() - state_entry_time) >= current_state->timeout;

            // Special handling for STATE_0 to use long hold for SOS
            if (current_state == STATE_1)
            {
                if ((millis() - button_press_start) >= SOS_TIMEOUT)
                {
                    current_state = current_state->next_state[0];  // long hold → STATE_5
                }
                else
                {
                    current_state = current_state->next_state[1];  // short press → STATE_2
                }
            }
            else
            {
                // Other states: follow timeout logic
                current_state = timeout_passed ? current_state->next_state[1] : current_state->next_state[0];
            }

            state_entry_time = millis();
        }
    }
    else
    {
        button_held = false;
    }

    print_fsm_state();
}



void fsm_run(void)
{
    static uint32_t last_toggle_time = 0;
    
    switch (current_state->led_state)
    {
        case LED_BLINK:
            if (millis() - last_toggle_time >= 500)  // 1Hz blink
            {
                fsm_led_toggle(LED_PIN);
                last_toggle_time = millis();
            }
            break;

        case LED_SOS:
            fsm_blink_sos(LED_PIN);
            break;

        default:
            fsm_set_output(LED_PIN, current_state->led_state);
            break;
    }
}

void fsm_led_toggle(uint8_t led)
{
    digitalWrite(led, !digitalRead(led));
}

void fsm_set_output(uint8_t led, fsm_out_t led_state)
{
    digitalWrite(led, led_state);
    switch (led_state)
    {
        //uint8_t prev_led_state = current_state->led_state;

        case LED_OFF:
            digitalWrite(led, LOW);
            break;
        case LED_ON:
            digitalWrite(led, HIGH);
            break;
        case LED_HALF:
            analogWrite(led, LED_HALF_POWER);
            break;
        case LED_BLINK:
            fsm_led_toggle(led);
            break;
        default:
            break;
    }
}

void fsm_blink_sos(uint8_t led)
{
    static uint8_t step = 0;
    static uint32_t last_time = 0;
    static bool led_on = false;

    // Morse timings
    const uint16_t dot = 200;
    const uint16_t dash = 600;
    const uint16_t pause = 200;

    if (millis() - last_time < pause)
        return;

    switch (step)
    {
        // S (dot dot dot)
        case 0: case 2: case 4:
            digitalWrite(led, HIGH);
            last_time = millis();
            led_on = true;
            break;
        case 1: case 3: case 5:
            digitalWrite(led, LOW);
            last_time = millis();
            led_on = false;
            break;

        // O (dash dash dash)
        case 6: case 8: case 10:
            digitalWrite(led, HIGH);
            last_time = millis();
            led_on = true;
            break;
        case 7: case 9: case 11:
            digitalWrite(led, LOW);
            last_time = millis();
            led_on = false;
            break;

        // S (dot dot dot)
        case 12: case 14: case 16:
            digitalWrite(led, HIGH);
            last_time = millis();
            led_on = true;
            break;
        case 13: case 15: case 17:
            digitalWrite(led, LOW);
            last_time = millis();
            led_on = false;
            break;

        // Loop again
        case 18:
            step = -1;  // next increment will set to 0
            break;
    }

    // Set duration
    if (led_on)
    {
        if (step <= 5 || step >= 12)
            last_time += dot;
        else
            last_time += dash;
    }
    else
    {
        last_time += pause;
    }

    step++;
}

void print_fsm_state(void)
{
    printf("Current state: %d\n\r", current_state->led_state);
}