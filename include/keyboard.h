#include "game_settings.h"
#include <termios.h>
#include "fcntl.h"
#include "unistd.h"
#include <stdio.h>
#include <ctype.h>
class Keyboard
{
private:
	Key _key;
public:
	Keyboard(Key key = Key::Nothing) : _key(key) {};
	void read_key();//чтение клавиши с клавиатуры
	termios kbin();//настройка терминала перед чтением с клавиатуры
	Key getKey() {return _key;};//получение клавиши из приватных полей
	void default_key() {_key = Key::Nothing;};//при отсутствии нажатия 
};
