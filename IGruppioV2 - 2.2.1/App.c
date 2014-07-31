#include "App.h"
#include "Grapichs.h"
#include "Adxl345.h"
#include "ITG3200.h"
#include "Adc-Gruppio.h"
#include "IGruppioV2.h"
#include "Uart-Gruppio.h"
//#include "PicasoSGC.h"
#include <p32xxxx.h>
#include <plib.h>


extern char Stop;
extern int  BackgroundCol;
extern int  WriteCol;
extern char GPSData[256],NewGPSData;
extern int  GPSDataLenght;
extern char RxBuffer[256];

#define Bianco 0xffff
#define Nero 0


void GPS()
{

char Str[256];
char CharRx;
int  index=0;
char Col=5;
char NChar=0;
int  StartCh=0;
int  LunghezzaStringa;

DrawBaseApp("GPS");

//DrawString("123456789012345678901234567890",0,2,2,Nero);
LedR=1;
DrawString("    Waiting GPS signal...",0,3,2,Nero);
while((!NewGPSData)&&(!Stop));
DrawString("                          ",0,3,2,Nero);
LedV=1;
LedR=0;


                    while(!Stop)
				{
                        
                        while((!NewGPSData)&&(!Stop));

                       // DrawString("                       ",0,4,2,Nero);
                        NewGPSData=0;
                        DrawCh(RxBuffer[0],0,5,Nero);
                        //sprintf(Str,"");
                  //      for(index=0;index<=GPSDataLenght;index++){
                       //     sprintf(Str,"%s%c",Str,GPSData[index]);

                   //     }
                     //   DrawString(Str,0,4,2,Nero);
                      //  index=0;

          					
				}

Stop=0;
LedV=0;
LedG=0;
LedR=0;
return;

}


//---------------------------------------------------------------
void AccAxies()
{

char Str[23];

DrawBaseApp("Axies");

	while(!Stop)
				{
					sprintf(Str,"X = %.2f G    ",ReadAccX());   			
					DrawString(Str,0,4,2,Nero);	

					sprintf(Str,"Y = %.2f G     ",ReadAccY());   			
					DrawString(Str,0,6,2,Nero);	

					sprintf(Str,"Z = %.2f G     ",ReadAccZ());   				
					DrawString(Str,0,8,2,Nero);	

					sprintf(Str,"Total = %.2f G    ",ReadAccTotal());   				
					DrawString(Str,0,10,2,Nero);	
	
				}

Stop=0;
return;

}

//----------------------------------------------------------------------------

void FreeFall()
{
float ACC;
char Str[23];

DrawBaseApp("FreeFall");



	while(!Stop)
				{
					ACC=ReadAccTotal();
					sprintf(Str,"Acc = %.2f G   ",ACC);   			
					DrawString(Str,0,4,2,Nero);	
					if(0.2>ACC){RGB1=1;RGB2=1;RGBR=1;RGBG=0;RGBB=1;}
					else {RGB1=0;RGB2=0;RGBR=1;RGBG=1;RGBB=1;}
	
				}

Stop=0;
return;

}


//-----------------------------------------------------------------------------

void Angle()
{

char Str[23];

DrawBaseApp("Angle");

	while(!Stop)
				{
					sprintf(Str,"X = %.2f g    ",ReadAngleX());   			
					DrawString(Str,0,4,2,Nero);	

					sprintf(Str,"Y = %.2f g     ",ReadAngleY());   			
					DrawString(Str,0,6,2,Nero);	

					sprintf(Str,"Z = %.2f g     ",ReadAngleZ());   				
					DrawString(Str,0,8,2,Nero);	

	
				}

Stop=0;
return;

}

//-----------------------------------------------------------------------------

void GyroAxies()
{

char Str[23];

DrawBaseApp("Gyro");

	while(!Stop)
				{
					sprintf(Str,"X = %.2f g/s    ",ReadWX());   			
					DrawString(Str,0,4,2,Nero);	

					sprintf(Str,"Y = %.2f g/s     ",ReadWY());   			
					DrawString(Str,0,6,2,Nero);	

					sprintf(Str,"Z = %.2f g/s     ",ReadWZ());   				
					DrawString(Str,0,8,2,Nero);	

	
				}

Stop=0;
return;

}
