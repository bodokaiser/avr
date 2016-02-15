#include <stdbool.h>
#include <avr/io.h>

int main() {
    DDRC = 0xff;

    while (true) {
        PORTC = 0xff;
        PORTC = 0x00;
    }

    return 0;
}
