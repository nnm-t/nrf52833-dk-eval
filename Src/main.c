#include <stdint.h>
#include <string.h>
#include "nrf.h"

#include "cppmain.h"

int main(void)
{
    setup();

    while (1)
    {
        loop();
    }
}