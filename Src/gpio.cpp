#include "gpio.h"

uint32_t GPIO::get_pin_number() const
{
    return _pin_number;
}

void GPIOInput::init()
{
    nrf_gpio_cfg_input(_pin_number, _pull_config);
}

bool GPIOInput::read_is_high()
{
    return static_cast<bool>(nrf_gpio_pin_read(_pin_number));
}

nrf_gpio_pin_pull_t GPIOInput::get_pull_config() const
{
return _pull_config;
}

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