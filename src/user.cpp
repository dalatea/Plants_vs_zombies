#include "user.h"

//int Scope_plants; //используем глобальную переменную из game
int amount_of_plants = 0;

User_act::User_act(Field* field, Keyboard key) : U_field(field), _key(key)
{
	active_object = Cell::empty;
	_graphics = new Graphics_Sym;
}

void User_act::key_control()
{
	_key.read_key();
	if(Scope_plants == 0)
	{
		start();
		cout  << CUP(term_lenght / 2 - 7, 1) << "\033[K"; 
	}
	switch(_key.getKey())
	{
		case Key::Nothing:
			break;
		case Key::Up:
			up();
			break;
		case Key::Down:
			down();
			break;
		case Key::Left:
			left();
			break;
		case Key::Right:
			right();
			break;
		case Key::Space:
			choose();			
			break;
		case Key::Enter:
			start();
			break;
		default:
			break;
	}
	_key.default_key();
}
/*
void User_act::paint(Cell obj) //раскрашивание клетки при нажатии
{
	int x = _x, y = _y;
	_graphics->draw(Cell::empty);
	cout << upCUP(cell_size);
	if(obj != Cell::empty)
	{
		_graphics->draw(Cell::plant);
		cout << leftCUP(6) << upCUP(2);
	}
	
	
}*/
void User_act::paint(Cell obj) //раскрашивание клетки при нажатии
{
	if(obj != Cell::empty)
	{
		_graphics -> draw(Cell::empty);
		cout << upCUP(cell_size);
	}
	
	_graphics -> draw(obj);
	
}


void User_act::right()
{
	if (_x < term_width and _x < U_field -> getLENGTH() - 1)
		{
			cout << CUP(_y * cell_size + 1, _x * 2 * cell_size + 1);
			Cell obj = U_field->_field[_x][_y]; //что в данной клетке
			cout << SGR((int)Color::RESET); //убрать эффект с клетки, в которой мы находимся
			paint(obj); //перекрасить клетку
			_x += 1;
			cout << CUP(_y * cell_size + 1, _x * 2 * cell_size + 1);
			obj = U_field->_field[_x][_y]; //что в данной клетке
			cout << SGR((int)Color::GREEN); //поставили эффект для выбранной клетки
			paint(obj); //перекрасить клетку
			cout << CUP(_y * cell_size + 1, _x * 2 * cell_size + 1);
		}
}

void User_act::left()
{
	
	if (_x > 0)
	{
		cout << CUP(_y * cell_size + 1, _x * 2 * cell_size + 1);
		Cell obj = U_field->_field[_x][_y]; //что в данной клетке
		cout << SGR((int)Color::RESET); //убрать эффект с клетки, в которой мы находимся
		paint(obj); //перекрасить клетку
		_x -= 1;
		cout << CUP(_y * cell_size + 1, _x * 2 * cell_size + 1);
		obj = U_field->_field[_x][_y]; //что в данной клетке
		cout << SGR((int)Color::GREEN); //поставили эффект для выбранной клетки
		paint(obj); //перекрасить клетку
		cout << CUP(_y * cell_size + 1, _x * 2 * cell_size + 1);
	}
}

void User_act::up()
{
	if (_y > 0)
	{
		cout << CUP(_y * cell_size + 1, _x * 2 * cell_size + 1);
		Cell obj = U_field->_field[_x][_y]; //что в данной клетке
		cout << SGR((int)Color::RESET); //убрать эффект с клетки, в которой мы находимся
		paint(obj); //перекрасить клетку
		_y -= 1;
		cout << CUP(_y * cell_size + 1, _x * 2 * cell_size + 1);
		obj = U_field->_field[_x][_y]; //что в данной клетке
		cout << SGR((int)Color::GREEN); //поставили эффект для выбранной клетки
		paint(obj); //перекрасить клетку
		cout << CUP(_y * cell_size + 1, _x * 2 * cell_size + 1);
	}
}

void User_act::down()
{
	
	if ((_y < term_lenght) and (_y < U_field -> getWIDTH() - 1))
	{
		cout << CUP(_y * cell_size + 1, _x * 2 * cell_size + 1);
		Cell obj = U_field->_field[_x][_y]; //что в данной клетке
		cout << SGR((int)Color::RESET); //убрать эффект с клетки, в которой мы находимся
		paint(obj); //перекрасить клетку
		_y += 1;
		cout << CUP(_y * cell_size + 1, _x * 2 * cell_size + 1);
		obj = U_field->_field[_x][_y]; //что в данной клетке
		cout << SGR((int)Color::GREEN); //поставили эффект для выбранной клетки
		paint(obj); //перекрасить клетку
		cout << CUP(_y * cell_size + 1, _x * 2 * cell_size + 1);
	}
}

void User_act::choose() 
{
	Plant* _plant;
	if(U_field->_field[_x][_y] == Cell::plant)
		return;
		
	Scope_Plants_Print();
	amount_of_plants++;
		
	U_field->_field[_x][_y] = Cell::plant;
	Cell obj = U_field->_field[_x][_y];
	
	cout << SGR((int)Color::GREEN); 
	_plant -> spawn(obj,  U_field);
	
		
}
void User_act::Scope_Plants_Print()
{
	cout << SGR((int)Color::RESET);
	Scope_plants--;
	
	cout  << CUP(term_lenght / 2 - 8, 31) << Scope_plants; 	
	if(Scope_plants < 10)
		cout  << " ";
		
	cout << CUP(_y * cell_size + 1, _x * 2 * cell_size + 1); 
}
void User_act::start() 
{
 	Rules* _rules;
	 Cell obj = U_field->_field[_x][_y];
	cout << SGR((int)Color::RESET);
	paint(obj);
	
	cout  << CUP(term_lenght / 2 - 8, 1) << "\033[K";
	_rules -> spawn(U_field);
}
/*
int main()
{
	//Field D_field;
	//Draw H(&D_field);
	bool gameRunning = true;
	struct termios oldSettings;
	Keyboard key_contr;
	cout << "\033[2J";
	Field field(6, 5);
	User_act user(&field, key_contr);
	
	field.print();
	cout << CUP(1,1);
	oldSettings = key_contr.kbin();
	
	while (gameRunning)
	{
		user.key_control();
	}
	tcsetattr(0, TCSANOW, &oldSettings);
}

/*void User_act::choose()
{
	//ф-я расскраски клетки
	//ф-я запоминающая наш выбор
	if (U_field->_field[_x][_y] != Cell::empty)
		active_object = field[_x][_y];
	else if (active_object != Cell::empty)
	{
		field[_x][_y] = active_object;
		cout << SGR(Color::RED);
		_field
		//нарисовать это
	}
	
	if (active_object != Cell::empty)
	{
		field[_x][_y] = active_object;
		
	}
}*/


