#pragma once

#include <csignal>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <vector>
#include <chrono>

#include "field.h"
#include "user.h"
//#include "zombie.h"

//int Scope_plants;

//---------------------------------------------------------
class Object
{
protected:
	int hp;//здоровье объекта
	int at;//наносимый объектом урон
public:
	Object(int HP, int AT) : hp(HP), at(AT) {};
	int attack();//метод атаки
	int death();//метод очищения объекта с поля
	void move() ;//метод передвижения по полю
};
//---------------------------------------------------------


/*
class Zombie : public Object
{
public:
	Zombie() : Object(5, 1){};
	int x; //зомби по итогу в себе хранит свою позицию
	int y;
	int Test; // две переменные которые отвечают за отрисовку, индивидуально для каждого зомби
	int parametr;
	void Move_One_Position(int, int);
	void Set_Position(Zombie&);
	int attack(int, int);
	friend class Plant;
	friend class Rules;
	
};
//---------------------------------------------------------




/*
class Sunflower : virtual public Object
{
private:
	Sunflower() : Object(5, 0, "Sunflower") {};
public:
	//int attack();
};

class Pod : virtual public Object
{
private:
	Pod () : Object(5, 1, "Pod") {};
public:
	int attack();
};

class Nut : virtual public Object
{
private:
	Nut () : Object(15, 0, "Nut") {};
public:
	//int attack();
};

class Mine : virtual public Object
{
private:
	Mine () : Object(1, 20, "Mine") {};
public:
	int attack();
};

class Freezer : virtual public Object
{
private:
	Freezer () : Object(1, 20, "Mine") {};
public:
	int attack();
};
class CabbageSprotus : virtual public Object
{
private:
	CabbageSprotus () : Object(1, 20, "Mine") {};
public:
	int attack();
};
//---------------------------------------------------------

/*
class NormalZombie : public Zombie, virtual public Object
{
private:
	NormalZombie() : Object(5, 1, "Zombie"), Zombie(5){};
};

class FastZombie : virtual public Object, public Zombie
{
private:
	FastZombie() : Object (8, 1, "Fast Zombie"), Zombie(8){};
};

class StrongZombie : virtual public Object, public Zombie
{
private:
	StrongZombie() : Object (11, 4, "Strong Zombie"), Zombie(3){};
};*/

