#ifndef __PINS_H__
#define __PINS_H__

#include "Arduino.h"

const int on_off_button = 4;
int on_off_button_state = HIGH;
int last_on_off_button_state = HIGH;

const int mode_button = 2;
int mode_button_state = HIGH;
int last_mode_button_state = HIGH;

unsigned int last_debounce_time = 0;
const unsigned int debounce_delay = 50;

const int red_pin = 6;
const int blue_pin = 5;
const int green_pin = 3;

enum States
{
	DISABLED,
	LEDR,
	LEDG,
	LEDB,
	DISCO
};

States state;

#endif // __PINS_H__