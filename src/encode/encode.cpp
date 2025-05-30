#include "encode.h"

// Debounce threshold: e.g. 500 µs
#define ENCODER_DEBOUNCE_US 500UL

volatile uint16_t count = 0;
static volatile uint32_t last_tick_us = 0;

void encode_setup(void)
{
    pinMode(ENC_A, INPUT);
    
    attachInterrupt(digitalPinToInterrupt(ENC_A), encode_interrupt, RISING);
}

void encode_interrupt(void)
{
//   // micros() is a quick register read, safe inside ISR
//   uint32_t now = micros();

//   // if too soon, ignore as bounce
//   if (now - last_tick_us < ENCODER_DEBOUNCE_US)
//     return;

//   last_tick_us = now;
  count++;
}

uint16_t encode_get_count(void)
{
    static uint16_t temp_count = 0;
    
    //noInterrupts(); 

    temp_count = count;

    count = 0;

    //printf("Count: %d \n\r", temp_count);
    //interrupts(); 
    
    return temp_count;
}