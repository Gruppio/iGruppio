#include "PicasoSGC.h"
#include "Grapichs.h"
#include "Adc-Gruppio.h"
#include "ITG3200.h"
#include "IGruppioV2.h"
#include <p32xxxx.h>

extern char Stop;
extern int  BackgroundCol;
extern int  WriteCol;





char DrawHome(char Pag)
{


char Str[10];
int X=0,Y=0;
int Grigio1;
float Batt;
unsigned int i=0;

Stop=0;	

if(Pag==1)DisplayImage("HOME",0,0);
if(Pag==2)DisplayImage("HOME2",0,0);

Grigio1=ReadPixel(0,10); 		//Leggo il grigio prima di scrivere
SetBackgroundColor(Grigio1);  //Lo imposto come background
SetPenSize(0);			 // Pieno
SetTransparent(0);		 //disegna il quadrato attorno
Batt=VoltageBatt();
if((Batt<4.2)&&(Batt>3.0)){DrawRectangle((165+Batt*15),6,228,15,0b1111100000000000);} //Disegna Rosso Batteria
if (Batt<3.0) {DrawRectangle(210,6,228,15,0b1111100000000000);}
SetPenSize(1);

	while(!Stop)
				{
				while(('N'==TouchStatus())&&(!Stop)){ //Finchè uno non schiaccia il display
											if((i%20)==0){
															sprintf(Str,"%.2fV",VoltageBatt());   				//Leggi Tensione batteria
															DrawString(Str,30,1,0,0);		   				//Scrivila
															sprintf(Str,"%.1f Cg",ReadTemp());			    //Leggi Temp e scrivila
															DrawString(Str,3,1,0,0);
														}			

											if(i<30){
													if(i<8)LedR=1;
													else LedR=0;
													if((i>=8)&&(i<=15))LedG=1;
													else LedG=0;
													if((i>=16)&&(i<23))LedV=1;
													else LedV=0;
													}	

											if(i<1600)i++;
											else i=0;		
									    }
										//Se uno schiaccia o scipolla il display e non è stato schiacciato Home
								if(!Stop){
										LedV=0;
										LedG=0;
										LedR=0;				
										WaitTouchActivity(&X,&Y);

										if((X>x1)&&(X<x2)&&(Y>y1)&&(Y<y2)){DrawRectangle(x1,y1,x2,y2,0xffff);WaitTouchRelease(&X,&Y);return 1;}
										if((X>x1)&&(X<x2)&&(Y>y3)&&(Y<y4)){DrawRectangle(x1,y3,x2,y4,0xffff);WaitTouchRelease(&X,&Y);return 4;}
										if((X>x1)&&(X<x2)&&(Y>y5)&&(Y<y6)){DrawRectangle(x1,y5,x2,y6,0xffff);WaitTouchRelease(&X,&Y);return 7;}

										if((X>x3)&&(X<x4)&&(Y>y1)&&(Y<y2)){DrawRectangle(x3,y1,x4,y2,0xffff);WaitTouchRelease(&X,&Y);return 2;}
										if((X>x3)&&(X<x4)&&(Y>y3)&&(Y<y4)){DrawRectangle(x3,y3,x4,y4,0xffff);WaitTouchRelease(&X,&Y);return 5;}
										if((X>x3)&&(X<x4)&&(Y>y5)&&(Y<y6)){DrawRectangle(x3,y5,x4,y6,0xffff);WaitTouchRelease(&X,&Y);return 8;}

										if((X>x5)&&(X<x6)&&(Y>y1)&&(Y<y2)){DrawRectangle(x5,y1,x6,y2,0xffff);WaitTouchRelease(&X,&Y);return 3;}
										if((X>x5)&&(X<x6)&&(Y>y3)&&(Y<y4)){DrawRectangle(x5,y3,x6,y4,0xffff);WaitTouchRelease(&X,&Y);return 6;}
										if((X>x5)&&(X<x6)&&(Y>y5)&&(Y<y6)){DrawRectangle(x5,y5,x6,y6,0xffff);WaitTouchRelease(&X,&Y);return 9;}
								
								}		
														
		}
Stop=0;
return 0;
}

//-----------------------------------------------------------------------------------------------------------------

