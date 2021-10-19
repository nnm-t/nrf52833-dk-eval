#include "spi_driver.h"

void SPIDriver::init()
{
    APP_ERROR_CHECK(nrf_drv_spi_init(&_spi_driver, &_config, _event_handler, NULL));
}

std::vector<uint8_t*> SPIDriver::transfer(std::vector<uint8_t*> &transmit, uint8_t receive_length)
{
    std::vector<uint8_t*> receive(receive_length);

    APP_ERROR_CHECK(nrf_drv_spi_transfer(&_spi_driver, transmit.front(), transmit.size(), receive.front(), receive_length));

    return receive;
}