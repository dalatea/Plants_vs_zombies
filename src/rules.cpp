#include "rules.h"

int length;
int width;
int amount_of_zombie;
int zombie_count = 1;
int time_count;

void Rules::spawn(Field* U_field)
{
	width = U_field -> getWIDTH();
	length = U_field -> getLENGTH(); 
	
	amount_of_zombie = 16;//width;
	
	//int zombie_count = 1; // сколько зомби на поле
	
	time_count = 1;
	
	bool procces = 1;
	
	Game n;
	
	std::vector <Zombie> zombies(amount_of_zombie);
	Zombie* z;
	
	std::vector <Plant> plants(amount_of_plants );
	auto iter = plants.cbegin();
	Plant plant;
	Plant* p;
	
	std::vector <Bullet> bullets(amount_of_plants  );
	bullets.reserve(amount_of_plants * 100);
	Bullet* b;
	
	for(int k = 0; k < amount_of_zombie ; k++) //можно в функцию перенести
	{
		z -> Set_Position(zombies.at(k));  // для каждого зомби определяем,то где они спавнятся, на каком y-ke
		usleep(1000);	 		//  обязательно! иначе будут одинаковые y
	}
	p -> Set_position(U_field, plants); // определяем где находятся растения
	b -> Set_position(plants, bullets); // определяем где находятся пули
	
	
	while(procces)
	{
		//if(time_count % 2 == 0)
		if(!bullets.empty())
			All_Bullet_Move(U_field, plants, zombies, bullets);
				
		if(time_count % 3 == 0)
		{
			procces = All_Zombie_Move(U_field, zombie_count, zombies, plants);
			if(zombie_count != amount_of_zombie)
				zombie_count++;
		}
		
		usleep(500000);
		time_count++;
	}
	
	n.END(1);
}
void Rules::All_Bullet_Move(Field* U_field, std::vector <Plant>& plants, std::vector <Zombie>& zombies,std::vector <Bullet>& bullets)
{
	auto iter_z = zombies.cbegin();
	auto iter_begin = bullets.cbegin();
	Graphics_Sym* _graphics = new Graphics_Sym;
	std::vector <int> mas_check(0);
	mas_check.reserve(amount_of_plants);
	
	int k = 0, l = 0;
	bool check = 0;
	
	Bullet bullet;
	Bullet* b;
	
	while(k < bullets.size() )
	{
		//cout << CUP(2,1) << zombies.at(0).x << " " << zombies.at(0).y << endl;
		//cout <<  bullets.at(k).x << " " << bullets.at(k).y << endl;
		check = 0;
		if(bullets.at(k).x < length)
		if((U_field -> _field[bullets.at(k).x][bullets.at(k).y] == Cell::zombie)) //ошибка тут, почему?????????
		{
			l = Search(bullets.at(k), zombies); // находим какого зомби у нас будет бить пуля
			//cout << CUP(4,1) << zombies.at(l).Test << " " << bullets.at(k).Test;
			cout << CUP(4,1) << l;
			if(bullets.at(k).Test + 1 == 10 - zombies.at(l).Test)
			{
				zombies.at(l).hp = BZattack(zombies.at(l), bullets.at(k));
				
				if(zombies.at(l).hp <= 0)
				{
					zombies.erase(iter_z + l);
					Zombie_death += 1;
					zombie_count--;
				
					cout << SGR((int)Color::RESET);
					cout << CUP(term_lenght / 2 - 6, 40) << Zombie_death;
					
					U_field -> _field[bullets.at(k).x][bullets.at(k).y] = Cell::empty;
				}
				std::advance(iter_begin , k); 
				bullets.erase(iter_begin);
				iter_begin = bullets.cbegin();
				k++;
				continue;
			}
		}
		Bullet_Move(U_field, bullets.at(k), _graphics);
		if((bullets.at(k).x >= length) )
		{
			mas_check.push_back(k);
			check = 1;
		}
		k++;
	}
	
	
	if(!mas_check.empty())
		Bullets_erase(mas_check, bullets);
	if(!plants.empty())
	{
		
		if((time_count % 10 == 0) )
		{
			for(int i = 0; i < plants.size(); i++)
				bullets.push_back(bullet);  // добавляю в конец вектора пуль еще пули в количестве растений
			b -> Set_position(plants, bullets);
		}
			
	}
}

