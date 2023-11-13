#pragma once

#include "keyboard.h"

struct Current_key
{
	Key _key;
};

class User_input
{
private:
	Current_key _pressed_key;
	Keyboard _keyboard;
public:
	Key key_control();
};
