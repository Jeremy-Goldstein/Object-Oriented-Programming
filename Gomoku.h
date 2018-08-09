//Declare the class which implements Gomoku using gamebase as a base class
#pragma once
#include "gamebase.h"

using namespace std;
class Gomoku :public gamebase
{
public:
	Gomoku();//Constructor for if user does not provide extra input via cmd args specifying dimensions or numToWin
	Gomoku(const int dim); //Constructor for if user provides dimensions via extra cmd arg, but not numToWin
	Gomoku(const int dim, const int winct); //constructor for if user provides both dimensions AND numToWin via cmd args
	bool done();//see gamebase.h for description of methods
	bool draw();
	int turn();
	void print();
	friend ostream & operator<<(ostream &stream, const Gomoku &game);
};
ostream & operator<<(ostream &stream, const Gomoku &game);//operator overload to print out the current state of the board