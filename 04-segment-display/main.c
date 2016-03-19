#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint8_t count = 0x01;

void show() {
    switch (count) {
        case 0x0a:
            count = 0x00;
        case 0x00:
            PORTA |= (1 << PA0);
            PORTA |= (1 << PA1);
            PORTA |= (1 << PA2);
            PORTA |= (1 << PA3);
            PORTA |= (1 << PA4);
            PORTA |= (1 << PA5);
            break;
        case 0x01:
            PORTA |= (1 << PA1);
            PORTA |= (1 << PA2);
            break;
        case 0x02:
            PORTA |= (1 << PA0);
            PORTA |= (1 << PA1);
            PORTA |= (1 << PA3);
            PORTA |= (1 << PA4);
            PORTA |= (1 << PA6);
            break;
        case 0x03:
            PORTA |= (1 << PA0);
            PORTA |= (1 << PA1);
            PORTA |= (1 << PA2);
            PORTA |= (1 << PA3);
            PORTA |= (1 << PA6);
            break;
        case 0x04:
            PORTA |= (1 << PA1);
            PORTA |= (1 << PA2);
            PORTA |= (1 << PA5);
            PORTA |= (1 << PA6);
            break;
        case 0x05:
            PORTA |= (1 << PA0);
            PORTA |= (1 << PA2);
            PORTA |= (1 << PA3);
            PORTA |= (1 << PA5);
            PORTA |= (1 << PA6);
            break;
        case 0x06:
            PORTA |= (1 << PA2);
            PORTA |= (1 << PA3);
            PORTA |= (1 << PA4);
            PORTA |= (1 << PA5);
            PORTA |= (1 << PA6);
            break;
        case 0x07:
            PORTA |= (1 << PA0);
            PORTA |= (1 << PA1);
            PORTA |= (1 << PA2);
            break;
        case 0x08:
            PORTA |= (1 << PA0);
            PORTA |= (1 << PA1);
            PORTA |= (1 << PA2);
            PORTA |= (1 << PA3);
            PORTA |= (1 << PA4);
            PORTA |= (1 << PA5);
            PORTA |= (1 << PA6);
            break;
        case 0x09:
            PORTA |= (1 << PA0);
            PORTA |= (1 << PA1);
            PORTA |= (1 << PA2);
            PORTA |= (1 << PA3);
            PORTA |= (1 << PA5);
            PORTA |= (1 << PA6);
            break;
    }
}

int main() {
    DDRD &= ~(1 << PD2);
    PORTD |= (1 << PD2);

    /* use PA0, PB0, PD0 as GPIO */
    DDRA |= (1 << PA0) | (1 << PA1) | (1 << PA2) | (1 << PA3);
    DDRA |= (1 << PA4) | (1 << PA5) | (1 << PA6);

    /* enable external interrupt */
    //GICR = (1 << INT0);
    /* trigger interrupt on high */
    //MCUCR = (1 << ISC01) | (1 << ISC00);
    //GIMSK = (1 << INT0);

    /* enable interrupts */
    sei();

    show();

    for (;;) {
        /* do nothing */
    }

    return 0;
}

ISR (INT0_vect) {
    count++;

    show();
}