char DrawMenu(char *Titolo,char NBot,char *B1,char *B2,char *B3,char *B4,char *B5,char *B6,char *B7)
{
char Str[20];
int X=0,Y=0,HButton;
int i=0,c=0;
int YBotMin[7];
int YBotMax[7];

Stop=0;	

DisplayImage("MENU",0,0);
SetBackgroundColor(Grigio);  // imposto come background
SetPenSize(0);			 // Pieno
SetTransparent(1);		 //NO disegna il quadrato attorno
DrawString(Titolo,CenterText(Titolo,2),1,2,Bianco); //scrivo il titolo centrato

HButton=((240-Ytitolo)/6)+5; //definisco l'altezza dei bottoni

//calcolo la y di partenza dei 7 bottoni
for(c=0;c<7;c++)
{
YBotMin[c]=Ytitolo+(HButton*c)+1;
}

//calcolo la y finale dei 7 bottoni
for(c=1;c<8;c++)
{
YBotMax[c-1]=Ytitolo+(HButton*c);
}

//Disegno gli NBot bottoni	  
if(1<=NBot)DrawMyButton(B1,0,1,YBotMin[0],239,YBotMax[0],2);
if(2<=NBot)DrawMyButton(B2,0,1,YBotMin[1],239,YBotMax[1],2);
if(3<=NBot)DrawMyButton(B3,0,1,YBotMin[2],239,YBotMax[2],2);
if(4<=NBot)DrawMyButton(B4,0,1,YBotMin[3],239,YBotMax[3],2);
if(5<=NBot)DrawMyButton(B5,0,1,YBotMin[4],239,YBotMax[4],2);
if(6<=NBot)DrawMyButton(B6,0,1,YBotMin[5],239,YBotMax[5],2);
if(7<=NBot)DrawMyButton(B7,0,1,YBotMin[6],239,YBotMax[6],2);



	while(!Stop)
				{
				while(('N'==TouchStatus())&&(!Stop)); //Finchè uno non schiaccia il display

										//Se uno schiaccia o scipolla il display e non è stato schiacciato Home
								if(!Stop){
			
										WaitTouchRelease(&X,&Y);
										if((NBot>=1)&&(Y>YBotMin[0])&&(Y<YBotMax[0])){DrawMyButton(B1,1,1,YBotMin[0],239,YBotMax[0],2);return 1;}
										if((NBot>=2)&&(Y>YBotMin[1])&&(Y<YBotMax[1])){DrawMyButton(B2,1,1,YBotMin[1],239,YBotMax[1],2);return 2;}
										if((NBot>=3)&&(Y>YBotMin[2])&&(Y<YBotMax[2])){DrawMyButton(B3,1,1,YBotMin[2],239,YBotMax[2],2);return 3;}
										if((NBot>=4)&&(Y>YBotMin[3])&&(Y<YBotMax[3])){DrawMyButton(B4,1,1,YBotMin[3],239,YBotMax[3],2);return 4;}
										if((NBot>=5)&&(Y>YBotMin[4])&&(Y<YBotMax[4])){DrawMyButton(B5,1,1,YBotMin[4],239,YBotMax[4],2);return 5;}
										if((NBot>=6)&&(Y>YBotMin[5])&&(Y<YBotMax[5])){DrawMyButton(B6,1,1,YBotMin[5],239,YBotMax[5],2);return 6;}
										if((NBot>=7)&&(Y>YBotMin[6])&&(Y<YBotMax[6])){DrawMyButton(B7,1,1,YBotMin[6],239,YBotMax[6],2);return 7;}

								}		
														
		}
Stop=0;
return 0;

}


//-----------------------------------------------------------------------------------------------------------------

