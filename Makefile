all: elf_compile hex_compile upload clean

elf_compile:
	avr-gcc -mmcu=atmega328p -Wall -Os -o o.elf ./src/main.c

hex_compile:
	avr-objcopy -O ihex -R .eeprom o.elf o.hex

upload:
	avrdude -p atmega328p -c stk500v1 -P /dev/ttyUSB0 -b 115200 -v -V -F -U flash:w:o.hex

clean:
	rm -r o.elf o.hex
