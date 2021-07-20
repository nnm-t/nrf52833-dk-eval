#pragma once

#include <vector>

#include "nrf_twi.h"
#include "nrf_drv_twi.h"

#include "i2c.h"

class I2CDriver : public I2C
{
    const nrf_drv_twi_t _i2c_driver = NRF_DRV_TWI_INSTANCE(TWI_INSTANCE_ID);

public:
    I2CDriver(const uint32_t scl, const uint32_t sda, const nrf_drv_twi_frequency_t frequency = NRF_DRV_TWI_FREQ_100K, const uint8_t interrupt_priority = APP_IRQ_PRIORITY_LOWEST) : I2C(scl, sda, frequency, interrupt_priority)
    {

    }

    uint32_t init() override;

    std::vector<uint8_t> receive(uint8_t address, uint8_t length);

    ret_code_t transmit(uint8_t address, std::vector<uint8_t>& vector, bool no_step = false);
};
