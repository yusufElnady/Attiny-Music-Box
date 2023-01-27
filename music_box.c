#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define C  239
#define Cs 225
#define D  213
#define Ds 201
#define E  190
#define F  179
#define Fs 169
#define G  159
#define Gs 150
#define A  142
#define As 134
#define B  127

void tone(int16_t divisor, /*unsigned char octave, */int16_t duration) {
	for (int i = 0; i < duration/300; i++) {
		TCCR1A = 0b00010000;//setting COM1B1-COM1B0 to 0-1 to toggle OC1B aka b3
		TCCR1B = 0x80 | (8-5);
		OCR1C = divisor-10;
		_delay_ms(300);
		TCCR1B = 0x80;
	}
}

int main() {
	// char fur_elise[] = {E,Ds,E,Ds,E,B,D,C,A,123,C,E,A,B,123,E,Gs,B,B-20,123,E,Ds,E,Ds,E,B,D,C,A,
	// 123,C,E,A,B,123,E,C,B,A,123,B,C,D,E,123,G,F,E,D,123,F,E,D,C,123,E,D,C,B,123};

	char hbd[] = {C,C,D,C,F,E,123,C,C,D,C,G,F,123,C,C,B,A,F,E,D,123,As,As,A,F,G,F,F,123,123};

	/*port declarations*/
	DDRB = 0xFF;//all pins are outputs
	DDRB &= ~(1 << 4);//pb4 is the button's input
	PORTB = 0XFF;//enable all internal pull up resistors

	// char pressed = 0;

	while (1) {
		for (short int i = 0; i < sizeof(hbd)/sizeof(char); i ++) {
			//choosing whether to play the tone or pausing
			if (hbd[i] == 123) {
				_delay_ms(300);
			} else {
				tone(hbd[i], 300);
			}

			// checking button presses
			// if (!(PINB & (1 << 4)) && pressed == 0) {
			// 	PORTB ^= (1 << 3);
			// 	pressed = 1;
			// } else {
			// 	pressed = 0;
			// }
		}
	}
}