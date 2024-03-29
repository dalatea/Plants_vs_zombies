#include "field_view.h"

Field_View::Field_View(Field_Model* field, Settings* set) : field_m(field)
{
	g_mode = set->getG_mode();
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
	Color color;
	cout << "\033[2J";
	for (int i = 0; i < _width; i++)
	{
		for (int j = 0; j < _length; j++)
		{
			cout << CUP(i * size + (i != 0), j * size * 2 + (j != 0)); //перемещаем курсор туда, где нужно отрисовать клетку
			color = _graphics->get_border();
			cout << SGR((int)color);
			_graphics->draw(Cell::empty, color); //отрисовываем клеточку
			if (j != _length - 1)
			{
				for (int k = 0; k < size + 1; k++)
				{
					if (i != _width - 1 or k != size)
					{
						cout << CUP(i * size + (i != 0) + k, j * size * 2 + size * 2 - 1);
						cout << "  ";
					}
					if (_width == 1)
					{
						cout << CUP(i * size + (i != 0) + k, j * size * 2 + size * 2 - 1);
						cout << "  ";
					}
				}
			cout << SGR((int)Color::RESET); 
			color = Color::RESET;
			}
		}
	}
	cout << CUP(0,0);
	color = _graphics->get_choose();
	cout << SGR((int)color);
	_graphics->draw(Cell::empty, color); //отрисовываем клеточку
	cout << SGR((int)Color::RESET);
	color = Color::RESET;
	_graphics->draw(Cell::score, color);
}

void Field_View::right(int term_width, User_coord* u_coord)
{
	int cell_size = field_m->getCell_size();
	Color color;
	int _x = u_coord->x;
	int _y = u_coord->y;
	Cell** _field = field_m->getField();
	
	if (_x < term_width and _x < field_m -> getLength() - 1)
		{
			cout << CUP(_y * cell_size + 1, _x * 2 * cell_size + 1);
			Cell obj = _field[_x][_y]; //что в данной клетке
			color = _graphics->get_border();;
			cout << SGR((int)color);//убрать эффект с клетки, в которой мы находимся
			paint_cell(obj, color); //перекрасить клетку
			u_coord->x += 1;
			_x += 1;
			cout << CUP(_y * cell_size + 1, _x * 2 * cell_size + 1);
			obj = _field[_x][_y]; //что в данной клетке
			color = _graphics->get_choose();
			cout << SGR((int)color); //поставили эффект для выбранной клетки
			paint_cell(obj, color); //перекрасить клетку
			cout << CUP(_y * cell_size + 1, _x * 2 * cell_size + 1);
			cout << SGR((int)Color::RESET);
		}
	color = Color::RESET;
	cout << SGR((int)color);
}

void Field_View::left(User_coord* u_coord)
{
	int cell_size = field_m->getCell_size();
	int _x = u_coord->x;
	int _y = u_coord->y;
	Cell** _field = field_m->getField();
	Color color;
	
	if (_x > 0)
	{
		cout << CUP(_y * cell_size + 1, _x * 2 * cell_size + 1);
		Cell obj = _field[_x][_y]; //что в данной клетке
		color = _graphics->get_border();
		cout << SGR((int)color);//убрать эффект с клетки, в которой мы находимся
		paint_cell(obj, color); //перекрасить клетку
		u_coord->x -= 1;
		_x -= 1;
		cout << CUP(_y * cell_size + 1, _x * 2 * cell_size + 1);
		obj = _field[_x][_y]; //что в данной клетке
		color = _graphics->get_choose();
		cout << SGR((int)color); //поставили эффект для выбранной клетки
		paint_cell(obj, color); //перекрасить клетку
		cout << CUP(_y * cell_size + 1, _x * 2 * cell_size + 1);
	}
	color = Color::RESET;
	cout << SGR((int)color);
}

void Field_View::up(User_coord* u_coord)
{
	int cell_size = field_m->getCell_size();
	int _x = u_coord->x;
	int _y = u_coord->y;
	Cell** _field = field_m->getField();
	Color color;
	
	if (_y > 0)
	{
		cout << CUP(_y * cell_size + 1, _x * 2 * cell_size + 1);
		Cell obj = _field[_x][_y]; //что в данной клетке
		color = _graphics->get_border();
		cout << SGR((int)color);//убрать эффект с клетки, в которой мы находимся
		paint_cell(obj, color); //перекрасить клетку
		u_coord->y -= 1;
		_y -= 1;
		cout << CUP(_y * cell_size + 1, _x * 2 * cell_size + 1);
		obj = _field[_x][_y]; //что в данной клетке
		color = _graphics->get_choose();
		cout << SGR((int)color); //поставили эффект для выбранной клетки
		paint_cell(obj, color); //перекрасить клетку
		cout << CUP(_y * cell_size + 1, _x * 2 * cell_size + 1);
	}
	color = Color::RESET;
	cout << SGR((int)color);
}

void Field_View::down(int term_length, User_coord* u_coord)
{
	int cell_size = field_m->getCell_size();
	int _x = u_coord->x;
	int _y = u_coord->y;
	Cell** _field = field_m->getField();
	Color color;
	
	if ((_y < term_length) and (_y < field_m -> getWidth() - 1))
	{
		cout << CUP(_y * cell_size + 1, _x * 2 * cell_size + 1);
		Cell obj = _field[_x][_y]; //что в данной клетке
		color = _graphics->get_border();
		cout << SGR((int)color);//убрать эффект с клетки, в которой мы находимся
		paint_cell(obj, color); //перекрасить клетку
		u_coord->y += 1;
		_y += 1;
		cout << CUP(_y * cell_size + 1, _x * 2 * cell_size + 1);
		obj = _field[_x][_y]; //что в данной клетке
		color = _graphics->get_choose();
		cout << SGR((int)color); //поставили эффект для выбранной клетки
		paint_cell(obj, color); //перекрасить клетку
		cout << CUP(_y * cell_size + 1, _x * 2 * cell_size + 1);
	}
	color = Color::RESET;
	cout << SGR((int)color);
}

void Field_View::Scope_Plants_Print(Settings* _set, User_coord* u_coord)
{
	int term_length = _set->getTerm_length();
	int cell_size = field_m->getCell_size();
	int _x = u_coord->x;
	int _y = u_coord->y;
	
	cout << SGR((int)Color::RESET);
	int Scope_plants = _set->change_scope_plants();
	
	cout  << CUP(term_length - term_length/3 + 3, 31) << Scope_plants; 	
	if(Scope_plants < 10)
		cout  << " ";
		
	cout << CUP(_y * cell_size + 1, _x * 2 * cell_size + 1); 
}

void Field_View::paint_cell(Cell obj, Color color)
{
	if(obj != Cell::empty)
	{
		if(obj == Cell::plant)
			_graphics -> draw(Cell::empty, color);
		cout << upCUP(field_m->getCell_size());
	}
	_graphics -> draw(obj, color);
}

void Field_View::choose(Cell obj)
{
	Color color;
	color = _graphics->get_choose();
	cout << SGR((int)color); 
	paint_cell(obj, color);
	cout << SGR((int)Color::RESET);
	cout << leftCUP(6) << upCUP(2);
}

Color Field_View::reset()
{
	Color color;
	color = _graphics->get_border();
	cout << SGR((int)color); 
	return color;
}

void Field_View::color()
{
	Color color;
	color = _graphics->get_choose();
	cout << SGR((int)color); 
}

Color Field_View::bg()
{
	cout << SGR((int)Color::RESET);
	Color color;
	color = _graphics->get_bg();
	cout << SGR((int)color); 
	return color;
}
