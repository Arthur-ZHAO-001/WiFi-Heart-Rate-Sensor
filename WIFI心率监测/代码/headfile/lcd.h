#ifndef __LCD_H_
#define __LCD_H_
/**********************************
��ʹ�õ���4λ���ݴ����ʱ���壬
ʹ��8λȡ���������
**********************************/
#include <STC12C5A60S2.h>
/**********************************
����ͷ�ļ�
**********************************/


//---�ض���ؼ���---//


/**********************************
PIN�ڶ���
**********************************/
#define LCD1602_DATAPINS P0
sbit LCD1602_E=P3^4;
sbit LCD1602_RS=P3^5;
sbit LCD1602_RW=P3^6;


void LcdWaitReady();
/**********************************
��������
**********************************/
/*��51��Ƭ��11.0592MHZʱ���µ���ʱ����*/
void delay(unsigned int n);
void LcdInit();
/*LCD1602д��8λ�����Ӻ���*/
void LcdWriteCom(unsigned char com);
/*LCD1602д��8λ�����Ӻ���*/	
void LcdWriteData(unsigned char dat);
/*LCD1602��ʼ���ӳ���*/		
void LCD1602_DisplayOneCharOnAddr(unsigned char x,unsigned char y,unsigned char ucData);				  
void LcdSetCursor(unsigned char x , unsigned char y);
void LcdShowStr(unsigned char x,unsigned char y ,unsigned char *str);
void InitUART(void);
#endif
