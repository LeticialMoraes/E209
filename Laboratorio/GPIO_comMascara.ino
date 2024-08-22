#include <avr/io.h>
#include <util/delay.h>

typedef enum {
    S0,  // Estado 00
    S1,  // Estado 01
    S2,  // Estado 10
    S3   // Estado 11
} State;

int main(void) {
    // Configuração das portas como saída
    DDRB |= (1 << PB2) | (1 << PB4);  // Configura PB0 e PB1 como saídas
    
    // Inicialização do estado
    State currentState = S0;

    while (1) {
        switch (currentState) {
            case S0:
                PORTB &= ~(1 << PB2);  // PB0 = 0
                PORTB &= ~(1 << PB4);  // PB1 = 0
                currentState = S1;     // Transição para S1
                break;
                
            case S1:
                PORTB |= (1 << PB2);   // PB0 = 1
                PORTB &= ~(1 << PB4);  // PB1 = 0
                currentState = S2;     // Transição para S2
                break;
                
            case S2:
                PORTB &= ~(1 << PB2);  // PB0 = 0
                PORTB |= (1 << PB4);   // PB1 = 1
                currentState = S3;     // Transição para S3
                break;
                
            case S3:
                PORTB |= (1 << PB2);   // PB0 = 1
                PORTB |= (1 << PB4);   // PB1 = 1
                currentState = S0;     // Transição para S0
                break;
        }
        _delay_ms(500); // Aguarda 500 ms
    }

    return 0;
}