MCU = atmega16a

TARGET = main
OUTPUT = main.o

CFLAGS  = -Wall
CFLAGS += -std=c11
CFLAGS += -mmcu=$(MCU)
CFLAGS += -o $(OUTPUT)

build:
	avr-gcc $(CFLAGS) $(TARGET).c

clean:
	rm main.o
