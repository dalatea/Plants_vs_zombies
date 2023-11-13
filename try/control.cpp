#include "control.h"

Game_control::Game_control()
{
	struct winsize ws;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws); //получаем текущий размер терминала
	if (ws.ws_row < 50 or ws.ws_col < 100)
		cout << term_size(50, 100); //устанавливаем минимальный размер, если окно меньше
	cout << "\033[2J"; //system("clear");
	cout << CUP(1,1);
	
	Graphics_mode g_mode = Graphics_mode::Symbol;
	Settings set(g_mode, ws.ws_col, ws.ws_row, 1);
	settings();
	_set = set;
	
}

void Game_control::settings()
{
	int level_exit_code = 0;
	cout << "Chose your level from 1 to 5\n";
	cin >> _set._level;
	if((level_number > 5)or(level_number < 1))
	{
        	cout << "Error\n";
       		exit(level_exit_code);
    	}
    
    	cout << "Write your name\n";
    	cin >> _set.User_NAME_;
    	
    	return level_number;
        
}

void Game_control::run()
{
	Field_Model field(set);
	Field_View view(&field, &set);
	struct Current_key current_key;
	Keyboard keyboard(current_key);
	
	gamerunning = true;
}

int Game_control::step()
{

}

int main()
{
	view.print();
	
	while (gameRunning)
	{
		keyboard.read_key();
		usleep(10000);
		cout << int(keyboard.get_Key());
	}
}

