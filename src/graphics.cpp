#include "graphics.h"

void Graphics_Sym::draw(Cell cell)  //метод выбора отрисовки в зависимости от того, что находится в клетке
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
	int x = cell_size / 2 + (cell_size % 2 == 0) ;
	int y = (cell_size / 2) - (cell_size % 2 == 0);
	cout << rightCUP(x) << downCUP(y);
	cout << "P ";
}

void Graphics_Sym::draw_bullet() //метод отрисовки зомби символами
{
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
	
	cout <<	CUP(term_lenght / 2 - 7, 1);
	for(int i = 0; i < term_lenght; i++)
		cout <<	"-";
	cout << endl;
	
	cout << "Level:"; // CUP(winsize[1] / 2 - 6, 8)- в эту координату пишем данные
	
	cout << CUP(term_lenght / 2 - 6, 10);
	cout << "Plants death: 0"; // CUP(winsize[1] / 2 - 6, 24) - в эту координату пишем данные
	
	cout << CUP(term_lenght / 2 - 6, 26);
	cout << "Zombie death: 0"; // CUP(winsize[1] / 2 - 6, 40) - в эту координату пишем данные
	
	cout << CUP(term_lenght / 2 - 4, 1);
	cout << "User name: "; //CUP(winsize[1] / 2 - 4, 12)- в эту координату пишем данные
	
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
