#include "fsm.h"

state fsm_t fsm_state[]{
    // State 1 
    {
        {red: ON, yellow: OFF, green: OFF}, // North-South
        {red: OFF, yellow: OFF, green: ON}, // East-West
        REQUEST ,
        STATE_2,  
    }

    // State 2 
    {
        {red: ON, yellow: OFF, green: OFF}, // North-South
        {red: OFF, yellow: OFF, green: ON}, // East-West
        STATE_1_TIMEOUT,
        STATE_3,  
    },

    // State 3 
    {
        {red: OFF, yellow: OFF, green: ON}, // North-South
        {red: ON, yellow: OFF, green: OFF}, // East-West
        REQUEST ,
        STATE_4,  
    },




}