#include "rules.h"

void Rules::choose(User_coord & u_coord) 
{
	int _x = u_coord.x;
	int _y = u_coord.y;
	Cell** _field;
	
	_field = field_model->getField();
	
	if(field_model -> getField()[_x][_y] == Cell::plant)
		return;
		
	field_view -> Scope_Plants_Print(_set, &u_coord);
		
	field_model -> getField()[_x][_y] = Cell::plant;
	Cell obj = field_model -> getField()[_x][_y];
	
	field_view->choose(obj);
		
}	
void Rules::All_Bullet_Move(std::vector <Plant>& plants, std::vector <Zombie>& zombies,std::vector <Bullet>& bullets)
{
	auto iter_z = zombies.cbegin();
	auto iter_begin = bullets.cbegin();
	auto iter = bullets.cbegin();
	
	std::vector <int> mas_check(0);
	std::vector <int> zombie_check(0);
	mas_check.reserve(plants.size());
	zombie_check.reserve(zombies.size());
	
	int k = 0, l = 0, _x, _y, n = 0, m;
	bool check = 0, z_check = 0;
	
	Bullet bullet;
	Bullet* b;
	
	int x, y, Test, parametr; //значения пули 
	
	int cell_size = _set -> getCell_size();
	while(k < bullets.size() )
	{
		x = bullets.at(k).getx();
		y = bullets.at(k).gety();
		Test = bullets.at(k).getTest();
		parametr = bullets.at(k).getparametr();
		
		//cout << CUP(1,1) << "size = " << bullets.size()<< endl;
		//cout << "x = " << bullets.at(k).x << " y = " << bullets.at(k).y << " k = " << k ;
		check = 0;
		
		l = First_Search(bullets.at(k), zombies); // находим какого зомби у нас будет бить пуля
		//cout << CUP(k,1) << l << " " << _set -> getZombie_death();
		
		if(l >= 0) // l -отвечает за то что пуля и зомби встретились внутри клетки
		{
			_x = (y * cell_size) + parametr ;
			_y = x * 2 * cell_size + Test ;
			//cout << CUP(4,1) << zombies.at(l).Test << " " << bullets.at(k).Test;
			//cout << CUP(4,1) << l;
			
			mas_check.push_back(k);
			//cout << "k1 = " << k  << " ";
				
			if(parametr != 0)		
				cout << CUP(_x + 1 + parametr, _y ) << " " ;
			else
				cout << CUP(_x + 3, _y) << " ";
			check = 1;
			
			int zhp = zombies.at(l).gethp();
			zhp = BZattack(zombies.at(l), bullets.at(k));
			zombies.at(l).assignhp(zhp);
			int zd = _set -> getZombie_death();
			
			if(zhp <= 0)
			{
				z_check = 1;
				
				zombie_check.push_back(l);
				
				_set -> assignZombie_death(zd + 1); 
				_set -> assignAmount_of_zombie(_set -> getAmount_of_zombie() - 1);
				assignzombie_count(getz_c() - 1);
				
				cout << SGR((int)Color::RESET);
				cout << CUP(_set ->getTerm_length() - _set ->getTerm_length()/3 + 1, 40)  << _set -> getZombie_death() ; 
					
				field_model -> getField()[x][y] = Cell::empty;
			}
				
				
		}
		/*
		n = Second_Search(bullets.at(k), zombies);
		
		if(n >= 0) // n -отвечает за то что пуля и зомби встретились на границе клетки
		{
			x = (bullets.at(k).y * cell_size) + bullets.at(k).parametr ;
			y = bullets.at(k).x * 2 * cell_size + bullets.at(k).Test ;
			//cout << CUP(4,1) << zombies.at(l).Test << " " << bullets.at(k).Test;
			//cout << CUP(4,1) << l;
			mas_check.push_back(k);
			if(bullets.at(k).parametr != 0)		
				cout << CUP(x + 1 + bullets.at(k).parametr, y - 5) << "K" ;
			else
				cout << CUP(x + 3, y - 5) << "K";
			check = 1;
			n = -1;
		}*/
		
		if(!check)
		{
			Bullet_Move(bullets.at(k));
			//cout << CUP(1,1) << bullets.at(bullets.size() - 1).gety();
		}
		if((x >= field_model -> getLength()) )
		{
			mas_check.push_back(k);
			//check = 1;
		}
		
		k++;
	}
	
	if(!zombie_check.empty())
		Zombies_erase(zombie_check, zombies);
	if(!mas_check.empty())
		m = Bullets_erase(mas_check, bullets);

	
}

