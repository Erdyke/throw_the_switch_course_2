#include "Core.h"
#include "Digital.h"
#include "LPC1768.h"
#include "Utils.h"

#define ALL_DIGITAL_BITS (MASK_RANGE(0, 5))

#define DIGITAL_PORT     LPC_GPIO2
#define DIGITAL_PIN_MIN  (0)
#define DIGITAL_PIN_MAX  (5)

#define DIGITAL_PINSEL   LPC_PINCON->PINSEL4
#define DIGITAL_PINMODE  LPC_PINCON->PINMODE4
#define DIGITAL_PINVAL   LPC_GPIO2->FIOPIN

void Digital_Init(void)
{
    //All our Digital I/O are going to be inputs
    DIGITAL_PORT->FIOMASK &= ~ ALL_DIGITAL_BITS;
    DIGITAL_PORT->FIODIR  &= ~ ALL_DIGITAL_BITS;

    //Clear pin select bits for bits we plan to use to make them GPIO pins
    DIGITAL_PINSEL  &= ~MASK_RANGE_PAIRS(DIGITAL_PIN_MIN, DIGITAL_PIN_MAX, 0x3);
    DIGITAL_PINMODE |= MASK_RANGE_PAIRS(DIGITAL_PIN_MIN, DIGITAL_PIN_MAX, 0x3);
}

uint8_t Digital_GetBits(void)
{
    uint32_t pin_values = DIGITAL_PINVAL & ALL_DIGITAL_BITS;
    return ((uint8_t) pin_values);
}