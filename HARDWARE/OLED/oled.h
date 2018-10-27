#ifndef __OLED_H
#define __OLED_H			  	 
#include "sys.h"

//-----------------OLED端口定义---------------- 
#define OLED_RST_Clr() PCout(15)=0   //RST
#define OLED_RST_Set() PCout(15)=1   //RST

#define OLED_RS_Clr() PCout(0)=0    //DC
#define OLED_RS_Set() PCout(0)=1    //DC

#define OLED_SCLK_Clr()  PCout(13)=0  //SCL
#define OLED_SCLK_Set()  PCout(13)=1   //SCL

#define OLED_SDIN_Clr()  PCout(14)=0   //SDA
#define OLED_SDIN_Set()  PCout(14)=1   //SDA

#define OLED_CMD  0	//写命令
#define OLED_DATA 1	//写数据

#define SIZE 		16		//显示字符的大小
#define Max_Column	128		//最大列数
#define Max_Row		64		//最大行数
#define X_WIDTH 	128		//X轴的宽度
#define Y_WIDTH 	64	    //Y轴的宽度					  				   
//OLED控制用函数
void OLED_WR_Byte(u8 dat,u8 cmd);	    
void OLED_Display_On(void);
void OLED_Display_Off(void);
void OLED_Refresh_Gram(void);		   				   		    
void OLED_Init(void);
void OLED_Clear(void);
void OLED_DrawPoint(u8 x,u8 y,u8 t);
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 size,u8 mode);
void OLED_ShowNumber(u8 x,u8 y,u32 num,u8 len,u8 size);
void OLED_ShowString(u8 x,u8 y,const u8 *p);	 
void OLED_ShowChinese_one(unsigned char x,unsigned char y,unsigned char address);
void OLED_ShowChinese_two(unsigned char x,unsigned char y,unsigned char address);
void OLED_Set_Pos(unsigned char x, unsigned char y) ;







#endif  
	 
