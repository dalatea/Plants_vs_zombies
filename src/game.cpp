#include "game.h"

int Scope_plants;
std::string User_NAME;

struct termios originalSettings;

int Game::game_menu()
{
    //unsigned level_number = 1;
    int level_exit_code = 0;
    cout << "Chose your level from 1 to 5\n";
    cin >> level_number;
    if((level_number > 5)or(level_number < 1))
    {
        cout << "Error\n";
        exit(level_exit_code);
    }
    
    cout << "Write your name\n";
    cin >> User_NAME;
    
    return level_number;
        
}
/*
int Game::start_game(bool apples)
{
    
}*/

int Game::start_game()
{
	struct winsize ws;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws); //получаем текущий размер терминала
	if (ws.ws_row < 50 or ws.ws_col < 100)
		//cout << term_size(50, 100); //устанавливаем минимальный размер, если окно меньше
		//system("resize -s 50 100");
		cout << "\e[8;40;150t";  //у меня не работает терм сайз поэтому юзаю через cout изменение терминала
	cout << "\033[2J"; //system("clear");
	cout << CUP(1,1);
	
	//std::signal(SIGINT, end_game); //следим за тем, чтобы не нажали ^C
	
    	int level_number;
   	level_number = game_menu();
   	cin.ignore();
	bool gameRunning = true;
	Keyboard key_contr;
	
	Field field(6,level_number);
	
	User_act user(&field, key_contr);
	
	cout << "\033[2J";
	field.print();
	cout << CUP(term_lenght / 2 - 6, 8) << level_number << CUP(1,1);
	
	originalSettings = key_contr.kbin();
	
	Scope_plants = (level_number * 6) * 2 / 3;
	
	cout << CUP(term_lenght / 2 - 4, 12) << User_NAME;
	
	cout <<	CUP(term_lenght / 2 - 8, 1);
	cout << "You can put this many plants: ";
	cout << Scope_plants;
	cout << CUP(1,1);
	while ((gameRunning) or (Scope_plants > 0))
	{
		user.key_control();
	}
	cout  << CUP(term_lenght / 2 - 7, 1) << "\033[K"; 	
	user.start();
	return 0;
}

int Game::start_level(unsigned level_number)
{
    
    cout << "\033[2J";
    Field field(6, level_number);
    field.print();

    return 0;  
}

void Game::end_game(int signal)
{
	if (signal == SIGINT) { //если нажали ^C, то очистить терминал
		cout << "\033[2J";
		cout << CUP(1,1);
		tcsetattr(STDIN_FILENO, TCSANOW, &originalSettings);
		exit(0);
	}
}

void Game::END(bool code)
{
	//Field field(6, level_number);
	if(code)
		cout << SGR((int)Color::RESET) << CUP(term_lenght / 2 - 8, 1) << "GAME OVER. ZOMBIE WINS";
	else
		cout << SGR((int)Color::RESET) << CUP(term_lenght / 2 - 8, 1) << "GAME OVER. PLANTS WINS";
	
	//field.print();
	
	
}
