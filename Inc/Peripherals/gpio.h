#pragma once

#include "nrf_gpio.h"

class GPIO
{
protected:
    const uint32_t _pin_number;

    GPIO(const uint32_t pin_number) : _pin_number(pin_number)
    {

    }
public:
    virtual void init() = 0;

    uint32_t get_pin_number() const;
};
