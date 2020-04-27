
//===========================================================================
//文件名称：common.h
//功能概要：公共要素源文件
//版权所有：苏州大学飞思卡尔嵌入式中心(sumcu.suda.edu.cn)
//更新记录：2012-10-12 V1.0
//         2013-02-02 V2.0(WYH)
//===========================================================================

#include "common.h"    //包含公共要素头文件
#include "string.h"
#include "includes.h"
#include "user.h"
void transformToDateString(uint_64 timeStamp ,char *dateString);
void transformToDate(uint_64 timeStamp ,uint_64 **dateArry);
void intToString(uint_64 num,uint_8* str,uint_8 len);


//============================================================================
//函数名称：enable_irq
//函数返回：无
//参数说明：irq：irq号, 各个模块的中断号定义在MKL25Z.h中
//功能概要：使能irq中断
//============================================================================
void enable_irq (IRQn_Type irq)
{
	//确定irq号为有效的irq号
	if (irq > MCU_IRQ_MAX)
		return;
	EnableIRQ(irq);
}

//============================================================================
//函数名称：disable_irq
//函数返回：无
//参数说明：irq：irq号, 各个模块的中断号定义在MKL25Z.h中
//功能概要：禁止irq中断
//============================================================================
void disable_irq (IRQn_Type irq)
{
	//确定irq号为有效的irq号
	if (irq > MCU_IRQ_MAX)
		return;
	DisableIRQ(irq);
}

//============================================================================
//函数名称：set_irq_priority
//函数返回：无
//参数说明：irq：irq号,各个模块的中断号定义在MKL25Z.h中
//         prio：优先级
//功能概要：设置irq中断和优先级
//============================================================================
void set_irq_priority (IRQn_Type irq, uint_16 prio)
{   
	uint_8 err = 0;

	if (irq > MCU_IRQ_MAX)
	{
		err = 1;
	}
	if (prio > MCU_IRQ_PRIOR_MAX)
	{
		err = 1;
	}
	if (err != 1)
	{
		SetPriority(irq, prio);
	}
}

//======================================================================
//函数名称：Delay_us
//函数返回：无
//参数说明：无
//功能概要：延时 - 微秒级
//======================================================================
void Delay_us(uint16_t u16us)
{
	vuint_32 u32ctr;
	for(u32ctr = 0; u32ctr < (MCU_SYSTEM_CLK_US * u16us); u32ctr++)
	{
		NOP;
	}
}

//======================================================================
//函数名称：Delay_us
//函数返回：无
//参数说明：无
//功能概要：延时 - 毫秒级
//======================================================================
void Delay_ms(uint16_t u16ms)
{
	uint_32 u32ctr;
	for(u32ctr = 0; u32ctr < (MCU_SYSTEM_CLK_MS*u16ms); u32ctr++)
	{
		NOP;
	}
}


//===========================================================================
//函数名称：SecAdd1
//函数返回：无
//参数说明：*p:为指向一个时分秒数组p[3]
//功能概要：秒单元+1，并处理时分单元（00:00:00-23:59:59)
//===========================================================================
void SecAdd1(uint_8 *p)
{
	*(p+2)+=1;         //秒+1
	if(*(p+2)>=60)     //秒溢出
	{
		*(p+2)=0;       //清秒
		*(p+1)+=1;      //分+1
		if(*(p+1)>=60)  //分溢出
		{
			*(p+1)=0;    //清分
			*p+=1;       //时+1
			if(*p>=24)   //时溢出
			{
				*p=0;      //清时
			}
		}
	}
}

//=====================================================================
//函数名称：timeChange
//函数返回：无
//参数说明：ticks：时间戳
//       time：解析后的日期，例:19700101000000(1970-01-01 00:00:00)
//功能概要：时间戳转成字符表示日期
//=====================================================================
void timeChange(uint_64 ticks,uint_8 *curtime)
{
	//62135625600000                 1970年之前的毫秒数      东八区，减8小时
	transformToDateString(ticks*1000+62135625600000-28800*1000,(char *)curtime);
}

//将64位时间戳转化为时间字符串
void transformToDateString(uint_64 timeStamp ,char *dateString)
{
    uint_64 year ,month ,day ,hour ,minute ,second ,milliSecond;
    uint_64 *intp[] = {&year ,&month ,&day ,&hour ,&minute ,&second ,&milliSecond };

    transformToDate(timeStamp ,intp);

	intToString(year,(uint_8 *)dateString,4);
	dateString[4] = '-';
	intToString(month,(uint_8 *)(dateString+5),2);
	dateString[7] = '-';
	intToString(day+1,(uint_8 *)(dateString+8),2);
	dateString[10] = ' ';
	intToString(hour,(uint_8 *)(dateString+11),2);
	dateString[13] = ':';
	intToString(minute,(uint_8 *)(dateString+14),2);
	dateString[16] = ':';
	intToString(second,(uint_8 *)(dateString+17),2);
	dateString[19] = 0;
}

//将64位时间戳转化为时间数组
void transformToDate(uint_64 timeStamp ,uint_64 **dateArry)
{
    uint_64 low ,high ,mid ,t;
    uint_64 year ,month ,day ,hour ,minute ,second ,milliSecond;
    uint_64 daySum[] = {0 ,31 ,59 ,90 ,120 ,151 ,181 ,212 ,243 ,273 ,304 ,334 ,365};
    uint_64 milOfDay = 24 * 3600 * 1000;
    uint_64 milOfHour = 3600 * 1000;

    /*防止超过9999-12-31 23:59:59:999*/
    if(timeStamp > 315537897599999) {
        timeStamp = 315537897599999;
    }

    low = 1;
    high = 9999;

    while(low <= high)
    {
        mid = (low+high)>>1;
        t = ((mid-1) * 365 + (mid-1)/4 - (mid-1)/100 + (mid-1)/400) * milOfDay;

        if(t == timeStamp)
        {
            low = mid + 1;
            break;
        }
        else if(t < timeStamp)
            low = mid + 1;
        else
            high = mid - 1;
    }
    year = low-1;
    uint_64 cc;
    uint_64 aa,bb;
    cc = (year-1) * 365;
    cc += (year-1)/4;
    aa = (year-1)/100;
    bb = (year-1)/400 ;

    cc -= aa;
    cc += bb;

    timeStamp -= cc* milOfDay;

    int isLeapYear = ((year&3) == 0 && year%100!=0) || year%400 == 0;

    for(month = 1 ;(daySum[month] + ((isLeapYear && month > 1) ? 1 : 0)) * milOfDay <= timeStamp && month < 13 ;month ++) {
        if(isLeapYear && month > 1)
            ++daySum[month];
    }
    timeStamp -= daySum[month-1] * milOfDay;

    day = timeStamp / milOfDay;
    timeStamp -= day * milOfDay;

    hour = timeStamp / milOfHour;
    timeStamp -= hour * milOfHour;

    minute = timeStamp / 60000;
    timeStamp -= minute * 60000;

    second = timeStamp / 1000;
    milliSecond = timeStamp % 1000;

    *dateArry[0] = year;
    *dateArry[1] = month;
    *dateArry[2] = day;
    *dateArry[3] = hour;
    *dateArry[4] = minute;
    *dateArry[5] = second;
    *dateArry[6] = milliSecond;
}


void intToString(uint_64 num,uint_8* str,uint_8 len)
{
	uint_8 i;
	uint_8 remainder; //余数
	uint_64 divisor;  //除数

	divisor = num;
	for(i = 0;i < len;i++)
	{
		remainder = divisor % 10;
		divisor = divisor / 10;
		str[len-i-1] = remainder + '0';
	}
}






