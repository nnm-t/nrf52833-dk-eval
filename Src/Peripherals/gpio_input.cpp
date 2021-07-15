#include "gpio_input.h"

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
