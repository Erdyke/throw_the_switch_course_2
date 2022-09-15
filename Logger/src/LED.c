#include "LED.h"
#include "LPC1768.h"

#include "Utils.h"

#define LED_PORT LPC_GPIO1

#define LED_BITS (BIT_TO_MASK(18) | \
                  BIT_TO_MASK(20) | \
                  BIT_TO_MASK(21) | \
                  BIT_TO_MASK(23) )

void LED_Init(void)
{
    /* Configure for outputs */

    LED_PORT->FIODIR = LED_BITS;
    LED_PORT->FIOSET = LED_BITS;

    /* Set high to drive LEDs */
}