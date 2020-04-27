//======================================================================
//文件名称：user.h（用户程序头文件）
//制作单位：苏大arm技术中心(sumcu.suda.edu.cn)
//更新记录：2018.12：1.0，2019.1：A.10
//概要说明：本文件用于GEC用户在使用GEC芯片进行硬件板设计时存放用户板部分引脚定义，
//        GEC引脚具有的功能在gec.h文件中
//======================================================================

#ifndef USER_H   //防止重复定义（开始）
#define USER_H

#include "gec.h"
#include "printf.h"
#include "iwdg.h"

//===========================================================
//UART模块定义
#define UART_BAUD    115200 //串口波特率宏定义
#define UART_USER    UARTA  //TX引脚：GEC_10；RX引脚：GEC_8
//UART其他模块定义
#define UART_UE      UARTB  //用于通讯模组通讯，引脚未引出
#define UART_UPDATE  UARTC  //用于程序更新，无法被使用

//timer模块定义

//TSI模块定义

//指示灯端口及引脚定义
#define  LIGHT_RED    GPIOA_2  //红灯，所在引脚：GEC_56（PTB_NUM|7）
#define  LIGHT_GREEN  GPIOA_1  //绿灯， 所在引脚：GEC_55（PTB_NUM|8）
#define  LIGHT_BLUE   GPIOA_0  //蓝灯， 所在引脚：GEC_54（PTB_NUM|9）

//灯状态宏定义（灯亮、灯暗对应的物理电平由硬件接法决定）
#define  LIGHT_ON       0    //灯亮
#define  LIGHT_OFF      1    //灯暗

//中断重定义
#define	TIMER_USER_Handler			SysTick_Handler
#define	ADC1_IRQHandler				ADC1_IRQHandler
#define	TIM1_BRK_TIM15_IRQHandler	TIM1_BRK_TIM15_IRQHandler
#define	TIM1_UP_TIM16_IRQHandler	TIM1_UP_TIM16_IRQHandler
#define	TIM1_TRG_COM_IRQHandler		TIM1_TRG_COM_IRQHandler
#define	TIM1_CC_IRQHandler			TIM1_CC_IRQHandler
#define	TIM2_IRQHandler				TIM2_IRQHandler
#define	I2C1_EV_IRQHandler			I2C1_EV_IRQHandler
#define	I2C1_ER_IRQHandler			I2C1_ER_IRQHandler
#define	I2C2_EV_IRQHandler			I2C2_EV_IRQHandler
#define	I2C2_ER_IRQHandler			I2C2_ER_IRQHandler
#define	SPI1_IRQHandler				SPI1_IRQHandler
#define	SPI2_IRQHandler				SPI2_IRQHandler
#define	USART1_IRQHandler			USART1_IRQHandler
#define	UART_USER_Handler			USART2_IRQHandler               //USART2_IRQHandler重定义为UART_USER_Handler
#define	USART3_IRQHandler			USART3_IRQHandler
#define	RTC_Alarm_IRQHandler		RTC_Alarm_IRQHandler
#define	SPI3_IRQHandler				SPI3_IRQHandler
#define	TIM6_DAC_IRQHandler			TIM6_DAC_IRQHandler
#define	TIM7_IRQHandler				TIM7_IRQHandler
#define	LPUART1_IRQHandler			LPUART1_IRQHandler
#define	I2C3_EV_IRQHandler			I2C3_EV_IRQHandler
#define	I2C3_ER_IRQHandler			I2C3_ER_IRQHandler
#define EXTI0_IRQHandler            EXTI0_IRQHandler
#define EXTI3_IRQHandler            EXTI3_IRQHandler
#define EXTI9_5_IRQHandler 			EXTI9_5_IRQHandler

#define state_label       0
#define state_inference   1
#define state_train       2
#endif//防止重复定义（结尾）
