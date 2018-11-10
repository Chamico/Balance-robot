#include "oled.h"
#include "stdlib.h"
#include "oledfont.h"  	 
#include "delay.h"
		   
u8 OLED_GRAM[128][8];	 

u16 refresh_count = 0;
u8 flag = 0, flag_count = 0;

const unsigned char  Hzk[][32]={
	
{0x00,0x20,0x20,0x20,0xFF,0x2A,0x2A,0x2A,0x2A,0x2A,0xFF,0x20,0x20,0x20,0x00,0x00},
{0x88,0x88,0x91,0xA1,0xC9,0x89,0x89,0xBF,0x89,0x89,0xC9,0xA1,0x91,0x88,0x88,0x00},/*"��",0*/
{0x02,0x02,0x42,0x42,0x42,0x42,0x42,0x7F,0x42,0x42,0x42,0x42,0x42,0x02,0x02,0x00},
{0x00,0x00,0x00,0x00,0x00,0x02,0x01,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"��",1*/
{0x00,0x1F,0x30,0xD0,0x10,0x10,0x1F,0x02,0x0C,0xF1,0x10,0x10,0x10,0x1F,0x00,0x00},
{0x00,0xFE,0x84,0x84,0x84,0x84,0xFE,0x00,0x00,0x00,0xC2,0x01,0x02,0xFC,0x00,0x00},/*"��",2*/
{0x20,0x21,0x21,0x3F,0x21,0x21,0x08,0x0A,0x09,0x08,0xFF,0x09,0x88,0x68,0x09,0x00},
{0x04,0x06,0x04,0xF8,0x08,0x08,0x08,0x10,0xA2,0x41,0xFE,0x80,0x60,0x90,0x08,0x00},/*"��",3*/
{0x02,0x22,0x23,0x22,0x22,0x22,0x02,0x08,0x08,0xFF,0x08,0x08,0x08,0x0F,0x00,0x00},
{0x08,0x3C,0xC8,0x08,0x28,0x1D,0x02,0x0C,0x70,0x80,0x02,0x01,0x02,0xFC,0x00,0x00},/*"��",4*/
{0x08,0x08,0x09,0x09,0x09,0x09,0x09,0x08,0x08,0xFF,0x08,0x08,0x88,0x68,0x08,0x00},
{0x00,0x04,0x06,0x04,0xFC,0x08,0x08,0x08,0x00,0xC0,0x30,0x08,0x04,0x02,0x1F,0x00},/*"ʽ",5*/
{0x00,0x40,0x40,0x48,0x46,0x40,0x40,0x7F,0x40,0x40,0x42,0x4C,0x40,0x40,0x00,0x00},
{0x80,0x80,0x80,0x80,0x80,0x80,0x80,0xFF,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x00},/*"ƽ",6*/
{0x08,0x11,0x23,0xC4,0x10,0x2F,0xC9,0x4F,0x59,0x6F,0x00,0x02,0x22,0x23,0x22,0x00},
{0x80,0x00,0xFF,0x00,0x08,0xE9,0x2A,0xFC,0x2A,0xE9,0x08,0x02,0x01,0xFE,0x00,0x00},/*"��",7*/
{0x08,0x08,0x0B,0xFF,0x09,0x08,0x00,0x7F,0x40,0x40,0x40,0x7F,0x00,0x00,0x00,0x00},
{0x20,0xC0,0x00,0xFF,0x00,0xC1,0x06,0xF8,0x00,0x00,0x00,0xFC,0x02,0x02,0x1E,0x00},/*"��",8*/
{0x01,0x01,0x79,0x49,0x49,0x49,0x79,0x07,0x01,0x79,0x4D,0x4B,0x49,0x79,0x01,0x00},
{0x10,0x10,0x2F,0x29,0x49,0x49,0x8F,0x00,0x80,0x4F,0x49,0x29,0x29,0x1F,0x10,0x00},/*"��",9*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xFC,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
{0x01,0x02,0x04,0x08,0x30,0xC0,0x00,0x00,0x00,0xC0,0x30,0x08,0x04,0x02,0x01,0x00},/*"��",10*/

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
				OLED_WR_Byte (0xb0+i,OLED_CMD);    //����ҳ��ַ��0~7��
				OLED_WR_Byte (0x00,OLED_CMD);      //������ʾλ�á��е͵�ַ
				OLED_WR_Byte (0x10,OLED_CMD);      //������ʾλ�á��иߵ�ַ   
				for(n=0;n<128;n++)OLED_WR_Byte(OLED_GRAM[n][i],OLED_DATA); 
			}  

			for(i=0;i<8;i++)  
			{  
				OLED_WR_Byte (0xb0+i,OLED_CMD);    //����ҳ��ַ��0~7��
				OLED_WR_Byte (0x00,OLED_CMD);      //������ʾλ�á��е͵�ַ
				OLED_WR_Byte (0x10,OLED_CMD);      //������ʾλ�á��иߵ�ַ   
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

//��OLEDд��һ���ֽڡ�
//dat:Ҫд�������/����
//cmd:����/�����־ 0,��ʾ����;1,��ʾ����;
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

	  	  
//����OLED��ʾ    
void OLED_Display_On(void)
{
	OLED_WR_Byte(0X8D,OLED_CMD);  //SET DCDC����
	OLED_WR_Byte(0X14,OLED_CMD);  //DCDC ON
	OLED_WR_Byte(0XAF,OLED_CMD);  //DISPLAY ON
}
//�ر�OLED��ʾ     
void OLED_Display_Off(void)
{
	OLED_WR_Byte(0X8D,OLED_CMD);  //SET DCDC����
	OLED_WR_Byte(0X10,OLED_CMD);  //DCDC OFF
	OLED_WR_Byte(0XAE,OLED_CMD);  //DISPLAY OFF
}		   			 
//��������,������,������Ļ�Ǻ�ɫ��!��û����һ��!!!	  
void OLED_Clear(void)  
{  
	u8 i,n;  
	for(i=0;i<8;i++)for(n=0;n<128;n++)OLED_GRAM[n][i]=0X00;  
	OLED_Refresh_Gram();//������ʾ
}
//���� 
//x:0~127
//y:0~63
//t:1 ��� 0,���				   
void OLED_DrawPoint(u8 x,u8 y,u8 t)
{
	u8 pos,bx,temp=0;
	if(x>127||y>63)return;//������Χ��.
	pos=7-y/8;
	bx=y%8;
	temp=1<<(7-bx);
	if(t)OLED_GRAM[x][pos]|=temp;
	else OLED_GRAM[x][pos]&=~temp;	    
}

//��ָ��λ����ʾһ���ַ�,���������ַ�
//x:0~127
//y:0~63
//mode:0,������ʾ;1,������ʾ				 
//size:ѡ������ 16/12 
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 size,u8 mode)
{      			    
	u8 temp,t,t1;
	u8 y0=y;
	chr=chr-' ';//�õ�ƫ�ƺ��ֵ				   
    for(t=0;t<size;t++)
    {   
		if(size==12)temp=oled_asc2_1206[chr][t];  //����1206����
		else temp=oled_asc2_1608[chr][t];		 //����1608���� 	                          
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
//m^n����
u32 oled_pow(u8 m,u8 n)
{
	u32 result=1;	 
	while(n--)result*=m;    
	return result;
}				  
//��ʾ2������
//x,y :�������	 
//len :���ֵ�λ��
//size:�����С
//mode:ģʽ	0,���ģʽ;1,����ģʽ
//num:��ֵ(0~4294967295);	 		  
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
//��ʾ�ַ���
//x,y:�������  
//*p:�ַ�����ʼ��ַ
//��16����
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
//��ʼ��OLED					    
void OLED_Init(void)
{ 	
  RCC->APB2ENR|=1<<4;     	//ʹ��PORTCʱ��  
	RCC->APB2ENR|=1<<0;     	//ʹ��AFIOʱ��	
	GPIOC->CRH&=0X000FFFFF;	//PC13,14,15���ó���� 2MHz �������   
	GPIOC->CRH|=0X22200000; 
	GPIOC->CRL&=0XFFFFFFF0; 
	GPIOC->CRL|=0X00000002;//PC0 �������   
	PWR->CR|=1<<8;	//ȡ��������д���� 
	RCC->BDCR&=0xFFFFFFFE;	//�ⲿ���������ر� PC14��PC15��Ϊ��ͨIO	 	
	BKP->CR&=0xFFFFFFFE; 	//������TAMPER������Ϊͨ��IO��ʹ�� 
	PWR->CR&=0xFFFFFEFF;	//������д����

	OLED_RST_Clr();
	delay_ms(100);
	OLED_RST_Set(); 
					  
	OLED_WR_Byte(0xAE,OLED_CMD); //�ر���ʾ
	OLED_WR_Byte(0xD5,OLED_CMD); //����ʱ�ӷ�Ƶ����,��Ƶ��
	OLED_WR_Byte(80,OLED_CMD);   //[3:0],��Ƶ����;[7:4],��Ƶ��
	OLED_WR_Byte(0xA8,OLED_CMD); //��������·��
	OLED_WR_Byte(0X3F,OLED_CMD); //Ĭ��0X3F(1/64) 
	OLED_WR_Byte(0xD3,OLED_CMD); //������ʾƫ��
	OLED_WR_Byte(0X00,OLED_CMD); //Ĭ��Ϊ0

	OLED_WR_Byte(0x40,OLED_CMD); //������ʾ��ʼ�� [5:0],����.
													    
	OLED_WR_Byte(0x8D,OLED_CMD); //��ɱ�����
	OLED_WR_Byte(0x14,OLED_CMD); //bit2������/�ر�
	OLED_WR_Byte(0x20,OLED_CMD); //�����ڴ��ַģʽ
	OLED_WR_Byte(0x02,OLED_CMD); //[1:0],00���е�ַģʽ;01���е�ַģʽ;10,ҳ��ַģʽ;Ĭ��10;
	OLED_WR_Byte(0xA1,OLED_CMD); //���ض�������,bit0:0,0->0;1,0->127;
	OLED_WR_Byte(0xC0,OLED_CMD); //����COMɨ�跽��;bit3:0,��ͨģʽ;1,�ض���ģʽ COM[N-1]->COM0;N:����·��
	OLED_WR_Byte(0xDA,OLED_CMD); //����COMӲ����������
	OLED_WR_Byte(0x12,OLED_CMD); //[5:4]����
		 
	OLED_WR_Byte(0x81,OLED_CMD); //�Աȶ�����
	OLED_WR_Byte(0xEF,OLED_CMD); //1~255;Ĭ��0X7F (��������,Խ��Խ��)
	OLED_WR_Byte(0xD9,OLED_CMD); //����Ԥ�������
	OLED_WR_Byte(0xf1,OLED_CMD); //[3:0],PHASE 1;[7:4],PHASE 2;
	OLED_WR_Byte(0xDB,OLED_CMD); //����VCOMH ��ѹ����
	OLED_WR_Byte(0x30,OLED_CMD); //[6:4] 000,0.65*vcc;001,0.77*vcc;011,0.83*vcc;

	OLED_WR_Byte(0xA4,OLED_CMD); //ȫ����ʾ����;bit0:1,����;0,�ر�;(����/����)
	OLED_WR_Byte(0xA6,OLED_CMD); //������ʾ��ʽ;bit0:1,������ʾ;0,������ʾ	    						   
	OLED_WR_Byte(0xAF,OLED_CMD); //������ʾ	 
	OLED_Clear();
} 

void OLED_Set_Pos(unsigned char x, unsigned char y) 
{ 
	OLED_WR_Byte(0xb0+y,OLED_CMD);//д��ҳ��ַ
	OLED_WR_Byte((x&0x0f),OLED_CMD);  //д���еĵ�ַ  �Ͱ��ֽ�
	OLED_WR_Byte(((x&0xf0)>>4)|0x10,OLED_CMD);//д���еĵ�ַ �߰��ֽ�
}   





