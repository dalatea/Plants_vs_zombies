#include "control.h"

Game_control* game_pointer;

Game_control::Game_control()
{
	int level_number;
	std::string User_NAME;
	
	struct winsize ws;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws); //получаем текущий размер терминала
	if (ws.ws_row < 50 or ws.ws_col < 100)
	{
		cout << term_size(50, 100); //устанавливаем минимальный размер, если окно меньше
		ws.ws_row = 50;
		ws.ws_col = 100;
	}
	cout << "\033[2J"; //system("clear");
	cout << CUP(1,1);
	
	Graphics_mode g_mode = Graphics_mode::Symbol; //всё, что нужно для заполнения Settings
	level_number = level();
	User_NAME = user_name();

	int plants = (level_number * 6) * 2 / 3;
	
	_set = new Settings(g_mode, ws.ws_col, ws.ws_row, level_number, plants, User_NAME);
	
	field_model = new Field_Model(*_set);
	
	field_view = new Field_View(field_model, _set);
	/*Rules _rules();
	rules = _rules;*/
	
	struct Current_key _current_key;
	current_key = _current_key;
	keyboard = new Keyboard(&current_key);
	keyboard->read_key();
	current_key._key = Key::Nothing;
	
	struct User_coord _u_coord;
	u_coord = _u_coord;
	
	_step = Steps::put_plants;
}

int Game_control::level()
{
	int level_exit_code = 0;
	int level_number;
	cout << "Chose your level from 1 to 5\n";
	cin >> level_number;
	if((level_number > 5)or(level_number < 1))
	{
        	cout << "Error\n";
       		exit(level_exit_code);
    	}   	
    	return level_number;
}

std::string Game_control::user_name()
{
	std::string name;
	cout << "Enter your name\n";
	cin >> name;
	return name;
}

void Game_control::steps()
{
	switch(_step)
	{
		case Steps::put_plants :
			put_plants();
		case Steps::zombie_attack :
			zombie_attack();
	}
}

void Game_control::put_plants()
{
	field_view->print();
	while (_step == Steps::put_plants)
	{
		keyboard->read_key();
		if(_set->getScope_plants() == 0 or current_key._key == Key::Enter)
		{
			_step = Steps::zombie_attack;
			cout << "\033[2J";
		}
		move();
	}
	cout  << CUP(_set->getTerm_length() / 2 - 7, 1) << "\033[K";
}

void Game_control::zombie_attack()
{
	cout << "\033[2J";
	cout << "attack!!!";
}

void Game_control::move()
{
	switch(current_key._key)
	{
		case Key::Nothing:
			break;
		case Key::Up:
			field_view->up(&u_coord);
			break;
		case Key::Down:
			field_view->down(_set->getTerm_length(), &u_coord);
			break;
		case Key::Left:
			field_view->left(&u_coord);
			break;
		case Key::Right:
			field_view->right(_set->getTerm_width(), &u_coord);
			break;
		case Key::Space:
			choose();			
			break;
		/*case Key::Enter:        !!!(вроде)не нужно так как обработка enter есть в put_plants
			start();
			break;*/
		default:
			break;
	}
	keyboard->default_key();
}

Game_control::~Game_control()
{
	cout << "\033[2J"; //system("clear");
	cout << CUP(1,1);
	delete _set;
	delete field_view;
	delete field_model; 
	delete keyboard;
}

void Game_control::choose() 
{
	int _x = u_coord.x;
	int _y = u_coord.y;
	Cell** _field;
	_field = field_model->getField();
	
	//Plant* _plant;
	
	if(_field[_x][_y] == Cell::plant)
		return;
		
	field_view->Scope_Plants_Print(_set, &u_coord);
		
	_field[_x][_y] = Cell::plant;
	Cell obj = _field[_x][_y];
	
	cout << SGR((int)Color::GREEN); 
	//_plant -> spawn(obj,  U_field);
	
		
}

void end(int signal)
{
if (signal == SIGINT) { //если нажали ^C, то очистить терминал, удалить game
		delete game_pointer;
		exit(0);
		}
}

int main()
{	
	Game_control* Game = new Game_control;
	game_pointer = Game;
	
	std::signal(SIGINT, end);
	
	Game->steps();
	
	game_pointer = nullptr;
	delete Game;
	
	return 0;
}


