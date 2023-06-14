//This is a pointer to the location in memory at hex number 0x25
//it is a 1-byte register defined by ATmega328p that controls the physical pins 14 thru 19 (mapping to bits 0-5)
//setting a bit to 0 means it's set to low, setting a bit to 1 means it's high
//setting it to volatile to alert the compiler this variable can change outside 
//my code, so it doesn't optimize out this value
#define PORTB *((volatile unsigned char *)0x25)

//this is a pointer to the location in memory at hex 0x24
//this is the Data-direction register for PortB. It controls physical pins 14 thru 19 (mapping to bits 0-5)
//setting a bit to 0 means the pin is set to input mode, setting to 1 means it's output
//setting it to volatile to alert the compiler this variable can change outside 
//my code, so it doesn't optimize out this value
#define DDRB *((volatile unsigned char *)0x24)

int main()
{
    //setup
    //by setting the 6th bit on this register to 1
    //It is setting the bit that controls physical pin 13, and saying it is an output pin
    //using bitwise OR to turn on the 6th bit without affecting the other bits in DDRB
    DDRB |= 0b00100000;

    // loop
    while (1)
    {

        
        //by setting the 6th bit on this register to 1
        //It is setting the bit that controls physical pin 13, and setting it to high
        //using bitwise OR to turn on the 6th bit without affecting the other bits in PORTB
        PORTB |= 0b00100000;

        //go to sleep for an arbitrary amount of time
        for (long i = 0; i < 100000; i++)
        {
            //to make sure the compiler doesn't optimize this out, continue
            //setting the 6th bit of portb to 1
            PORTB |= 0b00100000;
        }
        //setting PortB 6th bit to 0 sets pins PortB controls to low
        PORTB &= 0b11011111;
        //go to sleep for an arbitrary amount of time
        for (long i = 0; i < 100000; i++)
        {
            //to make sure the compiler doesn't optimize this out, continue
            //setting PORTB 6th bit to 0
            PORTB &= 0b11011111;
        }
    }
}