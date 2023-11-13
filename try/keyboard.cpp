#include "keyboard.h"

Keyboard::Keyboard(Current_key key)
{
	term_set();
	pressed_key = key;
	pressed_key._key = Key::Nothing;
}

void Keyboard::term_set()
{
	char symb;
	struct termios newSettings; //нужна для того, чтобы программа не ждала enter для реагирования на ввод
	tcgetattr(0, &_oldSettings); //сохраняем характеристики стандартного терминала
	newSettings = _oldSettings;
	newSettings.c_lflag &= ~(ICANON | ECHO); // ~ICANON отключает ожидание enter, ~ECHO отключает вывод символов функцией getchar
	tcsetattr(0, TCSANOW, &newSettings); 
	int flags = fcntl(0, F_GETFL);
	fcntl(0, F_SETFL, flags | O_NONBLOCK);	
}

void Keyboard::term_unset()
{
	tcsetattr(STDIN_FILENO, TCSANOW, &_oldSettings);
}

void Keyboard::read_key() //считывание с клавиатуры, сохраняем клавишу в структуру Current_key
{
	char input;
	input = getchar();
	if (input != EOF)
	{
		switch (tolower(input)){
			case 0:
				pressed_key._key = Key::Nothing;
				break;
			case 'w':
				pressed_key._key = Key::Up;
				break;
			case 'a':
				pressed_key._key = Key::Left;
				break;
			case 'd':
				pressed_key._key = Key::Right;
				break;
			case 's':
				pressed_key._key = Key::Down;
				break;
			case 32:
				pressed_key._key = Key::Space;
				break;
			case '\n':
				pressed_key._key = Key::Enter;
				break;
		}
	}
}

Keyboard::~Keyboard()
{
	term_unset();
}
