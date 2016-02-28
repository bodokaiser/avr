#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint8_t count;

int main(void) {
    /* use PA0, PB0, PD0 as GPIO */
    DDRA = (1 << PA0);
    DDRD = (1 << PD2);

    /* set PA0-6 to high */
    PORTA |= (1 << PA0) | (1 << PA1) | (1 << PA2) | (1 << PA3);
    PORTA |= (1 << PA4) | (1 << PA5) | (1 << PA6);

    /* enable external interrupt */
    GICR = (1 << INT0);
    /* trigger interrupt on high */
    MCUCR = (1 << ISC01) | 1 << ISC00;

    /* enable interrupts */
    sei();

    for (;;) {
        /* do nothing */
    }

    return 0;
}

ISR (INT0_vect) {
    if (count < 9) {
        count++;
    } else {
        count = 0;
    }
}
