#ifndef __SPEAKER_H
#define __SPEAKER_H

#include "stm32f10x.h"

#define ON  0
#define OFF 1

#define SPEAKER(a)	if (a)	\
					GPIO_SetBits(GPIOB,GPIO_Pin_3);\
					else		\
					GPIO_ResetBits(GPIOB,GPIO_Pin_3)


void SPEAKER_GPIO_Config(void);
					
					
#endif /*__SPEAKER_H*/
