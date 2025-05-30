#ifndef DD_FSM_H
#define DD_FSM_H

#include <Arduino.h>
#include "own_stdio.h"

#define STATE_1 &button_led_fsm[0]
#define STATE_2 &button_led_fsm[1]
#define STATE_3 &button_led_fsm[2]
#define STATE_4 &button_led_fsm[3]
#define STATE_5 &button_led_fsm[4] 

#define STATE_RESET STATE_1

typedef enum
{
    LED_OFF = 0u,
    LED_ON,
    LED_HALF,
    LED_BLINK,
    LED_SOS     
} fsm_out_t;

typedef enum 
{
    PRESSED = 0u,
    RELEASED
} fsm_input_t;

typedef struct fsm
{
    fsm_out_t led_state;
    fsm_input_t button_state;
    uint16_t timeout;
    struct fsm *next_state[2];
} fsm_t;

void fsm_init(void);
void fsm_event_handler(void);
void fsm_run(void);
void fsm_led_toggle(uint8_t led);
void fsm_set_output(uint8_t led, fsm_out_t led_state);
void fsm_blink_sos(uint8_t led);
void print_fsm_state(void);



#endif //!DD_FSM_H