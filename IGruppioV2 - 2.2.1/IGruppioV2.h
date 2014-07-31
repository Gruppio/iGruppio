void InitTimer1();
void Delayus(long Time);
void ErrorHomeScreen (char *Str);
void InitInterrupt();
float VoltageBatt();



#define	LedV	PORTCbits.RC13
#define	LedG	PORTCbits.RC14
#define	LedR	PORTDbits.RD5
#define	RGB1	PORTBbits.RB15
#define	RGB2	PORTDbits.RD6
#define	RGBR	PORTDbits.RD1
#define	RGBG	PORTDbits.RD2
#define	RGBB	PORTDbits.RD3
#define	LedUV	PORTBbits.RB1	
#define	En38K	PORTDbits.RD0
#define	LedLcd	PORTDbits.RD4
#define	Home	PORTDbits.RD8
#define	Res		PORTBbits.RB2
#define	Wp		PORTBbits.RB12

#define PRESCALE       		256
#define T1_TICK       		(PBCLK/PRESCALE/INT_PER_SEC)
#define INT_PER_SEC			1   //Freq di cntrl


#define SYSCLK			(80000000)
#define PBCLK       	(SYSCLK/1)

#define DESIRED_BAUDRATE    	(9600)      //The desired BaudRate

// calculate actual BAUD generate value.
#define BAUD_VALUE 	((PBCLK/16/DESIRED_BAUDRATE)-1)





