/*
 * Controlling a stepper motor from a DVD drive.
 *
 * Written by Gregor Ottmann, https://github.com/Zappes
 */
#include <avr/io.h>
#include <util/delay.h>

// these are the 4 cables to the stepper motor. 
#define A_PLUS		_BV(PC0)
#define A_MINUS		_BV(PC1)
#define B_PLUS		_BV(PC2)
#define B_MINUS	_BV(PC3)

// the delay between the steps in milliseconds
#define DELAY 500
// the number of repetitions of the pattern before reversing direction
#define REPEAT 3

// these are the sequences in which the coils are activated for forward/reverse stepping
const uint8_t fwd_sequence[] = {A_PLUS | B_PLUS, A_PLUS | B_MINUS, A_MINUS | B_MINUS, A_MINUS | B_PLUS};
const uint8_t rev_sequence[] = {A_PLUS | B_MINUS, A_PLUS | B_PLUS, A_MINUS | B_PLUS, A_MINUS | B_MINUS};

int main(void)
{
	// set the pins to output
	DDRC	= 0xFF;
	PORTC = 0;

	while(1)
	{
		// step forward
		for(int rep = 0; rep < REPEAT; rep++) {
			for(int i = 0; i < sizeof(fwd_sequence); i++) {
				PORTC = fwd_sequence[i];
				_delay_ms(DELAY);
			}
		}

		// step backward
		for(int rep = 0; rep < REPEAT; rep++) {
			for(int i = 0; i < sizeof(rev_sequence); i++) {
				PORTC = rev_sequence[i];
				_delay_ms(DELAY);
			}
		}
	}

	return 0;
}

