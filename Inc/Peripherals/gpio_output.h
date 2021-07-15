#pragma once

#include "gpio.h"

class GPIOOutput : public GPIO
{
public:
    GPIOOutput(const uint32_t pin_number) : GPIO(pin_number)
    {

    }

    void init() override;

    void write(const bool is_high);

    void set();

    void reset();
};
