#pragma once

#include "zombie.h"
#include "objects.h"
#include "game.h"
#include "plants.h"
#include "bullet.h"

#include <iostream>


class Rules
{
public:
	//Regular function
	void Score();
	void spawn(Field*);
	
	//Zombie
	void Zombie_Move(Field*, Zombie&, Graphics_Sym*);
	bool Alinement(Field*, Zombie&);
	bool All_Zombie_Move(Field*, int, std::vector <Zombie>&, std::vector <Plant>&);
	unsigned Search(Zombie, std::vector <Plant>& );
	int ZPattack(Zombie, Plant);
	void Plants_erase(std::vector<int>&, std::vector <Plant>&);
	
	//Bullet
	void Bullet_Move(Field*, Bullet&, Graphics_Sym*);
	bool Alinement(Field*, Bullet&);
	void All_Bullet_Move(Field*, std::vector <Plant>&, std::vector <Zombie>&, std::vector <Bullet>&);
	unsigned Search(Bullet, std::vector <Zombie>& );
	int BZattack(Zombie, Bullet);
	void Bullets_erase(std::vector<int>&, std::vector <Bullet>&);
	
	friend class User_act;
	friend class Field;
	friend class Game;
	friend class Zombie;
	friend class Plant;
};


