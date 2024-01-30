#pragma once

#include "settings.h"
#include "escape.h"

class Graphics{
//абстрактный класс для отрисовки
protected:
	Settings* _settings;
	Color choose;
	Color border;
	Color bg;
public:
	Graphics(Settings* set) : _settings(set) {};
	virtual void draw(Cell, Color) = 0;
	virtual Color get_choose() = 0;
	virtual Color get_border() = 0;
	virtual Color get_bg() = 0;
	virtual ~Graphics() = default;
};

class Graphics_Sym : public Graphics{
public:
	Graphics_Sym(Settings* set) : Graphics(set) {choose = Color::GREEN; border = Color::RESET; bg = Color::RESET;};
	void draw_score();
	void draw(Cell, Color); //метод выбора отрисовки в зависимости от того, что находится в клетке
	void draw_empty_cell();  //метод отрисовки пустой клетки
	void draw_zombie(); //метод отрисовки зомби
	void draw_plant(); //метод отрисовки растения
	void draw_bullet(); //метод отрисовки пули растения
	Color get_choose(){return choose;}
	Color get_border(){return border;}
	Color get_bg(){return bg;}
};

class Graphics_Esc : public Graphics{
public:
	Graphics_Esc(Settings* set) : Graphics(set) {choose = Color::YELLOW_BG; border = Color::BROWN_BG; bg = Color::GREEN_BG;};
	void draw_score();
	void draw(Cell, Color); //метод выбора отрисовки в зависимости от того, что находится в клетке
	void draw_empty_cell(Color);  //метод отрисовки пустой клетки
	void draw_zombie(); //метод отрисовки зомби
	void draw_plant(); //метод отрисовки растения
	void draw_bullet(); //метод отрисовки пули растения
	Color get_choose(){return choose;}
	Color get_border(){return border;}
	Color get_bg(){return bg;}
};