int Rules::Bullets_erase(std::vector<int>& mas_check, std::vector <Bullet>& bullets) //удаление с конца
{

	int l = 0;
	std::sort(mas_check.begin(), mas_check.end());
	auto iter_begin = bullets.cbegin();
	for(int k = mas_check.size() - 1; k >= 0; k--)
	{
		//удаляю номер элемента, который хранится в mas_check
		//std::advance(iter_begin , mas_check.at(k) - l); //обязательно (- k) тк удаляя у нас изменяются номера элементов, и тогда mas_check начинает хранить уже устарешвие номера эл-ов
		bullets.erase(iter_begin + mas_check.at(k));
		iter_begin = bullets.cbegin();
		//l++;
	}
	mas_check.clear();
	return l;
}
void Rules::Zombies_erase(std::vector<int>& mas_check, std::vector <Zombie>& zombies) //удаление с конца
{

	int l = 0;
	std::sort(mas_check.begin(), mas_check.end());
	auto iter_begin = zombies.cbegin();
	for(int k = mas_check.size() - 1; k >= 0; k--)
	{
		//удаляю номер элемента, который хранится в mas_check
		//std::advance(iter_begin , mas_check.at(k) - l); //обязательно (- k) тк удаляя у нас изменяются номера элементов, и тогда mas_check начинает хранить уже устарешвие номера эл-ов
		zombies.erase(iter_begin + mas_check.at(k));
		iter_begin = zombies.cbegin();
		//l++;
	}
	mas_check.clear();
	
}

void Rules::Bullet_Move(Bullet& bullet)
{		
	int _x = 0 , _y = 0; //отрисовка
	bool check = false;
	
	int x, y, Test, parametr; //значения пули 
	x = bullet.getx();
	y = bullet.gety();
	Test = bullet.getTest();
	parametr = bullet.getparametr();
	
	int cell_size = _set -> getCell_size();
	
	_x = (y * field_model -> getCell_size()) + parametr ; // y по коориданатам 
	
	cout << SGR((int)Color::RESET);
	
	if(Test == (cell_size - 2) * 2 + 1) //такое условие, чтобы мы находились внутри клетки
	{
		if(parametr != 0)
			cout << CUP(_x + 2,(x  * 2 * cell_size) + Test  ) << " "; 
		else
			cout << CUP(_x + 3, (x  * 2 * cell_size) + Test  ) << " "; 
		x++;
		Test = 1;
	}
	if(field_model -> getLength()<= x) //Segmantation тк у у филда косянчеы координаты, исправить и норм
	{
		
		return;
	}
	_y = x * 2 * cell_size + Test ;
	if((Test + 1 == 5))
	{
		if(field_model -> getField()[x][y] == Cell::plant)
		{
			if(parametr != 0)		
				cout << CUP(_x + 1 + parametr, _y) << " " ;
			else
				cout << CUP(_x + 3, _y ) << " ";		
			Test ++;
			check = true;
		}
	}
	
	_y = x * 2 * cell_size + Test ;
	
	if((Test != 1) and (check == false))
	{
		if(parametr != 0)		
			cout << CUP(_x + 1 + parametr, _y) << " " ;
		else
			cout << CUP(_x + 3, _y ) << " ";
	}
	
	cout << CUP(_x + cell_size * parametr, _y) ;
	field_view -> paint_cell(Cell::bullet, Color::WHITE);
		
	Test++;
	
	bullet.assignx(x);
	bullet.assigny(y);
	bullet.assignTest(Test);
	bullet.assignparametr(parametr);
	
	cout << CUP(1,1);	

}
int Rules::First_Search(Bullet bullet, std::vector <Zombie>& zombies)
{
	for(int i = 0; i < zombies.size(); i++)
	{
		if((bullet.getx() == zombies.at(i).getx() - 1) and (bullet.gety() == zombies.at(i).gety()))
			if(bullet.getTest() + 1 == 10 - zombies.at(i).getTest())
				return i;
	}
	return -1;
}

unsigned Rules::Second_Search(Bullet bullet, std::vector <Zombie>& zombies)
{
	for(int i = 0; i < zombies.size(); i++)
	{
		if((bullet.getx() == zombies.at(i).getx() - 2) and (bullet.gety() == zombies.at(i).gety()))
			//if(() and (zombies.at(i).Test == (cell_size - 2) * 2 ) )
				return i;
	}
	return -1;
}


int Rules::BZattack(Zombie zombie, Bullet bullet)
{
	int hp;
	hp = zombie.gethp();
	hp -= bullet.getat();
	zombie.assignhp(hp);
	return hp;	
}

