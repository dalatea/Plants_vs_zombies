#pragma once

#include "field_model.h"
#include "graphics.h"


class Field_View
{
	Field_Model* field_m;
	Graphics* _graphics;
public:
	Field_View(Field_Model*, Settings*);
	void print();//вывод чистого поля
};
