MCU = atmega16a

PART = m16
PORT = usb
PROG = avrisp2

TARGET = main
OUTPUT = main.o

CFLAGS  = -Wall
CFLAGS += -std=c11
CFLAGS += -mmcu=$(MCU)
CFLAGS += -o $(OUTPUT)

DFLAGS  = -p $(PART)
DFLAGS += -c $(PROG)
DFLAGS += -P $(PORT)

build:
	avr-gcc -c $(CFLAGS) -Os $(TARGET).c
	avr-gcc -mmcu=$(MCU) -o $(TARGET).elf $(TARGET).o
	avr-objcopy -j .text -j .data -O ihex $(TARGET).elf $(TARGET).hex

flash:
	avrdude $(DFLAGS) -U flash:w:$(TARGET).hex

clean:
	rm main.{hex,elf,o}

.PHONY: flash