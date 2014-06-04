/**
  ******************************************************************************
  * @file    main.c
  * @author  vipzrx <vipzrx@gmail.com>
  * @version 
  * @date    2014-06-04
  * @brief   Main program body
  ******************************************************************************
  * @attention
  * 这是中文的注释
  * 
  ******************************************************************************
  */  

#include "stdio.h"


 /* 初始化UART3
	USART3 configured as follow:
        - BaudRate = 115200 baud  
        - Word Length = 8 Bits
        - One Stop Bit
        - No parity
        - Hardware flow control disabled (RTS and CTS signals)
        - Receive and transmit enabled
  */

  USART_InitStructure.USART_BaudRate = 115200;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

  FTB_EVAL_COMInit(COM3, &USART_InitStructure);
  