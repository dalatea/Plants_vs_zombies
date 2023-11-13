#pragma once

#include <string>
#include <csignal>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <sys/ioctl.h>

#include "field.h"
#include "graphics.h"
#include "user.h"

class Game
{
private:
	Settings _settings;
	unsigned highest_score;
    	unsigned death_score;
	unsigned level_number;
	int currency;
public:
	Game(Settings set) : _settings(set) {};
	int game_menu();
	//int start_game(bool); //int start_game(bool);
	int start_level(unsigned);
	int start_game();
	void END(bool);
	static void end_game(int);
};
