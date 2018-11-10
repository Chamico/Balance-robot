#include "show.h"
  /**************************************************************************
���ߣ�ƽ��С��֮��
�ҵ��Ա�С�꣺http://shop114407458.taobao.com/
**************************************************************************/
unsigned char i;          //��������
unsigned char Send_Count; //������Ҫ���͵����ݸ���
float Vol;

extern float blu_channel_1;
extern int Usart_Receive;

/**************************************************************************
�������ܣ�OLED��ʾ
��ڲ�������
����  ֵ����
**************************************************************************/
void oled_show(void)
{
	//=============��1�к͵�2����ʾ��Ŀ����===============//	
	OLED_ShowChinese_one(0,0,0); //��
	OLED_ShowChinese_one(16,0,1); //��
	OLED_ShowString(35,3,"MCU");
	OLED_ShowChinese_one(60,0,2); //��
	OLED_ShowChinese_one(78,0,3); //��
	OLED_ShowChinese_one(95,0,4); //��
	OLED_ShowChinese_one(112,0,5); //ʽ
	OLED_ShowChinese_two(20,0,6); //ƽ
	OLED_ShowChinese_two(37,0,7); //��
	OLED_ShowChinese_two(54,0,8); //��
	OLED_ShowChinese_two(71,0,9); //��
	OLED_ShowChinese_two(88,0,10); //��
	//=============��3����ʾ��Ŀ���===============//	
	OLED_ShowString(18,34,"201810742086");
		OLED_Refresh_Gram();	
	}
/**************************************************************************
�������ܣ���APP��������
��ڲ�������
����  ֵ����
��    �ߣ�ƽ��С��֮��
**************************************************************************/
void APP_Show(void)
{    
	static u8 flag;
	int app_2,app_3,app_4;
	app_4=(Voltage-1110)*2/3;	
	if(app_4>100)app_4=100;   //�Ե�ѹ���ݽ��д���
	app_2=Move_X*0.2;  if(app_2<0)app_2=-app_2;			                   //�Ա��������ݾ������ݴ������ͼ�λ�
	app_3=Move_Y*0.2;  if(app_3<0)app_3=-app_3;
	flag=!flag;
	if(PID_Send==1)//����PID����
	{
		printf("{C%d:%d:%d:%d:%d}$",(int)Balance_Kp,(int)Balance_Kd,(int)Velocity_Kp,(int)Velocity_Ki,0);//��ӡ��APP����	
		PID_Send=0;	
	}	
	 else	if(flag==0)// 
	 printf("{A%d:%d:%d:%d}$",(u8)app_2,(u8)app_3,app_4,(int)Yaw); //��ӡ��APP����
	 else
	 printf("{B%d:%d:%d:%d}$",(int)Pitch,(int)Roll,(int)Yaw,app_4);//��ӡ��APP���� ��ʾ����
}
/**************************************************************************
�������ܣ�����ʾ��������λ���������� �ر���ʾ��
��ڲ�������
����  ֵ����
��    �ߣ�ƽ��С��֮��
**************************************************************************/
void DataScope(void)
{   
		DataScope_Get_Channel_Data(Motor_A, 1 );      
		DataScope_Get_Channel_Data(Motor_B, 2 );    
		DataScope_Get_Channel_Data(Motor_C, 3 );            
  	DataScope_Get_Channel_Data(Roll_Bias, 4 );     
		DataScope_Get_Channel_Data(Pitch_Bias, 5 );
//		DataScope_Get_Channel_Data(0, 9 );  
//		DataScope_Get_Channel_Data( 0 , 10);
		Send_Count = DataScope_Data_Generate(5);
		for( i = 0 ; i < Send_Count; i++) 
		{
		while((USART1->SR&0X40)==0);  
		USART1->DR = DataScope_OutPut_Buffer[i]; 
		}
}
