#include "LED.h"
#include "LPC1768.h"

#include "Utils.h"
#include "stdlib.h"

#define LED_PORT LPC_GPIO1

#define ALL_LED_BITS (BIT_TO_MASK(18) | \
                      BIT_TO_MASK(20) | \
                      BIT_TO_MASK(21) | \
                      BIT_TO_MASK(23) )

uint32_t led_to_mask_table[NUM_LED] =
{
    BIT_TO_MASK(18),
    BIT_TO_MASK(20),
    BIT_TO_MASK(21),
    BIT_TO_MASK(23),
};

void LED_Init(void)
{
    /* Configure for outputs */

    LED_PORT->FIODIR = ALL_LED_BITS;
    LED_PORT->FIOSET = ALL_LED_BITS;

    /* Set high to drive LEDs */
}

void LED_On(LED_ID_T led_id)
{
    if(led_id >= NUM_LED)
        return;

    LED_PORT->FIOSET |= led_to_mask_table[led_id];
}

void LED_Off(LED_ID_T led_id)
{
    if(led_id >= NUM_LED)
        return;

    LED_PORT->FIOCLR |= led_to_mask_table[led_id];
}

void LED_Toggle(LED_ID_T led_id)
{
    uint32_t pin_mask = led_to_mask_table[led_id];

    if(LPC_GPIO1->FIOPIN & pin_mask)
    {
        LPC_GPIO1->FIOCLR |= pin_mask;
    }
    else
    {
        LPC_GPIO1->FIOSET |= pin_mask;
    }
}