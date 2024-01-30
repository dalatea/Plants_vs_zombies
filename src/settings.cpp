#include "settings.h"

Settings::Settings(Graphics_mode g, int c_size, int _term_width, int _term_length, int level, int plants, std::string name, int zombies, int _f_width, int _f_length) 
: 
g_mode(g),
cell_size(c_size), 
term_width(_term_width), 
term_length(_term_length), 
_level(level),
Scope_plants(plants),
User_NAME(name),
amount_of_zombie(zombies),
f_width(_f_width),
f_length(_f_length)
{
	amount_of_plants = 0;
};
