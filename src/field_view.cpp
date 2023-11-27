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
			else
				_graphics->draw(Cell::empty); //отрисовываем клеточку
		}
	}
	_graphics->draw(Cell::score);
}

void Field_View::right(int term_width, User_coord* u_coord)
{
	int cell_size = field_m->getCell_size();
	int _x = u_coord->x;
	int _y = u_coord->y;
	Cell** _field = field_m->getField();
	
	if (_x < term_width and _x < field_m -> getLength() - 1)
		{
			cout << CUP(_y * cell_size + 1, _x * 2 * cell_size + 1);
			Cell obj = _field[_x][_y]; //что в данной клетке
			cout << SGR((int)Color::RESET); //убрать эффект с клетки, в которой мы находимся
			paint_cell(obj); //перекрасить клетку
			u_coord->x += 1;
			_x += 1;
			cout << CUP(_y * cell_size + 1, _x * 2 * cell_size + 1);
			obj = _field[_x][_y]; //что в данной клетке
			cout << SGR((int)Color::GREEN); //поставили эффект для выбранной клетки
			paint_cell(obj); //перекрасить клетку
			cout << CUP(_y * cell_size + 1, _x * 2 * cell_size + 1);
		}
}

void Field_View::left(User_coord* u_coord)
{
	int cell_size = field_m->getCell_size();
	int _x = u_coord->x;
	int _y = u_coord->y;
	Cell** _field = field_m->getField();
	
	if (_x > 0)
	{
		cout << CUP(_y * cell_size + 1, _x * 2 * cell_size + 1);
		Cell obj = _field[_x][_y]; //что в данной клетке
		cout << SGR((int)Color::RESET); //убрать эффект с клетки, в которой мы находимся
		paint_cell(obj); //перекрасить клетку
		u_coord->x -= 1;
		_x -= 1;
		cout << CUP(_y * cell_size + 1, _x * 2 * cell_size + 1);
		obj = _field[_x][_y]; //что в данной клетке
		cout << SGR((int)Color::GREEN); //поставили эффект для выбранной клетки
		paint_cell(obj); //перекрасить клетку
		cout << CUP(_y * cell_size + 1, _x * 2 * cell_size + 1);
	}
}

void Field_View::up(User_coord* u_coord)
{
	int cell_size = field_m->getCell_size();
	int _x = u_coord->x;
	int _y = u_coord->y;
	Cell** _field = field_m->getField();
	
	if (_y > 0)
	{
		cout << CUP(_y * cell_size + 1, _x * 2 * cell_size + 1);
		Cell obj = _field[_x][_y]; //что в данной клетке
		cout << SGR((int)Color::RESET); //убрать эффект с клетки, в которой мы находимся
		paint_cell(obj); //перекрасить клетку
		u_coord->y -= 1;
		_y -= 1;
		cout << CUP(_y * cell_size + 1, _x * 2 * cell_size + 1);
		obj = _field[_x][_y]; //что в данной клетке
		cout << SGR((int)Color::GREEN); //поставили эффект для выбранной клетки
		paint_cell(obj); //перекрасить клетку
		cout << CUP(_y * cell_size + 1, _x * 2 * cell_size + 1);
	}
}

void Field_View::down(int term_length, User_coord* u_coord)
{
	int cell_size = field_m->getCell_size();
	int _x = u_coord->x;
	int _y = u_coord->y;
	Cell** _field = field_m->getField();
	
	if ((_y < term_length) and (_y < field_m -> getWidth() - 1))
	{
		cout << CUP(_y * cell_size + 1, _x * 2 * cell_size + 1);
		Cell obj = _field[_x][_y]; //что в данной клетке
		cout << SGR((int)Color::RESET); //убрать эффект с клетки, в которой мы находимся
		paint_cell(obj); //перекрасить клетку
		u_coord->y += 1;
		_y += 1;
		cout << CUP(_y * cell_size + 1, _x * 2 * cell_size + 1);
		obj = _field[_x][_y]; //что в данной клетке
		cout << SGR((int)Color::GREEN); //поставили эффект для выбранной клетки
		paint_cell(obj); //перекрасить клетку
		cout << CUP(_y * cell_size + 1, _x * 2 * cell_size + 1);
	}
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

void Field_View::paint_cell(Cell obj)
{
	if(obj != Cell::empty)
	{
		_graphics -> draw(Cell::empty);
		cout << upCUP(field_m->getCell_size());
	}
	
	_graphics -> draw(obj);
}

