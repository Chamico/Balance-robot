#include "show.h"
  /**************************************************************************
作者：平衡小车之家
我的淘宝小店：http://shop114407458.taobao.com/
**************************************************************************/
unsigned char i;          //计数变量
unsigned char Send_Count; //串口需要发送的数据个数
float Vol;

extern float blu_channel_1;
extern int Usart_Receive;

/**************************************************************************
函数功能：OLED显示
入口参数：无
返回  值：无
**************************************************************************/
void oled_show(void)
{
	//=============第1行和第2行显示项目名称===============//	
	OLED_ShowChinese_one(0,0,0); //基
	OLED_ShowChinese_one(16,0,1); //于
	OLED_ShowString(35,3,"MCU");
	OLED_ShowChinese_one(60,0,2); //的
	OLED_ShowChinese_one(78,0,3); //球
	OLED_ShowChinese_one(95,0,4); //动
	OLED_ShowChinese_one(112,0,5); //式
	OLED_ShowChinese_two(20,0,6); //平
	OLED_ShowChinese_two(37,0,7); //衡
	OLED_ShowChinese_two(54,0,8); //机
	OLED_ShowChinese_two(71,0,9); //器
	OLED_ShowChinese_two(88,0,10); //人
	//=============第3行显示项目编号===============//	
	OLED_ShowString(18,34,"201810742086");
		OLED_Refresh_Gram();	
	}
/**************************************************************************
函数功能：向APP发送数据
入口参数：无
返回  值：无
作    者：平衡小车之家
**************************************************************************/
void APP_Show(void)
{    
	static u8 flag;
	int app_2,app_3,app_4;
	app_4=(Voltage-1110)*2/3;	
	if(app_4>100)app_4=100;   //对电压数据进行处理
	app_2=Move_X*0.2;  if(app_2<0)app_2=-app_2;			                   //对编码器数据就行数据处理便于图形化
	app_3=Move_Y*0.2;  if(app_3<0)app_3=-app_3;
	flag=!flag;
	if(PID_Send==1)//发送PID参数
	{
		printf("{C%d:%d:%d:%d:%d}$",(int)Balance_Kp,(int)Balance_Kd,(int)Velocity_Kp,(int)Velocity_Ki,0);//打印到APP上面	
		PID_Send=0;	
	}	
	 else	if(flag==0)// 
	 printf("{A%d:%d:%d:%d}$",(u8)app_2,(u8)app_3,app_4,(int)Yaw); //打印到APP上面
	 else
	 printf("{B%d:%d:%d:%d}$",(int)Pitch,(int)Roll,(int)Yaw,app_4);//打印到APP上面 显示波形
}
/**************************************************************************
函数功能：虚拟示波器往上位机发送数据 关闭显示屏
入口参数：无
返回  值：无
作    者：平衡小车之家
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