void Rules::Bullets_erase(std::vector<int>& mas_check, std::vector <Bullet>& bullets)
{
	auto iter_begin = bullets.cbegin();
	for(int k = 0; k < mas_check.size(); k++)
	{
		//удаляю номер элемента, который хранится в mas_check
		std::advance(iter_begin , mas_check.at(k) - k); //обязательно (- k) тк удаляя у нас изменяются номера элементов, и тогда mas_check начинает хранить уже устарешвие номера эл-ов
		bullets.erase(iter_begin);
		iter_begin = bullets.cbegin();
	}
	mas_check.clear();
}

void Rules::Bullet_Move(Field* U_field, Bullet& bullet, Graphics_Sym* _graphics)
{		
	int x = 0 , y = 0;
	bool check = false;
	
	x = (bullet.y * cell_size) + bullet.parametr ; // y по коориданатам 
	
	cout << SGR((int)Color::RESET);
	
	if(bullet.Test == (cell_size - 2) * 2 + 1) //такое условие, чтобы мы находились внутри клетки
	{
		if(bullet.parametr != 0)
			cout << CUP(x + 2,(bullet.x  * 2 * cell_size) + bullet.Test  ) << " "; 
		else
			cout << CUP(x + 3, (bullet.x  * 2 * cell_size) + bullet.Test  ) << " "; 
		bullet.x++;
		bullet.Test = 1;
	}
	if(length <= bullet.x) //Segmantation тк у у филда косянчеы координаты, исправить и норм
	{
		
		return;
	}
	y = bullet.x * 2 * cell_size + bullet.Test ;
	if((bullet.Test + 1 == 5))
	{
		if(U_field -> _field[bullet.x][bullet.y] == Cell::plant)
		{
		if(bullet.parametr != 0)		
				cout << CUP(x + 1 + bullet.parametr, y) << " " ;
			else
				cout << CUP(x + 3, y ) << " ";		
		bullet.Test ++;
		check = true;
		}
	}
		
	y = bullet.x * 2 * cell_size + bullet.Test ;
	
	if((bullet.Test != 1) and (check == false))
	{
		if(bullet.parametr != 0)		
			cout << CUP(x + 1 + bullet.parametr, y) << " " ;
		else
			cout << CUP(x + 3, y ) << " ";
	}
	
	cout << CUP(x, y) ;
	_graphics -> draw(Cell::bullet);
		
	bullet.Test++;
	cout << CUP(1,1);	

}
unsigned Rules::Search(Bullet bullet, std::vector <Zombie>& zombies)
{
	for(int i = 0; i < zombies.size(); i++)
		if((bullet.x == zombies.at(i).x - 1) and (bullet.y == zombies.at(i).y))
			return i;
	return 0;
}

int Rules::BZattack(Zombie zombie, Bullet bullet)
{
	zombie.hp -= bullet.at;
	return zombie.hp;	
}

bool Rules::All_Zombie_Move(Field* U_field, int zombie_count, std::vector <Zombie>& zombies, std::vector <Plant>& plants)
{
	bool procces = true;
	unsigned l, p = 0;
	auto iter = plants.cbegin();
	bool check = false;
	std::vector<int> mas_check(0);
	mas_check.reserve(plants.size() + 1);
	
	
	Graphics_Sym* _graphics = new Graphics_Sym;
	
	for(int k = 0; k < zombie_count; k++)
	{	
		if(Alinement(U_field, zombies.at(k))) //проверка на то что в клетке
		{
			l = Search(zombies.at(k), plants); // находим какое растение у нас будет бить зомби
			plants.at(l).hp = ZPattack(zombies.at(k), plants.at(l)); // функция атаки
			if(plants.at(l).hp == 0)
			{
				U_field -> _field[zombies.at(k).x - 1][zombies.at(k).y] = Cell::zombie;
				
				//cout << CUP(plants[l].y * (cell_size) + zombies[k].parametr, plants[l].x * 2 * cell_size - 4 ) << "R";

				mas_check.push_back(l);
				check = 1;
				
				
				Plants_death += 1;
				cout << SGR((int)Color::RESET);
				cout << CUP(term_lenght / 2 - 6, 24) << Plants_death;
			}
		}
		else 
			Zombie_Move(U_field, zombies.at(k), _graphics);
		if(zombies.at(k).x == 0) //если дошли до конца то ломаем цикл
		{
			
			procces = false;
			break;
		}	
			//usleep(50000);
	}
	if(check)
		Plants_erase(mas_check, plants);
	
	return procces;
}
void Rules::Plants_erase(std::vector <int>& mas_check, std::vector <Plant>& plants)
{
	auto iter_begin = plants.cbegin();
	int l = 0;
	cout << mas_check.size() << endl;
	for(int k = 0; k < mas_check.size() ; k++)
	{
		amount_of_plants--;
		std::advance(iter_begin , mas_check.at(k) - k);
		plants.erase(iter_begin);
		iter_begin = plants.cbegin();
		
		//plants.erase(iter_begin + mas_check.at(k)); //удаляю номер элемента, который хранится в mas_check
		//iter_begin = plants.cbegin();
		//l++;
	}
	//plants.resize(amount_of_plants);
	cout << CUP(1,1) << plants.size() << endl;
	mas_check.clear();
}

