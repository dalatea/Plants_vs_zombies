#pragma once

#include <iostream>
#include <sstream>

using namespace std;

class estream
{
private:
	string _escape;
public:
	estream(string e) : _escape(e) {};
	friend ostream& operator<<(ostream&, estream);
};

estream CUP(int, int);
estream upCUP(int);
estream downCUP(int);
estream rightCUP(int);
estream leftCUP(int);
estream term_size(int cols, int rows);
estream SGR(int);
