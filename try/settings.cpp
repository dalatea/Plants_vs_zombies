#include "settings.h"

Settings::Settings(Graphics_mode g,int _term_width, int _term_length, int level) 
: 
g_mode(g),
cell_size(6), 
term_width(_term_width), 
term_length(_term_length), 
_level(level){};
