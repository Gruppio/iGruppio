#define	Acc 		0x3A
#define	Power_Ctl	0x2D
#define	Data_Format	0x31
#define	Bw_Rate		0x2C

#define Resolution 4/1000;

int InitAcc();
int ReadRegX();
int ReadRegY();
int ReadRegZ();
float ReadAccX();
float ReadAccY();
float ReadAccZ();
float ReadAccTotal();
float ReadAngleX();
float ReadAngleY();
float ReadAngleZ();

