

#define uart1_rx_ready (U1ASTA & 0x00000001)
#define uart1_read_char() U1ARXREG
#define uart1_tx_ready !(U1ASTA & 0x00000200)
#define uart1_write_char(c) (U1ATXREG = c)

#define uart2_rx_ready (U1BSTA & 0x00000001)
#define uart2_read_char() U1BRXREG
#define uart2_tx_ready !(U1BSTA & 0x00000200)
#define uart2_write_char(c) (U1BTXREG = c)

#define uart3_rx_ready (U2ASTA & 0x00000001)
#define uart3_read_char() U2ARXREG
#define uart3_tx_ready !(U2ASTA & 0x00000200)
#define uart3_write_char(c) (U2ATXREG = c)

#define uart4_rx_ready (U2BSTA & 0x00000001)
#define uart4_read_char() U2BRXREG
#define uart4_tx_ready !(U2BSTA & 0x00000200)
#define uart4_write_char(c) (U2BTXREG = c)

#define uart5_rx_ready (U3ASTA & 0x00000001)
#define uart5_read_char() U3ARXREG
#define uart5_tx_ready !(U3ASTA & 0x00000200)
#define uart5_write_char(c) (U3ATXREG = c)

#define uart6_rx_ready (U3BSTA & 0x00000001)
#define uart6_read_char() U3BRXREG
#define uart6_tx_ready !(U3BSTA & 0x00000200)
#define uart6_write_char(c) (U3BTXREG = c)

char InitUart(int PBCK, char Module, int Baud, char nbits, char parita);

void Uart1_write_string(char *s);
void Uart1_putc(char c);
void Uart1_putI(int i);
char Uart1_getc(void);

void Uart2_write_string(char *s);
void Uart2_putc(char c);
void Uart2_putI(int i);
char Uart2_getc(void);

void Uart3_write_string(char *s);
void Uart3_putc(char c);
void Uart3_putI(int i);
char Uart3_getc(void);

void Uart4_write_string(char *s);
void Uart4_putc(char c);
void Uart4_putI(int i);
char Uart4_getc(void);

void Uart5_write_string(char *s);
void Uart5_putc(char c);
void Uart5_putI(int i);
char Uart5_getc(void);

void Uart6_write_string(char *s);
void Uart6_putc(char c);
void Uart6_putI(int i);
char Uart6_getc(void);

char Uart_Extern_getc();

