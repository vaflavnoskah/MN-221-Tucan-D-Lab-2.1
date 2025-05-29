#include "fsm.h"

fsm_t fsm[] =
{
    // out 1       | out 2 | button | time | next state
        {OFF,         OFF,    REALEASED,  0,   {STATE_1, STATE_2, NULL, NULL}}
        {HALF_POWER,  OFF,    REALEASED,  5,   {STATE_2, STATE_0, }}
        {FULL_POWER,  OFF,    REALEASED,  5,   {STATE_2, STATE_0, }}
        {OFF,         ON,     REALEASED,  0,   {STATE_1, STATE_2, NULL, NULL}}


};


static fsm_t *current_state = NULL; // Pointer to the current state of the FSM

void fsm_init(void) // Function to initialize the FSM
{
    current_state = STATE_INIT; // Set the initial state of the FSM
    pinMode(LED_1, OUTPUT);
    pinMode(LED_2, OUTPUT); // Set the pin modes for the LEDs

     // Set the initial output of the FSM
}

void fsm_loop{
    static uint32_t next_check_button_time = 0; // Variable to store the next check time for the button
    static uint32_t was_pressed_on_time  = 0; // Variable to store the next check time for the FSM

    if (digitalRead(BUTTON_1) == PRESSED) // Check if the button is pressed
    {
        if (millis() > was_pressed_on_time > 1000) // Check if the button is pressed for more than 1 second
        {
            current_state = current_state->next_state[0]; // Transition to the next state
            was_pressed_on_time = millis(); // Update the time of the last button press
        }
    }
    else if (current_state->out_2 == ON) // Check if the FSM is in the ON state
    {
        if (millis() - next_check_button_time > 1000) // Check if it is time to check the button again
        {
            current_state = current_state->next_state[1]; // Transition to the next state
            next_check_button_time = millis(); // Update the time of the last check
        }
    }
    else if (current_state->out_2 == OFF) // Check if the FSM is in the OFF state
    {
        /* code */
    }
    
}

