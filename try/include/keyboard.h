#pragma once

#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#include "settings.h"
#include "user_input.h"

/*#include "unistd.h"
#include <stdio.h>
#include <ctype.h>*/

class Keyboard : public User_input{
private:
	struct termios _oldSettings; //начальные настройки терминала
	void term_set();//настройка терминала перед вводом
	void term_unset(); //настройка терминала после завершения программы
public:
	Keyboard(Current_key key);
	void read_key();//чтение клавиши с клавиатуры
	Key get_Key() {return pressed_key._key;};
	~Keyboard();
};
