#include "Uart-Gruppio.h"
#include "PicasoSGC.h"
#include <p32xxxx.h>



void Lcd_putc(char c)
{

	Uart4_putc(c);

}
//------------------------------------
void Lcd_putI(int i)
{
	Uart4_putI(i);

}
//------------------------------------

char Lcd_getc()
{
	return	Uart4_getc();
}
//------------------------------------
void AutoBaud()
{
char Rcv=0;

	while(Rcv!=ACK)
				{
					Lcd_putc(0x55);
					Rcv=Lcd_getc();
				}
	
}

//------------------------------------
void SetNewBaudRate(char Rate)
{
char Rcv=0;

	while(Rcv!=ACK){
					Lcd_putc(0x51);
					Lcd_putc(Rate);
					Rcv=Lcd_getc();
					}
	
}
//------------------------------------
void ReplaceBackgroundColor(int Color)
{
char Rcv=0;

	while(Rcv!=ACK){
					Lcd_putc(0x42);
					Lcd_putI(Color);
					Rcv=Lcd_getc();
					}
	
}
//------------------------------------
void ClearScreen()
{
char Rcv=0;

	while(Rcv!=ACK){Lcd_putc(0x45);Rcv=Lcd_getc();}
	
}
//------------------------------------
void DisplayControl(char mode,char value)
{
char Rcv=0;

	while(Rcv!=ACK){
					Lcd_putc(0x59);
					Lcd_putc(mode);
					Lcd_putc(value);
					Rcv=Lcd_getc();
					}
	
}
//------------------------------------
void SetVolume(char Rate)
{
char Rcv=0;

	while(Rcv!=ACK){
					Lcd_putc(0x76);
					Lcd_putc(Rate);
					Rcv=Lcd_getc();
					}
	
}
//------------------------------------
void DrawCircle(int x,int y,int raggio,int Color)
{
char Rcv=0;

	while(Rcv!=ACK){
					Lcd_putc(0x43);
					Lcd_putI(x);
					Lcd_putI(y);
					Lcd_putI(raggio);
					Lcd_putI(Color);
					Rcv=Lcd_getc();

					}
	
}
//------------------------------------
void SetBackgroundColor(int Color)
{
char Rcv=0;

	while(Rcv!=ACK){
					Lcd_putc(0x4B);
					Lcd_putI(Color);
					Rcv=Lcd_getc();
					}
	
}
//------------------------------------
void SetPenSize(int Size)
{
char Rcv=0;

	while(Rcv!=ACK){
					Lcd_putc(0x70);
					Lcd_putI(Size);
					Rcv=Lcd_getc();
					}
	
}
//------------------------------------
void SetFont(int Size) //Da 0 a 3
{
char Rcv=0;

	while(Rcv!=ACK){
					Lcd_putc(0x46);
					Lcd_putI(Size);
					Rcv=Lcd_getc();
					}
	
}
//------------------------------------
void SetTransparent(int Size)//0 trasparent - 1 opaque
{
char Rcv=0;

	while(Rcv!=ACK){
					Lcd_putc(0x4F);
					Lcd_putI(Size);
					Rcv=Lcd_getc();
					}
	
}
//------------------------------------
void DrawLine(int x1,int y1,int x2,int y2,int Color)
{
char Rcv=0;

	while(Rcv!=ACK){
					Lcd_putc(0x4C);
					Lcd_putI(x1);
					Lcd_putI(y1);
					Lcd_putI(x2);
					Lcd_putI(y2);
					Lcd_putI(Color);
					Rcv=Lcd_getc();
					}
	
}
//------------------------------------
void DrawChBig(char ch,int x,int y,int Color,char Largh,char Alt)
{
char Rcv=0;

	while(Rcv!=ACK){
					Lcd_putc(0x74);
					Lcd_putc(ch);
					Lcd_putI(x);
					Lcd_putI(y);
					Lcd_putI(Color);
					Lcd_putc(Largh);
					Lcd_putc(Alt);
					Rcv=Lcd_getc();
					}
	
}
//------------------------------------
void DrawCh(char ch,char Col,char Rig,int Color)
{
char Rcv=0;

	while(Rcv!=ACK){
					Lcd_putc(0x54);
					Lcd_putc(ch);
					Lcd_putc(Col);
					Lcd_putc(Rig);
					Lcd_putI(Color);
					Rcv=Lcd_getc();
					}
	
}
//------------------------------------
void DrawString(char *s,char Col,char Rig,char font,int Color)
{
char Rcv=0;

	while(Rcv!=ACK){
					Lcd_putc(0x73);
					Lcd_putc(Col);
					Lcd_putc(Rig);
					Lcd_putc(font);
					Lcd_putI(Color);
  					while(*s)
 							 {
								Lcd_putc(*s);
    							s++;
 							 }
					Lcd_putc(0x00);
					Rcv=Lcd_getc();
					}
	
}
//------------------------------------
void DrawStringBig(char *s,int x,int y,char font,int Color,char Largh,char Alt)
{
char Rcv=0;

	while(Rcv!=ACK){
					Lcd_putc(0x53);
					Lcd_putI(x);
					Lcd_putI(y);
					Lcd_putc(font);
					Lcd_putI(Color);
					Lcd_putc(Largh);
					Lcd_putc(Alt);
  					while(*s)
 							 {
								Lcd_putc(*s);
    							s++;
 							 }
					Lcd_putc(0x00);
					Rcv=Lcd_getc();
					}
	
}
//------------------------------------
void ReplaceColor(int x1,int y1,int x2,int y2,int Color,int ColorNew)
{
char Rcv=0;

	while(Rcv!=ACK){
					Lcd_putc(0x4C);
					Lcd_putI(x1);
					Lcd_putI(y1);
					Lcd_putI(x2);
					Lcd_putI(y2);
					Lcd_putI(Color);
					Lcd_putI(ColorNew);
					Rcv=Lcd_getc();
					}
	
}
//------------------------------------
void PutPixel(int x1,int y1,int Color)
{
char Rcv=0;

	while(Rcv!=ACK){
					Lcd_putc(0x50);
					Lcd_putI(x1);
					Lcd_putI(y1);
					Lcd_putI(Color);
					Rcv=Lcd_getc();
					}
	
}
//------------------------------------
void DrawTriangle(int x1,int y1,int x2,int y2,int x3,int y3,int Color)
{
char Rcv=0;

	while(Rcv!=ACK){
					Lcd_putc(0x47);
					Lcd_putI(x1);
					Lcd_putI(y1);
					Lcd_putI(x2);
					Lcd_putI(y2);
					Lcd_putI(Color);
					Rcv=Lcd_getc();
					}
	
}
//------------------------------------
void DrawRectangle(int x1,int y1,int x2,int y2,int Color)
{
char Rcv=0;

	while(Rcv!=ACK){
					Lcd_putc(0x72);
					Lcd_putI(x1);
					Lcd_putI(y1);
					Lcd_putI(x2);
					Lcd_putI(y2);
					Lcd_putI(Color);
					Rcv=Lcd_getc();
					}
	
}
//------------------------------------
void DrawEllipse(int x1,int y1,int rx,int ry,int Color)
{
char Rcv=0;

	while(Rcv!=ACK){
					Lcd_putc(0x4C);
					Lcd_putI(x1);
					Lcd_putI(y1);
					Lcd_putI(rx);
					Lcd_putI(ry);
					Lcd_putI(Color);
					Rcv=Lcd_getc();
					}
	
}
//-------------------------------------------
void InitLcd()
{

AutoBaud();

DisplayControl(0x00,0x00); //Spengo la luce
DisplayControl(0x01,0x01); // Accendo il Display
//DisplayControl(0x02,0x08);  //Contrasto da 0x00 a 0x0F
DisplayControl(0x03,0x01);  //PowerUp
DisplayControl(0x04,0x03);  //PORTRAIT
DisplayControl(0x05,0x00);  //En TouchScreen
DisplayControl(0x06,0x01);  //Image format
DisplayControl(0x08,0x02);	//Protect FAT
InitSD();

}


