#pragma once

#include <string>

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

struct User_coord
{
	int x = 0;
	int y = 0;
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
	DARK_GREEN = 22,
	WHITE = 37,
	RESET = 0,
	GREEN_BG = 42,
	YELLOW_BG = 11,
	WHITE_BG = 47,
	BLACK_BG = 40,
	BROWN_BG = 43,
	BLUE_BG = 46
};

enum class Steps{
	put_plants,
	zombie_attack
};

class Settings{
private:
	Graphics_mode g_mode;
	int cell_size;
	int term_width;
	int term_length;
	int _level;
	int Scope_plants;
	int amount_of_plants;
	std::string User_NAME;//имя пользователя
	//int amount_of_zombie_;
public:
	Settings();
	Settings(Graphics_mode, int, int, int, int, std::string);
	Graphics_mode getG_mode() {return g_mode;};
	int getCell_size() {return cell_size;};
	int getTerm_width() {return term_width;};
	int getTerm_length() {return term_length;};
	int getLevel() {return _level;};
	int getScope_plants() {return Scope_plants;};
	int change_scope_plants() {Scope_plants--; amount_of_plants++; return Scope_plants;};
	std::string getUser_name() {return User_NAME;};
	
};
