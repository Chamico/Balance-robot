#include "show.h"
  /**************************************************************************
���ߣ�ƽ��С��֮��
�ҵ��Ա�С�꣺http://shop114407458.taobao.com/
**************************************************************************/
unsigned char i;          //��������
unsigned char Send_Count; //������Ҫ���͵����ݸ���
float Vol;
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
	//=============��4����ʾ���PWM��ֵ===============//	
	OLED_ShowString(0,44,"A:");
	//OLED_ShowNumber(10,44,Motor_A,3,12);
	OLED_ShowString(45,44,"B:");
	//OLED_ShowNumber(55,44,Motor_B,3,12);
	OLED_ShowString(90,44,"C:");
	//OLED_ShowNumber(100,44,Motor_C,3,12);

//		if(Pitch_Bias<0)		OLED_ShowNumber(15,0,Pitch_Bias+360,3,12);
//		else					      OLED_ShowNumber(15,0,Pitch_Bias,3,12);	
//       
//	OLED_ShowString(40,0,"Y:");
//		if(Roll_Bias<0)		OLED_ShowNumber(55,0,Roll_Bias+360,3,12);
//		else					    OLED_ShowNumber(55,0,Roll_Bias,3,12);	
//	
//	   OLED_ShowString(80,0,"Z:");
//		if(Yaw<0)		OLED_ShowNumber(95,0,Yaw+360,3,12);
//		else					OLED_ShowNumber(95,0,Yaw,3,12);		

//		//=============��ʾ���A��״̬=======================//	
//										      OLED_ShowString(00,10,"A");
//	  if( Target_A<0)		    OLED_ShowString(15,10,"-"),
//		                      OLED_ShowNumber(25,10,-Target_A,4,12);
//		else                 	OLED_ShowString(15,10,"+"),
//		                      OLED_ShowNumber(25,10, Target_A,4,12); 
//													OLED_ShowString(70,10,"X");
//		if( Move_X<0)		      OLED_ShowString(85,10,"-"),
//		                      OLED_ShowNumber(95,10,-Move_X,4,12);
//		else                 	OLED_ShowString(85,10,"+"),
//		                      OLED_ShowNumber(95,10, Move_X,4,12);
//		//=============��ʾ���B��״̬=======================//	
//										      OLED_ShowString(00,20,"B");
//		  if( Target_B<0)		  OLED_ShowString(15,20,"-"),
//		                      OLED_ShowNumber(25,20,-Target_B,4,12);
//		else                 	OLED_ShowString(15,20,"+"),
//		                      OLED_ShowNumber(25,20, Target_B,4,12);
//		
//													OLED_ShowString(70,20,"Y");
//		if( Move_Y<0)		      OLED_ShowString(85,20,"-"),
//		                      OLED_ShowNumber(95,20,-Move_Y,4,12);
//		else                 	OLED_ShowString(85,20,"+"),
//		                      OLED_ShowNumber(95,20, Move_Y,4,12);
// 		//=============��ʾ���C��״̬=======================//	
//												  OLED_ShowString(00,30,"C");
//		  if( Target_C<0)		  OLED_ShowString(15,30,"-"),
//		                      OLED_ShowNumber(25,30,-Target_C,4,12);
//		else                 	OLED_ShowString(15,30,"+"),
//		                      OLED_ShowNumber(25,30, Target_C,4,12); 
//													
//		                      OLED_ShowString(70,30,"Z");
//		if( Move_Z<0)		      OLED_ShowString(85,30,"-"),
//		                      OLED_ShowNumber(95,30,-Move_Z,4,12);
//		else                 	OLED_ShowString(85,30,"+"),
//		                      OLED_ShowNumber(95,30, Move_Z,4,12);	
//		//=============��ʾ���D��״̬=======================//
//  	OLED_ShowString(0,40,"XR:");
//		if(Pitch<0)		      OLED_ShowNumber(20,40,Pitch+360,3,12);
//		else					      OLED_ShowNumber(20,40,Pitch,3,12);	
//       
//  	OLED_ShowString(45,40,"YR:");
//		if(Roll<0)		   OLED_ShowNumber(65,40,Roll+360,3,12);
//		else					    OLED_ShowNumber(65,40,Roll,3,12);	
//		
//				 if(Flag_Stop==0) OLED_ShowString(100,40,"O-N");
//			   else             OLED_ShowString(100,40,"OFF");
//		//=============��6����ʾģʽ�͵�ѹ=======================//
//												  OLED_ShowString(60,50,"MODE");
//				 if(Flag_Show==0) OLED_ShowString(100,50,"P-C");
//			   else             OLED_ShowString(100,50,"APP");
//		                      OLED_ShowString(13,50,".");
//		                      OLED_ShowString(35,50,"V");
//		                      OLED_ShowNumber(0,50,Voltage/100,2,12);
//		                      OLED_ShowNumber(23,50,Voltage%100,2,12);
//		 if(Voltage%100<10) 	OLED_ShowNumber(17,50,0,2,12);
//		//=============ˢ��=======================//
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
