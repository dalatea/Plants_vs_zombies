#pragma once

#include "objects.h"

class Bullet
{
public:
	int at;//атака пули
	Bullet(int AT = 1) : at(AT){};
	int x; //пуля по итогу в себе хранит свою позицию
	int y;
	int x1; // переменная чтобы правильно отрисовать
	int Test; // две переменные которые отвечают за отрисовку, индивидуально для каждой пули
	int parametr;
	void Bullet_spawn();
	void Set_position(std::vector <Plant>&, std::vector <Bullet>&);
	int attack(int, int);
	friend class Plant;
	friend class Rules;
	friend class Zombie;
};
