#pragma once

#include "graphics.h"
#include "field_model.h"
#include "field_view.h"
#include "keyboard.h"
#include <cstdlib>


#include <csignal>
#include <sys/ioctl.h>

class Game_control
{
private:
	Settings* _set;
	Field_View* field_view;
	Field_Model* field_model;
	//Rules rules; 
	Keyboard* keyboard;
	Steps _step;
	Current_key current_key;
	User_coord u_coord;
public:
	Game_control();
	int level();
	std::string user_name();
	void steps();
	void put_plants();
	void zombie_attack();
	void move();
	void choose();
	//static void end(int);
	~Game_control();
};
