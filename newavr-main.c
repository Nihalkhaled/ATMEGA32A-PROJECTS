/*
 * File:   newavr-main.c
 * Author: NIHAL KHALED
 *
 * Created on April 10, 2020, 11:57 PM
 */


#include <avr/io.h>
#define LED0 2
#define LED1 7
#define LED2 3

#define PushB0  0
#define PushB1  4
#define PushB2  2




int main(void) {
    DDRD |=(1<<LED2);
    DDRC |=(1<<LED0);
    DDRC |=(1<<LED1);
    
    DDRD &=~(1<<PushB2);
    DDRB &=~(1<<PushB0);
    DDRB &=~(1<<PushB1);
    
    PORTC &=~(1<<LED1) ;
    PORTC &=~(1<<LED0) ;
    PORTD &=~(1<<LED2) ;
    
    /* Replace with your application code */
    while (1) {
        
    if (PINB &(1<<PushB1))
    {
       PORTC |=(1<<LED1) ;
    }
    else if (PINB &(1<<PushB0))
    {
       PORTC |=(1<<LED0) ;

    }
    else if (PIND &(1<<PushB2))
    {
       PORTD |=(1<<LED2) ;

    }
    else 
    {
       PORTC &=~(1<<LED1) ;
       PORTC &=~(1<<LED0) ;
       PORTD &=~(1<<LED2) ;

    }
    }
}
