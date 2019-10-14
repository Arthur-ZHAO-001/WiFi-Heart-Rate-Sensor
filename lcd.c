
#include <intrins.h>
#include "lcd.h"
/*******************************************************************************
* �� �� ��         : Lcd1602_Delay1ms
* ��������		   : ��ʱ��������ʱ1ms
* ��    ��         : c
* ��    ��         : ��
* ˵    ��         : �ú�������11.0592MHZ������
*******************************************************************************/

void Lcd1602_Delay1ms(unsigned char c)   
{
  unsigned char t;
  while(c--)
  {
    for (t=0;t<120;t++);
  }
    	
}

/*******************************************************************************
* �� �� ��         : LcdWriteCom
* ��������		   : ��LCDд��һ���ֽڵ�����
* ��    ��         : com
* ��    ��         : ��
*******************************************************************************/
void LcdWriteCom(unsigned char com)	  //д������
{
	LCD1602_E = 0;     //ʹ��
	LCD1602_RS = 0;	   //ѡ��������
	LCD1602_RW = 0;	   //ѡ��д��
	
	LCD1602_DATAPINS = com;     //��������
	Lcd1602_Delay1ms(1);		//�ȴ������ȶ�

	LCD1602_E = 1;	          //д��ʱ��
	Lcd1602_Delay1ms(5);	  //����ʱ��
	LCD1602_E = 0;
}

/*******************************************************************************
* �� �� ��         : LcdWriteData
* ��������		   : ��LCDд��һ���ֽڵ�����
* ��    ��         : dat
* ��    ��         : ��
*******************************************************************************/		    
void LcdWriteData(unsigned char dat)			//д������
{
	LCD1602_E = 0;	//ʹ������
	LCD1602_RS = 1;	//ѡ����������
	LCD1602_RW = 0;	//ѡ��д��

	LCD1602_DATAPINS = dat; //д������
	Lcd1602_Delay1ms(1);

	LCD1602_E = 1;   //д��ʱ��
	Lcd1602_Delay1ms(5);   //����ʱ��
	LCD1602_E = 0;
}

/*******************************************************************************
* �� �� ��       : LcdInit()
* ��������		 : ��ʼ��LCD��
* ��    ��       : ��
* ��    ��       : ��
*******************************************************************************/		   
void LcdInit()						  //LCD��ʼ���ӳ���
{
 	LcdWriteCom(0x38);  //����ʾ
	LcdWriteCom(0x0c);  //����ʾ����ʾ���
	LcdWriteCom(0x06);  //дһ��ָ���1
	LcdWriteCom(0x01);  //����
	LcdWriteCom(0x80);  //��������ָ�����
}

void LcdSetCursor(unsigned char x , unsigned char y)
{
	unsigned char addr;
	if (y==0)
		addr=0x00+x;
	else
		addr=0x40+x;
	LcdWriteCom(addr|0x80);
}

void LcdShowStr(unsigned char x,unsigned char y ,unsigned char *str)
{
	LcdSetCursor(x,y);
	while(*str!='\0')
	{
		LcdWriteData(*str++);
	}
}

void LCD1602_DisplayOneCharOnAddr(unsigned char x,unsigned char y,unsigned char ucData)
{
	LcdSetCursor(x,y);   //���λ��
	LcdWriteData(ucData);	  //д������
}
void delay(unsigned int n)
{
	unsigned int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<100;j++);
}