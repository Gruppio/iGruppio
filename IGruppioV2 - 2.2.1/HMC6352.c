#include "I2C - Gruppio.h"
#include <p32xxxx.h>
#include <plib.h>
#include "HMC6352.h"

int InitMag()
{
	int Risposta;
	unsigned char ID=0;

	ID=I2C2AReadRegister(Mag,0x00);
	if(ID!=0x42) return -1;	//Mag not find

	Risposta=0;
	Risposta=I2C2AWriteTwoRegister(Mag,0x47,0x47,0b01110000); //Write Op Mode to Ram
	if(Risposta<0) return -2;

	Risposta=0;
	Risposta=I2C2AWriteTwoRegister(Mag,0x77,0x08,0b01110000); //Write Op Mode to EEPROM
	if(Risposta<0) return -3;	

;

//Delay di 22ms
return 1;
}

//--------------------------------------------------------------------------
int ReadHeading()
{
	int Risposta;
	
	Risposta=I2C2AReadTwoRegister(Mag,0x41,'>'); 
	return Risposta/10;
}

//--------------------------------------------------------------------------

int EnterCalibrationMode()
{
	int Risposta;
	
	Risposta=0;
	Risposta=I2C2AWriteByte(Mag,0x43); //Write 
	if(Risposta<0) return -1;	
	return 1;
}

//--------------------------------------------------------------------------

int ExitCalibrationMode()
{
	int Risposta;
	
	Risposta=0;
	Risposta=I2C2AWriteByte(Mag,0x45); //Write 
	if(Risposta<0) return -1;	
	return 1;
}
