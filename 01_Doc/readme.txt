更新记录：
【20200412】胡展鹏
增加了看门狗机制，设置喂狗间隔为7秒。
(1)在05_userBoard中添加了iwdg.c与iwdg.h看门狗构件，以及完善user.h中的包含头文件
(2)在main.c中的1.5步骤下添加了看门狗初始化函数，以及在主循环开头添加了喂狗函数
(3)在isr.c文件中添加了看门狗中断处理函数

【20200410】胡展鹏
(1)修改显示界面
(2)增加了设备运行状态显示
(3)修改了预测机制，输出所有类别的预测概率

【20200406】胡展鹏
(1)增加了初始化摄像头模块的返回值判断机制
(2)将原有的main.c中的多余参数删除

【20200326】胡展鹏
(1)将原有的model.h与model.c合进lenet_1.h与lenet_1.c，加入了model_int.c与model_int.h用来进行模型参数的初始化与更新
(2)将模型识别对象换为USB插头、排针以及芯片的PCB板
(3)完善了相关注释

【20191219】胡展鹏
去除了之前的EORS架构，只保留了推理，把标记与训练放在PC端。
加入了lenet_1.c以及lenet_1.h模块，并且更新了camera.c与camera.h模块构件
在main.c中对4层模型参数数组的初始化














【20191108】——葛新越
			解决“有时下拉一次复位引脚后，直接回到BIOS程序运行”和“有时回到BIOS程序运行后，重新上电无法再回到USER程序运行”的问题。
			需要对应修改BIOS程序，详见BIOS程序readme.txt。
			【20191108】1/2 引脚复位相关问题解决
			在bios_api.c中，添加“component_fun=(void **)(GEC_COMPONENT_LST_START*MCU_SECTORSIZE); ”，获取BIOS函数表首地址。
			【20191108】2/2 引脚复位相关问题解决
			在BIOS_API_Init中，判断USER中串口更新中断和定时器中断是否为BIOS对应中断地址。若都是，则不作操作；否则修改为BIOS对应中断地址。
			
【20191109-1】——葛新越
            测试在USER程序中继承BIOS底层驱动，包括GPIO，FLASH和UART。
            将各自.h文件中USE_BIOS_GPIO，USE_BIOS_FLASH，USE_BIOS_UART设置为1，编译后机器码减少，且各功能正常。
            
【20191109-2】——葛新越
            优化Flash构件，目前可以在任意有效地址（0x08000000-0x20000000）实现flash写入读取任意长度数据数组（数据类型为uint_8）。
            
【20191109-3】——葛新越
            优化警告问题，主要是函数调用或变量赋值时类型不一致（系统强制类型转换时会警告）。
            
==================================================================================
工程名称：GPIO_Output_C_STM32-191109
版权所有：SUDA-ARM(sumcu.suda.edu.cn)
版本更新：2019-11-09
程序介绍：本程序为STM32的C语言模板工程。
本程序实现了：(1)每1S红灯闪烁一次，并通过串口UARTC（板上标识为uart2）输出红灯亮暗状态;
	          (2)若串口UART_USER（板上标识为uart0）接收到数据，则会将会回发收 到的数据(波特率115200)。
==================================================================================
1. 工程概述
(1)本工程为STM32L431RC微控制器无操作系统C语言模板工程
(2)使用串口UARTC（板上标识为uart2）与外界通信，波特率为115200，1位停止位，无校验
(3)启动串口UART_USER（板上标识为uart0）接收中断，回发接收数据
(4)在60秒内连续拉低ReSet脚6次以上（包括6次）程序回到BIOS运行，绿灯闪烁

2. 软件环境
(1)AHL-GEC-IDE V3.57

3. 硬件环境
核心板：金葫芦系列STM32L432RC核心板  
UART2接线： microUSB串口线
UART0接线： USB转TTL串口线（如：PL2303HX）

4. 串口更新程序流程
    将烧录了BIOS程序的MCU上，用于串口更新的串口（本工程中为UART2）与PC机连接；给MCU上电，并打开上位机程序，便可以开
始串口更新。串口更新的程序步骤如下：
（1）握手并获取MCU芯片信息：上位机程序点击“软件更新”->“串口更新”，进入串口更新界面。选择“重新连接”时，上位机会遍历连
接在PC机上的设备，逐个发送握手帧，握手帧得到MCU的正确回应时表示握手成功；此后，上位机会再发送一个命令帧获取芯片信息。

5.NMI中断（STM32L432RC没有NMI，以ReSet脚模拟）
使用场景：烧入User程序后出现错误，可将复位脚在一分钟内拉低6次以上（包括6次）使程序回到BIOS运行
实现的功能（04_GEC/gec.c中的pin_reset_judge();函数)：
（1）在60s内连续拉低NMI引脚6次以内（不含6次），实现拉低一次NMI引脚绿灯闪烁一次，而后红灯闪烁USER程序正常运行；
（2）在60s内连续拉低NMI引脚6次，实现绿灯闪烁，一直停留在BIOS程序运行,此后（指无时长限制）再点NMI引脚还是停留在BIOS运行；

6.MCU扇区分配
（1）Flash分配
		BIOS的FLASH： 0~16扇区， 0x08000000~0x08008800, 34KB
			DY_CMD:  17~18扇区， 0x08008800~0x08009800,  4KB
			CPT_LST: 19~20扇区， 0x08009800~0x0800a800,  4KB
			CPT_FUN: 21~25扇区， 0x0800a800~0x0800d000, 10KB
		USER的USER_INTVEC:26扇区，0x0800d000~0x0800d800, 2KB
			FLASH:27~127扇区，   0x0800d800~0x08040000,202KB
（2）RAM分配
		BIOS的RAM：64KB
 			GEC_BIOS_RAM_START = 0x20000000;      /*BIOS RAM区域起始地址  */
 			GEC_BIOS_RAM_END   = 0x20010000;      /*BIOS RAM区域结束地址*/
 		User的RAM：56KB
 			GEC_USER_RAM_START = 0x20002000;      /*USER RAM区域起始地址  */
 			GEC_USER_RAM_END   = 0x20010000;      /*USER RAM区域结束地址*/

7.BIOS和USER程序的衔接
（1）BIOS和USER程序的相互跳转
BIOS跳转到USER实现:将USER程序Flash的前两个字（即SP的初始值和复位向量）赋值给SP和PC指针；
USER跳转到BIOS实现：调用系统复位函数NVIC_SystemReset函数。
（2）共享中断服务例程
将中断向量表从BIOS的Flash拷贝到User的FLASH起始扇区，并将中断向量表的起始地址寄存武器SCB->VTOR修改为User的FLASH的中断向量表起始地址；
BIOS若使用某个中断服务例程不需要修改RAM的中断向量表的表项，而USER若使用某个中断服务例程需要对应的修改User的FLASH中断向量表的表项。

=============================================================================
声明：
（1）本源代码，在所提供的硬件系统测试通过，真诚奉献给社会，不足之处，欢迎指正。
（2）若使用其他硬件系统，移植代码时，请仔细根据自己的硬件匹配。
----------------------------------------------------------------------------
SD-ARM   技术服务：http://sumcu.suda.edu.cn;	0512-65214835
=============================================================================



C语言中的唯一的一个三目运算符
       mFlag=(mFlag=='A'?'L':'A');
        printf((mFlag=='A')?" LIGHT_RED:OFF--\n":" LIGHT_RED:ON==\n");