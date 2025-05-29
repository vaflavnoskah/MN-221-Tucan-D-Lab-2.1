#include "dd_fan.h"
#include "ed_relay/ed_relay.h"

int dd_fan_status = 0;

void dd_fan_setup()
{
    dd_fan_status = 0;
}

void fan_loop()
{
    if (dd_fan_status == 1)
    {
        dd_fan_on();
    }
    else
    {
        dd_fan_off();
    }
}

int dd_fan_on_hw()
{
    ed_relay_on_hw();
    dd_fan_status = DD_FAN_ON;
    return dd_fan_status;
}

int dd_fan_off_hw()
{
    ed_relay_off_hw();
    dd_fan_status = DD_FAN_OFF;
    return dd_fan_status;
}

int dd_fan_on()
{
    ed_relay_on();
    dd_fan_status = DD_FAN_ON;
    return dd_fan_status;
}

int dd_fan_off()
{
    ed_relay_off();
    dd_fan_status = DD_FAN_OFF;
    return dd_fan_status;
}

int dd_fan_is_on_hw()
{
    if (ed_relay_is_on_hw() == ED_RELAY_ON)
    {
        dd_fan_status = DD_FAN_ON;
    }
    else
    {
        dd_fan_status = DD_FAN_OFF;
    }
    return dd_fan_status;
}

