// debounce parameter
#define COUNT 5

// port to poll button
#define INPT (1 << PD0)

// first segment display pin layout
#define DIS1_A (1 << PA4)
#define DIS1_B (1 << PA3)
#define DIS1_C (1 << PA0)
#define DIS1_D (1 << PA1)
#define DIS1_E (1 << PA2)
#define DIS1_F (1 << PA5)
#define DIS1_G (1 << PA6)

// second segment display pin layout
#define DIS2_A (1 << PC5)
#define DIS2_B (1 << PC6)
#define DIS2_C (1 << PC2)
#define DIS2_D (1 << PC1)
#define DIS2_E (1 << PC0)
#define DIS2_F (1 << PC4)
#define DIS2_G (1 << PC3)

// displays digit on first segment display
void show1(uint8_t);
// displays digit on second segment display
void show2(uint8_t);