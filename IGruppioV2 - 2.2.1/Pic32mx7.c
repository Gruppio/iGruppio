
/*															Software per I-GruppioV2 

/* ------------------------------------------------------------ */
/*				Include File Definitions	            	    */
/* ------------------------------------------------------------ */

#include <plib.h>
#include "Uart-Gruppio.h"
#include "PicasoSGC.h"
#include "I2C - Gruppio.h"
#include "Adxl345.h"
#include "ITG3200.h"
#include "HMC6352.h"
#include "MLX90614.h"
#include "Grapichs.h"
#include "Adc-Gruppio.h"
#include "IGruppioV2.h"
#include "App.h"
#include "Timer-PWM-Gruppio.h"
#include <string.h>



/* ------------------------------------------------------------ */
/*						Configuration Bits		                */
/* ------------------------------------------------------------ */
    
    #pragma config FPLLMUL  = MUL_20        // PLL Multiplier
    #pragma config FPLLIDIV = DIV_4         // PLL Input Divider
    #pragma config FPLLODIV = DIV_1         // PLL Output Divider
    #pragma config FPBDIV   = DIV_1         // Peripheral Clock divisor
    #pragma config FWDTEN   = OFF           // Watchdog Timer 
    #pragma config WDTPS    = PS1           // Watchdog Timer Postscale
    #pragma config FCKSM    = CSDCMD        // Clock Switching & Fail Safe Clock Monitor
    #pragma config OSCIOFNC = OFF           // CLKO Enable
    #pragma config POSCMOD  = HS            // Primary Oscillator
    #pragma config IESO     = OFF           // Internal/External Switch-over
    #pragma config FSOSCEN  = OFF           // Secondary Oscillator Enable
    #pragma config FNOSC    = PRIPLL        // Oscillator Selection
    #pragma config CP       = OFF           // Code Protect
    #pragma config BWP      = OFF           // Boot Flash Write Protect
    #pragma config PWP      = OFF           // Program Flash Write Protect
    #pragma config ICESEL   = ICS_PGx2      // ICE/ICD Comm Channel Select
    #pragma config DEBUG    = OFF           // Debugger Disabled for Starter Kit
            
/* ------------------------------------------------------------ */
/*				Local Type Definitions			                */
/* ------------------------------------------------------------ */



#define AnalogPin       0b1111111111011110 //solo RB0(Batt) e RB5 (Mic) Ana. ci saranno anche RB8(AN1-RX),RB9(AN2),RB10(AN3),RB14(AN0-TX).
#define TrisAInit	0
#define TrisBInit	0b0100011100100001
#define TrisCInit	0
#define TrisDInit	0b0000111100000000
#define TrisEInit	0
#define TrisFInit	0
#define TrisGInit	0b0000001010000000

#define PortAInit	0    //7654321076543210
#define PortBInit	0b0010000000000000
#define PortCInit	0
#define PortDInit	0b0000000000010000
#define PortEInit	0
#define PortFInit	0
#define PortGInit	0

/* ------------------------------------------------------------ */
/*				Function						                */
/* ------------------------------------------------------------ */

void MenuSensor();
void MenuRadio();
void MenuLight();
void MenuAcc();
void MenuGyro();
void MenuRgb();

/* ------------------------------------------------------------ */
/*				Global Variables				                */
/* ------------------------------------------------------------ */

//Variabili x le App
char Stop=0;
char *AppOpen=""; //Dice quale app sta girando
//Variabili x la Grafica
int BackgroundCol,WriteCol,Pag,NApp;
//Variabili x la seriale esterna (Usart5)
char RxBuffer[256];
//variabili x il GPS
char GPSData[256],NewGPSData=0,GPSInit=0;
int GPSDataLenght=0;

unsigned int RxIndex=0;






