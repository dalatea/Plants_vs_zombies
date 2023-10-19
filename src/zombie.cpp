#include "objects.h"
#include "zombie.h"

int Plants_death = 0;
int Zombie_death = 0;

void Zombie::Set_Position(Zombie& zombie)
{
	uint64_t ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); //определение милисекунд, чтобы рандом так радном был
	srand(ms);
	int i = length, j = 0;
	j = rand() % width ; //формула на рандомную клеточку по y
	
	zombie.x = i;
	zombie.y = j;
	
	zombie.parametr = j / 2;
	zombie.Test = 0;
	
	if(zombie.y == 4)
		zombie.parametr--;// условие, чтобы правильно настроить курсор для рисовки 
	else if(zombie.y == 1)
		zombie.parametr++;
	
}


