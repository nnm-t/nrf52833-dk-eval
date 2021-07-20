#include "i2c_driver.h"

uint32_t I2CDriver::init()
{
    const ret_code_t error_code = nrf_drv_twi_init(&_i2c_driver, &_config, NULL, NULL);
    APP_ERROR_CHECK(error_code);

    nrf_drv_twi_enable(&_i2c_driver);
    return error_code;
}

std::vector<uint8_t> I2CDriver::receive(uint8_t address, uint8_t length)
{
    std::vector<uint8_t> vector;
    vector.reserve(length);

    const ret_code_t error_code = nrf_drv_twi_rx(&_i2c_driver, address, &vector.front(), length);

    if (error_code != NRF_SUCCESS) {
        // 受信失�
        return std::vector<uint8_t>();
    }

    return vector;
}


ret_code_t I2CDriver::transmit(uint8_t address, std::vector<uint8_t>& vector, bool no_step)
{
    return nrf_drv_twi_tx(&_i2c_driver, address, &vector.front(), vector.size(), no_step);
}