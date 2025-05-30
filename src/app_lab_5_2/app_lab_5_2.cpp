#include "app_lab_5_2/app_lab_5_2.h"

pid_t pid;

volatile int set_point = (int)SETPOINT;
volatile double speed = 0.0;
volatile uint8_t power = 0;

void setup() 
{
    own_stdio_setup();
    timer_init_ISR_100Hz(TIMER_DEFAULT); 
    dd_h_bridge_setup();
    encode_setup();
    pid_init(&pid, set_point, KP, KI, KD, PWM_MIN, PWM_MAX);
}

void loop() 
{
    static uint32_t last_print = 0;

    if(last_print < millis())
    {
        int set_point_percent = setPointToPercent(set_point);
        printf("Speed: %d, Set point: %d%%, Power: %d\n\r", (int)speed, set_point_percent, power);

        last_print = millis() + PRINT_RECURENCE;
    }
}

void timer_handle_interrupts(int timer)
{
    static uint16_t count;
    static uint16_t filtered_count;

    count = encode_get_count();
    filtered_count = meanFilter(count);
    
    speed = filtered_count * CONSTANT_TO_RPM;
    
    power = pid_compute(&pid, speed);
    
    set_h_bridge_power(power);
}

void serialEvent()
{
    char str[32] = {0};
    scanf("%s", str);

    int percent = atoi(str);

    set_point = percentToSetPoint(percent);
    pid_set_setpoint(&pid, set_point);
}


int setPointToPercent(int set_point)
{
    // Convert set_point в проценты с округлением
    return (int)(((long)(set_point) * 100 + 16383 ) / 32767);
}


int percentToSetPoint(int percent)
{
    if(percent < 0)
    {
        percent = 0;
    }
    else if(percent > 100)
    {
        percent = 100;
    }

    // Convert проценты в диапозон 0-32767 с округлением
    return (int)(( (long)percent * 32767 + 50 ) / 100 );
}