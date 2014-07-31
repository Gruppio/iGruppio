/*
Libreria in C32 per Pic 32mx7 che si occupa del modulo UART.
*/

/******************************************************************************/
/*                                                                  */
/*      Inizializza l' UART con i parametri di base:                          */  
/*      per_clk preripheral clock in Hz.                                      */
/*      modulo  numero del modulo da inizializzare  1="1A", 2="1B", 3="2A",   */
/*              4="2B", 5="3A", 6="3B"                                        */
/*      baud    velocita' espressa in baud                                    */
/*      nbits   numero di bits 8 o 9                                          */
/*      parita "N" nessuna, "O" odd, "E" even                                 */
/*                                                                            */
/*      ritorna 0 se non ci sono errori                                       */
/*              1 se nbit e parita non sono OK                                */  
/*              2 se il numero del modulo e' sbagliato                        */
/******************************************************************************/

#include "Uart-Gruppio.h"
#include <p32xxxx.h>

char InitUart(int PBCK, char Module, int Baud, char nbits, char parita)
{
  unsigned int brg;
  unsigned int mode;
  unsigned int sta;
  char errore;
  
  brg = PBCK/(16 * Baud) -1;  // calcola il valore in base alla velocita'
                                   // ed alla frequenza di cloc delle periferiche
                                   
  mode = 0;  // stato iniziale dopo il reset
  sta = 0;
  
  // setta i bits per lunghezza dato e parita'
  parita = toupper(parita);
  if ((nbits == 9) && (parita == 'N')) mode |= 0x00000006;
  else if ((nbits == 8) && (parita == 'N')); // condizione di default
  else if ((nbits == 8) && (parita == 'O')) mode |= 0x00000004;
  else if ((nbits == 8) && (parita == 'E')) mode |= 0x00000002;
  else errore = 1;
  
  // abilita la trasmissione settando il bit UTXEN (10) di STA
  sta |= 0x00000400;
  
  // abilita la ricezione settando il bit URXEN (12) di STA
  sta |= 0x00001000;
  
  // abilita il modulo settando il bit ON (15) di mode
  mode |= 0x00008000;
  
  // in base al modulo selezionato assegna i valori
  switch (Module)
  {
    case 1: U1ABRG = brg; U1ASTA = sta; U1AMODE = mode; break;
    case 2: U1BBRG = brg; U1BSTA = sta; U1BMODE = mode; break;
    case 3: U2ABRG = brg; U2ASTA = sta; U2AMODE = mode; break;
    case 4: U2BBRG = brg; U2BSTA = sta; U2BMODE = mode; break;
    case 5: U3ABRG = brg; U3ASTA = sta; U3AMODE = mode; break;
    case 6: U3BBRG = brg; U3BSTA = sta; U3BMODE = mode; break;
    default: errore = 2;
  }
}

//-------------------------------------------------------------------

void Uart1_write_string(char *s)
{
  while(*s)
  {
    while (!uart1_tx_ready);
    uart1_write_char(*s);
    s++;
  }
}

//--------------------------------------------------------------------

void Uart1_putc(char c)
{
  while(!uart1_tx_ready);
  uart1_write_char(c);
}

//--------------------------------------------------------------------

void Uart1_putI(int i)
{
char c1=0,c0=0;

  c0=(i&0x00FF);
  c1=(i&0xFF00)>>8;

  while(!uart1_tx_ready);
  uart1_write_char(c1);
  while(!uart1_tx_ready);
  uart1_write_char(c0);

}

//--------------------------------------------------------------------

char Uart1_getc(void)
{
  while(!uart1_rx_ready);
  return(uart1_read_char());
}

//--------------------------------------------------------------------
//-------------------------------------------------------------------

void Uart2_write_string(char *s)
{
  while(*s)
  {
    while (!uart2_tx_ready);
    uart2_write_char(*s);
    s++;
  }
}

//--------------------------------------------------------------------

void Uart2_putc(char c)
{
  while(!uart2_tx_ready);
  uart2_write_char(c);
}

