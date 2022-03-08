#include "pin_controls.h"

void setup()
{
	pinMode(on_off_button, INPUT_PULLUP);
	pinMode(mode_button, INPUT_PULLUP);
	
	pinMode(red_pin, OUTPUT);  
	pinMode(blue_pin, OUTPUT);
	pinMode(green_pin, OUTPUT);
	
	state = DISABLED;
}

void loop()
{
	int reading = digitalRead(on_off_button);
	if (reading != last_on_off_button_state) {
		last_debounce_time = millis();
	}
	if ((millis() - last_debounce_time) > debounce_delay)
	{
		if (reading != on_off_button_state)
		{
			on_off_button_state = reading;
			if (on_off_button_state == HIGH)
			{ 
					turn_on_off();
			}
		}
	}
	last_on_off_button_state = reading;
	
	
	reading = digitalRead(mode_button);
	if (reading != last_mode_button_state) {
		last_debounce_time = millis();
	}
	if ((millis() - last_debounce_time) > debounce_delay)
	{
		if (reading != mode_button_state)
		{
			mode_button_state = reading;
			if (mode_button_state == HIGH)
			{ 
					change_mode();
			}
		}
	}
	last_mode_button_state = reading;
	
	switch(state)
	{
		case LEDR:
			digitalWrite(red_pin, HIGH);
			break;
		case LEDG:
			digitalWrite(green_pin, HIGH);
			break;
		case LEDB:
			digitalWrite(blue_pin, HIGH);
			break;
		case DISCO:
			disco();
			break;
	}
}