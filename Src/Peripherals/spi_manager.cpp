#include "spi_manager.h"

void SPIManager::init()
{
    APP_ERROR_CHECK(nrf_spi_mngr_init(_spi_manager, _config));
}

void SPIManager::transfer()
{

}