void Rules::Zombie_Move(Field* U_field, Zombie& zombie, Graphics_Sym* _graphics)
{		
	int x = 0 , y = 0;
	 
	int count = 0;
	
	x = zombie.y * (cell_size) + zombie.parametr;
	
	if(zombie.Test == (cell_size - 2) * 2 ) //такое условие, чтобы мы находились внутри клетки
	{
		if(zombie.parametr != 0) //ЧТОБЫ КОГДА ЗОМБИ УШЕЛ ИЗ КЛЕТКИ, ЕГО Z ПОЧИСТИЛАСЬ
			cout << CUP(x + 2, zombie.x * 2 * cell_size - 2 - zombie.Test) << " "; 
		else
			cout << CUP(x + 3, zombie.x * 2 * cell_size - 2 - zombie.Test) << " "; //ОЧИСТКА ПРЕДЫДУЩЕГО ПОЛОЖЕНИЯ
		zombie.x--;
		zombie.Test = 0;

	}
	
	cout << SGR((int)Color::RED);

	if(zombie.x == 0) //УСЛОВИЕ ОСОБОЕ ДЛЯ ПОСЛЕДНЕЙ КЛЕТОЧКИ
		y = length - count + length / 2 - 1;
	else 
		y = zombie.x * 2 * cell_size - 4 - zombie.Test;
		
	//ЧТОБЫ КЛЕТОЧКИ БЫЛИ ЦЕЛЫЕ И + НЕ ОЧИЩАЛИСЬ
	if(zombie.Test != 0)	
		(zombie.parametr != 0 )? cout << CUP(x + 1 + zombie.parametr, y + 2) << " " : cout << CUP(x + 3, y + 2) << " " ;
	
	cout << CUP(x, y) ; //устанавливаем курсор, чтобы правильно нарисовать зомби
		
	_graphics -> draw(Cell::zombie);
		
	zombie.Test++; 

}

bool Rules::Alinement(Field* U_field, Zombie& zombie)
{
	cout << SGR((int)Color::RESET);

	if(U_field -> _field[zombie.x - 1][zombie.y] == Cell::empty)
	{ 
		U_field -> _field[zombie.x - 1][zombie.y] = Cell::zombie; // говорим, что в этой клеточке находится зомби
		return 0;
	}
	else if(U_field -> _field[zombie.x - 1][zombie.y] == Cell::plant)
		return 1;

	else
		return 0; 
	
	
	//if(zombie.hp > 0) //если у зомби остается хп, то мы двигаемся дальше
		//return;//Zombie_Move_One_Cell(U_field, i ,j);
	//else
		 //если зомби умирает, то мы заканчиваем движение вообще
			
	//U_field -> _field[zombie.x - 1][zombie.y] = Cell::empty; //прошли клетку и очищаем ее

}

unsigned Rules::Search(Zombie zombie, std::vector <Plant>& plants)
{
	for(int i = 0; i < plants.size(); i++)
		if((zombie.x == plants.at(i).x) and (zombie.y == plants.at(i).y))
			return i;
	return 0;
}

int Rules::ZPattack(Zombie zombie, Plant plant)
{
	plant.hp -= zombie.at;
	return plant.hp;
}
