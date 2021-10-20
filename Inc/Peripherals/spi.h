#pragma once

#include "nrf_spi.h"
#include "nrf_drv_spi.h"

#define SPI_INSTANCE_ID 0

class SPI
{
protected:
    nrf_drv_spi_config_t _config;
public:
    SPI(const uint8_t ss, const uint8_t miso, const uint8_t mosi, const uint8_t sck, const nrf_drv_spi_frequency_t frequency = NRF_DRV_SPI_FREQ_4M)
    {
        _config = NRF_DRV_SPI_DEFAULT_CONFIG;
        _config.ss_pin = ss;
        _config.miso_pin = miso;
        _config.mosi_pin = mosi;
        _config.sck_pin = sck;
        _config.frequency = frequency;
    }

    virtual void init() = 0;

    nrf_drv_spi_config_t get_config()
    {
        return _config;
    }
};