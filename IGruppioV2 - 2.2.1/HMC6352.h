#define	Mag 		0x42
#define	WriteEEPROM	0x77
#define	ReadEEPROM	0x72
#define	WriteRAM	0x47
#define	ReadRAM		0x67
#define SR			0x4F
#define	EnterCalibration 0x43
#define	ExitCalibration 0x45
#define	SaveOpMode	0x4C
#define GetData		0x41


int InitMag();
int ReadHeading();
int EnterCalibrationMode();
int ExitCalibrationMode();




