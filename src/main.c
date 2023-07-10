#include <avr/io.h>

// Define LED pin
#define LED 5

void setup()
{
    // Set bit as a output
    DDRD |=  (1 << LED);
}

void loop()
{
    while (1)
    {
        // 'Toggle' the bit
        PORTD ^= (1 << LED);
    }
}

void main()
{
    setup();
    loop();
}
