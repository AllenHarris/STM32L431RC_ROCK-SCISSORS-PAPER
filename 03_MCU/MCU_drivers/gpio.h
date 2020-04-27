//=====================================================================
//文件名称：gpio.h
//功能概要：GPIO底层驱动构件头文件
//制作单位：苏州大学嵌入式系统与物联网研究所(sumcu.suda.edu.cn)
//版    本：2019-05-27  V1.0;
//适用芯片：STM32L433xx
//=====================================================================

#ifndef _GPIO_H       //防止重复定义（_GPIO_H  开头)
#define _GPIO_H

#include "common.h"   //包含公共要素头文件
#include "string.h"

// 端口号地址偏移量宏定义
#define PTA_NUM    (0<<8)
#define PTB_NUM    (1<<8)
#define PTC_NUM    (2<<8)
#define PTD_NUM    (3<<8)
#define PTE_NUM    (4<<8)
#define PTH_NUM    (7<<8)
// GPIO引脚方向宏定义
#define GPIO_INPUT  (0)      //GPIO输入
#define GPIO_OUTPUT (1)      //GPIO输出
// GPIO引脚拉高低状态宏定义
#define PULL_UP    (0x01u)   //拉高
#define PULL_DOWN  (0x02u)   //拉低
// GPIO引脚中断类型宏定义
#define RISING_EDGE  (1)     //上升沿触发
#define FALLING_EDGE (2)     //下降沿触发
#define DOUBLE_EDGE  (3)     //双边沿触发
// GPIO输出速率宏定义
#define LOW_SPEED       (0x00u)  //低速
#define MSDIUM_SPEED    (0x01u)  //中速
#define HIGH_SPEED      (0x02u)  //高速
#define VERY_HIGH_SPEED (0x03u)  //超高速


#define USE_BIOS_GPIO    (0) //1代表函数继承自BIOS，0代表使用自带函数
#if (USE_BIOS_GPIO==0)
//=======================函数注释区====================================
//=====================================================================
//函数名称：gpio_init
//函数返回：无
//参数说明：port_pin：(端口号)|(引脚号)（如：(PTB_NUM)|(9) 表示为B口9号脚）
//         dir：引脚方向（0=输入，1=输出,可用引脚方向宏定义）
//         state：端口引脚初始状态（0=低电平，1=高电平）
//功能概要：初始化指定端口引脚作为GPIO引脚功能，并定义为输入或输出，若是输出，
//         还指定初始状态是低电平或高电平
//=====================================================================
void gpio_init(uint_16 port_pin, uint_8 dir, uint_8 state);

//=====================================================================
//函数名称：gpio_set
//函数返回：无
//参数说明：port_pin：(端口号)|(引脚号)（如：(PTB_NUM)|(9) 表示为B口9号脚）
//          state：希望设置的端口引脚状态（0=低电平，1=高电平）
//功能概要：当指定端口引脚被定义为GPIO功能且为输出时，本函数设定引脚状态
//=====================================================================
void gpio_set(uint_16 port_pin, uint_8 state);

//=====================================================================
//函数名称：gpio_get
//函数返回：指定端口引脚的状态（1或0）
//参数说明：port_pin：(端口号)|(引脚号)（如：(PTB_NUM)|(9) 表示为B口9号脚）
//功能概要：当指定端口引脚被定义为GPIO功能且为输入时，本函数获取指定引脚状态
//=====================================================================
uint_8 gpio_get(uint_16 port_pin);

//=====================================================================
//函数名称：gpio_reverse
//函数返回：无
//参数说明：port_pin：(端口号)|(引脚号)（如：(PTB_NUM)|(9) 表示为B口9号脚）
//功能概要：当指定端口引脚被定义为GPIO功能且为输出时，本函数反转引脚状态
//=====================================================================
void gpio_reverse(uint_16 port_pin);

//=====================================================================
//函数名称：gpio_pull
//函数返回：无
//参数说明：port_pin：(端口号)|(引脚号)（如：(PTB_NUM)|(9) 表示为B口9号脚）
//       pullselect：下拉/上拉（PULL_DOWN=下拉，PULL_UP=上拉）
//功能概要：当指定端口引脚被定义为GPIO功能且为输入时，本函数设置引脚下拉/上拉
//=====================================================================
void gpio_pull(uint_16 port_pin, uint_8 pullselect);

//=====================================================================
//函数名称：gpio_enable_int
//函数返回：无
//参数说明：port_pin：(端口号)|(引脚号)（如：(PTB_NUM)|(9) 表示为B口9号脚）
//          irqtype：引脚中断类型，由宏定义给出，再次列举如下：
//                  RISING_EDGE  9      //上升沿触发
//                  FALLING_EDGE 10     //下降沿触发
//                  DOUBLE_EDGE  11     //双边沿触发
//功能概要：当指定端口引脚被定义为GPIO功能且为输入时，本函数开启引脚中断，并
//          设置中断触发条件。
//注          意： KL25芯片，只有PORTA、PORTD口具有GPIO类中断功能
//         KW01芯片，只有PORTA、PORTC、PORTD口具有GPIO类中断功能
//         KL36芯片，只有PORTA、PORTC、PORTD口具有GPIO类中断功能
//        STM32L433芯片，PORTA、PORTB、PORTC、PORTH口具有GPIO类中断功能,在EXIT(扩展
//                     中断)处配置，且只包含上升沿触发、下降沿触发、双边沿触发三种引脚中断类型
//=====================================================================
void gpio_enable_int(uint_16 port_pin,uint_8 irqtype);

