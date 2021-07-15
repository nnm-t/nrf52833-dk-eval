#pragma once

#include "gpio.h"

class GPIOInput : public GPIO
{
    const nrf_gpio_pin_pull_t _pull_config;

    GPIOInput(const uint32_t pin_number, const nrf_gpio_pin_pull_t pull_config) : GPIO(pin_number), _pull_config(pull_config)
    {

    }
public:
    static GPIOInput no_pull(const uint32_t pin_number)
    {
        return GPIOInput(pin_number, NRF_GPIO_PIN_NOPULL);
    }

    static GPIOInput pull_down(const uint32_t pin_number)
    {
        return GPIOInput(pin_number, NRF_GPIO_PIN_PULLDOWN);
    }

    static GPIOInput pull_up(const uint32_t pin_number)
    {
        return GPIOInput(pin_number, NRF_GPIO_PIN_PULLUP);
    }

    void init() override;

    bool read_is_high();

    nrf_gpio_pin_pull_t get_pull_config() const;
};
