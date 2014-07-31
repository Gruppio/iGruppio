#include "I2C - Gruppio.h"
#include <p32xxxx.h>
#include <plib.h>



void InitI2C(int PBCK, char Module, int Baud)
{
  unsigned int brg;
  unsigned int con;
  unsigned int sta;
  char errore;
  
  brg = PBCK/(2 * Baud) -2;  // calcola il valore in base alla velocita'
                                   // ed alla frequenza di cloc delle periferiche
                                   
  con = 0;  // stato iniziale dopo il reset
  sta = 0;

  
  // abilita il modulo settando il bit ON (15) di mode
  con |= 0x00008000;
  
  // in base al modulo selezionato assegna i valori
  switch (Module)
  {
    case 1: I2C1ABRG = brg; I2C1ASTAT = sta; I2C1ACON = con; break;
    case 2: I2C2ABRG = brg; I2C2ASTAT= sta; I2C2ACON = con; break;
    case 3: I2C3ABRG = brg; I2C3ASTAT = sta; I2C3ACON = con; break;
  }
}

//----------------------------------------------------------------------

void IdleI2C2A(void)
{
    // Wait until I2C Bus is Inactive 
    while(I2C2ACONbits.SEN | I2C2ACONbits.PEN | I2C2ACONbits.RSEN | I2C2ACONbits.RCEN | I2C2ACONbits.ACKEN | I2C2ASTATbits.TRSTAT);
}

//--------------------------------------------------------------
int I2C2AReadRegister(char Address,char Register)
{
	char AddressW,AddressR;
	int DataR;

	AddressW=Address;
	AddressR=Address+1;

	IdleI2C2A();

 	I2CStart(I2C2A);
	IdleI2C2A();

    if(I2CSendByte(I2C2A, AddressW))return -1;
	while(!I2CTransmissionHasCompleted(I2C2A));

    if(!I2CByteWasAcknowledged(I2C2A))return -2;

	if(I2CSendByte(I2C2A, Register))return -3;
 	while(!I2CTransmissionHasCompleted(I2C2A));

    if(!I2CByteWasAcknowledged(I2C2A))return -4;
  
// facoltativo

IdleI2C2A();
//I2CStop(I2C2A); //Facoltativo
//IdleI2C2A();



   	I2CRepeatStart(I2C2A);
	IdleI2C2A();

	if(I2CSendByte(I2C2A, AddressR))return -5;
	while(!I2CTransmissionHasCompleted(I2C2A));

    if(!I2CByteWasAcknowledged(I2C2A))return -6;

	I2CReceiverEnable(I2C2A, TRUE);
	while(!I2C2ASTATbits.RBF);

   DataR = I2CGetByte(I2C2A);

   I2CAcknowledgeByte(I2C2A, FALSE);
   I2CStop(I2C2A);

return DataR;
}
	

//--------------------------------------------------------------
/*Questa Funzione legge 2 registri e restituisce un INT che è Reg[0]<<8+Reg[1] Se ordine è 1,Reg[1]<<8+Reg[0] se ordine è 0 */

int I2C2AReadTwoRegister(char Address,char Register,char Ordine)
{
	char AddressW,AddressR;
	int DataR[2];
	int Risultato=0;

	AddressW=Address;
	AddressR=Address+1;

	IdleI2C2A();

 	I2CStart(I2C2A);
	IdleI2C2A();

    if(I2CSendByte(I2C2A, AddressW))return -1;
	while(!I2CTransmissionHasCompleted(I2C2A));

    if(!I2CByteWasAcknowledged(I2C2A))return -2;

	if(I2CSendByte(I2C2A, Register))return -3;
 	while(!I2CTransmissionHasCompleted(I2C2A));

    if(!I2CByteWasAcknowledged(I2C2A))return -4;
  


IdleI2C2A();
I2CStop(I2C2A); //Facoltativo
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

   I2CAcknowledgeByte(I2C2A, FALSE);
   I2CStop(I2C2A);

	if((Ordine==0) || (Ordine=='<'))	{Risultato=((DataR[1]<<8)|(DataR[0]));}
	else {Risultato=((DataR[0]<<8)|(DataR[1]));}

return Risultato;
}


//----------------------------------------------------------------------------------------------------

int I2C2AWriteRegister(char Address,char Register,char Data)
{
	char AddressW;

	
	AddressW=Address;
	
	IdleI2C2A();

 	I2CStart(I2C2A);
	IdleI2C2A();

    if(I2CSendByte(I2C2A, AddressW))return -1;
	while(!I2CTransmissionHasCompleted(I2C2A));

    if(!I2CByteWasAcknowledged(I2C2A))return -2;

	if(I2CSendByte(I2C2A, Register))return -3;
 	while(!I2CTransmissionHasCompleted(I2C2A));

    if(!I2CByteWasAcknowledged(I2C2A))return -4;

	if(I2CSendByte(I2C2A, Data))return -5;
 	while(!I2CTransmissionHasCompleted(I2C2A));

    if(!I2CByteWasAcknowledged(I2C2A))return -6;


   IdleI2C2A();
   I2CStop(I2C2A);

return 1;
}

//----------------------------------------------------------------------------------------------------

int I2C2AWriteTwoRegister(char Address,char Register,char Data,char Data2)
{
	char AddressW;

	
	AddressW=Address;
	
	IdleI2C2A();

 	I2CStart(I2C2A);
	IdleI2C2A();

    if(I2CSendByte(I2C2A, AddressW))return -1;
	while(!I2CTransmissionHasCompleted(I2C2A));

    if(!I2CByteWasAcknowledged(I2C2A))return -2;

	if(I2CSendByte(I2C2A, Register))return -3;
 	while(!I2CTransmissionHasCompleted(I2C2A));

    if(!I2CByteWasAcknowledged(I2C2A))return -4;

	if(I2CSendByte(I2C2A, Data))return -5;
 	while(!I2CTransmissionHasCompleted(I2C2A));

    if(!I2CByteWasAcknowledged(I2C2A))return -6;

	if(I2CSendByte(I2C2A, Data2))return -7;
 	while(!I2CTransmissionHasCompleted(I2C2A));

    if(!I2CByteWasAcknowledged(I2C2A))return -8;


   IdleI2C2A();
   I2CStop(I2C2A);

return 1;
}

//----------------------------------------------------------------------------------------------------



int I2C2AWriteByte(char Address,char Register)
{
	char AddressW;

	
	AddressW=Address;
	
	IdleI2C2A();

 	I2CStart(I2C2A);
	IdleI2C2A();

    if(I2CSendByte(I2C2A, AddressW))return -1;
	while(!I2CTransmissionHasCompleted(I2C2A));

    if(!I2CByteWasAcknowledged(I2C2A))return -2;

	if(I2CSendByte(I2C2A, Register))return -3;
 	while(!I2CTransmissionHasCompleted(I2C2A));

    if(!I2CByteWasAcknowledged(I2C2A))return -4;

   IdleI2C2A();
   I2CStop(I2C2A);

return 1;
}

//--------------------------------------------------------------
