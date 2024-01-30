#pragma once

//#include "zombie.h"
#include "objects.h"
#include "field_view.h"
//#include "game.h"
//#include "plants.h"
//#include "bullet.h"
//#include "user.h"

#include <iostream>


class Rules
{
	Field_View* field_view;
	Field_Model* field_model;
	Settings* _set;
	int zombie_count;
public:
	Rules(Field_View* fv, Field_Model* fm, Settings* set) : field_view(fv), field_model(fm), _set(set){};
	//Regular function
	void Score();
	void assignzombie_count(int x) {zombie_count = x;};
	int getz_c(){return zombie_count;};
	//void spawn(Field*);
	
	//Plant
	void choose(User_coord & );
	
	//Zombie
	void Zombie_Move(Zombie&);
	bool Alinement( Zombie&);
	bool All_Zombie_Move(int, std::vector <Zombie>&, std::vector <Plant>&);
	unsigned Search(Zombie, std::vector <Plant>& );
	int ZPattack(Zombie, Plant);
	void Plants_erase(std::vector<int>&, std::vector <Plant>&);
	void Zombies_erase(std::vector<int>&, std::vector <Zombie>&);
	
	//Bullet
	void Bullet_Move(Bullet&);
	bool Alinement(Bullet&);
	void All_Bullet_Move(std::vector <Plant>&, std::vector <Zombie>&, std::vector <Bullet>&);
	int First_Search(Bullet, std::vector <Zombie>& );
	unsigned Second_Search(Bullet, std::vector <Zombie>& );
	int BZattack(Zombie, Bullet);
	int Bullets_erase(std::vector<int>&, std::vector <Bullet>&);
	
	
	//friend class User_act;
	//friend class Field;
	//friend class Game;
	//friend class Zombie;
	//friend class Plant;
};


