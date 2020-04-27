
#include "gec.h"

//======================================================================
//函数名称：BIOS_API_Init
//函数返回：无
//参数说明：无
//功能概要：（1）BIOS区域驱动构件函数指针初始化
//          （2）User中断向量表涉及BOIS两个中断向量的更改
//======================================================================
void  BIOS_API_Init()
{
#if (GEC_USER_SECTOR_START!=0)
	uint_32 user[MCU_SECTORSIZE/4];
	void ** bios=MCU_FLASH_ADDR_START;
//（1）驱动构件函数指针初始化
      //【20191108】1/2 引脚复位相关问题解决--------------------------
      component_fun=(void **)(GEC_COMPONENT_LST_START*MCU_SECTORSIZE);    //获取BIOS函数表首地址
      //【20191108】1/2----------------------------------------------
      //读取USER中断向量表各中断处理程序地址
	  flash_read_physical((uint_8 *)user,GEC_USER_SECTOR_START*MCU_SECTORSIZE+MCU_FLASH_ADDR_START,MCU_SECTORSIZE);
	  //【20191108】2/2 引脚复位相关问题解决--------------------------
	  if((user[BIOS_UART_UPDATE_IRQn] != (uint_32)bios[BIOS_UART_UPDATE_IRQn]) //判断USER中串口更新中断和定时器中断是否为BIOS对应中断地址
	  || (user[BIOS_TIMER_IRQn] != (uint_32)bios[BIOS_TIMER_IRQn]))    //若都是，则不作操作；否则修改为BIOS对应中断地址
	  //注：此种判断方法无需将原中断向量表对应位置修改为0xffff。若已修改为0xffff，也可根据是否为0xffff进行判断
	  {
//（2）改变User中断向量表中BIOS_UART中断、BIOS_TIMER中断向量
		  flash_erase(GEC_USER_SECTOR_START);
		  //改USER中断向量表的BIOS程序写入串口的中断处理程序地址
		  user[BIOS_UART_UPDATE_IRQn]=(uint_32)bios[BIOS_UART_UPDATE_IRQn];
		  //改USER中断向量表的BIOS程序定时器的中断处理程序地址
		  user[BIOS_TIMER_IRQn]=(uint_32)bios[BIOS_TIMER_IRQn];
		  flash_write_physical(GEC_USER_SECTOR_START*MCU_SECTORSIZE+MCU_FLASH_ADDR_START,MCU_SECTORSIZE,(uint_8 *)user);
	  }
	  //【20191108】2/2----------------------------------------------
//（3）中断向量表指针重定向
	  SCB->VTOR = (uint_32)(GEC_USER_SECTOR_START*MCU_SECTORSIZE+MCU_FLASH_ADDR_START);  //指向USER程序FLASH中的中断向量表
#endif  
}
