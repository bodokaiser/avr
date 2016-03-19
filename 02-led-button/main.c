#include <avr/io.h>
#include <avr/interrupt.h>

#define COUNT 5

volatile uint8_t value  = 0;
volatile uint8_t count  = 0;
volatile uint8_t toggle = 0;

int main(void) {
    DDRB |=  (1 << PB0);
    DDRC &= ~(1 << PC0);
    PORTC |= (1 << PC0);

    TIMSK |= (1 << TOIE0);
    TCCR0 |= (1 << CS00) | (1 << CS01);

    sei();

    for (;;) {
        if (toggle) {
            PORTB ^= (1 << PB0);

            toggle = 0;
        }
    }

    return 0;
}

ISR (TIMER0_OVF_vect) {
    uint8_t v = !(PINC & (1 << PC0));

    if (value == v) {
        count = 0;
        value = v;

        return;
    }

    if (COUNT == ++count) {
        toggle = 1;
    }
}
