#include <p32xxxx.h>
#include <plib.h>
#include "Timer-PWM-Gruppio.h"

float InitTimerAType(int PBCK, char Module, int Freq,char Interruppt)
{
  unsigned int Pr;
  unsigned int con;
  unsigned int sta;
  char errore;
  unsigned int Pre;
  
  	if((PBCK/65535)<Freq) Pre=1;
	else if(((PBCK/8)/65535)<Freq) Pre=8;
	     else if(((PBCK/64)/65535)<Freq) Pre=64;
		 	  else Pre=256;

  
	Pr = (Freq/(Pre*PBCK)) -1;  
                       
  	con = 0;  // Resetto il modulo
  	sta = 0;

    switch (Module)
  {
    case 1: {T1CON = con; break;}
    case 2: {T2CON = con; break;}
    case 3: {T3CON = con; break;}
    case 4: {T4CON = con; break;}
    case 5: {T5CON = con; break;}
  }
  // abilita il modulo settando il bit ON (15) di mode*
  con |= 0x00008000;
  
  // in base al modulo selezionato assegna i valori
  switch (Module)
  {
    case 1: I2C1ABRG = 0; I2C1ASTAT = sta; I2C1ACON = con; break;
    case 2: I2C2ABRG = 0; I2C2ASTAT= sta; I2C2ACON = con; break;
    case 3: I2C3ABRG = 0; I2C3ASTAT = sta; I2C3ACON = con; break;
  }
}

