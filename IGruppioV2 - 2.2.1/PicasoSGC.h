
#include <p32xxxx.h>
// 4DGL Functions values
#define AUTOBAUD     0x55
#define CLS          0x45
#define BAUDRATE     0x51
#define VERSION      0x56
#define BCKGDCOLOR   0x42
#define DISPCONTROL  0x59
#define SETVOLUME    0x76
#define CIRCLE       0x43
#define TRIANGLE     0x47
#define LINE         0x4C
#define RECTANGLE    0x72
#define ELLIPSE      0x65
#define PIXEL        0x50
#define READPIXEL    0x52
#define SCREENCOPY   0x63
#define PENSIZE      0x70
#define SETFONT      0x46
#define TEXTMODE     0x4F
#define TEXTCHAR     0x54
#define GRAPHCHAR    0x74
#define TEXTSTRING   0x73
#define GRAPHSTRING  0x53
#define TEXTBUTTON   0x62
#define GETTOUCH     0x6F
#define WAITTOUCH    0x77
#define SETTOUCH     0x75


// Screen answers
#define ACK          0x06
#define NAK          0x15

// Screen states


// Graphics modes
#define SOLID        0x00
#define WIREFRAME    0x01

// Text modes
#define TRANSPARENT  0x00
#define OPAQUE       0x01

// Fonts Sizes
#define FONT_5X7     0x00
#define FONT_8X8     0x01
#define FONT_8X12    0x02
#define FONT_12X16   0x03

// Touch Values
#define WAIT         0x00
#define PRESS        0x01
#define RELEASE      0x02
#define MOVE         0x03
#define STATUS       0x04
#define GETPOSITION  0x05

// Data speed
#define BAUD_110     0x00
#define BAUD_300     0x01
#define BAUD_600     0x02
#define BAUD_1200    0x03
#define BAUD_2400    0x04
#define BAUD_4800    0x05
#define BAUD_9600    0x06
#define BAUD_14400   0x07
#define BAUD_19200   0x09
#define BAUD_31250   0x09
#define BAUD_38400   0x0A
#define BAUD_56000   0x0B
#define BAUD_57600   0x0C
#define BAUD_115200  0x0D
#define BAUD_128000  0x0E
#define BAUD_256000  0x0F

// Defined Colors
#define WHITE 0xFFFFFF
#define BLACK 0x000000
#define RED   0xFF0000
#define GREEN 0x00FF00
#define BLUE  0x0000FF
#define LGREY 0xBFBFBF
#define DGREY 0x5F5F5F

#define Blu  0b0000000000011111
#define Grigio 0xCEBA
#define Nero 0
#define Bianco 0xFFFF



// Mode data
#define BACKLIGHT    0x00
#define DISPLAY      0x01
#define CONTRAST     0x02
#define POWER        0x03
#define ORIENTATION  0x04
#define TOUCH_CTRL   0x05
#define IMAGE_FORMAT 0x06
#define PROTECT_FAT  0x08

// change this to your specific screen (newer versions) if needed
// Startup orientation is PORTRAIT so SIZE_X must be lesser than SIZE_Y
#define SIZE_X       240
#define SIZE_Y       320

#define IS_LANDSCAPE 0
#define IS_PORTRAIT  1

// Screen orientation
#define LANDSCAPE    0x01
#define LANDSCAPE_R  0x02
#define PORTRAIT     0x03
#define PORTRAIT_R   0x04

// Parameters
#define ENABLE       0x00
#define DISABLE      0x01
#define RESET        0x02

#define NEW          0x00
#define OLD          0x01

#define DOWN         0x00
#define UP           0x01

#define PROTECT      0x00
#define UNPROTECT    0x02


#define	Res		PORTBbits.RB2
#define	LedV	PORTCbits.RC13
#define	LedG	PORTCbits.RC14
#define	LedR	PORTDbits.RD5

#define Ytitolo 34

void Lcd_putc(char c);
void Lcd_putI(int i);
char Lcd_getc();
void AutoBaud();
void SetNewBaudRate(char Rate);
void ReplaceBackgroundColor(int Color);
void ClearScreen();
void DisplayControl(char mode,char value);
void SetVolume(char Rate);
void DrawCircle(int x,int y,int raggio,int Color);
void SetBackgroundColor(int Color);
void DrawLine(int x1,int y1,int x2,int y2,int Color);
void DrawTriangle(int x1,int y1,int x2,int y2,int x3,int y3,int Color);
void DrawRectangle(int x1,int y1,int x2,int y2,int Color);
void DrawEllipse(int x1,int y1,int rx,int ry,int Color);
void PutPixel(int x1,int y1,int Color);
void ReplaceColor(int x1,int y1,int x2,int y2,int Color,int ColorNew);
void InitLcd();
void InitSD();
void DisplayImage(char *s,int x,int y);
void SetPenSize(char Size);
void SetTransparent(char Size);
void SetFont(char Size);
void DrawCh(char ch,char Col,char Rig,int Color);
void PlayAudio(char *s,char option);
void DrawChBig(char ch,int x,int y,int Color,char Largh,char Alt);
void DrawString(char *s,char Col,char Rig,char font,int Color);
void DrawStringBig(char *s,int x,int y,char font,int Color,char Largh,char Alt);
void DrawButton(char *s,char state,int x,int y,char font,int ButtonColor,int StringColor,char Largh,char Alt);
void ReadTouch(char mode,int *x1,int *y1);
void WaitUntilTouch(int Time);
void DetectTouchRegion(int x1,int y1,int x2,int y2);
int  ReadPixel(int x1,int y1);
void WaitTouchActivity(int *x1,int *y1);
char TouchStatus();
void WaitTouchPress(int *x1,int *y1);
void WaitTouchRelease(int *x1,int *y1);
void WaitTouchMoving(int *x1,int *y1);
void GetTouchCoordinates(int *x1,int *y1);
int CenterText(char *s,char font);
void DrawMyButton(char *s,char Schiacciato,int x,int y,int x2,int y2,char font);








