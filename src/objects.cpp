#include "objects.h"


bool Plant::Set_position(Field_Model* U_field, std::vector <Plant>& plants)
{
	int k = 0;
	int length = U_field -> getLength();
	int width = U_field -> getWidth();
	//Cell** field = Field_Model::getField();
	bool procces = true;
	if(plants.empty())
	{
		procces = false;
		return procces;
	}
	for (int i = 0; i < length; i++)
		for (int j = 0; j < width; j++)
			if(U_field -> getField()[i][j] == Cell::plant)
			{
				plants.at(k)._x = i;
				plants.at(k)._y = j;
				k++;
			}
	return procces;	
}
void Bullet::Set_position(std::vector <Plant>& plants, std::vector<Bullet>& bullets)
{
	int k = bullets.size() / plants.size() - 1;
	
	int x, y, parametr, Test;
	
	for(int i = 0; i < plants.size() ; i++)
	{
	
		bullets.at(k * plants.size() + i).assignx( plants.at(i).getx() )  ;
		
		bullets.at(k * plants.size() + i).assigny( plants.at(i).gety());
		
		bullets.at(k * plants.size() + i)._parametr = plants.at(i).gety() / 2;
		
		if(bullets.at(k * plants.size() + i)._y == 4)
			bullets.at(k * plants.size() + i )._parametr--;// условие, чтобы правильно настроить курсор для рисовки 
		else if(bullets.at(k * plants.size() + i)._y == 1)
			bullets.at(k * plants.size() + i )._parametr++;
		
		bullets.at(k * plants.size() + i)._Test = 6;
		//if((bullets.at(k).x > length) or (bullets.at(k).y > width))
		//	i--;
	}
}

void Zombie::Set_Position(Zombie& zombie, Field_Model* U_field, Settings* _set)
{
	uint64_t ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); //определение милисекунд, чтобы рандом так радном был
	srand(ms);
	int length = U_field -> getLength();
	int width = U_field -> getWidth();
	int i = length, j = 0;
	j = rand() % width ; //формула на рандомную клеточку по y
	
	zombie._x = i;
	zombie._y = j;
	
	zombie._parametr = j / 2;
	
	if(_set -> getG_mode() == Graphics_mode::Escape)
		zombie._Test = 1;
	else
		zombie._Test = 0;

	if(zombie._y == 4)
		zombie._parametr--;// условие, чтобы правильно настроить курсор для рисовки 
	else if(zombie._y == 1)
		zombie._parametr++;
}

void Object::assignx(int x)
{
	_x = x;
}

void Object::assigny(int y)
{
	_y = y;
}

void Object::assignTest(int Test)
{
	_Test = Test;
}

void Object::assignparametr(int parametr)
{
	_parametr = parametr;
}

void Object::assignhp(int hp)
{
	_hp = hp;
}

void Object::assignat(int at)
{
	_at = at;
}

