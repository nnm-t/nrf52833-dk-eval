#pragma once

#include "spi.h"

#include "nrf_spi_mngr.h"

class SPIManager : public SPI
{
    static constexpr const uint8_t max_pending_transactions = 5;

    NRF_SPI_MNGR_DEF(_spi_manager, max_pending_transactions, SPI_INSTANCE_ID);

public:
    SPIManager(const uint8_t ss, const uint8_t mosi, const uint8_t miso, const uint8_t sck) : SPI(ss, mosi, miso, sck)
    {

    }

    void init() override;

    void transfer();
};