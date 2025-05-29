#include "ed_relay/ed_relay.h"
void ed_relay_setup(){
    pinMode(ED_RELAY_PIN, OUTPUT);
}

int ed_relay_status = 0;

void ed_relay_loop(){
    if(ed_relay_status == 1){
        ed_relay_on();
    }else{
        ed_relay_off();
    }
}

int ed_relay_on_hw(){
    digitalWrite(ED_RELAY_PIN, HIGH);
    ed_relay_status = ED_RELAY_ON;
    return ed_relay_status;
}

int ed_relay_off_hw(){
    digitalWrite(ED_RELAY_PIN, LOW);
    ed_relay_status = ED_RELAY_OFF;
    return ed_relay_status;
}

void ed_relay_on(){
    ed_relay_status = ED_RELAY_ON;
    return ed_relay_status;
}

void ed_relay_off(){
    ed_relay_status = ED_RELAY_OFF;
}

int ed_relay_is_on_hw(){
    if(digitalRead(ED_RELAY_PIN) == HIGH){
        ed_relay_status = ED_RELAY_ON;
    }else{
        ed_relay_status = ED_RELAY_OFF;
    }
    return ed_relay_status;
}

int ed_relay_is_on(){
    return ed_relay_status;
}


