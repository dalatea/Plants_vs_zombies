#include "graphics.h"

void Graphics_Sym::draw(Cell cell, Color color)  //метод выбора отрисовки в зависимости от того, что находится в клетке
{
	switch(cell)
	{
		case Cell::empty:
			draw_empty_cell();
			break;
		case Cell::zombie:
			draw_zombie();
			break;
		case Cell::plant:
			draw_plant();
			break;
		case Cell::bullet:
			draw_bullet();
			break;
		case Cell::score:
			draw_score();
			break;
	}
	
}

void Graphics_Sym::draw_empty_cell() //метод отрисовки пустой клетки символами
{
	const int cell_size = _settings->getCell_size();
	
	for (int i = 0; i < cell_size; i++)
	{
		if (i % (cell_size - 1) == 0)
		{
			for (int j = 0; j < cell_size - 1; j++)
			{
				cout << " +";
			}
			cout << downCUP(1) << leftCUP((cell_size - 1) * 2);
		}
		else
		{
			for (int j = 0; j < cell_size; j++)
			{
				if (j % (cell_size - 1) == 0)
				{
					cout << "+";
				}
				else
					cout << "  "; //2 пробела
			}
			cout << leftCUP((cell_size - 1) * 2) << downCUP(1);
		}
	}
}

void Graphics_Sym::draw_zombie() //метод отрисовки зомби символами
{
	const int cell_size = _settings->getCell_size();
	
	//int x = (cell_size - 2) * 2;
	int x = 0;
	int y = (cell_size / 2) - (cell_size % 2 == 0);
	cout << rightCUP(x) << downCUP(y);
	cout << "Z";
	//cout << leftCUP((cell_size - 2) * 2) << upCUP((cell_size / 2) - (cell_size % 2 == 0));
	cout << upCUP((cell_size / 2) - (cell_size % 2 == 0));
}

void Graphics_Sym::draw_plant() //метод отрисовки растения символами
{
	const int cell_size = _settings->getCell_size();
	
	int x = cell_size / 2 + (cell_size % 2 == 0) ;
	int y = (cell_size / 2) - (cell_size % 2 == 0);
	cout << rightCUP(x) << downCUP(y);
	cout << "P ";
}

void Graphics_Sym::draw_bullet() //метод отрисовки зомби символами
{
	const int cell_size = _settings->getCell_size();
	
	//int x = (cell_size - 2) * 2;
	int x = 0;
	int y = (cell_size / 2) - (cell_size % 2 == 0);
	cout << rightCUP(x) << downCUP(y);
	cout << ".";
	//cout << leftCUP((cell_size - 2) * 2) << upCUP((cell_size / 2) - (cell_size % 2 == 0));
	//cout << upCUP((cell_size / 2) - (cell_size % 2 == 0));
}

void Graphics_Sym::draw_score()
{
	int term_length = _settings->getTerm_length();
	int term_width = _settings->getTerm_width();
	
	cout <<	CUP(term_length - term_length/3, 1);
	for(int i = 0; i < term_length; i++)
		cout <<	"-";
	cout << endl;
	
	cout << CUP(term_length - term_length/3 + 1, 1);
	cout << "Level: " << _settings->getLevel(); // CUP(winsize[1] / 2 - 6, 8)- в эту координату пишем данные
	
	cout << CUP(term_length - term_length/3 + 1, 10);
	cout << "Plants death: 0"; // CUP(winsize[1] / 2 - 6, 24) - в эту координату пишем данные
	
	cout << CUP(term_length - term_length/3 + 1, 26);
	cout << "Zombie death: 0"; // CUP(winsize[1] / 2 - 6, 40) - в эту координату пишем данные
	
	cout << CUP(term_length - term_length/3 + 3, 1);
	cout << "User name: " << _settings->getUser_name();; //CUP(winsize[1] / 2 - 4, 12)- в эту координату пишем данные
	
	cout  << CUP(term_length - term_length/3 + 3, 16);
	cout << "Unused plants: " << _settings->getScope_plants();
	
	cout << CUP(1,1);
}

void Graphics_Esc::draw(Cell cell, Color color)  //метод выбора отрисовки в зависимости от того, что находится в клетке
{
	switch(cell)
	{
		case Cell::empty:
			draw_empty_cell(color);
			break;
		case Cell::zombie:
			draw_zombie();
			break;
		case Cell::plant:
			draw_plant();
			break;
		case Cell::bullet:
			draw_bullet();
			break;
		case Cell::score:
			draw_score();
			break;
	}
	
}

void Graphics_Esc::draw_empty_cell(Color color) //метод отрисовки пустой клетки символами
{
	const int cell_size = _settings->getCell_size();
	
	for (int i = 0; i < cell_size; i++)
	{
		if (i % (cell_size - 1) == 0)
		{
			for (int j = 0; j < cell_size - 1; j++)
				cout << "  ";
			cout << downCUP(1) << leftCUP((cell_size - 1) * 2);
		}
		else
		{
			for (int j = 0; j < cell_size; j++)
			{
				if (j % (cell_size - 1) == 0)
				{
					cout << " ";
				}
				else
				{
					cout << SGR((int)Color::GREEN_BG); 
					cout << SGR((int)Color::DARK_GREEN); //трава
					cout << "^ "; //2 пробела
					cout << SGR((int)color); 
				}
			}
			cout << leftCUP((cell_size - 1) * 2) << downCUP(1);
		}
	}
}

