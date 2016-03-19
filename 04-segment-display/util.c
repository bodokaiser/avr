
void show(uint8_t count) {
    switch (count) {
        case 0x00:
            PORTA = (1 << PA0) | (1 << PA1) | (1 << PA2) | (1 << PA3) | (1 << PA4) | (1 << PA5);
            break;
        case 0x01:
            PORTA = (1 << PA1) | (1 << PA2);
            break;
        case 0x02:
            PORTA = (1 << PA0) | (1 << PA1) | (1 << PA3) | (1 << PA4) | (1 << PA6);
            break;
        case 0x03:
            PORTA = (1 << PA0) | (1 << PA1) | (1 << PA2) | (1 << PA3) | (1 << PA6);
            break;
        case 0x04:
            PORTA = (1 << PA1) | (1 << PA2) | (1 << PA5) | (1 << PA6);
            break;
        case 0x05:
            PORTA = (1 << PA0) | (1 << PA2) | (1 << PA3) | (1 << PA5) | (1 << PA6);
            break;
        case 0x06:
            PORTA = (1 << PA2) | (1 << PA3) | (1 << PA4) | (1 << PA5) | (1 << PA6);
            break;
        case 0x07:
            PORTA = (1 << PA0) | (1 << PA1) | (1 << PA2);
            break;
        case 0x08:
            PORTA = (1 << PA0) | (1 << PA1) | (1 << PA2) | (1 << PA3) | (1 << PA4) | (1 << PA5) | (1 << PA6);
            break;
        case 0x09:
            PORTA = (1 << PA0) | (1 << PA1) | (1 << PA2) | (1 << PA3) | (1 << PA5) | (1 << PA6);
            break;
    }
}
