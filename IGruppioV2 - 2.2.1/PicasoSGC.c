#include "Uart-Gruppio.h"
#include "PicasoSGC.h"
#include <p32xxxx.h>

extern char Stop;

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
 //while((!uart4_rx_ready)&&(!Stop));
 while((!uart4_rx_ready));
  return uart4_read_char();

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
void SetPenSize(char Size)
{
char Rcv=0;

	while(Rcv!=ACK){
					Lcd_putc(0x70);
					Lcd_putc(Size);
					Rcv=Lcd_getc();
					}
	
}
//------------------------------------
void SetFont(char Size) //Da 0 a 3
{
char Rcv=0;

	while(Rcv!=ACK){
					Lcd_putc(0x46);
					Lcd_putc(Size);
					Rcv=Lcd_getc();
					}
	
}
//------------------------------------
void SetTransparent(char Size)//1 trasparent - 0 opaque
{
char Rcv=0;

	while(Rcv!=ACK){
					Lcd_putc(0x4f);
					if(Size!=0)	Lcd_putc(0);
					if(Size==0)	Lcd_putc(1);
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
//DisplayControl(0x05,0x02);  //En TouchScreen
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

//------------------------------------
void DrawButton(char *s,char state,int x,int y,char font,int ButtonColor,int StringColor,char Largh,char Alt)
{
char Rcv=0;

	while(Rcv!=ACK){
					Lcd_putc(0x62);
					Lcd_putc(state);
					Lcd_putI(x);
					Lcd_putI(y);
					Lcd_putI(ButtonColor);
					Lcd_putc(font);
					Lcd_putI(StringColor);
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
void ReadTouch(char mode,int *x1,int *y1)
{
unsigned char Rcv[5];
unsigned int X,Y;
char i=0;

i=0;
					Lcd_putc(0x6f);
					Lcd_putc(mode);


for(i=0;i<4;i++){
			Rcv[i]=Lcd_getc();
}		



					X=((Rcv[0]<<8)|(Rcv[1]));
					Y=((Rcv[2]<<8)|(Rcv[3]));

					*x1=X;
					*y1=Y;
						
}

//------------------------------------
void WaitUntilTouch(int Time)
{
char Rcv=0;


					Lcd_putc(0x77);
					Lcd_putI(Time);
					Rcv=Lcd_getc();
}

//------------------------------------
void DetectTouchRegion(int x1,int y1,int x2,int y2)
{
char Rcv=0;

	while(Rcv!=ACK){
					Lcd_putc(0x75);
					Lcd_putI(x1);
					Lcd_putI(y1);
					Lcd_putI(x2);
					Lcd_putI(y2);
					Rcv=Lcd_getc();
					}
	
}

//------------------------------------
int ReadPixel(int x1,int y1)
{
unsigned char Rcv[2];
unsigned int X;
char i=0;


		Lcd_putc(0x52);
		Lcd_putI(x1);
		Lcd_putI(y1);				;


for(i=0;i<2;i++){
			Rcv[i]=Lcd_getc();
}		



X=((Rcv[0]<<8)|(Rcv[1]));
return X;
						
}

//------------------------------------
char TouchStatus()
{

unsigned char Rcv[5];
unsigned int X,Y;
char i=0;

i=0;
					Lcd_putc(0x6f);
					Lcd_putc(0x04);


for(i=0;i<4;i++){
			Rcv[i]=Lcd_getc();
}		



if(Rcv[1]==0) return 'N'; //Niente
if(Rcv[1]==1) return 'P'; //Press
if(Rcv[1]==2) return 'R'; //Released
if(Rcv[1]==3) return 'M';  //Moving

}

//------------------------------------
void WaitTouchPress(int *x1,int *y1)
{
unsigned char Rcv[5];
unsigned int X,Y;
char i=0;

i=0;
					Lcd_putc(0x6f);
					Lcd_putc(0x01);


for(i=0;i<4;i++){
			Rcv[i]=Lcd_getc();
			if(Stop)i=10;
}		



					X=((Rcv[0]<<8)|(Rcv[1]));
					Y=((Rcv[2]<<8)|(Rcv[3]));

					*x1=X;
					*y1=Y;
						
}
//------------------------------------
void WaitTouchActivity(int *x1,int *y1)
{
unsigned char Rcv[5];
unsigned int X,Y;
char i=0;

i=0;
					Lcd_putc(0x6f);
					Lcd_putc(0x00);


for(i=0;i<4;i++){
			Rcv[i]=Lcd_getc();
			if(Stop)i=10;
}		



					X=((Rcv[0]<<8)|(Rcv[1]));
					Y=((Rcv[2]<<8)|(Rcv[3]));

					*x1=X;
					*y1=Y;
						
}
//------------------------------------
void WaitTouchRelease(int *x1,int *y1)
{
unsigned char Rcv[5];
unsigned int X,Y;
char i=0;

i=0;
					Lcd_putc(0x6f);
					Lcd_putc(0x02);


for(i=0;i<4;i++){
			Rcv[i]=Lcd_getc();
			if(Stop)i=10;
}		



					X=((Rcv[0]<<8)|(Rcv[1]));
					Y=((Rcv[2]<<8)|(Rcv[3]));

					*x1=X;
					*y1=Y;
						
}
//------------------------------------
void WaitTouchMoving(int *x1,int *y1)
{
unsigned char Rcv[5];
unsigned int X,Y;
char i=0;

i=0;
					Lcd_putc(0x6f);
					Lcd_putc(0x03);


for(i=0;i<4;i++){
			Rcv[i]=Lcd_getc();
			if(Stop)i=10;
}		



					X=((Rcv[0]<<8)|(Rcv[1]));
					Y=((Rcv[2]<<8)|(Rcv[3]));

					*x1=X;
					*y1=Y;
						
}
//------------------------------------
void GetTouchCoordinates(int *x1,int *y1)
{
unsigned char Rcv[5];
unsigned int Xa,Ya;
char i=0;


					Lcd_putc(0x6f);
					Lcd_putc(0x05);


for(i=0;i<4;i++){
			Rcv[i]=Lcd_getc();
			if(Stop)i=10;
}		



					Xa=((Rcv[0]<<8)|(Rcv[1]));
					Ya=((Rcv[2]<<8)|(Rcv[3]));

					*x1=Xa;
					*y1=Ya;
						
}

//----------------------------------------------------------
int CenterText(char *s,char font)
{
int X,Lungh,LunghScreen,LunghCh=5;

if(font==0)LunghCh=5;
if(font==1)LunghCh=8;
if(font==2)LunghCh=8;
if(font==3)LunghCh=12;

Lungh=strlen(s);
LunghScreen=240/LunghCh;
X=LunghScreen/2;
X=X-Lungh/2;

return X;
}
//----------------------------------------------------------
void DrawMyButton(char *s,char Schiacciato,int x,int y,int x2,int y2,char font)
{
int Xtext,Lungh,LunghButton,LunghCh=5;
int Ytext,AltButton,AltCh=5;


if(font==0){LunghCh=5;AltCh=7;}
if(font==1){LunghCh=8;AltCh=8;}
if(font==2){LunghCh=8;AltCh=12;}
if(font==3){LunghCh=12;AltCh=16;}

//calcolo la x per mettere il testo al centro del bottone
Lungh=strlen(s)*LunghCh;
LunghButton=x2-x;
if(LunghButton>Lungh){
		Xtext=(LunghButton-Lungh)/2;
		Xtext=Xtext+x;
}
else Xtext=x;		

//calcolo la y per mettere il testo al centro del bottone
AltButton=y2-y;
if(AltButton>AltCh){
		Ytext=(AltButton-AltCh)/2;
		Ytext=y+Ytext;
}
else Ytext=y;	

if(Schiacciato)
{
	DrawRectangle(x,y,x2,y2,Blu);
	DrawStringBig(s,Xtext,Ytext,font,Bianco,1,1);
	DrawLine(x,y,x,y2,Nero); //riga nera
	DrawLine(x,y,x2,y,Nero); //riga nera
	DrawLine(x2,y2,x2,y,Bianco); //riga Bianca
	DrawLine(x2,y2,x,y2,Bianco); //riga Bianca
}
else
{
	DrawRectangle(x,y,x2,y2,Grigio);
	DrawStringBig(s,Xtext,Ytext,font,Nero,1,1);
	DrawLine(x,y,x,y2,Bianco); //riga nera
	DrawLine(x,y,x2,y,Bianco); 
	DrawLine(x2,y2,x2,y,Nero); //riga Bianca
	DrawLine(x2,y2,x,y2,Nero); //riga Bianca
}

}
