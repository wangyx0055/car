#ifndef __SYS_TICK_H
#define __SYS_TICK_H

#include "stm32f10x.h"

extern u32 nTime,count;


void SysTick_us_Init(void);
void SysTick_ms_Init(void);
void SysTick_s_Init(void);

void Delay_us(u32 nTime);
void TimingDelay_Decrement(void);

#endif /*__SYS_TICK_H*/
