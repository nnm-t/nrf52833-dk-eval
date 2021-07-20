#pragma once


#include "nrf_twi.h"
#include "nrf_drv_twi.h"
#include "nrf_twi_mngr.h"

#define TWI_INSTANCE_ID 0

class I2C
{
protected:
    nrf_drv_twi_config_t _config;

public:
    I2C(const uint32_t scl, const uint32_t sda, const nrf_drv_twi_frequency_t frequency = NRF_DRV_TWI_FREQ_100K, const uint8_t interrupt_priority = APP_IRQ_PRIORITY_LOWEST)
    {
        _config = {
            .scl = scl,
            .sda = sda,
            .frequency = frequency,
            .interrupt_priority = interrupt_priority,
            .clear_bus_init = false
        };
    }

    virtual uint32_t init() = 0;

    nrf_drv_twi_config_t get_config()
    {
        return _config;
    }
};
