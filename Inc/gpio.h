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