//=====================================================================
//函数名称：gpio_disable_int
//函数返回：无
//参数说明：port_pin：(端口号)|(引脚号)（如：(PTB_NUM)|(9) 表示为B口9号脚）
//功能概要：当指定端口引脚被定义为GPIO功能且为输入时，本函数关闭引脚中断
//注          意： KL25芯片，只有PORTA、PORTD口具有GPIO类中断功能
//         KW01芯片，只有PORTA、PORTC、PORTD口具有GPIO类中断功能
//         KL36芯片，只有PORTA、PORTC、PORTD口具有GPIO类中断功能
//        STM32L433芯片，PORTA、PORTB、PORTC、PORTH口具有GPIO类中断功能,在EXIT(扩展
//                     中断)处配置，且只包含上升沿触发、下降沿触发、双边沿触发三种引脚中断类型
//=====================================================================
void gpio_disable_int(uint_16 port_pin);

//=====================================================================
//函数名称：gpio_get_int
//函数返回：引脚GPIO中断标志（1或0）1表示引脚有GPIO中断，0表示引脚没有GPIO中断。
//参数说明：port_pin：(端口号)|(引脚号)（如：(PTB_NUM)|(9) 表示为B口9号脚）
//功能概要：当指定端口引脚被定义为GPIO功能且为输入时,获取中断标志。
//注          意： KL25芯片，只有PORTA、PORTD口具有GPIO类中断功能
//        KW01芯片，只有PORTA、PORTC、PORTD口具有GPIO类中断功能
//        KL36芯片，只有PORTA、PORTC、PORTD口具有GPIO类中断功能
//        STM32L433芯片，PORTA、PORTB、PORTC、PORTH口具有GPIO类中断功能,在EXIT(扩展
//                     中断)处配置，且只包含上升沿触发、下降沿触发、双边沿触发三种引脚中断类型
//=====================================================================
uint_8 gpio_get_int(uint_16 port_pin);

//=====================================================================
//函数名称：gpio_clear_int
//函数返回：无
//参数说明：port_pin：(端口号)|(引脚号)（如：(PTB_NUM)|(9) 表示为B口9号脚）
//功能概要：当指定端口引脚被定义为GPIO功能且为输入时,清除中断标志。
//注          意： KL25芯片，只有PORTA、PORTD口具有GPIO类中断功能
//         KW01芯片，只有PORTA、PORTC、PORTD口具有GPIO类中断功能
//         KL36芯片，只有PORTA、PORTC、PORTD口具有GPIO类中断功能
//        STM32L433芯片，PORTA、PORTB、PORTC、PORTH口具有GPIO类中断功能,在EXIT(扩展
//                     中断)处配置，且只包含上升沿触发、下降沿触发、双边沿触发三种引脚中断类型
//=====================================================================
void gpio_clear_int(uint_16 port_pin);

//=====================================================================
//函数名称：gpio_clear_allint
//函数返回：无
//参数说明：无
//功能概要：清除所有端口的GPIO中断
//注          意： KL25芯片，只有PORTA、PORTD口具有GPIO类中断功能
//         KW01芯片，只有PORTA、PORTC、PORTD口具有GPIO类中断功能
//         KL36芯片，只有PORTA、PORTC、PORTD口具有GPIO类中断功能
//        STM32L433芯片，PORTA、PORTB、PORTC、PORTH口具有GPIO类中断功能,在EXIT(扩展
//                     中断)处配置，且只包含上升沿触发、下降沿触发、双边沿触发三种引脚中断类型
//=====================================================================
void gpio_clear_allint(void);

//=====================================================================
//函数名称：gpio_drive_strength
//函数返回：无
//参数说明：port_pin：(端口号)|(引脚号)（如：(PTB_NUM)|(9) 表示为B口9号脚）
//       control：控制引脚的驱动能力，LOW_SPEED=低速,MSDIUM_SPEED=中速
//               HIGH_SPEED=高速,VERY_HIGH_SPEED=超高速
//功能概要：（引脚驱动能力：指引脚输入或输出电流的承受力，一般用mA单位度量
//        ，正常驱动能力5mA,高驱动能力18mA。）当引脚被配置为数字输出时,
//        对引脚的驱动能力进行设置
//=====================================================================
void gpio_drive_strength(uint_16 port_pin, uint_8 control);
//=======================函数注释区结束====================================


//=======================函数定义区结束=====================================
#elif (USE_BIOS_GPIO==1)

#define gpio_init ((void (*)(uint_16 port_pin, uint_8 dir, uint_8 state))(component_fun[37]))
#define gpio_set ((void (*)(uint_16 port_pin, uint_8 state))(component_fun[38]))
#define gpio_get ((uint_8 (*)(uint_16 port_pin))(component_fun[39]))
#define gpio_reverse ((void (*)(uint_16 port_pin))(component_fun[40]))
#define gpio_pull ((void (*)(uint_16 port_pin, uint_8 pullselect))(component_fun[41]))
#define gpio_enable_int ((void (*)(uint_16 port_pin,uint_8 irqtype))(component_fun[42]))
#define gpio_disable_int ((void (*)(uint_16 port_pin))(component_fun[43]))
#define gpio_drive_strength ((void (*)(uint_16 port_pin, uint_8 control))(component_fun[44]))

#endif

#endif
