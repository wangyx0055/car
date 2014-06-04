/**
 * @file exit.c 
 * @brief  按键使用中断
 *  
 */

 #include "exit.h"

static void NVIC_Configuration(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;

	/**/
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

	/*配置中断源*/
	NVIC_InitStructure.NVIC_IRQChannel = EXIT0_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_init(&NVIC_InitStructure);
}