char DrawMenuSelector(char *Titolo,char NBot,char *B1,char *B2,char *B3,char *B4,char *B5,char *B6,char *B7,char Selected)
{
char Str[20];
int X=0,Y=0,HButton;
int i=0,c=0;
int YBotMin[7];
int YBotMax[7];

Stop=0;	

if(Selected==0){
DisplayImage("MENU",0,0);
SetBackgroundColor(Grigio);  // imposto come background
SetPenSize(0);			 // Pieno
SetTransparent(1);		 //NO disegna il quadrato attorno
DrawString(Titolo,CenterText(Titolo,2),1,2,Bianco); //scrivo il titolo centrato
}
HButton=((240-Ytitolo)/6)+5; //definisco l'altezza dei bottoni

//calcolo la y di partenza dei 7 bottoni
for(c=0;c<7;c++)
{
YBotMin[c]=Ytitolo+(HButton*c)+1;
}

//calcolo la y finale dei 7 bottoni
for(c=1;c<8;c++)
{
YBotMax[c-1]=Ytitolo+(HButton*c);
}


//Disegno gli NBot bottoni
if(Selected==0){	  
if(1<=NBot)DrawMyButton(B1,0,1,YBotMin[0],239,YBotMax[0],2);
if(2<=NBot)DrawMyButton(B2,0,1,YBotMin[1],239,YBotMax[1],2);
if(3<=NBot)DrawMyButton(B3,0,1,YBotMin[2],239,YBotMax[2],2);
if(4<=NBot)DrawMyButton(B4,0,1,YBotMin[3],239,YBotMax[3],2);
if(5<=NBot)DrawMyButton(B5,0,1,YBotMin[4],239,YBotMax[4],2);
if(6<=NBot)DrawMyButton(B6,0,1,YBotMin[5],239,YBotMax[5],2);
if(7<=NBot)DrawMyButton(B7,0,1,YBotMin[6],239,YBotMax[6],2);
}


	while(!Stop)
				{
				while(('N'==TouchStatus())&&(!Stop)); //Finchè uno non schiaccia il display

										//Se uno schiaccia o scipolla il display e non è stato schiacciato Home
								if(!Stop){
			
										WaitTouchRelease(&X,&Y);

										if(Selected==1)DrawMyButton(B1,0,1,YBotMin[0],239,YBotMax[0],2);
										if(Selected==2)DrawMyButton(B2,0,1,YBotMin[1],239,YBotMax[1],2);
										if(Selected==3)DrawMyButton(B3,0,1,YBotMin[2],239,YBotMax[2],2);
										if(Selected==4)DrawMyButton(B4,0,1,YBotMin[3],239,YBotMax[3],2);
										if(Selected==5)DrawMyButton(B5,0,1,YBotMin[4],239,YBotMax[4],2);
										if(Selected==6)DrawMyButton(B6,0,1,YBotMin[5],239,YBotMax[5],2);
										if(Selected==7)DrawMyButton(B7,0,1,YBotMin[6],239,YBotMax[6],2);							
			
										if((NBot>=1)&&(Y>YBotMin[0])&&(Y<YBotMax[0])){DrawMyButton(B1,1,1,YBotMin[0],239,YBotMax[0],2);return 1;}
										if((NBot>=2)&&(Y>YBotMin[1])&&(Y<YBotMax[1])){DrawMyButton(B2,1,1,YBotMin[1],239,YBotMax[1],2);return 2;}
										if((NBot>=3)&&(Y>YBotMin[2])&&(Y<YBotMax[2])){DrawMyButton(B3,1,1,YBotMin[2],239,YBotMax[2],2);return 3;}
										if((NBot>=4)&&(Y>YBotMin[3])&&(Y<YBotMax[3])){DrawMyButton(B4,1,1,YBotMin[3],239,YBotMax[3],2);return 4;}
										if((NBot>=5)&&(Y>YBotMin[4])&&(Y<YBotMax[4])){DrawMyButton(B5,1,1,YBotMin[4],239,YBotMax[4],2);return 5;}
										if((NBot>=6)&&(Y>YBotMin[5])&&(Y<YBotMax[5])){DrawMyButton(B6,1,1,YBotMin[5],239,YBotMax[5],2);return 6;}
										if((NBot>=7)&&(Y>YBotMin[6])&&(Y<YBotMax[6])){DrawMyButton(B7,1,1,YBotMin[6],239,YBotMax[6],2);return 7;}
										
										//Cancello il vechio selezionato
										
								}		
														
		}
Stop=0;
return 0;

}



//-----------------------------------------------------------------------------------------------------------------

