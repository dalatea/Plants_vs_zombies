#pragma once

#include <string>

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
	int amount_of_zombie;//количество зомби
	int Plants_death ;//количество убитых растений
	int Zombie_death;//количество убитых зомби 
	int f_width;
	int f_length;
public:
	Settings();
	Settings(Graphics_mode, int, int, int, int, int, std::string, int, int, int);
	Graphics_mode getG_mode() {return g_mode;};
	int getPlants_death() {return Plants_death;};
	void assignPlants_death(int pl) {Plants_death = pl;}
	int getCell_size() {return cell_size;};
	int getTerm_width() {return term_width;};
	int getTerm_length() {return term_length;};
	int getLevel() {return _level;};
	int getScope_plants() {return Scope_plants;};
	int getZombie_death() {return Scope_plants;};
	int getAmount_of_plants() {return amount_of_plants;};
	void assignAmount_of_plants(int amp) {amount_of_plants = amp;} 
	int getAmount_of_zombie() {return amount_of_zombie;};
	void assignAmount_of_zombie(int amz) {amount_of_zombie = amz;} 
	void assignZombie_death(int zd) {Zombie_death = zd;} 
	int change_scope_plants() {Scope_plants--; amount_of_plants++; return Scope_plants;};
	std::string getUser_name() {return User_NAME;};
	int getF_width() {return f_width;};
	int getF_length() {return f_length;};
	
};
