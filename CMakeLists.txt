# CLion 静的解析用
cmake_minimum_required(VERSION 3.19)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)

# ToolchainとnRF5 SDKのPathを環境変数から読み込む (実際はIDE設定などで流し込めばOK)
set(TOOLCHAIN_PATH $ENV{TOOLCHAIN_PATH})
set(SDK_ROOT $ENV{SDK_ROOT})
message("Toolchain directory: ${TOOLCHAIN_PATH}")
message("SDK root directory: ${SDK_ROOT}")

if (WIN32)
    # Windowsのみexe形式
    set(TOOLCHAIN_EXTENSION ".exe")
else()
    set(TOOLCHAIN_EXTENSION "")
endif()

# ASMのenable_languageを設定しておく
enable_language(ASM)
set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)
# コンパイラは拡張子付きのフルパスで指定する (CMAKE_ASM_COMPILERの差し替えでは必須)
set(CMAKE_C_COMPILER "${TOOLCHAIN_PATH}/arm-none-eabi-gcc${TOOLCHAIN_EXTENSION}")
set(CMAKE_CXX_COMPILER "${TOOLCHAIN_PATH}/arm-none-eabi-g++${TOOLCHAIN_EXTENSION}")
set(CMAKE_ASM_COMPILER "${TOOLCHAIN_PATH}/arm-none-eabi-gcc${TOOLCHAIN_EXTENSION}")

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(PROJ_DIR "${CMAKE_CURRENT_SOURCE_DIR}")

project(nrf52833-ble-test C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)

include_directories(
        ${PROJ_DIR}/Inc
        ${SDK_ROOT}/components/ble/common
        ${SDK_ROOT}/components/ble/ble_advertising
        ${SDK_ROOT}/components/ble/ble_link_ctx_manager
        ${SDK_ROOT}/components/ble/ble_services/ble_nus
        ${SDK_ROOT}/components/ble/nrf_ble_gatt
        ${SDK_ROOT}/components/ble/nrf_ble_qwr
        ${SDK_ROOT}/components/softdevice/common
        ${SDK_ROOT}/components/softdevice/mbr/headers
        ${SDK_ROOT}/components/softdevice/s140/headers
        ${SDK_ROOT}/components/softdevice/s140/headers/nrf52
        ${SDK_ROOT}/components
        ${SDK_ROOT}/components/boards
        ${SDK_ROOT}/components/drivers_nrf/nrf_soc_nosd
        ${SDK_ROOT}/components/libraries/atomic
        ${SDK_ROOT}/components/libraries/balloc
        ${SDK_ROOT}/components/libraries/bsp
        ${SDK_ROOT}/components/libraries/delay
        ${SDK_ROOT}/components/libraries/experimental_section_vars
        ${SDK_ROOT}/components/libraries/log
        ${SDK_ROOT}/components/libraries/log/src
        ${SDK_ROOT}/components/libraries/memobj
        ${SDK_ROOT}/components/libraries/pwr_mgmt
        ${SDK_ROOT}/components/libraries/ringbuf
        ${SDK_ROOT}/components/libraries/strerror
        ${SDK_ROOT}/components/libraries/timer
        ${SDK_ROOT}/components/libraries/util
        ${SDK_ROOT}/components/libraries/uart
        ${SDK_ROOT}/components/toolchain/cmsis/include
        ${SDK_ROOT}/external/fprintf
        ${SDK_ROOT}/integration/nrfx
        ${SDK_ROOT}/modules/nrfx
        ${SDK_ROOT}/modules/nrfx/drivers
        ${SDK_ROOT}/modules/nrfx/drivers/include
        ${SDK_ROOT}/modules/nrfx/hal
        ${SDK_ROOT}/modules/nrfx/mdk
        ${SDK_ROOT}/modules/nrfx/soc
)

file(GLOB_RECURSE SOURCES
        ${PROJ_DIR}/Src/*.*
        ${SDK_ROOT}/components/ble/ble_advertising/ble_advertising.c
        ${SDK_ROOT}/components/ble/ble_link_ctx_manager/ble_link_ctx_manager.c
        ${SDK_ROOT}/components/ble/ble_services/ble_nus/ble_nus.c
        ${SDK_ROOT}/components/ble/common/ble_advdata.c
        ${SDK_ROOT}/components/ble/common/ble_conn_params.c
        ${SDK_ROOT}/components/ble/nrf_ble_gatt/nrf_ble_gatt.c
        ${SDK_ROOT}/components/ble/nrf_ble_qwr/nrf_ble_qwr.c
        ${SDK_ROOT}/components/boards/boards.c
        ${SDK_ROOT}/components/libraries/log/src/nrf_log_frontend.c
        ${SDK_ROOT}/components/libraries/log/src/nrf_log_backend_rtt.c
        ${SDK_ROOT}/components/libraries/log/src/nrf_log_backend_serial.c
        ${SDK_ROOT}/components/libraries/log/src/nrf_log_default_backends.c
        ${SDK_ROOT}/components/libraries/log/src/nrf_log_frontend.c
        ${SDK_ROOT}/components/libraries/log/src/nrf_log_str_formatter.c
        ${SDK_ROOT}/components/libraries/pwr_mgmt/nrf_pwr_mgmt.c
        ${SDK_ROOT}/components/libraries/timer/app_timer.c
        ${SDK_ROOT}/components/libraries/uart/app_uart.c
        ${SDK_ROOT}/components/libraries/util/app_error.c
        ${SDK_ROOT}/components/libraries/util/app_error_handler_gcc.c
        ${SDK_ROOT}/components/libraries/util/app_error_weak.c
        ${SDK_ROOT}/components/libraries/util/app_util_platform.c
        ${SDK_ROOT}/components/libraries/util/nrf_assert.c
        ${SDK_ROOT}/components/libraries/atomic/nrf_atomic.c
        ${SDK_ROOT}/components/libraries/balloc/nrf_balloc.c
        ${SDK_ROOT}/components/libraries/memobj/nrf_memobj.c
        ${SDK_ROOT}/components/libraries/ringbuf/nrf_ringbuf.c
        ${SDK_ROOT}/components/libraries/strerror/nrf_strerror.c
        ${SDK_ROOT}/components/softdevice/common/nrf_sdh.c
        ${SDK_ROOT}/components/softdevice/common/nrf_sdh_ble.c
        ${SDK_ROOT}/components/softdevice/common/nrf_sdh_soc.c
        ${SDK_ROOT}/external/fprintf/nrf_fprintf.c
        ${SDK_ROOT}/external/fprintf/nrf_fprintf_format.c
        ${SDK_ROOT}/modules/nrfx/soc/nrfx_atomic.c
        ${SDK_ROOT}/modules/nrfx/mdk/system_nrf52833.c
        ${SDK_ROOT}/modules/nrfx/mdk/ses_startup_nrf52833.s
        ${SDK_ROOT}/modules/nrfx/mdk/ses_startup_nrf_common.s
)

add_definitions(
        -DBOARD_PCA10100
        -DNRF52833_XXAA
)

# 静的解析に使うだけなのでコンパイルオプションやリンカスクリプトは最小限のみ
set(TARGET_NAME ${PROJECT_NAME})
add_executable(${TARGET_NAME}.out ${SOURCES})
