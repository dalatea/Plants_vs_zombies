#pragma once

#include "objects.h"

class Plant
{
public:
	int hp; //здоровье растения
	Plant(int HP = 5) : hp(HP){};
	int x, y;//координаты
	int count = 0;
	void Set_position(Field*, std::vector <Plant>&); //установить позицию растения
	void spawn(Cell,  Field*);//появление растения на поле
	friend class Zombie;
};
