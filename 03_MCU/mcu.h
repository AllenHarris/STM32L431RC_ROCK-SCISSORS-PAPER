#ifndef _MCU_H_
#define _MCU_H_
 // （1）包含芯片及内核头文件
#include "stm32l4xx.h"                //芯片头文件(注意放在最前面)
#include "cpu.h"                      //内核头文件

//(2)MCU基本信息相关宏常数
//                            "1234567890123456789"
#define MCU_TYPE              "[STM32L4x]         "  //MCU型号（19字节）
//                            "1234567890"
#define BIOS_TYPE             "20191009 "            //BIOS版本号（9字节）
#define MCU_SECTORSIZE        2048                    //扇区大小（B）
#define MCU_SECTOR_NUM        128                     //MCU扇区总数
#define MCU_STACKTOP          0x2000ffff              //栈顶地址（RAM最大地址+1）
#define MCU_FLASH_ADDR_START  0x08000000              //MCU的FLASH起始地址
#define MCU_FLASH_ADDR_LENGTH 0x00040000              //MCU的FLASH长度（256KB）
#define MCU_RAM_ADDR_START    0x20000000	          //MCU的RAM起始地址
#define MCU_RAM_ADDR_LENGTH   0x00010000	          //MCU的RAM长度（64KB）

//(3)中断信息相关宏常数及宏函数
#define MCU_IRQ_MAX           83      // 可设置中断最大个数
#define MCU_IRQ_PRIOR_MAX     15      // 可设置最大中断优先级

#define ENABLE_INTERRUPTS        __enable_irq()             // 开总中断()
#define DISABLE_INTERRUPTS       __disable_irq()            // 关总中断()
#define NOP 				     __asm ("NOP")              // 无操作
#define DisableIRQ(irq)          NVIC_DisableIRQ(irq)       // 禁止irq中断
#define EnableIRQ(irq)           NVIC_EnableIRQ(irq)        // 打开irq中断
#define SetPriority(irq, prio)   NVIC_SetPriority(irq, prio)  // 设置irq中断优先级

//(2)复位发生标志位判断
#define IS_PIN_RESET_OCCURED        0//BGET(RCM_SRS0_PIN_SHIFT,RCM_SRS0)    // 按键复位
#define IS_POWERON_RESET_OCCURED    1//BGET(RCM_SRS0_POR_SHIFT, RCM_SRS0)   // 上电复位
#define IS_WDOG_RESET_OCCURED       2//BGET(RCM_SRS0_WDOG_SHIFT, RCM_SRS0)  // 看门狗复位

//(4)定义系统使用的时钟频率
#define  MCU_SYSTEM_CLK       SystemCoreClock          // 芯片系统时钟频率(HZ)
#define  MCU_SYSTEM_CLK_KHZ   SystemCoreClock/1000     // 芯片系统时钟频率(KHz)
#define  MCU_BUS_CLK_KHZ      SYSTEM_CLK_KHZ/2         // 芯片总线时钟频率(KHz)
#define  MCU_SYSTEM_CLK_MS    (48000)                   // 1ms所需时钟频率(HZ)
#define  MCU_SYSTEM_CLK_US    (48000 / 1000)            // 1us所需时钟频率(HZ)

#endif /* _MCU_H_ */
