#pragma once

#include "objects.h"
#include "plants.h"
class Zombie
{
public:
	int hp;//здоровье зомби
	int at;//атака зомби
	Zombie(int HP = 5, int AT = 1) : hp(HP), at(AT){};
	int x; //зомби по итогу в себе хранит свою позицию
	int y;
	// две переменные которые отвечают за отрисовку, индивидуально для каждого зомби
	int Test;  //ЗА Х
	int parametr; //ЗА У
	void Move_One_Position(int, int);// устанавливает позицию зомби
	void Set_Position(Zombie&);// метод перемещения зомби
	int attack(Field*, Plant plant);//метод атаки зомби
	friend class Plant;
	friend class Rules;
	
};
