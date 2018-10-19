#include "exti.h"
  /**************************************************************************
作者：平衡小车之家
我的淘宝小店：http://shop114407458.taobao.com/
**************************************************************************/
/**************************************************************************
函数功能：外部中断初始化
入口参数：无
返回  值：无 
**************************************************************************/
void EXTI_Init(void)
{
	RCC->APB2ENR|=1<<3;    //使能PORTB时钟	   	 
	GPIOB->CRH&=0X0FFFFFFF; 
	GPIOB->CRH|=0X80000000;//PB5上拉输入
  GPIOB->ODR|=1<<15;      //PB5上拉	
	Ex_NVIC_Config(GPIO_B,15,FTIR);		//下降沿触发
	MY_NVIC_Init(1,1,EXTI15_10_IRQn,2);  	//抢占2，子优先级1，组2
}










