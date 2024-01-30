#pragma once

#include "settings.h"

class User_input
{
protected:
	Current_key* pressed_key;
public:
	virtual void read_key() = 0;
	virtual void default_key() = 0;
	virtual ~User_input() = default;
};

