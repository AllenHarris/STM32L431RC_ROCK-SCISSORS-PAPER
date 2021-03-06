//文件名称：light.h

#ifndef _LIGHT_H      //防止重复定义（_LIGHT_H  开头)
#define _LIGHT_H

#ifdef _cplusplus
extern "C"{
#endif

//头文件包含
#include "common.h"    //包含公共要素头文件
#include "gpio.h"      //用到gpio构件

//指示灯端口及引脚定义
//#define  LIGHT_RED    GPIOA_2  //红灯，所在引脚：GEC_56（PTB_NUM|7）
//#define  LIGHT_GREEN  GPIOA_1  //绿灯， 所在引脚：GEC_55（PTB_NUM|8）
#define  LIGHT_BLUE   GPIOA_0  //蓝灯， 所在引脚：GEC_54（PTB_NUM|9）

//灯状态宏定义（灯亮、灯暗对应的物理电平由硬件接法决定）
#define  LIGHT_ON       0    //灯亮
#define  LIGHT_OFF      1    //灯暗

//=================接口函数声明=======================================
//=========================================================================
//函数名称：light_init
//函数参数：port_pin：(端口号)|(引脚号)（如：(PTB_NUM)|(9) 表示为B口9号脚）
//       state：设定小灯状态。由宏定义。
//函数返回：无
//功能概要：指示灯驱动初始化。
//======================================================================
void light_init(uint_16 port_pin, uint_8 state);

//======================================================================
//函数名称：light_control
//函数参数：port_pin：(端口号)|(引脚号)（如：(PTB_NUM)|(9) 表示为B口9号脚）
//       state：设定小灯状态。由宏定义。
//函数返回：无
//功能概要：控制指示灯亮暗。
//======================================================================
void light_control(uint_16 port_pin, uint_8 state);

//======================================================================
//函数名称：light_change
//函数参数：port_pin：(端口号)|(引脚号)（如：(PTB_NUM)|(9) 表示为B口9号脚）
//函数返回：无
//功能概要：切换指示灯亮暗。
//======================================================================
void light_change(uint_16 port_pin);

#ifdef __cplusplus
}
#endif

#endif    //防止重复定义（_LIGHT_H  结尾)

