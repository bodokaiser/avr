#include <avr/io.h>
#include <avr/interrupt.h>

int main(void) {
    /* use PA0, PB0, PD0 as output GPIO */
    DDRA = (1 << PA0);
    DDRB = (1 << PB0);
    DDRD = (1 << PD0);

    /* set PA0 low, PB0 high */
    PORTA &= (1 << PA0);
    PORTB |= (1 << PB0);

    /* enable overflow interrupt */
    TIMSK = (1 << TOIE0);
    /* set prescale to 1024 */
    TCCR0 = (1 << CS02) | (1 << CS00);
    /* enable interrupts */
    sei();

    for (;;) {
        /* do nothing */
    }

    return 0;
}

ISR (TIMER0_OVF_vect) {
    /* toggle PD0 */
    PORTD ^= (1 << PD0);
}
