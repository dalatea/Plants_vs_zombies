#include "objects.h"


void Plant::spawn(Cell obj, Field* U_field)
{
	Keyboard key_cntrl;
	User_act User_a(U_field, key_cntrl);
	if(obj != Cell::empty)
	{
		
		User_a.paint(obj);
	}
	cout << leftCUP(6) << upCUP(2);
}

void Plant::Set_position(Field* U_field, std::vector <Plant>& plants)
{
	int k = 0;
	
	for (int i = 0; i < width; i++)
		for (int j = 0; j < length; j++)
			if(U_field -> _field[i][j] == Cell::plant)
			{
				plants.at(k).x = i;
				plants.at(k).y = j;
				k++;
			}	
}
void Bullet::Set_position(std::vector <Plant>& plants, std::vector<Bullet>& bullets)
{
	int k = bullets.size() / plants.size() - 1;
	
	for(int i = 0; i < plants.size() ; i++)
	{
	
		bullets.at(k * plants.size() + i).x = plants.at(i).x ;
		bullets.at(k * plants.size() + i).x1 = plants.at(i).x;
				
		bullets.at(k * plants.size() + i).y = plants.at(i).y;
		
		bullets.at(k * plants.size() + i).parametr = plants.at(i).y / 2;
		
		if(bullets.at(k * plants.size() + i).y == 4)
			bullets.at(k * plants.size() + i ).parametr--;// условие, чтобы правильно настроить курсор для рисовки 
		else if(bullets.at(k * plants.size() + i).y == 1)
			bullets.at(k * plants.size() + i ).parametr++;
		
		bullets.at(k * plants.size() + i).Test = 6;
		//if((bullets.at(k).x > length) or (bullets.at(k).y > width))
		//	i--;
	}
	
}
