#include "IGruppioV2.h"
#include "Adc-Gruppio.h"
#include <p32xxxx.h>
#include <plib.h>

void InitInterrupt()
{
///ConfigIntTimer1(T1_INT_ON | T1_INT_PRIOR_2);
mINT1SetIntPriority(1);
INTEnableSystemMultiVectoredInt();
mINT1IntEnable(1);

}

//---------------------------------------------------------

void InitTimer1(){

OpenTimer1(T1_ON | T1_SOURCE_INT | T1_PS_1_256, T1_TICK);
}

//--------------------------------------------------------------

void Delayus(long Time)
{
  long Cicli;

  Cicli=Time;
  while(Cicli)Cicli--;
}

//-------------------------------------------------------------
void ErrorHomeScreen (char *Str)
{
int x;
RGB1=1;RGB2=1;RGBR=0;RGBG=1;RGBB=1;
SetTransparent(1);
x=CenterText(Str,2);
DrawString(Str,x,3,2,0);
Delayus(2000000);
RGB1=0;RGB2=0;RGBR=1;RGBG=1;RGBB=1;

}

//-------------------------------------------------------------
float VoltageBatt()
{
float V;

V=readADC(0);
V=V/113,7;
V=V+0.7;
return V;

}