//--------------------------------------------------------------------

void Uart2_putI(int i)
{
char c1=0,c0=0;

  c0=(i&0x00FF);
  c1=(i&0xFF00)>>8;

  while(!uart2_tx_ready);
  uart2_write_char(c1);
  while(!uart2_tx_ready);
  uart2_write_char(c0);

}

//--------------------------------------------------------------------
char Uart2_getc(void)
{
  while(!uart2_rx_ready);
  return(uart2_read_char());
}

//--------------------------------------------------------------------
//-------------------------------------------------------------------

void Uart3_write_string(char *s)
{
  while(*s)
  {
    while (!uart3_tx_ready);
    uart3_write_char(*s);
    s++;
  }
}

//--------------------------------------------------------------------

void Uart3_putc(char c)
{
  while(!uart3_tx_ready);
  uart3_write_char(c);
}



//--------------------------------------------------------------------

void Uart3_putI(int i)
{
char c1=0,c0=0;

  c0=(i&0x00FF);
  c1=(i&0xFF00)>>8;

  while(!uart3_tx_ready);
  uart3_write_char(c1);
  while(!uart3_tx_ready);
  uart3_write_char(c0);

}
//--------------------------------------------------------------------

char Uart3_getc(void)
{
  while(!uart3_rx_ready);
  return(uart3_read_char());
}

//--------------------------------------------------------------------
//-------------------------------------------------------------------

void Uart4_write_string(char *s)
{
  while(*s)
  {
    while (!uart4_tx_ready);
    uart4_write_char(*s);
    s++;
  }
}

//--------------------------------------------------------------------

void Uart4_putc(char c)
{
  while(!uart4_tx_ready);
  uart4_write_char(c);
}

//--------------------------------------------------------------------

void Uart4_putI(int i)
{
char c1=0,c0=0;

  c0=(i&0xFF);
  c1=(i >> 8) & 0xFF;

  while(!uart4_tx_ready);
  uart4_write_char(c1);
  while(!uart4_tx_ready);
  uart4_write_char(c0);

}

//--------------------------------------------------------------------

char Uart4_getc(void)
{
  while(!(U2BSTA & 0x0001));
  return U2BRXREG;
}

//--------------------------------------------------------------------
//-------------------------------------------------------------------

void Uart5_write_string(char *s)
{
  while(*s)
  {
    while (!uart5_tx_ready);
    uart5_write_char(*s);
    s++;
  }
}

//--------------------------------------------------------------------

void Uart5_putc(char c)
{
  while(!uart5_tx_ready);
  uart5_write_char(c);
}

//--------------------------------------------------------------------

void Uart5_putI(int i)
{
char c1=0,c0=0;

  c0=(i&0x00FF);
  c1=(i&0xFF00)>>8;

  while(!uart5_tx_ready);
  uart5_write_char(c1);
  while(!uart5_tx_ready);
  uart5_write_char(c0);

}

//--------------------------------------------------------------------

char Uart5_getc(void)
{
  while(!uart5_rx_ready);
  return(uart5_read_char());
}

//--------------------------------------------------------------------
//-------------------------------------------------------------------

void Uart6_write_string(char *s)
{
  while(*s)
  {
    while (!uart6_tx_ready);
    uart6_write_char(*s);
    s++;
  }
}

//--------------------------------------------------------------------

void Uart6_putc(char c)
{
  while(!uart6_tx_ready);
  uart6_write_char(c);
}

//--------------------------------------------------------------------

void Uart6_putI(int i)
{
char c1=0,c0=0;

  c0=(i&0x00FF);
  c1=(i&0xFF00)>>8;

  while(!uart6_tx_ready);
  uart6_write_char(c1);
  while(!uart6_tx_ready);
  uart6_write_char(c0);

}

//--------------------------------------------------------------------

char Uart6_getc(void)
{
  while(!uart6_rx_ready);
  return(uart6_read_char());
}

//--------------------------------------------------------------------


