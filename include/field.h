#pragma once

#include "graphics.h"

class Field
{
private:
	Cell** _field;  //поле - двумерный массив из перечислений того, что может находится в клетке
	Graphics* _graphics; //указатель на класс отрисовки Graphics
	unsigned _length; //длина поля
	unsigned _width; //ширина поля
public:
	Field(unsigned length, unsigned width);
	Cell getCell(unsigned, unsigned);//получение клетки
	void print();//вывод чистого поля
	//Plant plants[amount_of_zombie];
	friend class User_act;
	friend class Rules;
	friend class Zombie;
	friend class Graphics_Sym;
	friend class Plant;
	unsigned getLENGTH();
	unsigned getWIDTH();
	~Field();
};


