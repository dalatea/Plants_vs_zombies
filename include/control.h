class Control
{
protected:
	int _x; //где находится курсор
	int _y;
public:
	Control(int x = 0, int y = 0) : _x(x), _y(y) {};
	virtual void key_control() = 0;
	virtual ~Control();
};
