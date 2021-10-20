#pragma once

#include "nrf_twi.h"
#include "nrf_drv_twi.h"
#include "nrf_twi_mngr.h"

#include "i2c.h"

class I2CManager : public I2C
{
    static constexpr const uint8_t max_pending_transactions = 5;

    NRF_TWI_MNGR_DEF(_i2c_manager, max_pending_transactions, I2C_INSTANCE_ID);

    nrf_twi_mngr_transaction_t _transaction;

public:
    I2CManager(const uint32_t scl, const uint32_t sda, nrf_twi_mngr_transfer_t const transfers, nrf_twi_mngr_callback_t callback, const nrf_drv_twi_frequency_t frequency = NRF_DRV_TWI_FREQ_100K, const uint8_t interrupt_priority = APP_IRQ_PRIORITY_LOWEST) : I2C(scl, sda, frequency, interrupt_priority)
    {
        _transaction = {
                .callback = callback,
                .p_user_data = NULL,
                .p_transfers = transfers,
                .number_of_transfers = sizeof(transfers) / sizeof(transfers[0])
        }
    }

    const uint32_t init() override
    {
        return nrf_twi_mngr_init(&_i2c_manager, &_config);
    }

    void schedule()
    {
        APP_ERR_CHECK(nrf_twi_mngr_schedule(&_i2c_manager, &_transaction));
    }
};
