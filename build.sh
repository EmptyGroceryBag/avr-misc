#!/bin/bash
rm -rf *.elf *.hex *.o

avr-gcc -g -Os -DF_CPU=16000000UL -mmcu=atmega2560 -c main.c
avr-gcc -g -mmcu=atmega2560 -o main.elf main.o -lm &&
avr-objcopy -j .text -j .data -O ihex main.elf main.hex &&
#avr-objcopy -R .eeprom -O ihex main.elf main.hex &&

avrdude -p atmega2560 -c wiring -P /dev/ttyACM0 -b 115200 -D -U flash:w:main.hex:i
