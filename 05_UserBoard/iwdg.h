#ifndef _IWDG_H    //防止重复定义（_IWDG_H  开头)
#define _IWDG_H

//1 头文件
#include "common.h"    //包含公共要素头文件

//分频系数宏定义
#define IWDG_PRESCALER_4     ((uint8_t)0x00)
#define IWDG_PRESCALER_8     ((uint8_t)(IWDG_PR_PR_0))
#define IWDG_PRESCALER_16    ((uint8_t)(IWDG_PR_PR_1))
#define IWDG_PRESCALER_32    ((uint8_t)(IWDG_PR_PR_1 | IWDG_PR_PR_0))
#define IWDG_PRESCALER_64    ((uint8_t)(IWDG_PR_PR_2))
#define IWDG_PRESCALER_128   ((uint8_t)(IWDG_PR_PR_2 | IWDG_PR_PR_0))
#define IWDG_PRESCALER_256   ((uint8_t)(IWDG_PR_PR_2 | IWDG_PR_PR_1))

//KR寄存器操作指令
#define IWDG_KEY_RELOAD                            ((uint32_t)0xAAAA)  /*!< IWDG Reload Counter Enable   */
#define IWDG_KEY_ENABLE                            ((uint32_t)0xCCCC)  /*!< IWDG Peripheral Enable       */
#define IWDG_KEY_WRITE_ACCESS_ENABLE               ((uint32_t)0x5555)  /*!< IWDG KR Write Access Enable  */
#define IWDG_KEY_WRITE_ACCESS_DISABLE              ((uint32_t)0x0000)  /*!< IWDG KR Write Access Disable */

// ===========================================================================
// 函数名称：iwdg_init
// 函数参数：prer:分频系数（WDGTB）,仅最低2位有效； rlr:分频数：IWDG_PRESCALER_4~IWDG_PRESCALER_256
// 函数返回：无
// 功能概要： 初始化独立看门狗，传入需要的参数设置。定时时间=((4*2^prer)*rlr)/32 (ms).
// ===========================================================================
void iwdg_init(uint_8 prer, uint_16 rlr);

// ===========================================================================
// 函数名称：iwdg_feed
// 函数参数：无
// 函数返回：无
// 功能概要： 喂狗，重载计时器
// ===========================================================================
void iwdg_feed(void);
#endif
