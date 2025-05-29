#ifndef FSM_H
#define FSM_H

#include <Arduino.h>
#include <stdint.h>

#define MAX_NUMBERS_OF_TRANSITIONS 2 // Maximum number of transitions in the FSM

#define STATE_0    &fsm[0] // State 0
#define STATE_1    &fsm[1] // State 1
#define STATE_2    &fsm[2] // State 2
#define STATE_3    &fsm[3] // State 3

typedef enum  output_state // Enumeration of the FSM states
{
   OFF = 0U, // State 0
} fsm_state_t;

typedef struct final_state_machine
{
    uint8_t out_1; // Current state of the FSM
    uint8_t out_2; // Current event of the FSM
    uint8_t button; // Next state of the FSM
    uint16_t time; // Action to be performed in the current state
    struct final_state_machine *next_state[]; // Pointer to the next state in the FSM
} fsm_t;


extern fsm_t fsm[]; // Declaration of the FSM array

void fsm_init(void);
void fsm_loop(void) // Function to initialize the FSM
void fsm_set_output(uint8_t out,); // Function to set the current state of the FSM
#endif