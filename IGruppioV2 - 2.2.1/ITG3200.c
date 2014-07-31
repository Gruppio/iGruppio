#include "I2C - Gruppio.h"
#include <p32xxxx.h>
#include <plib.h>
#include "ITG3200.h"

int InitGyro(char Filtro,char Sample)
{
	int Risposta;
	unsigned char ID=0;

	ID=I2C2AReadRegister(Gyro,0x00);
	if(ID!=0x69) return -1;	//Gyro not found

	Risposta=0;
	Risposta=I2C2AWriteRegister(Gyro,0x3E,0x80); //Reset
	if(Risposta<0) return -2;

	Risposta=0;
	Risposta=I2C2AWriteRegister(Gyro,SampleRateDivider,Sample); //4 campioni
	if(Risposta<0) return -3;

	Risposta=0;

	if(Filtro==0)	Risposta=I2C2AWriteRegister(Gyro,DLPF,0b00011000); //256Hz
	if(Filtro==1)	Risposta=I2C2AWriteRegister(Gyro,DLPF,0b00011001); //188Hz
	if(Filtro==2)	Risposta=I2C2AWriteRegister(Gyro,DLPF,0b00011010); //98Hz
	if(Filtro==3)	Risposta=I2C2AWriteRegister(Gyro,DLPF,0b00011011); //42Hz
	if(Filtro==4)	Risposta=I2C2AWriteRegister(Gyro,DLPF,0b00011100); //20Hz
	if(Filtro==5)	Risposta=I2C2AWriteRegister(Gyro,DLPF,0b00011101); //10Hz
	if(Filtro==6)	Risposta=I2C2AWriteRegister(Gyro,DLPF,0b00011110); //5Hz

	if(Filtro>6) return -6;

	if(Risposta<0) return -4;	

	Risposta=0;
	Risposta=I2C2AWriteRegister(Gyro,0x3E,0); //En
	if(Risposta<0) return -5;

return 1;
}

//--------------------------------------------------------------------------
int ReadRegGyroY()//Che in realtà è l'asse x dell'acc
{
	int Risposta;
	
	Risposta=I2C2AReadTwoRegister(Gyro,31,'>'); 
	return Risposta;
}

//--------------------------------------------------------------------------
int ReadRegGyroX()//Che in realtà è l'asse y dell'acc
{
	int Risposta;
	
	Risposta=I2C2AReadTwoRegister(Gyro,29,'>'); 
	return Risposta;
}

//--------------------------------------------------------------------------
int ReadRegGyroZ()//Che in realtà è l'asse Z dell'acc
{
	int Risposta;
	
	Risposta=I2C2AReadTwoRegister(Gyro,33,'>'); 
	return Risposta;
}

//----------------------------------------------------------------
float ReadWY()
{
	float Risultato=0;

	Risultato=ReadRegGyroY();
	if(Risultato>32768)Risultato=Risultato-65535;//Se è negativo
	Risultato=Risultato/ResolutionGyro;
	return Risultato;
}

//----------------------------------------------------------------
float ReadWX()
{
	float Risultato=0;

	Risultato=ReadRegGyroX();
	if(Risultato>32768)Risultato=Risultato-65535;//Se è negativo
	Risultato=Risultato/ResolutionGyro;
	return Risultato;
}

//----------------------------------------------------------------
float ReadWZ()
{
	float Risultato=0;

	Risultato=ReadRegGyroZ();
	if(Risultato>32768)Risultato=Risultato-65535;//Se è negativo
	Risultato=Risultato/ResolutionGyro;
	return Risultato;
}
//----------------------------------------------------------------
float ReadTemp()
{
	int Risposta;
	float Tempe=0;
	
	Risposta=I2C2AReadTwoRegister(Gyro,27,'>'); 
	if(Risposta>32768)Risposta=Risposta-65535;
	Tempe=(Risposta + 23000);
	Tempe=Tempe/280;
	return Tempe;
}

