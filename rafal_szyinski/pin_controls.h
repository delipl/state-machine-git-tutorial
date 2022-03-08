#ifndef __PIN_CONTROLS_H__
#define __PIN_CONTROLS_H__

#include "pins.h"

void turn_off_color();
void turn_on_off();
void change_mode();
void disco();

void turn_off_color()
{
	digitalWrite(red_pin, LOW);  	
	digitalWrite(blue_pin, LOW);
	digitalWrite(green_pin, LOW);
}

void turn_on_off()
{
	switch(state)
	{
		case DISABLED:
			state = LEDR;
			break;
		default:
			turn_off_color();
			state = DISABLED;
			break;
	}
}

void change_mode()
{
	turn_off_color();
	switch(state)
	{
		case LEDR:
			state = LEDG;
			break;
		case LEDG:
			state = LEDB;
			break;
		case LEDB:
			state = DISCO;
			break;
		case DISCO:
			state = LEDR;
			break;
	}
}

void disco()
{
    digitalWrite(red_pin, HIGH);  
    delay(50);
    digitalWrite(red_pin, LOW);
    digitalWrite(green_pin, HIGH);
    delay(50);
    digitalWrite(green_pin, LOW);
    digitalWrite(blue_pin, HIGH);
    delay(50);
    digitalWrite(blue_pin, LOW);
}

#endif // __PIN_CONTROLS_H__