void Graphics_Esc::draw_zombie() //метод отрисовки зомби символами
{
	const int cell_size = _settings->getCell_size();
	//int x = (cell_size - 2) * 2;
	int x = 0;
	int y = (cell_size / 2) - (cell_size % 2 == 0);
	cout << rightCUP(x) << downCUP(y);
	cout << SGR((int)Color::GREEN_BG);
	cout << "\U0001F9DF";
	//cout << leftCUP((cell_size - 2) * 2) << upCUP((cell_size / 2) - (cell_size % 2 == 0));
	cout << upCUP((cell_size / 2) - (cell_size % 2 == 0));
}

void Graphics_Esc::draw_plant() //метод отрисовки растения символами
{
	const int cell_size = _settings->getCell_size();
	
	int x = cell_size / 2 + (cell_size % 2 == 0) ;
	int y = (cell_size / 2) - (cell_size % 2 == 0);
	cout << rightCUP(x-1) << downCUP(y);
	cout << SGR((int)Color::GREEN_BG);
	cout << "\U0001F33C";
	cout << rightCUP(1);
}

void Graphics_Esc::draw_bullet() //метод отрисовки зомби символами
{
	const int cell_size = _settings->getCell_size();
	
	//int x = (cell_size - 2) * 2;
	int x = 0;
	int y = (cell_size / 2) - (cell_size % 2 == 0);
	cout << rightCUP(x) << downCUP(y);
	cout << SGR((int)Color::GREEN_BG);
	cout << "\U0001F538";
	//cout << leftCUP((cell_size - 2) * 2) << upCUP((cell_size / 2) - (cell_size % 2 == 0));
	//cout << upCUP((cell_size / 2) - (cell_size % 2 == 0));
}

void Graphics_Esc::draw_score()
{
	int term_length = _settings->getTerm_length();
	int term_width = _settings->getTerm_width();
	cout <<	CUP(term_length - term_length/3, 1);
	for(int i = 0; i < term_length; i++)
	{
		cout <<	"-";
	}
	cout << endl;
	
	cout << CUP(term_length - term_length/3 + 1, 1);
	cout << "Level: " << _settings->getLevel(); // CUP(winsize[1] / 2 - 6, 8)- в эту координату пишем данные
	
	cout << CUP(term_length - term_length/3 + 1, 10);
	cout << "Plants death: 0"; // CUP(winsize[1] / 2 - 6, 24) - в эту координату пишем данные
	
	cout << CUP(term_length - term_length/3 + 1, 26);
	cout << "Zombie death: 0"; // CUP(winsize[1] / 2 - 6, 40) - в эту координату пишем данные
	
	cout << CUP(term_length - term_length/3 + 3, 1);
	cout << "User name: " << _settings->getUser_name();; //CUP(winsize[1] / 2 - 4, 12)- в эту координату пишем данные
	
	cout  << CUP(term_length - term_length/3 + 3, 16);
	cout << "Unused plants: " << _settings->getScope_plants();
	
	cout << CUP(1,1);
}
/*void Graphics_Escape::draw_zombie()
{
	for (int i = 0; i < cell_size; i++)
	{
		if (i % (cell_size - 1) == 0)
		{
			for (int j = 0; j < cell_size - 1; j++)
			{
				cout << "+ ";
			}
			cout << downCUP(1) << leftCUP((cell_size - 1) * 2);
		}
		else if (i == (cell_size / 2) - (cell_size % 2 == 0))
		{
			for (int j = 0; j < cell_size; j++)
			{
				if (j % (cell_size - 1) == 0)
				{
					cout << "+";
				}
				else if (j == cell_size / 2)
				{
					cout << "Z ";
				}
				else
					cout << "  "; //2 пробела
			}
			cout << leftCUP((cell_size - 1) * 2) << downCUP(1);
		}
		else
		{
			for (int j = 0; j < cell_size; j++)
			{
				if (j % (cell_size - 1) == 0)
				{
					cout << "+";
				}
				else
					cout << "  "; //2 пробела
			}
			cout << leftCUP((cell_size - 1) * 2) << downCUP(1);
		}
		
	}
}

void Graphics_Escape::draw_plant()
{
	for (int i = 0; i < cell_size; i++)
	{
		if (i % (cell_size - 1) == 0)
		{
			for (int j = 0; j < cell_size - 1; j++)
			{
				cout << "+ ";
			}
			cout << downCUP(1) << leftCUP((cell_size - 1) * 2);
		}
		else if (i == (cell_size / 2) - (cell_size % 2 == 0))
		{
			for (int j = 0; j < cell_size; j++)
			{
				if (j % (cell_size - 1) == 0)
				{
					cout << "+";
				}
				else if (j == cell_size / 2)
				{
					cout << "P ";
				}
				else
					cout << "  "; //2 пробела
			}
			cout << leftCUP((cell_size - 1) * 2) << downCUP(1);
		}
		else
		{
			for (int j = 0; j < cell_size; j++)
			{
				if (j % (cell_size - 1) == 0)
				{
					cout << "+";
				}
				else
					cout << "  "; //2 пробела
			}
			cout << leftCUP((cell_size - 1) * 2) << downCUP(1);
		}
		
	}
}*/
