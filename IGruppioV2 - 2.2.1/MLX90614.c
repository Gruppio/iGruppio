#include "I2C - Gruppio.h"
#include <p32xxxx.h>
#include <plib.h>
#include "MLX90614.h"



//--------------------------------------------------------------------------
int ReadIRTemp()
{
	int Risposta;
	
//	Risposta=I2C2AReadTwoRegister(0x00,0x07,'<'); 
	char AddressW,AddressR,Register,Ordine;
	int DataR[3];
	int Risultato=0;

	AddressW=0;
	AddressR=0x01;
	Register=0x07;
	Ordine='<';

	IdleI2C2A();

 	I2CStart(I2C2A);
	IdleI2C2A();

    if(I2CSendByte(I2C2A, AddressW))return -1;
	while(!I2CTransmissionHasCompleted(I2C2A));

    if(!I2CByteWasAcknowledged(I2C2A))return -2;

	if(I2CSendByte(I2C2A, Register))return -3;
 	while(!I2CTransmissionHasCompleted(I2C2A));

    if(!I2CByteWasAcknowledged(I2C2A))return -4;
  


//IdleI2C2A();
//I2CStop(I2C2A); //Facoltativo
IdleI2C2A();



   	I2CRepeatStart(I2C2A);
	IdleI2C2A();

	if(I2CSendByte(I2C2A, AddressR))return -5;
	while(!I2CTransmissionHasCompleted(I2C2A));

    if(!I2CByteWasAcknowledged(I2C2A))return -6;

	I2CReceiverEnable(I2C2A, TRUE);
	while(!I2C2ASTATbits.RBF);

   DataR[0] = I2CGetByte(I2C2A);

//Leggo il 2 Registro

    I2CAcknowledgeByte(I2C2A, TRUE);
	IdleI2C2A();

	I2CReceiverEnable(I2C2A, TRUE);
	while(!I2C2ASTATbits.RBF);

	DataR[1] = I2CGetByte(I2C2A);

//Leggo il 2 Registro

    I2CAcknowledgeByte(I2C2A, TRUE);
	IdleI2C2A();

	I2CReceiverEnable(I2C2A, TRUE);
	while(!I2C2ASTATbits.RBF);

	DataR[2] = I2CGetByte(I2C2A);


   I2CAcknowledgeByte(I2C2A, FALSE);
   I2CStop(I2C2A);

	if((Ordine==0) || (Ordine=='<'))	{Risultato=((DataR[1]<<8)|(DataR[0]));}
	else {Risultato=((DataR[0]<<8)|(DataR[1]));}

return Risultato;
}

