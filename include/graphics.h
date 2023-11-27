#pragma once

#include "settings.h"
#include "escape.h"

class Graphics{
//абстрактный класс для отрисовки
protected:
	Settings* _settings;
public:
	Graphics(Settings* set) : _settings(set) {};
	virtual void draw(Cell) = 0;
	virtual ~Graphics() = default;
};

class Graphics_Sym : public Graphics{
public:
	Graphics_Sym(Settings* set) : Graphics(set) {};
	void draw_score();
	void draw(Cell); //метод выбора отрисовки в зависимости от того, что находится в клетке
	void draw_empty_cell();  //метод отрисовки пустой клетки
	void draw_zombie(); //метод отрисовки зомби
	void draw_plant(); //метод отрисовки растения
	void draw_bullet(); //метод отрисовки пули растения
};

class Graphics_Esc : public Graphics{
public:
	Graphics_Esc(Settings* set) : Graphics(set) {};
	void draw_score();
	void draw(Cell); //метод выбора отрисовки в зависимости от того, что находится в клетке
	void draw_empty_cell();  //метод отрисовки пустой клетки
	void draw_zombie(); //метод отрисовки зомби
	void draw_plant(); //метод отрисовки растения
	void draw_bullet(); //метод отрисовки пули растения
};


