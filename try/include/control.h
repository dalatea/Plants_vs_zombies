#pragma once

#include "graphics.h"
#include "user_input.h"
#include "field.h"

#include "keyboard.h"
#include <csignal>
#include <sys/ioctl.h>

class Game_control
{
private:
	Settings _set;
	Field_View* field_view;
	Field_Model* field_model;
	Steps _step;
	bool gamerunning;
public:
	Game_control();
	void settings();
	void run();
	void step();
};
