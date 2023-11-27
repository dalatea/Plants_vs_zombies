#include "field_model.h"

Field_Model::Field_Model(Settings _settings) : _length(6)
{
	int level = _settings.getLevel();
	_width = level;
	_cell_size = _settings.getCell_size();
	
	_field = new Cell*[_length]; //выделяем память на первый ряд
	
	for (int i = 0; i < _length; i += 1)
	{
		_field[i] = new Cell[_width]; //выделяем память на остальные ряды
		for (int j = 0; j < _width; j += 1)
		{
			_field[i][j] = Cell::empty; //помещаем в каждую клеточку информацию о том, что она пустая
		}
	}
}

Field_Model::~Field_Model() 
{
	for (int i = 0; i < _width; i++)
	{
		delete[] _field[i];
	}
		delete[] _field;
}

Cell Field_Model::getCell(unsigned x, unsigned y)
{
	return _field[x][y];
}

/*void Field::print()
{
	int size = _settings.getCell_size();
	int _length = _settings.getField_length();
	int _width = _settings.getField_width();
	
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
				_graphics->draw(_field[i][j]); //отрисовываем клеточку
				cout << SGR((int)Color::RESET);
			}
			_graphics->draw(_field[i][j]); //отрисовываем клеточку
		}
	}
	_graphics->draw(Cell::score);
}*/

