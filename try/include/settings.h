#pragma once

#include <string>

extern int Scope_plants; //максимальное количество растений
extern int amount_of_plants;//количество растений
extern int amount_of_zombie;//количество зомби
extern int Plants_death ;//количество убитых растений
extern int Zombie_death ;//количество убитых зомби 

enum class Key{ //перечисление клавиш, которые используются пользователем
	Nothing = 0,
	Up = 87,
	Down = 83,
	Right = 68,
	Left = 65,
	Space = 32,
	Enter = 13
};

struct Current_key
{
	Key _key;
};

enum class Graphics_mode
{
	Symbol,
	Escape
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

enum class Steps{
	main_menu,
	put_plants,
	zombie_atack
};

class Settings{
private:
	Graphics_mode g_mode;
	const int cell_size;
	const int term_width;
	const int term_length;
	std::string User_NAME;//имя пользователя
	int _level;
	//int Scope_plants_;
	//int amount_of_plants_;
	//int amount_of_zombie_;
	//std::string User_NAME_;
public:
	Settings(Graphics_mode, int, int, int);
	Graphics_mode getG_mode() {return g_mode;};
	int getCell_size() {return cell_size;};
	int getTerm_width() {return term_width;};
	int getTerm_length() {return term_length;};
	int getLevel() {return _level;};
	
};
