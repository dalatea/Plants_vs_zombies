#pragma once

#include "field_model.h"
#include "graphics.h"


class Field_View
{
	Field_Model* field_m;
	Graphics* _graphics;
	Graphics_mode g_mode;
public:
	Field_View();
	Field_View(Field_Model*, Settings*);
	void print();//вывод чистого поля
	void paint_cell(Cell obj, Color);
	void right(int, User_coord*);
	void up(User_coord*);
	void down(int, User_coord*);
	void left(User_coord*);
	void Scope_Plants_Print(Settings*, User_coord*);
};
