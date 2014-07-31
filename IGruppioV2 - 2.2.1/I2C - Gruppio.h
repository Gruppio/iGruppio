void InitI2C(int PBCK, char Module, int Baud);
int I2C2AWriteRegister(char Address,char Register,char Data);
int I2C3AReadRegister(char Address,char Register);
void IdleI2C3A(void);
int I2C2AReadTwoRegister(char Address,char Register,char Ordine);
int I2C2AWriteTwoRegister(char Address,char Register,char Data,char Data2);
int I2C2AWriteByte(char Address,char Register);