int main( void )
{	
char stringa[20];

AD1PCFG=AnalogPin;
TRISA=TrisAInit;
PORTA=PortAInit;
TRISB=TrisBInit;
PORTB=PortBInit;
TRISC=TrisCInit;
PORTC=PortCInit;
TRISD=TrisDInit;
PORTD=PortDInit;
TRISE=TrisEInit;
PORTE=PortEInit;
TRISF=TrisFInit;
PORTF=PortFInit;
TRISG=TrisGInit;
PORTG=PortGInit;


//InitTimer1();

Delayus(50000);
Res=1;

InitI2C(PBCLK,2,100000);  // Inizializzo l'I2CBus
InitUart(PBCLK,5,9600,8,'N');  //Inizializzo la UART esterna per l'XBee.
 INTEnable(INT_SOURCE_UART_RX(UART3A), INT_ENABLED);
  INTSetVectorPriority(INT_VECTOR_UART(UART3A), INT_PRIORITY_LEVEL_2);
  INTSetVectorSubPriority(INT_VECTOR_UART(UART3A), INT_SUB_PRIORITY_LEVEL_0);
  INTConfigureSystem(INT_SYSTEM_CONFIG_MULT_VECTOR);
  INTEnableInterrupts();

InitUart(PBCLK,4,9600,8,'N');  //Inizializzo la UART per LCD.
if(!InitAcc()){RGB1=1;RGB2=1;RGBR=0;RGBG=1;RGBB=1;}
if(!InitGyro(1,4)){RGB1=1;RGB2=1;RGBR=0;RGBG=1;RGBB=1;}
if(!InitMag()){RGB1=1;RGB2=1;RGBR=0;RGBG=1;RGBB=1;}
initADC(AnalogPin);
InitInterrupt();
Delayus(2500000);
InitLcd();

//SetNewBaudRate(0x06);

Pag=1;

while(1){	
		NApp=DrawHome(Pag); //Disegno la pagina e leggo il numero[1%9] dell'app schiacciata
		
		if(Pag==1){ //Pagina 1
					switch(NApp){
								case 0:{Pag=1;NApp='N';break;}
								case 1:{MenuSensor();NApp='N';break;}
								case 2:{MenuLight();NApp='N';break;}
								case 3:{ErrorHomeScreen("No App");NApp='N';break;}
								case 4:{ErrorHomeScreen("No App");NApp='N';break;}
								case 5:{MenuRadio();NApp='N';break;}
								case 6:{ErrorHomeScreen("No App");NApp='N';break;}
								case 7:{ErrorHomeScreen("No App");NApp='N';break;}
								case 8:{ErrorHomeScreen("No App");NApp='N';break;}
								case 9:{Pag=2;NApp='N';break;}
								}			
					} //Fine Pagina 1		

		if(Pag==2){ //Pagina 2
					switch(NApp){
								case 0:{Pag=1;NApp='N';break;}
								case 1:{ErrorHomeScreen("No App");NApp='N';break;}
								case 2:{ErrorHomeScreen("No App");NApp='N';break;}
								case 3:{GPS();NApp='N';break;}
								case 4:{ErrorHomeScreen("No App");NApp='N';break;}
								case 5:{ErrorHomeScreen("No App");NApp='N';break;}
								case 6:{ErrorHomeScreen("No App");NApp='N';break;}
								case 7:{Pag=1;NApp='N';break;}
								case 8:{ErrorHomeScreen("No App");NApp='N';break;}
								case 9:{ErrorHomeScreen("No Pag3");NApp='N';break;}
								}			
					} //Fine Pagina 2		

		}		


}


// End Main----------------------------------------------------------

void MenuSensor()
{
while(!Stop){
			NApp=DrawMenu("Sensori",6,"Accelerometer","Gyroscope","Compass","Temperature","Microphone","Temperature IR","");
			switch(NApp){
								case 0:{NApp='N';return;}
								case 1:{MenuAcc();NApp='N';break;}
								case 2:{MenuGyro();NApp='N';break;}
								case 3:{ErrorHomeScreen("No App");NApp='N';break;}
								case 4:{ErrorHomeScreen("No App");NApp='N';break;}
								case 5:{ErrorHomeScreen("No App");NApp='N';break;}
								case 6:{ErrorHomeScreen("No App");NApp='N';break;}
							//	case 7:{ErrorHomeScreen("No App");NApp='N';break;}
			}			
}
Stop=0;
return;

}

//----------------------------------------------------------------------
void MenuAcc()
{
while(!Stop){
			NApp=DrawMenu14("Accelerometer",14,"Axies","FreeFall","Angle","D","E","F","G","A","B","C","D","E","F","G");
			switch(NApp){
								case 0:{NApp='N';return;}
								case 1:{AccAxies();NApp='N';break;}
								case 2:{FreeFall();NApp='N';break;}
								case 3:{Angle();NApp='N';break;}
								case 4:{ErrorHomeScreen("No App");NApp='N';break;}
								case 5:{ErrorHomeScreen("No App");NApp='N';break;}
								case 6:{ErrorHomeScreen("No App");NApp='N';break;}
								case 7:{ErrorHomeScreen("No App");NApp='N';break;}
								case 8:{ErrorHomeScreen("No App");NApp='N';break;}
								case 9:{ErrorHomeScreen("No App");NApp='N';break;}
								case 10:{ErrorHomeScreen("No App");NApp='N';break;}
								case 11:{ErrorHomeScreen("No App");NApp='N';break;}
								case 12:{ErrorHomeScreen("No App");NApp='N';break;}
								case 13:{ErrorHomeScreen("No App");NApp='N';break;}
								case 14:{ErrorHomeScreen("No App");NApp='N';break;}
			}			
}
Stop=0;
return;

}

//-----------------------------------------------------------------------
void MenuLight()
{
while(!Stop){
			NApp=DrawMenu("Light",6,"RGB","Ambilight","UV","Acc RGB","Gyro RGB","Compass RGB","");
			switch(NApp){
								case 0:{NApp='N';return;}
								case 1:{MenuRgb();NApp='N';break;}
								case 2:{ErrorHomeScreen("No App");NApp='N';break;}
								case 3:{ErrorHomeScreen("No App");NApp='N';break;}
								case 4:{ErrorHomeScreen("No App");NApp='N';break;}
								case 5:{ErrorHomeScreen("No App");NApp='N';break;}
								case 6:{ErrorHomeScreen("No App");NApp='N';break;}
							//	case 7:{ErrorHomeScreen("No App");NApp='N';break;}
			}			
}
Stop=0;
return;

}


