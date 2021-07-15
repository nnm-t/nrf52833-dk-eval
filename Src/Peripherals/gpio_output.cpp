#include "gpio_output.h"

void GPIOOutput::init()
{
    nrf_gpio_cfg_output(_pin_number);
}

void GPIOOutput::write(const bool is_high)
{
    nrf_gpio_pin_write(_pin_number, static_cast<uint32_t>(is_high));
}

void GPIOOutput::set()
{
    nrf_gpio_pin_set(_pin_number);
}

void GPIOOutput::reset()
{
    nrf_gpio_pin_clear(_pin_number);
}
