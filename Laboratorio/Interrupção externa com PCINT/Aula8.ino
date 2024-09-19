#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

ISR(PCINT0_vect) {
    PORTD |= (1 << PD7);
    _delay_ms(1000);
    PORTD &= ~(1 << PD7);
}

ISR(PCINT1_vect) {
    PORTD |= (1 << PD6);
    _delay_ms(5000);
    PORTD &= ~(1 << PD6);
    
    PORTB |= (1 << PB1);
    _delay_ms(2000);
    PORTB &= ~(1 << PB1);
}

int main(void) {
    DDRD |= (1 << PD5) | (1 << PD6) | (1 << PD7);
    DDRB |= (1 << PB1);
    
    PORTD |= (1 << PD4);
    PORTB |= (1 << PB0);
    PORTC |= (1 << PC0);
    
    PCICR |= (1 << PCIE2);
    PCMSK2 |= (1 << PCINT20);

    PCICR |= (1 << PCIE1);
    PCMSK1 |= (1 << PCINT8);

    PCICR |= (1 << PCIE0);
    PCMSK0 |= (1 << PCINT0);

    sei();
    
    while (1) {
        PORTD |= (1 << PD5);
        _delay_ms(250);
        PORTD &= ~(1 << PD5);
        _delay_ms(250);
    }

    return 0;
}
