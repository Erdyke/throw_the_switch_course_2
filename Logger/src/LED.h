#ifndef LED_H
#define LED_H

typedef enum
{
    LED0 = 0,
    LED1,
    LED2,
    LED3,
    NUM_LED
} LED_ID_T;

void LED_Init(void);
void LED_Toggle(LED_ID_T id);
void LED_On(LED_ID_T id);
void LED_Off(LED_ID_T id);


#endif