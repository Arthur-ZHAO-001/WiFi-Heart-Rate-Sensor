#ifndef st7735_H_
#define st7735_H_
#define uchar unsigned char
#define uint unsigned int
#define RED  		0xf800
#define GREEN		0x07e0
#define BLUE 		0x001f
#define WHITE		0xffff
#define BLACK		0x0000
#define YELLOW  0xFFE0
#define GRAY0   0xEF7D   
#define GRAY1   0x8410      	
#define GRAY2   0x4208   

#define USE_LANDSCAPE//���Գ���������л��������뿪���˺꣬����������

	//P3M1.n,P3M0.n 	=00--->Standard,	01--->push-pull
	//					=10--->pure input,	11--->open drain



//---------------------------Һ��������˵��-------------------------------------//
//����ǰ��ο�Һ����˵�����10ҳ���Ŷ���
sbit bl        =P3^2;//��ģ��BL���ţ�������Բ���IO���ƻ���PWM���ƣ�Ҳ����ֱ�ӽӵ��ߵ�ƽ����
sbit scl       =P1^7;//��ģ��CLK����,������Pin9_SCL
sbit sda       =P1^5;//��ģ��DIN/MOSI���ţ�������Pin8_SDA
sbit rs        =P1^2;//��ģ��D/C���ţ�������Pin7_A0
sbit cs        =P1^3;//��ģ��CE���ţ�������Pin12_CS
sbit reset     =P3^3;//��ģ��RST���ţ�������Pin6_RES
//---------------------------End ofҺ��������---------------------------------//

void Display_Desc();
void delay_ms(uint time);
void  Contrast_Adjust();
void  SPI_WriteData(uchar Data);
void  Lcd_WriteIndex(uchar Data);
void  Lcd_WriteData(uchar Data);
void  LCD_WriteData_16Bit(unsigned int Data);
void clean1();
void showcoordinate();
void Reset();
void lcd_initial();
void Lcd_SetRegion(unsigned int x_start,unsigned int y_start,unsigned int x_end,unsigned int y_end);
void PutPixel(uint x_start,uint y_start,uint color);
void put_bigpixel(uint x,uint y,uint color);
void dsp_single_colour(int color);
void Drawline(uint x1,uint y1,uint x2,uint y2);
uchar code Zk_ASCII8X16[];
void Output_Pixel(uint x,uint y);
void Display_ASCII8X16(uint x0,uint y0,uchar *s);
void Hline(uint y,uint x1,uint x2);
void Vline(uint x,uint y1, uint y2);
void Drawline(uint x1,uint y1,uint x2,uint y2);
