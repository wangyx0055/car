#include "sys_tick.h"

void SysTick_us_Init(void){
    if (SysTick_Config(SystemCoreClock / 1000000)) { /*1us中断一次*/
while(1); /*调用不成功，进入死循环*/
    }
    SysTick->CTRL &= ~ SysTick_CTRL_ENABLE_Msk; /*关闭滴答定时器，需要的时候开启*/
}

u32 nTime;

void Delay_us(u32 DelayTime){
    SysTick_us_Init();
		nTime=DelayTime;
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;   /*开启滴答定时器*/
    while (nTime != 0) {;}
	}		

void TimingDelay_Decrement(void){
    if (nTime != 0) {
        nTime--;
    }
}

