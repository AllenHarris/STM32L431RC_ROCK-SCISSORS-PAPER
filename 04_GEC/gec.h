//======================================================================
//文件名称：gec.h（GEC芯片引脚头文件）
//制作单位：苏大arm技术中心(sumcu.suda.edu.cn)
//更新记录：2018.12：1.0，2019.2：A.12
//概要说明：本文件为GEC引脚的功能索引
//======================================================================

#ifndef GEC_H    //防止重复定义（开始）
#define GEC_H

#include "mcu.h"
#include "gpio.h"
#include "uart.h"
#include "flash.h"
//GEC基本信息==================================================
#define GEC_USER_SECTOR_START    (26)   //26=从BIOS启动,0=自启动0
#define GEC_COMPONENT_LST_START  (19)   //函数列表开始扇区号
#define BIOS_UART_UPDATE_IRQn    (55)   //BIOS程序写入串口的中断号
#define BIOS_TIMER_IRQn          (44)   //的BIOS程序定时器的中断号

//===========================================================
//（0）GEC引脚名与内部MCU（STM32L4+）引脚对应关系
//有关名称
#define  GND          0XFFFF    //地
#define  P5V          0XFFFE    //5V电源
#define  P3V3         0XFFFD    //3V3电源
#define  GNSS_ANT     0XFFFC    //北斗/GPS天线引脚名称
#define  MAIN_ANT     0XFFFB    //主通信模组引脚名称
#define  DBG_TXD      0XFFFA    //主通信模组调试串口输出引脚名称
#define  DBG_RXD      0XFFF9    //主通信模组调试串口输入引脚名称
#define  SWD_DIO      0XFFF8    //SWD数据输入引脚名称
#define  SWD_CLK      0XFFF7    //SWD时钟信号引脚名称
#define  NRST         0XFFF6    //NRST
//端口号地址偏移量宏定义
#define PTA_NUM     (0<<8)
#define PTB_NUM     (1<<8)
#define PTC_NUM     (2<<8)
#define PTD_NUM     (3<<8)
#define PTE_NUM     (4<<8)
//GEC引脚定义
#define  GEC_1     GND
#define  GEC_2     PTC_NUM|9
#define  GEC_3     PTC_NUM|8
#define  GEC_4     PTC_NUM|7
#define  GEC_5     PTC_NUM|6
#define  GEC_6     PTC_NUM|5
#define  GEC_7     PTC_NUM|4
#define  GEC_8     PTA_NUM|3     //UART0_RX
#define  GEC_9     GND
#define  GEC_10    PTA_NUM|2     //UART0_TX

#define  GEC_11    PTB_NUM|1
#define  GEC_12    PTB_NUM|0
#define  GEC_13    PTC_NUM|11     //UART2_RX
#define  GEC_14    PTC_NUM|10     //UART2_TX
#define  GEC_15    PTA_NUM|7
#define  GEC_16    PTA_NUM|6
#define  GEC_17    GND
#define  GEC_18    GNSS_ANT
#define  GEC_19    GND
#define  GEC_20    GND

#define  GEC_21    PTA_NUM|5
#define  GEC_22    PTA_NUM|15
#define  GEC_23    PTB_NUM|3
#define  GEC_24    PTB_NUM|4
#define  GEC_25    PTB_NUM|5
#define  GEC_26    GND
#define  GEC_27    PTB_NUM|6
#define  GEC_28    PTB_NUM|14
#define  GEC_29    PTB_NUM|15
#define  GEC_30    PTB_NUM|13

#define  GEC_31    PTB_NUM|12
#define  GEC_32    GND
#define  GEC_33    MAIN_ANT
#define  GEC_34    GND
#define  GEC_35    GND
#define  GEC_36    P3V3
#define  GEC_37    PTA_NUM|8
#define  GEC_38    PTB_NUM|11   //GPIOC_13/I2CB_SDA
#define  GEC_39    PTB_NUM|10   //GPIOC_14/I2CB_SCL
#define  GEC_40    PTA_NUM|4	//

