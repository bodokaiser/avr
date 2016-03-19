#include <avr/io.h>
#include <avr/interrupt.h>

#include "util.c"

#define COUNT 5

volatile uint8_t digit  = 0;
volatile uint8_t value  = 0;
volatile uint8_t count  = 0;
volatile uint8_t toggle = 0;

int main(void) {
    DDRA |= (1 << PA0) | (1 << PA1) | (1 << PA2) | (1 << PA3);
    DDRA |= (1 << PA4) | (1 << PA5) | (1 << PA6);

    DDRC &= ~(1 << PC0);
    PORTC |= (1 << PC0);

    TIMSK |= (1 << TOIE0);
    TCCR0 |= (1 << CS00) | (1 << CS01);

    sei();

    show(digit);

    for (;;) {
        if (toggle) {
            show(++digit);

            if (digit == 0x09) {
                digit = 0;
            }

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
