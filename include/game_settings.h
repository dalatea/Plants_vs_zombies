#pragma once

#include <string>
#include <termios.h>
#include "fcntl.h"

extern int Scope_plants; //максимальное количество растений
extern int amount_of_plants;//количество растений
extern int amount_of_zombie;//количество зомби
extern std::string User_NAME;//имя пользователя
extern int length;//длина поля
extern int width;//ширина поля
extern int Plants_death ;//количество убитых растений
extern int Zombie_death ;//количество убитых зомби 

struct Settings{
	int graphics_mode_;
	int Scope_plants_;
	int amount_of_plants_;
	int amount_of_zombie_;
	std::string User_NAME_;
	int length_;
	int width_;
	const int cell_size_ = 6;
	const int term_width_ = 140;
	const int term_lenght_ = 80;
};
const int cell_size = 6;//размер клеток поля
const int term_width = 140;//минимальная ширина терминала
const int term_lenght = 80;//минимальная длина терминала

enum class Key{ //перечисление клавиш, которые используются пользователем
	Nothing = 0,
	Up = 87,
	Down = 83,
	Right = 68,
	Left = 65,
	Space = 32,
	Enter = 13
};

enum class Cell{ //перечисление того, что может находиться в клетке
	empty,
	zombie,
	plant,
	score,
	bullet
};

enum class Color{//перечисление кодов цветов
	RED = 31,
	GREEN = 32,
	WHITE = 37,
	RESET = 0,
	GREEN_BG = 42,
	WHITE_BG = 47
};

