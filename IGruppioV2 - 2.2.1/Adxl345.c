#include "I2C - Gruppio.h"
#include <p32xxxx.h>
#include <plib.h>
#include "Adxl345.h"

int InitAcc()
{
	int Risposta;
	unsigned char ID=0;

	ID=I2C2AReadRegister(Acc,0x00);
	if(ID!=0xE5) return -1;	//Acc not find

	Risposta=0;
	Risposta=I2C2AWriteRegister(Acc,Power_Ctl,0);
	if(Risposta<0) return -2;	

	Risposta=0;
	Risposta=I2C2AWriteRegister(Acc,Data_Format,0x0B); //+-16g ; mettere 0x81 per +-4g
	if(Risposta<0) return -3;

	Risposta=0;
	Risposta=I2C2AWriteRegister(Acc,Bw_Rate,0x0F); //3200 HZ Measurement mode
	if(Risposta<0) return -4;	

	Risposta=0;
	Risposta=I2C2AWriteRegister(Acc,Power_Ctl,0b00001000); //Accendo il ciapino
	if(Risposta<0) return -5;

//Delay di 22ms
return 1;
}

//--------------------------------------------------------------------------
int ReadRegY()//Che in realtà è l'asse x dell'acc
{
	int Risposta;
	
	Risposta=I2C2AReadTwoRegister(Acc,0x32,'<'); 
	return Risposta;
}

//--------------------------------------------------------------------------
int ReadRegX()//Che in realtà è l'asse y dell'acc
{
	int Risposta;
	
	Risposta=I2C2AReadTwoRegister(Acc,0x34,'<'); 
	return Risposta;
}

//--------------------------------------------------------------------------
int ReadRegZ()//Che in realtà è l'asse Z dell'acc
{
	int Risposta;
	
	Risposta=I2C2AReadTwoRegister(Acc,0x36,'<'); 
	return Risposta;
}

//----------------------------------------------------------------
float ReadAccY()
{
	float Risultato=0;

	Risultato=ReadRegY();
	if(Risultato>32768)Risultato=Risultato-65535;//Se è negativo
	Risultato=Risultato*Resolution;
	return Risultato;
}

//----------------------------------------------------------------
float ReadAccX()
{
	float Risultato=0;

	Risultato=ReadRegX();
	if(Risultato>32768)Risultato=Risultato-65535;//Se è negativo
	Risultato=Risultato*Resolution;
	return Risultato;
}

//----------------------------------------------------------------
float ReadAccZ()
{
	float Risultato=0;

	Risultato=ReadRegZ();
	if(Risultato>32768)Risultato=Risultato-65535;//Se è negativo
	Risultato=Risultato*Resolution;
	return Risultato;
}

//----------------------------------------------------------------
float ReadAccTotal()
{
	float Risultato=0;
	float AcX,AcY,AcZ;

	AcX=ReadAccX(); //leggo le Acc
	AcY=ReadAccY();
	AcZ=ReadAccZ();

	AcX=AcX*AcX; //Elevo al quadrato
	AcY=AcY*AcY;
	AcZ=AcZ*AcZ;

	Risultato=AcX+AcY+AcZ;
	Risultato=sqrtf(Risultato);
	return Risultato;
}

//----------------------------------------------------------------
float ReadAngleX()
{
	float Risultato=0;
	float AcX,AcT;

	AcX=ReadAccX(); //leggo le Acc
	AcT=ReadAccTotal();

	AcX=AcX/AcT; //Normalizzo
	
	if(AcX>=1) return 90;
	if(AcX<=-1) return -90;

	Risultato=asinf(AcX);
	Risultato=Risultato*57,29577951; //*180 /pi
	return Risultato;
}

//----------------------------------------------------------------
float ReadAngleY()
{
	float Risultato=0;
	float AcY,AcT;

	AcY=ReadAccY(); //leggo le Acc
	AcT=ReadAccTotal();

	AcY=AcY/AcT; //Normalizzo
	
	if(AcY>=1) return 90;
	if(AcY<=-1) return -90;

	Risultato=asinf(AcY);
	Risultato=Risultato*57,29577951; //*180 /pi
	return Risultato;
}

//----------------------------------------------------------------
float ReadAngleZ()
{
	float Risultato=0;
	float AcZ,AcT;

	AcZ=-ReadAccZ(); //leggo le Acc
	AcT=ReadAccTotal();

	AcZ=AcZ/AcT; //Normalizzo
	
	if(AcZ>=1) return 90;
	if(AcZ<=-1) return -90;

	Risultato=asinf(AcZ);
	Risultato=Risultato*57,29577951; //*180 /pi
	return Risultato;
}


