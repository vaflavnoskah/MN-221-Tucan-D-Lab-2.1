#ifndef FSM_H
#define FSM_H

#include <Arduino.h>    
#include "config.h"

#define STATE_1  &fsm[0]
#define STATE_2  &fsm[1]
#define STATE_3  &fsm[2]
#define STATE_4  &fsm[3]
#define STATE_5  &fsm[4]
#define STATE_6  &fsm[5]
#define STATE_7  &fsm[6]  
#define STATE_8  &fsm[7]
#define STATE_9  &fsm[8]
#define STATE_10 &fsm[9]

#define STATE_INIT STATE_1

#define STATE_1_TIMEOUT  1000

typedef enum {
    OFF = 0u,
    ON,
    BLINK
    } out_state_t;


typedef struct {
    out_state_t red: 1;
    out_state_t yellow: 1;
    out_state_t green: 2;
} traffic_light_t;

typedef struct {
    traffic_light_t north_south;
    traffic_light_t east_west;
    fsm_event_t event;
    uint32_t time;
    struct fsm *next_state;
} fsm_t;


