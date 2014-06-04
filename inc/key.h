#ifndef __KEY_H
#define __KEY_H

#include "stm32f10x.h"

#define KEY_ON	0
#define KEY_OFF	1

void key_gpio_config(void);
u8 key_scan(GPIO_TypeDef* GPIOx, u16 GPIO_Pin);

#endif /*__LED_H*/

