#ifndef OBJECTS_H
#define OBJECTS_H

#include <csignal>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>


#include "field_model.h"
//#include "control.h"
//#include "user.h"
//#include "zombie.h"

//int Scope_plants;

//---------------------------------------------------------
class Object
{
protected:
	int _hp;
	int _at;
	int _x;
	int _y;
	int _Test; // две переменные которые отвечают за отрисовку, индивидуально для каждого зомби
	int _parametr;
public:
	Object(int HP, int AT) : _hp(HP), _at(AT){};
	
	int getx() {return _x;};
	int gety(){return _y;};
	int getTest(){return _Test;};
	int getparametr(){return _parametr;};
	int gethp() {return _hp;};
	int getat() {return _at;}
	
	void assignx(int);
	void assigny(int);
	void assignTest(int);
	void assignparametr(int);
	void assignhp(int);
	void assignat(int);
	
	int attack();
	int death();
	void move() ;
};


class Plant : public Object
{
public:
	Plant(int HP = 5, int AT = 1) : Object(HP,AT){};
	int count = 0;
	int getx() {return _x;};
	int gety(){return _y;};
	int assignx(int);
	int assigny(int);
	void Set_position(Field_Model*, std::vector <Plant>&);
	void spawn(Cell,  Field_Model*) {};
	//friend class Zombie;
};
//---------------------------------------------------------



class Zombie : public Object
{
public:
	Zombie(int HP = 5, int AT = 1) : Object(HP, AT){};
	
	void Move_One_Position(int, int);
	void Set_Position(Zombie&, Field_Model*);
	int attack(int, int);

	
	
	//friend class Plant;
	//friend class Rules;
	
};

class Bullet : public Object
{
public:
	Bullet(int HP = 1, int AT = 1) : Object(HP,AT){};
	
	void Bullet_spawn();
	void Set_position(std::vector <Plant>&, std::vector <Bullet>&);
	int attack(int, int);
	
	//friend class Plant;
	//friend class Rules;
	//friend class Zombie;
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


#endif

