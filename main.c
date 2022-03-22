#include <stdio.h>
#include <avr/io.h>

#define F_CPU 16000000UL
#include <util/delay.h>

int main() {
	// set all PORTB pins for output
	DDRB = 0xFF;

	if (printf("Hello, World!")) {
		for (;;) {
				// toggle PORTB pins
				PORTB ^= 0xFF;
				// wait one second
				printf("in the loop...");
				_delay_ms(250);
		}
	}
}
