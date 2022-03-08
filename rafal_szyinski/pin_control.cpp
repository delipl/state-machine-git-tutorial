#include "pin_controls.hpp"

void turn_off_color()
{
	digitalWrite(red_pin, LOW);  	
	digitalWrite(blue_pin, LOW);
	digitalWrite(green_pin, LOW);
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