#define  GEC_41    PTC_NUM|15  	//
#define  GEC_42    PTC_NUM|14	//
#define  GEC_43    GND
#define  GEC_44    PTA_NUM|1
#define  GEC_45    PTA_NUM|0
#define  GEC_46    PTC_NUM|1   	//GPIOB_14/I2CA的SDA引脚
#define  GEC_47    PTC_NUM|0   	//GPIOB_15/I2CA的SCL引脚
#define  GEC_48    PTC_NUM|2
#define  GEC_49    PTC_NUM|3
#define  GEC_50    NRST

#define  GEC_51    GND
#define  GEC_52    GND
#define  GEC_53    DBG_RXD
#define  GEC_54    PTB_NUM|9
#define  GEC_55    PTB_NUM|8
#define  GEC_56    PTB_NUM|7
#define  GEC_57    NRST  //NMI（保留）
#define  GEC_58    SWD_DIO
#define  GEC_59    PTD_NUM|2
#define  GEC_60    GND

#define  GEC_61    PTC_NUM|12
#define  GEC_62    SWD_CLK
#define  GEC_63    GND
#define  GEC_64    P3V3
#define  GEC_65    GND
#define  GEC_66    P5V
#define  GEC_67    P5V
#define  GEC_68    GND

//（1）GPIO引脚
//GPIOA模块（具有中断功能）
#define  GPIOA_0    GEC_54   //PTB_NUM|9
#define  GPIOA_1    GEC_55   //PTB_NUM|8
#define  GPIOA_2    GEC_56   //PTB_NUM|7
#define  GPIOA_3    GEC_59   //PTD_NUM|2
#define  GPIOA_4    GEC_61   //PTC_NUM|12
//GPIOB模块
#define  GPIOB_0    GEC_15   //PTA_NUM|7
#define  GPIOB_1    GEC_16   //PTA_NUM|6

#define  GPIOB_2    GEC_21   //PTA_NUM|5
#define  GPIOB_3    GEC_22   //PTA_NUM|15
#define  GPIOB_4    GEC_23   //PTB_NUM|3
#define  GPIOB_5    GEC_24   //PTB_NUM|4
#define  GPIOB_6    GEC_25   //PTB_NUM|5

#define  GPIOB_7    GEC_27   //PTB_NUM|6
#define  GPIOB_8    GEC_28   //PTB_NUM|14
#define  GPIOB_9    GEC_29   //PTB_NUM|15
#define  GPIOB_10   GEC_30   //PTB_NUM|13
#define  GPIOB_11   GEC_31   //PTB_NUM|12

#define  GPIOB_12   GEC_37   //PTA_NUM|8
#define  GPIOB_13   GEC_38   //PTB_NUM|11
#define  GPIOB_14   GEC_39   //PTB_NUM|10
#define  GPIOB_15   GEC_40   //PTA_NUM|4
//GPIOC模块
#define  GPIOC_0    GEC_2    //PTC_NUM|9
#define  GPIOC_1    GEC_3    //PTC_NUM|8
#define  GPIOC_2    GEC_4    //PTC_NUM|7
#define  GPIOC_3    GEC_5    //PTC_NUM|6
#define  GPIOC_4    GEC_6    //PTC_NUM|5
#define  GPIOC_5    GEC_7    //PTC_NUM|4
#define  GPIOC_6    GEC_11   //PTB_NUM|1
#define  GPIOC_7    GEC_12   //PTB_NUM|0
#define  GPIOC_8    GEC_41   //PTC_NUM|15
#define  GPIOC_9    GEC_42   //PTC_NUM|14
#define  GPIOC_10   GEC_44   //PTA_NUM|1
#define  GPIOC_11   GEC_45   //PTA_NUM|0
#define  GPIOC_12   GEC_46   //PTC_NUM|1
#define  GPIOC_13   GEC_47   //PTC_NUM|0
#define  GPIOC_14   GEC_48   //PTC_NUM|2
#define  GPIOC_15   GEC_49   //PTC_NUM|3

//（2）UART引脚
//UART模块定义
#define UARTA  2  //TX引脚： GEC_10；RX引脚： GEC_8(板上标识uart0)
#define UARTB  1  //未引出（请勿使用）
#define UARTC  3  //TX引脚： GEC_14；RX引脚： GEC_13(板上标识uart2)

#define SPIA  1
#define SPIB  0

#endif  //防止重复定义（结尾）