bool Rules::All_Zombie_Move(int zombie_c, std::vector <Zombie>& zombies, std::vector <Plant>& plants)
{
	bool procces = true;
	unsigned l, p = 0;
	auto iter = plants.cbegin();
	bool check = false;
	std::vector<int> mas_check(0);
	mas_check.reserve(plants.size() + 1);
	
	int x, y, Test, parametr; //значения zombie 
	
	for(int k = 0; k < zombie_count; k++)
	{	
		
		x = zombies.at(k).getx();
		y = zombies.at(k).gety();
		Test = zombies.at(k).getTest();
		parametr = zombies.at(k).getparametr();
		//cout << CUP(k + 2, 1) << l;
		
		if(Alinement(zombies.at(k))) //проверка на то что в клетке
		{
			l = Search(zombies.at(k), plants); // находим какое растение у нас будет бить зомби
			//cout << CUP(k + 2, 1) << l;
			int php ;
			php = ZPattack(zombies.at(k), plants.at(l)); // функция атаки
			plants.at(l).assignhp(php);
			//cout << CUP(2,1) << php;
			if(php <= 0)
			{
				field_model -> getField()[x - 1][y] = Cell::zombie;
				
				//cout << CUP(plants[l].y * (cell_size) + zombies[k].parametr, plants[l].x * 2 * cell_size - 4 ) << "R";

				mas_check.push_back(l);
				check = true;
				
				_set -> assignPlants_death(_set -> getPlants_death() + 1 ) ;
				cout << SGR((int)Color::RESET);
				cout << CUP(_set ->getTerm_length() - _set ->getTerm_length()/3 + 1, 24) << _set -> getPlants_death();
			}
		}
		else
			Zombie_Move( zombies.at(k));
		if(zombies.at(k).getx() == -1) //если дошли до конца то ломаем цикл
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
	int l = _set -> getAmount_of_plants();
	for(int k = 0; k < mas_check.size()  ; k++)
	{
		l--;
		_set -> assignAmount_of_plants(l);
		//std::advance(iter_begin , mas_check.at(k) - k);
		plants.erase(iter_begin + mas_check.at(k));
		iter_begin = plants.cbegin();
	}
	mas_check.clear();
}

void Rules::Zombie_Move(Zombie& zombie)
{		
	int _x = 0 , _y = 0;
	 
	int count = 0;
	
	int x, y, Test, parametr; //значения пули 
	x = zombie.getx();
	y = zombie.gety();
	Test = zombie.getTest();
	parametr = zombie.getparametr();
	
	int cell_size = _set -> getCell_size();
	
	if(y > 0)
		y += 1;
	
	_x = y * cell_size + parametr;
	
	if(Test == (cell_size - 2) * 2 ) //такое условие, чтобы мы находились внутри клетки
	{
		if(parametr != 0) //ЧТОБЫ КОГДА ЗОМБИ УШЕЛ ИЗ КЛЕТКИ, ЕГО Z ПОЧИСТИЛАСЬ
		{
			if( y == 1) 
				cout << CUP(_x - 3*(parametr + 1), x * 2 * cell_size - 2 - Test) << " "; 
			
			else
				cout << CUP(_x - 2 * (parametr + 1), x * 2 * cell_size - 2 - Test) << " ";
			
		}
		else
			cout << CUP(_x + 3, x * 2 * cell_size - 2 - Test) << " "; //ОЧИСТКА ПРЕДЫДУЩЕГО ПОЛОЖЕНИЯ
		field_model -> getField()[x - 1][y] = Cell::empty; //прошли клетку и очищаем ее
		x--;
		if(x <= 0)
			return;
			
		Test = 0;
		//U_field -> _field[zombie.x - 1][zombie.y] = Cell::zombie;
	}
	
	
	//cout << SGR((int)Color::RED);

	if(x == 0) //УСЛОВИЕ ОСОБОЕ ДЛЯ ПОСЛЕДНЕЙ КЛЕТОЧКИ
		_y = field_model -> getLength() - count + field_model -> getLength() / 2 - 1;
	else 
		_y = x * 2 * cell_size - 4 - Test;
		
	//ЧТОБЫ КЛЕТОЧКИ БЫЛИ ЦЕЛЫЕ И + НЕ ОЧИЩАЛИСЬ
	if(Test != 0)
	{
		if(parametr != 0 )
			cout << CUP(_x - 2 * (parametr + 1), _y + 2) << " ";
		else
			cout << CUP(_x + 3, _y + 2) << " " ;
	}
	
	
	cout << CUP(_x, _y) ; //устанавливаем курсор, чтобы правильно нарисовать зомби
		
	field_view -> paint_cell(Cell::zombie, Color::RED);
	cout << leftCUP(6) << upCUP(2);
	
	Test++; 
	
	zombie.assignx(x);
	//zombie.assigny(y);
	zombie.assignTest(Test);
	//zombie.assignparametr(parametr);
	
	

}

bool Rules::Alinement(Zombie& zombie)
{
	cout << SGR((int)Color::RESET);

	if(field_model -> getField()[zombie.getx() - 1][zombie.gety()] == Cell::empty)
	{ 
		field_model -> getField()[zombie.getx() - 1][zombie.gety()] = Cell::zombie; // говорим, что в этой клеточке находится зомби
		return 0;
	}
	else if(field_model -> getField()[zombie.getx() - 1][zombie.gety()] == Cell::plant)
		return 1;
	else
		return 0; 
}

unsigned Rules::Search(Zombie zombie, std::vector <Plant>& plants)
{
	for(int i = 0; i < plants.size(); i++)
	{
		if((zombie.getx() + 1 == plants.at(i).getx()) and (zombie.gety() == plants.at(i).gety()))
		{
			return i;
		}
	}
	return 0;
}

int Rules::ZPattack(Zombie zombie, Plant plant)
{
	int hp = plant.gethp();
	hp -= zombie.getat();
	//plant.assignhp(hp); //-= zombie.at;
	return hp;
}
