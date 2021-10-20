#pragma once

#include <vector>

#include "spi.h"

class SPIDriver : public SPI
{
    const nrf_drv_spi_t _spi_driver = NRF_DRV_SPI_INSTANCE(SPI_INSTANCE_ID);
    nrf_drv_spi_evt_handler_t _event_handler;

public:
    SPIDriver(const uint8_t ss, const uint8_t miso, const uint8_t mosi, const uint8_t sck, nrf_drv_spi_evt_handler_t event_handler) : SPI(ss, miso, mosi, sck), _event_handler(event_handler)
    {

    }

    std::vector<uint8_t*> transfer(std::vector<uint8_t*>& transmit, uint8_t receive_length);

    void init() override;
};