class Game_control
{
private:
	*User_input input;
	*Graphics graphics;
	*Field field;
public:
	void run();
	int step();
};
