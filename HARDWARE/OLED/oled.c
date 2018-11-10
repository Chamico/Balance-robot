#include "oled.h"
#include "stdlib.h"
#include "oledfont.h"  	 
#include "delay.h"
		   
u8 OLED_GRAM[128][8];	 

u16 refresh_count = 0;
u8 flag = 0, flag_count = 0;

const unsigned char  Hzk[][32]={
	
{0x00,0x20,0x20,0x20,0xFF,0x2A,0x2A,0x2A,0x2A,0x2A,0xFF,0x20,0x20,0x20,0x00,0x00},
{0x88,0x88,0x91,0xA1,0xC9,0x89,0x89,0xBF,0x89,0x89,0xC9,0xA1,0x91,0x88,0x88,0x00},/*"基",0*/
{0x02,0x02,0x42,0x42,0x42,0x42,0x42,0x7F,0x42,0x42,0x42,0x42,0x42,0x02,0x02,0x00},
{0x00,0x00,0x00,0x00,0x00,0x02,0x01,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"于",1*/
{0x00,0x1F,0x30,0xD0,0x10,0x10,0x1F,0x02,0x0C,0xF1,0x10,0x10,0x10,0x1F,0x00,0x00},
{0x00,0xFE,0x84,0x84,0x84,0x84,0xFE,0x00,0x00,0x00,0xC2,0x01,0x02,0xFC,0x00,0x00},/*"的",2*/
{0x20,0x21,0x21,0x3F,0x21,0x21,0x08,0x0A,0x09,0x08,0xFF,0x09,0x88,0x68,0x09,0x00},
{0x04,0x06,0x04,0xF8,0x08,0x08,0x08,0x10,0xA2,0x41,0xFE,0x80,0x60,0x90,0x08,0x00},/*"球",3*/
{0x02,0x22,0x23,0x22,0x22,0x22,0x02,0x08,0x08,0xFF,0x08,0x08,0x08,0x0F,0x00,0x00},
{0x08,0x3C,0xC8,0x08,0x28,0x1D,0x02,0x0C,0x70,0x80,0x02,0x01,0x02,0xFC,0x00,0x00},/*"动",4*/
{0x08,0x08,0x09,0x09,0x09,0x09,0x09,0x08,0x08,0xFF,0x08,0x08,0x88,0x68,0x08,0x00},
{0x00,0x04,0x06,0x04,0xFC,0x08,0x08,0x08,0x00,0xC0,0x30,0x08,0x04,0x02,0x1F,0x00},/*"式",5*/
{0x00,0x40,0x40,0x48,0x46,0x40,0x40,0x7F,0x40,0x40,0x42,0x4C,0x40,0x40,0x00,0x00},
{0x80,0x80,0x80,0x80,0x80,0x80,0x80,0xFF,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x00},/*"平",6*/
{0x08,0x11,0x23,0xC4,0x10,0x2F,0xC9,0x4F,0x59,0x6F,0x00,0x02,0x22,0x23,0x22,0x00},
{0x80,0x00,0xFF,0x00,0x08,0xE9,0x2A,0xFC,0x2A,0xE9,0x08,0x02,0x01,0xFE,0x00,0x00},/*"衡",7*/
{0x08,0x08,0x0B,0xFF,0x09,0x08,0x00,0x7F,0x40,0x40,0x40,0x7F,0x00,0x00,0x00,0x00},
{0x20,0xC0,0x00,0xFF,0x00,0xC1,0x06,0xF8,0x00,0x00,0x00,0xFC,0x02,0x02,0x1E,0x00},/*"机",8*/
{0x01,0x01,0x79,0x49,0x49,0x49,0x79,0x07,0x01,0x79,0x4D,0x4B,0x49,0x79,0x01,0x00},
{0x10,0x10,0x2F,0x29,0x49,0x49,0x8F,0x00,0x80,0x4F,0x49,0x29,0x29,0x1F,0x10,0x00},/*"器",9*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xFC,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
{0x01,0x02,0x04,0x08,0x30,0xC0,0x00,0x00,0x00,0xC0,0x30,0x08,0x04,0x02,0x01,0x00},/*"人",10*/

};

void OLED_ShowChinese_one(unsigned char x,unsigned char y,unsigned char address)
{
	unsigned char i = 0;
	OLED_Set_Pos(x,y+7);
	for(i = 0;i < 16; i++)
	{
		OLED_WR_Byte(Hzk[2 * address ][i],OLED_DATA);

	}
	OLED_Set_Pos(x,y+6);
	for(i = 0; i < 16; i++)
	{
		OLED_WR_Byte(Hzk[2 * address + 1][i],OLED_DATA);
	}
}

void OLED_ShowChinese_two(unsigned char x,unsigned char y,unsigned char address)
{
	unsigned char i = 0;
	OLED_Set_Pos(x,y+5);
	for(i = 0;i < 16; i++)
	{
		OLED_WR_Byte(Hzk[2 * address ][i],OLED_DATA);

	}
	OLED_Set_Pos(x,y+4);
	for(i = 0; i < 16; i++)
	{
		OLED_WR_Byte(Hzk[2 * address + 1][i],OLED_DATA);
	}
}


void OLED_Refresh_Gram(void)
{
	u8 i,n;	
	if(flag == 0){
	
			for(i=0;i<8;i++)  
			{  
				OLED_WR_Byte (0xb0+i,OLED_CMD);    //设置页地址（0~7）
				OLED_WR_Byte (0x00,OLED_CMD);      //设置显示位置—列低地址
				OLED_WR_Byte (0x10,OLED_CMD);      //设置显示位置—列高地址   
				for(n=0;n<128;n++)OLED_WR_Byte(OLED_GRAM[n][i],OLED_DATA); 
			}  

			for(i=0;i<8;i++)  
			{  
				OLED_WR_Byte (0xb0+i,OLED_CMD);    //设置页地址（0~7）
				OLED_WR_Byte (0x00,OLED_CMD);      //设置显示位置—列低地址
				OLED_WR_Byte (0x10,OLED_CMD);      //设置显示位置—列高地址   
				for(n=0;n<128;n++)OLED_WR_Byte(OLED_GRAM[n][i],OLED_DATA); 
			}  			
	
		
		flag_count++;
		
		if(flag_count > 1)
		{
			
			flag_count = 22;
			flag = 1;
		}
		
	} 
	else

	{}
	
}

//向OLED写入一个字节。
//dat:要写入的数据/命令
//cmd:数据/命令标志 0,表示命令;1,表示数据;
void OLED_WR_Byte(u8 dat,u8 cmd)
{	
	u8 i;			  
	if(cmd)
	  OLED_RS_Set();
	else 
	  OLED_RS_Clr();		  
	for(i=0;i<8;i++)
	{			  
		OLED_SCLK_Clr();
		if(dat&0x80)
		   OLED_SDIN_Set();
		else 
		   OLED_SDIN_Clr();
		OLED_SCLK_Set();
		dat<<=1;   
	}				 		  
	OLED_RS_Set();   	  
} 

	  	  
//开启OLED显示    
void OLED_Display_On(void)
{
	OLED_WR_Byte(0X8D,OLED_CMD);  //SET DCDC命令
	OLED_WR_Byte(0X14,OLED_CMD);  //DCDC ON
	OLED_WR_Byte(0XAF,OLED_CMD);  //DISPLAY ON
}
//关闭OLED显示     
void OLED_Display_Off(void)
{
	OLED_WR_Byte(0X8D,OLED_CMD);  //SET DCDC命令
	OLED_WR_Byte(0X10,OLED_CMD);  //DCDC OFF
	OLED_WR_Byte(0XAE,OLED_CMD);  //DISPLAY OFF
}		   			 
//清屏函数,清完屏,整个屏幕是黑色的!和没点亮一样!!!	  
void OLED_Clear(void)  
{  
	u8 i,n;  
	for(i=0;i<8;i++)for(n=0;n<128;n++)OLED_GRAM[n][i]=0X00;  
	OLED_Refresh_Gram();//更新显示
}
//画点 
//x:0~127
//y:0~63
//t:1 填充 0,清空				   
void OLED_DrawPoint(u8 x,u8 y,u8 t)
{
	u8 pos,bx,temp=0;
	if(x>127||y>63)return;//超出范围了.
	pos=7-y/8;
	bx=y%8;
	temp=1<<(7-bx);
	if(t)OLED_GRAM[x][pos]|=temp;
	else OLED_GRAM[x][pos]&=~temp;	    
}

//在指定位置显示一个字符,包括部分字符
//x:0~127
//y:0~63
//mode:0,反白显示;1,正常显示				 
//size:选择字体 16/12 
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 size,u8 mode)
{      			    
	u8 temp,t,t1;
	u8 y0=y;
	chr=chr-' ';//得到偏移后的值				   
    for(t=0;t<size;t++)
    {   
		if(size==12)temp=oled_asc2_1206[chr][t];  //调用1206字体
		else temp=oled_asc2_1608[chr][t];		 //调用1608字体 	                          
        for(t1=0;t1<8;t1++)
		{
			if(temp&0x80)OLED_DrawPoint(x,y,mode);
			else OLED_DrawPoint(x,y,!mode);
			temp<<=1;
			y++;
			if((y-y0)==size)
			{
				y=y0;
				x++;
				break;
			}
		}  	 
    }          
}
//m^n函数
u32 oled_pow(u8 m,u8 n)
{
	u32 result=1;	 
	while(n--)result*=m;    
	return result;
}				  
//显示2个数字
//x,y :起点坐标	 
//len :数字的位数
//size:字体大小
//mode:模式	0,填充模式;1,叠加模式
//num:数值(0~4294967295);	 		  
void OLED_ShowNumber(u8 x,u8 y,u32 num,u8 len,u8 size)
{         	
	u8 t,temp;
	u8 enshow=0;						   
	for(t=0;t<len;t++)
	{
		temp=(num/oled_pow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				OLED_ShowChar(x+(size/2)*t,y,' ',size,1);
				continue;
			}else enshow=1; 
		 	 
		}
	 	OLED_ShowChar(x+(size/2)*t,y,temp+'0',size,1); 
	}
} 
//显示字符串
//x,y:起点坐标  
//*p:字符串起始地址
//用16字体
void OLED_ShowString(u8 x,u8 y,const u8 *p)
{
#define MAX_CHAR_POSX 122
#define MAX_CHAR_POSY 58          
    while(*p!='\0')
    {       
        if(x>MAX_CHAR_POSX){x=0;y+=16;}
        if(y>MAX_CHAR_POSY){y=x=0;OLED_Clear();}
        OLED_ShowChar(x,y,*p,12,1);	 
        x+=8;
        p++;
    }  
}	   
//初始化OLED					    
void OLED_Init(void)
{ 	
  RCC->APB2ENR|=1<<4;     	//使能PORTC时钟  
	RCC->APB2ENR|=1<<0;     	//使能AFIO时钟	
	GPIOC->CRH&=0X000FFFFF;	//PC13,14,15设置成输出 2MHz 推挽输出   
	GPIOC->CRH|=0X22200000; 
	GPIOC->CRL&=0XFFFFFFF0; 
	GPIOC->CRL|=0X00000002;//PC0 推挽输出   
	PWR->CR|=1<<8;	//取消备份区写保护 
	RCC->BDCR&=0xFFFFFFFE;	//外部低俗振荡器关闭 PC14，PC15成为普通IO	 	
	BKP->CR&=0xFFFFFFFE; 	//侵入检测TAMPER引脚作为通用IO口使用 
	PWR->CR&=0xFFFFFEFF;	//备份区写保护

	OLED_RST_Clr();
	delay_ms(100);
	OLED_RST_Set(); 
					  
	OLED_WR_Byte(0xAE,OLED_CMD); //关闭显示
	OLED_WR_Byte(0xD5,OLED_CMD); //设置时钟分频因子,震荡频率
	OLED_WR_Byte(80,OLED_CMD);   //[3:0],分频因子;[7:4],震荡频率
	OLED_WR_Byte(0xA8,OLED_CMD); //设置驱动路数
	OLED_WR_Byte(0X3F,OLED_CMD); //默认0X3F(1/64) 
	OLED_WR_Byte(0xD3,OLED_CMD); //设置显示偏移
	OLED_WR_Byte(0X00,OLED_CMD); //默认为0

	OLED_WR_Byte(0x40,OLED_CMD); //设置显示开始行 [5:0],行数.
													    
	OLED_WR_Byte(0x8D,OLED_CMD); //电荷泵设置
	OLED_WR_Byte(0x14,OLED_CMD); //bit2，开启/关闭
	OLED_WR_Byte(0x20,OLED_CMD); //设置内存地址模式
	OLED_WR_Byte(0x02,OLED_CMD); //[1:0],00，列地址模式;01，行地址模式;10,页地址模式;默认10;
	OLED_WR_Byte(0xA1,OLED_CMD); //段重定义设置,bit0:0,0->0;1,0->127;
	OLED_WR_Byte(0xC0,OLED_CMD); //设置COM扫描方向;bit3:0,普通模式;1,重定义模式 COM[N-1]->COM0;N:驱动路数
	OLED_WR_Byte(0xDA,OLED_CMD); //设置COM硬件引脚配置
	OLED_WR_Byte(0x12,OLED_CMD); //[5:4]配置
		 
	OLED_WR_Byte(0x81,OLED_CMD); //对比度设置
	OLED_WR_Byte(0xEF,OLED_CMD); //1~255;默认0X7F (亮度设置,越大越亮)
	OLED_WR_Byte(0xD9,OLED_CMD); //设置预充电周期
	OLED_WR_Byte(0xf1,OLED_CMD); //[3:0],PHASE 1;[7:4],PHASE 2;
	OLED_WR_Byte(0xDB,OLED_CMD); //设置VCOMH 电压倍率
	OLED_WR_Byte(0x30,OLED_CMD); //[6:4] 000,0.65*vcc;001,0.77*vcc;011,0.83*vcc;

	OLED_WR_Byte(0xA4,OLED_CMD); //全局显示开启;bit0:1,开启;0,关闭;(白屏/黑屏)
	OLED_WR_Byte(0xA6,OLED_CMD); //设置显示方式;bit0:1,反相显示;0,正常显示	    						   
	OLED_WR_Byte(0xAF,OLED_CMD); //开启显示	 
	OLED_Clear();
} 

void OLED_Set_Pos(unsigned char x, unsigned char y) 
{ 
	OLED_WR_Byte(0xb0+y,OLED_CMD);//写入页地址
	OLED_WR_Byte((x&0x0f),OLED_CMD);  //写入列的地址  低半字节
	OLED_WR_Byte(((x&0xf0)>>4)|0x10,OLED_CMD);//写入列的地址 高半字节
}   





