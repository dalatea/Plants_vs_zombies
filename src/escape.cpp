#include "escape.h"

estream CUP(int x, int y)
{
	ostringstream sout;
	sout << "\033[" << x << ";" << y << "H"; //устанавливает курсор в положении x,y
	return estream(sout.str());
}

estream upCUP(int y)
{
	ostringstream sout;
	sout << "\033[" << y << "A"; //перемещает курсор на y вверх
	return estream(sout.str());
}

estream downCUP(int y)
{
	ostringstream sout;
	sout << "\033[" << y << "B"; //перемещает курсор на y вниз
	return estream(sout.str());
}

estream rightCUP(int x)
{
	ostringstream sout;
	sout << "\033[" << x << "C"; //перемещает курсор на x вправо
	return estream(sout.str());
}

estream leftCUP(int x)
{
	ostringstream sout;
	sout << "\033[" << x << "D"; //перемещает курсор на x влево
	return estream(sout.str());
}

estream SGR(int r)
{
	ostringstream sout;
	if (r == 11)
		sout << "\033[48;5;"<< r << "m";
	else if(r == 22)
		sout << "\033[38;5;"<< r << "m";
	else
		sout << "\033["<< r << "m"; 
	return estream(sout.str());
}

estream term_size(int cols, int rows)
{
	ostringstream sout;
	sout << "\033[8;" << cols << ';' << rows << "t"; //меняет размер терминала
	return estream(sout.str());
}

std::ostream& operator << (std::ostream& out, estream e)
{
	out << e._escape << flush; //собирает последовательность и выталкивает её
	return out;
}
