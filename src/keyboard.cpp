#include "keyboard.h"

termios Keyboard::kbin()
{
	char symb;
	struct termios oldSettings, newSettings; //нужна для того, чтобы программа не ждала enter для реагирования на ввод
	tcgetattr(0, &oldSettings); //сохраняем характеристики стандартного терминала
	newSettings = oldSettings;
	newSettings.c_lflag &= ~(ICANON | ECHO); // ~ICANON отключает ожидание enter, ~ECHO отключает вывод символов функцией getchar
	tcsetattr(0, TCSANOW, &newSettings); 
	int flags = fcntl(0, F_GETFL);
	fcntl(0, F_SETFL, flags | O_NONBLOCK);	
	return oldSettings;
}

void Keyboard::read_key()
{
	char input;
	input = getchar();
	if (input != EOF)
	{
		switch (tolower(input)){
			case 0:
				_key = Key::Nothing;
				break;
			case 'w':
				_key = Key::Up;
				break;
			case 'a':
				_key = Key::Left;
				break;
			case 'd':
				_key = Key::Right;
				break;
			case 's':
				_key = Key::Down;
				break;
			case 32:
				_key = Key::Space;
				break;
			case '\n':
				_key = Key::Enter;
				break;
		}
	}
}
