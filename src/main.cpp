#include "control.h"

Game_control* game_pointer;

void end_1(int signal)
{
if (signal == SIGINT) { //если нажали ^C, то очистить терминал, удалить game
		cout << SGR((int)Color::RESET);
		cout << "\033[2J"; //system("clear");
		cout << CUP(1,1);
		exit(0);
		}
}

void end_2(int signal)
{
if (signal == SIGINT) { //если нажали ^C, то очистить терминал, удалить game
		cout << SGR((int)Color::RESET);
		cout << "\033[2J"; //system("clear");
		cout << CUP(1,1);
		delete game_pointer;
		exit(0);
		}
}

int main()
{	
	std::signal(SIGINT, end_1);
	
	Game_control* Game = new Game_control();
	game_pointer = Game;
		
	std::signal(SIGINT, end_2);
	
	Game->steps();
	
	game_pointer = nullptr;
	delete Game;
	
	return 0;
}

