#include "control.h"

Game_control::Game_control()
{
	ifstream in("./settings.txt");
	if (in.is_open())
	{
		int level_number;
		std::string User_NAME;
		string word, s;
		int c, plants, zombie, f_width, f_length, cell_size;
		string l;
	
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
		
		level_number = level();//всё, что нужно для заполнения Settings
		User_NAME = user_name();
		Graphics_mode g_mode = graphics();
		
		
		l = to_string(level_number);
		while (!in.eof())
		{
			getline(in, s);
			if (s == "#CELL_SIZE{")
			{
				getline(in, s);
				cell_size = stoi(s);
				getline(in, s);
			}
			if (s[1] == 'L' and (l[0] == s[size("#LEVEL_")-1]))
			{
				getline(in, s);
				istringstream iss(s);
				iss >> plants >> zombie >> f_width >> f_length;
				getline(in, s);
			}
		}
		cout << "\033[?25l"; //спрятать курсор
		
		_set = new Settings(g_mode, cell_size, ws.ws_col, ws.ws_row, level_number, plants, User_NAME, zombie, f_width, f_length);
	
		field_model = new Field_Model(*_set);
	
		field_view = new Field_View(field_model, _set);
		
		rules = new Rules(field_view, field_model, _set);
	
		struct Current_key _current_key;
		current_key = _current_key;
		user = new Keyboard(&current_key);
		user->read_key();
		current_key._key = Key::Nothing;
	
		struct User_coord _u_coord;
		u_coord = _u_coord;
	
		_step = Steps::put_plants;
	}
	else
	{
		cout << "No configuration file" << endl;
		exit(0);
	}
	in.close();
}

int Game_control::level()
{
	int level_exit_code = 0;
	int level_number;
	cout << "Choose your level from 1 to 5\n";
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
	cout << "\nEnter your name\n";
	cin >> name;
	return name;
}

Graphics_mode Game_control::graphics()
{
	int graphics;
	cout << "\nChoose graphics\n\n";
	cout << "Press 1 for symbol graphics\n";
	cout << "Press 2 for color graphics\n";
	cin >> graphics;
	if (graphics == 1)
		return Graphics_mode::Symbol;
	else if (graphics == 2)
		return Graphics_mode::Escape;
	else
	{
		cout << "Error\n";
		exit(0);
	}
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
		user->read_key();
		if(_set->getScope_plants() == 0 or current_key._key == Key::Enter)
		{
			Cell obj = field_model -> getField()[u_coord.x][u_coord.y];
			field_view -> Field_View::paint_cell(obj, field_view->reset());
			cout << leftCUP(6) << upCUP(2);
			_step = Steps::zombie_attack;
		}
		move();
	}
}

void Game_control::zombie_attack()
{
	int width = field_model -> getWidth();
	int length = field_model -> getLength(); 
	
	
	_set -> assignAmount_of_zombie(width * 5);
	//int amount_of_zombie = 2;//width;
	
	//int zombie_count = 1; // сколько зомби на поле
	int time_count = 1;
	rules -> assignzombie_count(1);
	bool procces = 1;
	_set -> assignZombie_death(0);
	
	int amount_of_plants = _set -> getAmount_of_plants();
	
	std::vector <Zombie> zombies(_set -> getAmount_of_zombie());
	Zombie* z;
	
	std::vector <Plant> plants(amount_of_plants );
	auto iter = plants.cbegin();
	Plant plant(5,1);
	Plant* p;
	
	std::vector <Bullet> bullets(amount_of_plants);
	bullets.reserve(amount_of_plants * 100);
	Bullet bullet;
	Bullet* b;
	
	for(int k = 0; k < _set -> getAmount_of_zombie() ; k++) //можно в функцию перенести
	{
		z -> Set_Position(zombies.at(k), field_model);  // для каждого зомби определяем,то где они спавнятся, на каком y-ke
		usleep(2000);	 		//  обязательно! иначе будут одинаковые y
	}
	p -> Set_position(field_model, plants); // определяем где находятся растения
	b -> Set_position(plants, bullets); // определяем где находятся пули
	
	
	while(procces)
	{
	
		if(!zombies.empty())
		{
			if(time_count % 3 == 0)
			{
				procces = rules -> All_Zombie_Move(rules -> getz_c(), zombies, plants);
				if(rules -> getz_c() < _set -> getAmount_of_zombie())//нужно вот здесь исправить условие у нас конечно зомби коунт уменьшается когда его убиваем но тогда у нас начинает работать это условие которое увеличивает зомби каунт возможно в этом проблема
				{
					cout << CUP(2,1) << rules -> getz_c();
					int z_c = rules -> getz_c();
					rules -> assignzombie_count(z_c + 1);
				}
			
			}
		}
		else
			break;
		if(rules -> getz_c() == 0)
			break;
		if(!bullets.empty())
			rules -> All_Bullet_Move(plants, zombies, bullets);

		if(!plants.empty())
		{
			if((time_count % 10 == 0) )
			{
				for(int i = 0; i < plants.size(); i++)
					bullets.push_back(bullet);  // добавляю в конец вектора пуль еще пули в количестве растений
				b -> Set_position(plants, bullets);
			}	
		}
		usleep(500000);
		time_count++;
	}
	
	game_over(procces);
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
			//choose();
			rules -> choose(u_coord);			
			break;
		/*case Key::Enter:        !!!(вроде)не нужно так как обработка enter есть в put_plants
			start();
			break;*/
		default:
			break;
	}
	user->default_key();
}

Game_control::~Game_control()
{
	cout << "\033[2J"; //system("clear");
	cout << CUP(1,1);
	delete _set;
	delete field_view;
	delete field_model; 
	delete user;
}


/*
void end(int signal)
{
	if (signal == SIGINT) //если нажали ^C, то очистить терминал, удалить game
	{ 
		delete game_pointer;
		exit(0);
	}
}*/
void Game_control::game_over(bool procces)
{
	if (procces == 0) //если нажали ^C, то очистить терминал, удалить game
	{ 
		cout << SGR((int)Color::RED) << CUP(_set ->getTerm_length() - _set ->getTerm_length()/3 - 1, 1)  << "GAME OVER. ZOMBIE WIN"; 
	}
	else
		cout << SGR((int)Color::GREEN) << CUP(_set ->getTerm_length() - _set ->getTerm_length()/3 - 1, 1)  << "GAME OVER. PLANTS(YOU) WIN"; 
}
/*
int main()
{	
	Game_control* Game = new Game_control;
	game_pointer = Game;
	
	std::signal(SIGINT, end);
	
	Game->steps();
	
	game_pointer = nullptr;
	delete Game;
	
	return 0;
}*/