//-----------------------------------------------------------------------
void MenuRgb()
{
NApp=0;
while(!Stop){
			NApp=DrawMenuSelector("RGB",7,"Off","Red","Green","Blue","Yellow","Pourple","White",NApp);
						
							
							switch(NApp){
								
								case 0:{RGB1=0;RGB2=0;RGBR=1;RGBG=1;RGBB=1;NApp='N';return;}
								case 1:{RGB1=0;RGB2=0;RGBR=1;RGBG=1;RGBB=1;break;}
								case 2:{RGB1=1;RGB2=1;RGBR=0;RGBG=1;RGBB=1;break;}
								case 3:{RGB1=1;RGB2=1;RGBR=1;RGBG=0;RGBB=1;break;}
								case 4:{RGB1=1;RGB2=1;RGBR=1;RGBG=1;RGBB=0;break;}
								case 5:{RGB1=1;RGB2=1;RGBR=0;RGBG=0;RGBB=1;break;}
								case 6:{RGB1=1;RGB2=1;RGBR=0;RGBG=1;RGBB=0;break;}
								case 7:{RGB1=1;RGB2=1;RGBR=0;RGBG=0;RGBB=0;break;}
									
			}			
}
RGB1=0;RGB2=0;RGBR=1;RGBG=1;RGBB=1;
Stop=0;
return;

}

//-----------------------------------------------------------------------
void MenuRadio()
{
while(!Stop){
			NApp=DrawMenu("Radio",2,"Seg-One","Quadricopter","","","","","");
			switch(NApp){
								case 0:{NApp='N';return;}
								case 1:{ErrorHomeScreen("No App");NApp='N';break;}
								case 2:{ErrorHomeScreen("No App");NApp='N';break;}
							//	case 3:{ErrorHomeScreen("No App");NApp='N';break;}
							//	case 4:{ErrorHomeScreen("No App");NApp='N';break;}
							//	case 5:{ErrorHomeScreen("No App");NApp='N';break;}
							//	case 6:{ErrorHomeScreen("No App");NApp='N';break;}
							//	case 7:{ErrorHomeScreen("No App");NApp='N';break;}
			}			
}
Stop=0;
return;

}
//-----------------------------------------------------------------------
void MenuGyro()
{
while(!Stop){
			NApp=DrawMenu("Gyroscope",1,"Rotation Velocity","","","","","","");
			switch(NApp){
								case 0:{NApp='N';return;}
								case 1:{GyroAxies();NApp='N';break;}
							//	case 2:{ErrorHomeScreen("No App");NApp='N';break;}
							//	case 3:{ErrorHomeScreen("No App");NApp='N';break;}
							//	case 4:{ErrorHomeScreen("No App");NApp='N';break;}
							//	case 5:{ErrorHomeScreen("No App");NApp='N';break;}
							//	case 6:{ErrorHomeScreen("No App");NApp='N';break;}
							//	case 7:{ErrorHomeScreen("No App");NApp='N';break;}
			}			
}
Stop=0;
return;

}
//-----------------------------------------------------------------------


//-----------------------------------------------------------------------

void __ISR(_EXTERNAL_1_VECTOR, ipl1) HomeHandler(void)
{
    // clear the interrupt flag
	Delayus(500000);
    mINT1ClearIntFlag();
	Stop=1;
}


/******************************************************************************/
/*  Routine di servizio delle interrupt dell' UART 6                          */
/******************************************************************************/
void __ISR(_UART_3A_VECTOR, ipl2) IntUart3AHandler(void)
{

   // Controlla che tipo di interrupt e'
   if(INTGetFlag(INT_SOURCE_UART_RX(UART3A)))
   {
       int c=0;
       LedG=1;
      // Clear the RX interrupt Flag
      INTClearFlag(INT_SOURCE_UART_RX(UART3A));
     // IFS1bits.U3ARXIF = 0;   // azzera Receive interrupt flag

   //   RxBuffer[RxIndex]=uart5_read_char();

       RxBuffer[0]=uart5_read_char();



  /*    if(RxBuffer[RxIndex]=='$'){
          RxIndex++;
          for(c=0;c<=(RxIndex-1);c++){GPSData[c]=RxBuffer[c];}

          GPSDataLenght=(RxIndex-1);
          RxIndex=0;
          RxBuffer[0]='$';
          NewGPSData=1;

                            } */

            if(RxIndex<254)RxIndex++;
            else RxIndex=0;
            NewGPSData=1;

   }

   if ( INTGetFlag(INT_SOURCE_UART_TX(UART3A)) )
   {
      // Clear the TX interrupt Flag
      INTClearFlag(INT_SOURCE_UART_TX(UART3A));
      //IFS1bits.U3ATXIF = 0;   // azzera Transmit interrupt flag (bit 11)

      /**********************************************************/
      /* Codice per la gestione dell' interrupt di trasmissione */
      /**********************************************************/

   }
   LedG=0;
}


