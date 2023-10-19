#include "field.h"

Field::Field(unsigned length, unsigned width) 
{
	_length = length;
	_width = width;
	_graphics = new Graphics_Sym; //в указатель на Graphics помещаем наследника Graphics_Sym, где есть методы отрисовки с помощью символов, потом можем выбирать любой другой метод отрисовки (например можно создаь класс Graphics_Escape)
	
	//cout << width << endl;
	
	_field = new Cell*[length]; //выделяем память на первый ряд
	
	for (int i = 0; i < length; i += 1)
	{
		_field[i] = new Cell[width]; //выделяем память на остальные ряды
		for (int j = 0; j < width; j += 1)
		{
			_field[i][j] = Cell::empty; //помещаем в каждую клеточку информацию о том, что она пустая
		}
	}
}

Field::~Field() 
{
	for (int i = 0; i < _width; i++)
	{
		delete[] _field[i];
	}
		delete[] _field;
}

Cell Field::getCell(unsigned x, unsigned y)
{
	return _field[x][y];
}

void Field::print()
{
	cout << "\033[2J";
	int size = 6; //временно определён тут, потом надо будет переместить в отдельный класс
	for (int i = 0; i < _width; i++)
	{
		for (int j = 0; j < _length; j++)
		{
			cout << CUP(i * size + (i != 0), j * size * 2 + (j != 0)); //перемещаем курсор туда, где нужно отрисовать клетку
			if (i == 0 and j == 0)
			{
				cout << CUP(0,0);
				cout << SGR((int)Color::GREEN); //поставили эффект для выбранной клетки
				_graphics->draw(_field[i][j]); //отрисовываем клеточку
				cout << SGR((int)Color::RESET);
			}
			_graphics->draw(_field[i][j]); //отрисовываем клеточку
		}
	}
	_graphics->draw(Cell::score);
}



unsigned Field::getLENGTH()
{
	return _length;
}

unsigned Field::getWIDTH()
{
	return _width;
}

