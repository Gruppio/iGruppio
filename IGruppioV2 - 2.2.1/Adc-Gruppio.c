#include "Adc-Gruppio.h"
#include <p32xxxx.h>
#include <plib.h>



//----------------------------------------------------------------------------
void initADC( int amask)// 0 ana, 1 digi
{
AD1PCFG = amask; // select analog input pins
//			FEDCBA9876543210FEDCBA9876543210
AD1CON1 = 0b00000000000000000000000011100000; // manual conversion sequence control
AD1CSSL = 0; // no scanning required
AD1CON2 = 0; // use MUXA, AVss/AVdd used as Vref+/-
AD1CON3=0x1F3F; // Tad=2+1) x 2 x Tpb=6x27 ns>75 ns
AD1CON1bits.ADON=1; // turn on the ADC
} //initADC




//------------------------------------------------------------------------------
int readADC(int ch)
{
AD1CHSbits.CH0SA = ch; // 1. select input channel
AD1CON1bits.SAMP = 1; // 2. start sampling
while (!AD1CON1bits.DONE); // 3. wait conversion complete
return ADC1BUF0; // 4. read conversion result
} // readADC


