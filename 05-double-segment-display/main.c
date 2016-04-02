#include <avr/interrupt.h>
#include <avr/io.h>

#include "main.h"

volatile uint8_t digit = 0;
volatile uint8_t value = 0;
volatile uint8_t count = 0;
volatile uint8_t toggle = 0;

int main(void) {
  // disabled JTAG on PORTC
  MCUCSR = (1 << JTD);
  MCUCSR = (1 << JTD);

  // set display ports to output
  DDRA = DIS1_A | DIS1_B | DIS1_C | DIS1_D | DIS1_E | DIS1_F | DIS1_G;
  DDRC = DIS2_A | DIS2_B | DIS2_C | DIS2_D | DIS2_E | DIS2_F | DIS2_G;

  // set input port to input
  DDRD = ~INPT;
  PORTD = INPT;

  // enable timer
  TIMSK |= (1 << TOIE0);
  TCCR0 |= (1 << CS00) | (1 << CS01);
  sei();

  show1(0x00);
  show2(0x00);

  for (;;) {
    if (toggle) {
      digit++;

      show1(digit);
      show2(digit);

      if (digit == 0x09) {
        digit = 0;
      }

      toggle = 0;
    }
  }

  return 0;
}

ISR(TIMER0_OVF_vect) {
  uint8_t v = !(PIND & INPT);

  if (value == v) {
    count = 0;
    value = v;

    return;
  }

  if (COUNT == ++count) {
    toggle = 1;
  }
}

void show1(uint8_t count) {
  switch (count) {
  case 0x00:
    PORTA = ~(DIS1_A | DIS1_B | DIS1_C | DIS1_D | DIS1_E | DIS1_F);
    break;
  case 0x01:
    PORTA = ~(DIS1_B | DIS1_C);
    break;
  case 0x02:
    PORTA = ~(DIS1_A | DIS1_B | DIS1_E | DIS1_D | DIS1_G);
    break;
  case 0x03:
    PORTA = ~(DIS1_A | DIS1_B | DIS1_C | DIS1_D | DIS1_G);
    break;
  case 0x04:
    PORTA = ~(DIS1_B | DIS1_C | DIS1_F | DIS1_G);
    break;
  case 0x05:
    PORTA = ~(DIS1_A | DIS1_C | DIS1_D | DIS1_F | DIS1_G);
    break;
  case 0x06:
    PORTA = ~(DIS1_C | DIS1_D | DIS1_E | DIS1_F | DIS1_G);
    break;
  case 0x07:
    PORTA = ~(DIS1_A | DIS1_B | DIS1_C);
    break;
  case 0x08:
    PORTA = ~(DIS1_A | DIS1_B | DIS1_C | DIS1_D | DIS1_E | DIS1_F | DIS1_G);
    break;
  case 0x09:
    PORTA = ~(DIS1_A | DIS1_B | DIS1_C | DIS1_F | DIS1_G);
    break;
  }
}

void show2(uint8_t count) {
  switch (count) {
  case 0x00:
    PORTC = ~(DIS2_A | DIS2_B | DIS2_C | DIS2_D | DIS2_E | DIS2_F);
    break;
  case 0x01:
    PORTC = ~(DIS2_B | DIS2_C);
    break;
  case 0x02:
    PORTC = ~(DIS2_A | DIS2_B | DIS2_E | DIS2_D | DIS2_G);
    break;
  case 0x03:
    PORTC = ~(DIS2_A | DIS2_B | DIS2_C | DIS2_D | DIS2_G);
    break;
  case 0x04:
    PORTC = ~(DIS2_B | DIS2_C | DIS2_F | DIS2_G);
    break;
  case 0x05:
    PORTC = ~(DIS2_A | DIS2_C | DIS2_D | DIS2_F | DIS2_G);
    break;
  case 0x06:
    PORTC = ~(DIS2_C | DIS2_D | DIS2_E | DIS2_F | DIS2_G);
    break;
  case 0x07:
    PORTC = ~(DIS2_A | DIS2_B | DIS2_C);
    break;
  case 0x08:
    PORTC = ~(DIS2_A | DIS2_B | DIS2_C | DIS2_D | DIS2_E | DIS2_F | DIS2_G);
    break;
  case 0x09:
    PORTC = ~(DIS2_A | DIS2_B | DIS2_C | DIS2_F | DIS2_G);
    break;
  }
}