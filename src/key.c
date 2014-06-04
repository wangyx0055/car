/**
 * @file key.c 
 * @brief 扫描 
 */

#include "key.h"

static void Delay(__IO u32 ncount) /*不精确延时*/
{
    for (; ncount != 0; ncount--) 
	{;}
}

/**
 * @brief 配置用到的IO口 KEY1 （PA0） 
 *                    KEY2 （PC13）
 * @author k1 (2014/5/28)
 */
void key_gpio_config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    
    /*开启时钟*/
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC, ENABLE);

	/*初始化PA1*/
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOA, &GPIO_InitStructure);          

	/*初始化PC13*/
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOC, &GPIO_InitStructure); 
}
/**
 * @brief 检查是否有键按下 
 * @param 具体的端口和引脚 
 *      @arg
 *      @arg
 * @retval 按键的状态 
 *      @arg
 *      @arg
 */
u8 key_scan(GPIO_TypeDef* GPIOx, u16 GPIO_Pin)
{    
	/*检查是否有键按下*/
    if (GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON) 
	{ 
		Delay(1000);/*延时消抖*/
		if (GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON) 
        {
            while(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON);/*等待按键释放*/
            return KEY_ON;
        }
        else
            return KEY_OFF;
    }
    return KEY_OFF;
}
