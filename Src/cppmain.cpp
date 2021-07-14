#include "cppmain.h"
#include "nrf_delay.h"
#include "boards.h"

#ifdef __cplusplus
extern "C" {
#endif

void setup(void)
{
    bsp_board_init(BSP_INIT_LEDS);
}

void loop(void)
{
    bsp_board_led_invert(0);
    nrf_delay_ms(500);
}

#ifdef __cplusplus
}
#endif
