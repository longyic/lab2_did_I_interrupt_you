/*
 * lab2_did_I_interrupt_you.c
 *
 * Created: 2018/9/11 17:19:31
 * Author : Lenovo
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

int led = 0;
int main(void)
{
    DDRB |= (1 << PORTB5);
	PORTB |= (1 << PORTB0);
	TIMSK1 |= (1 << ICIE1);
	TCCR1B &= ~(1 << ICES1);
	TIFR1 |= (1 << ICF1);
	led = 0;
	sei();
    while (1) 
    {
		if(led)
		{
			PORTB |= 0x20;
			TCCR1B |= (1 << ICES1);
		}
		else
		{
			PORTB &= 0xDF;
			TCCR1B &= ~(1 << ICES1);
		}
    }
}

ISR(TIMER1_CAPT_vect)
{
	led = ~led;
}

