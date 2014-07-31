#define	Gyro 		0xD0
#define	SampleRateDivider	0x15
#define	DLPF	0x16

#define ResolutionGyro 14,375; //valore del registro/ Resolution = Gradi/sec equivale a LSB/gradi/sec 


int InitGyro(char Filtro,char Sample);
int ReadRegGyroX();
int ReadRegGyroY();
int ReadRegGyroZ();
float ReadTemp();
float ReadWX();
float ReadWY();
float ReadWZ();


