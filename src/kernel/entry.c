#include <stdint.h>

#define UART                        0x10000000
#define UART_THR                    (uint8_t*) (UART + 0x00)
#define UART_LSR                    (uint8_t*) (UART + 0x05)
#define UART_LSR_EMPTY_MASK         0x40

int uart_putc(char ch) {
	while ((*UART_LSR & UART_LSR_EMPTY_MASK) == 0);
	return *UART_THR = ch;
}

void uart_puts(char *s) {
	while (*s) uart_putc(*s++);
}

int _entry(void) {
	uart_puts("Hello RISC-V!\n");
	while (1) {}
	return 0;
}
