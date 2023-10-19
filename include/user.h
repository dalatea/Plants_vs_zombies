#pragma once

#include "field.h"
#include "rules.h"
#include "objects.h"
#include "keyboard.h"

class User
{
protected:
	int _x = 0; //где находится курсор
	int _y = 0;
public:
	virtual void key_control() = 0;
	virtual ~User() = default;
};

class User_act : public User
{
	Field* U_field;
	Graphics* _graphics;
	Cell active_object;
	Keyboard _key;
	//Rules* _rules;
	//Plant* _plant;
public:
	User_act(Field*, Keyboard);
	void Scope_Plants_Print();
	void key_control();
	void up();
	void down();
	void left();
	void right();
	void choose();
	void paint(Cell);
	void start();

};
