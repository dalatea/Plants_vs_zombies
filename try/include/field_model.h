#pragma once

#include "settings.h"


class Field_Model
{
private:
	Cell** _field;  //поле - двумерный массив из перечислений того, что может находится в клетке
	unsigned _length; //длина поля
	unsigned _width; //ширина поля
	unsigned _cell_size;
public:
	Field_Model(Settings);
	Cell getCell(unsigned, unsigned);//получение клетки
	unsigned getLength() {return _length;};
	unsigned getWidth() {return _width;};
	unsigned getCell_size() {return _cell_size;};
	~Field_Model();	
	
	//Plant plants[amount_of_zombie];
	//friend class Rules;
	//friend class Zombie;
	//friend class Graphics_Sym;
	//friend class Plant;
};