char DrawMenu14(char *Titolo,char NBot,char *B1,char *B2,char *B3,char *B4,char *B5,char *B6,char *B7,char *B8,char *B9,char *B10,char *B11,char *B12,char *B13,char *B14)
{
char Str[20];
int X=0,Y=0,HButton;
int i=0,c=0;
int YBotMin[14];
int YBotMax[14];

Stop=0;	

DisplayImage("MENU",0,0);
SetBackgroundColor(Grigio);  // imposto come background
SetPenSize(0);			 // Pieno
SetTransparent(1);		 //NO disegna il quadrato attorno
DrawString(Titolo,CenterText(Titolo,2),1,2,Bianco); //scrivo il titolo centrato

HButton=((240-Ytitolo)/6)+5; //definisco l'altezza dei bottoni

//calcolo la y di poartenza dei 7 bottoni
for(c=0;c<14;c++)
{
YBotMin[c]=Ytitolo+(HButton*c)+1;
}

//calcolo la y finale dei 7 bottoni
for(c=1;c<15;c++)
{
YBotMax[c-1]=Ytitolo+(HButton*c);
}

//Disegno gli NBot bottoni	  
if(NBot>=1)DrawMyButton(B1,0,1,YBotMin[0],119,YBotMax[0],2);
if(NBot>=2)DrawMyButton(B3,0,1,YBotMin[1],119,YBotMax[1],2);
if(NBot>=3)DrawMyButton(B5,0,1,YBotMin[2],119,YBotMax[2],2);
if(NBot>=4)DrawMyButton(B7,0,1,YBotMin[3],119,YBotMax[3],2);
if(NBot>=5)DrawMyButton(B9,0,1,YBotMin[4],119,YBotMax[4],2);
if(NBot>=6)DrawMyButton(B11,0,1,YBotMin[5],119,YBotMax[5],2);
if(NBot>=7)DrawMyButton(B13,0,1,YBotMin[6],119,YBotMax[6],2);

if(NBot>=1)DrawMyButton(B2,0,120,YBotMin[0],239,YBotMax[0],2);
if(NBot>=2)DrawMyButton(B4,0,120,YBotMin[1],239,YBotMax[1],2);
if(NBot>=3)DrawMyButton(B6,0,120,YBotMin[2],239,YBotMax[2],2);
if(NBot>=4)DrawMyButton(B8,0,120,YBotMin[3],239,YBotMax[3],2);
if(NBot>=5)DrawMyButton(B10,0,120,YBotMin[4],239,YBotMax[4],2);
if(NBot>=6)DrawMyButton(B12,0,120,YBotMin[5],239,YBotMax[5],2);
if(NBot>=7)DrawMyButton(B14,0,120,YBotMin[6],239,YBotMax[6],2);



	while(!Stop)
				{
				while(('N'==TouchStatus())&&(!Stop)); //Finchè uno non schiaccia il display

										//Se uno schiaccia o scipolla il display e non è stato schiacciato Home
								if(!Stop){
			
										WaitTouchRelease(&X,&Y);
								if(X<120){
										if((NBot>=1)&&(Y>YBotMin[0])&&(Y<YBotMax[0])){DrawMyButton(B1,1,1,YBotMin[0],119,YBotMax[0],2);return 1;}
										if((NBot>=3)&&(Y>YBotMin[1])&&(Y<YBotMax[1])){DrawMyButton(B3,1,1,YBotMin[1],119,YBotMax[1],2);return 3;}
										if((NBot>=5)&&(Y>YBotMin[2])&&(Y<YBotMax[2])){DrawMyButton(B5,1,1,YBotMin[2],119,YBotMax[2],2);return 5;}
										if((NBot>=7)&&(Y>YBotMin[3])&&(Y<YBotMax[3])){DrawMyButton(B7,1,1,YBotMin[3],119,YBotMax[3],2);return 7;}
										if((NBot>=9)&&(Y>YBotMin[4])&&(Y<YBotMax[4])){DrawMyButton(B9,1,1,YBotMin[4],119,YBotMax[4],2);return 9;}
										if((NBot>=11)&&(Y>YBotMin[5])&&(Y<YBotMax[5])){DrawMyButton(B11,1,1,YBotMin[5],119,YBotMax[5],2);return 11;}
										if((NBot>=13)&&(Y>YBotMin[6])&&(Y<YBotMax[6])){DrawMyButton(B13,1,1,YBotMin[6],119,YBotMax[6],2);return 13;}
										}		

								else{
										if((NBot>=2)&&(Y>YBotMin[0])&&(Y<YBotMax[0])){DrawMyButton(B2,1,120,YBotMin[0],239,YBotMax[0],2);return 2;}
										if((NBot>=4)&&(Y>YBotMin[1])&&(Y<YBotMax[1])){DrawMyButton(B4,1,120,YBotMin[1],239,YBotMax[1],2);return 4;}
										if((NBot>=6)&&(Y>YBotMin[2])&&(Y<YBotMax[2])){DrawMyButton(B6,1,120,YBotMin[2],239,YBotMax[2],2);return 6;}
										if((NBot>=8)&&(Y>YBotMin[3])&&(Y<YBotMax[3])){DrawMyButton(B8,1,120,YBotMin[3],239,YBotMax[3],2);return 8;}
										if((NBot>=10)&&(Y>YBotMin[4])&&(Y<YBotMax[4])){DrawMyButton(B10,1,120,YBotMin[4],239,YBotMax[4],2);return 10;}
										if((NBot>=12)&&(Y>YBotMin[5])&&(Y<YBotMax[5])){DrawMyButton(B12,1,120,YBotMin[5],239,YBotMax[5],2);return 12;}
										if((NBot>=14)&&(Y>YBotMin[6])&&(Y<YBotMax[6])){DrawMyButton(B14,1,120,YBotMin[6],239,YBotMax[6],2);return 14;}
										}		


								}		
														
		}
Stop=0;
return 0;

}

//-----------------------------------------------------------------------------------------------------------------

void DrawBaseApp(char *Titolo)
{


DisplayImage("MENU",0,0);
SetBackgroundColor(Grigio);  // imposto come background
SetPenSize(0);			 // Pieno
SetTransparent(1);		 //NO disegna il quadrato attorno
DrawString(Titolo,CenterText(Titolo,2),1,2,Bianco); //scrivo il titolo centrato
SetTransparent(0);		 // disegna il quadrato attorno

return ;

}



