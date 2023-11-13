#include "field_view.h"

Field_View::Field_View(Field_Model* field, Settings* set) : field_m(field)
{
	Graphics_mode g_mode = set->getG_mode();
	switch(g_mode)
	{
		case Graphics_mode::Symbol : 
						_graphics = new Graphics_Sym(set);
						break;
		case Graphics_mode::Escape :
						_graphics = new Graphics_Esc(set);
						break;
	}
}

void Field_View::print()
{
	int size = field_m->getCell_size();
	int _length = field_m->getLength();
	int _width = field_m->getWidth();

	cout << "\033[2J";
	
	for (int i = 0; i < _width; i++)
	{
		for (int j = 0; j < _length; j++)
		{
			cout << CUP(i * size + (i != 0), j * size * 2 + (j != 0)); //перемещаем курсор туда, где нужно отрисовать клетку
			if (i == 0 and j == 0)
			{
				cout << CUP(0,0);
				cout << SGR((int)Color::GREEN); //поставили эффект для выбранной клетки
				_graphics->draw(Cell::empty); //отрисовываем клеточку
				cout << SGR((int)Color::RESET);
			}
			_graphics->draw(Cell::empty); //отрисовываем клеточку
		}
	}
	_graphics->draw(Cell::score);
}