//------------------------------------
void InitSD()
{
char Rcv=0;

	while(Rcv!=ACK)
				{
					Lcd_putc(0x40);
					Lcd_putc(0x69);
					Rcv=Lcd_getc();
				}

	
}
//------------------------------------
void DisplayImage(char *s,int x,int y)
{
char Rcv=0;

	while(Rcv!=ACK){
					Lcd_putc(0x40);
					Lcd_putc(0x6D);

  					while(*s)
 							 {
								Lcd_putc(*s);
    							s++;
 							 }

					Lcd_putc('.');
					Lcd_putc('G');
					Lcd_putc('C');
					Lcd_putc('I');
					Lcd_putc(0x00);

					Lcd_putI(x);
					Lcd_putI(y);
					Lcd_putI(0);
					Lcd_putI(0);

					Rcv=Lcd_getc();
					}
	
}
//------------------------------------
void PlayAudio(char *s,char option)
{
char Rcv=0;

	while(Rcv!=ACK){
					Lcd_putc(0x40);
					Lcd_putc(0x6C);

					Lcd_putc(option);

  					while(*s)
 							 {
								Lcd_putc(*s);
    							s++;
 							 }

					Lcd_putc('.');
					Lcd_putc('W');
					Lcd_putc('A');
					Lcd_putc('V');
					Lcd_putc(0x00);


					Rcv=Lcd_getc();
					}
	
}

