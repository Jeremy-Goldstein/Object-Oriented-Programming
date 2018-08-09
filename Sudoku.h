//Declare the class which implements Sudoku using gamebase as a base class
#pragma once
#include "gamebase.h"

using namespace std;
class Sudoku:public gamebase
{
public:
	Sudoku();//Constructor for if user does not provide extra input via cmd args specifying dimensions or numToWin
	bool squaresFilled();//Check if all the squares have been filled
	int play(); //Unlike the other games, Sudoku needs its own play() method
	bool done();//see gamebase.h for description of methods
	bool draw();
	int turn();
	void print();
	int prompt(unsigned int &y, unsigned int &x, unsigned int &num);
	friend ostream & operator<<(ostream &stream, const Sudoku &game);

};
ostream & operator<<(ostream &stream, const Sudoku &game);//operator overload to print out the current state of the board