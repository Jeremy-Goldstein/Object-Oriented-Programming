//Declare a class which implements TicTacToe using the gamebase class as a base
#pragma once
#include "gamebase.h"

using namespace std;
class TicTacToe :public gamebase
{
public:
	TicTacToe(); //constructor
	bool done(); //see gamebase.h for descriptions of methods
	bool draw();
	int turn();
	void print();
	friend ostream & operator<<(ostream &stream, const TicTacToe &tictactoe);
};
ostream & operator<<(ostream &stream, const TicTacToe &tictactoe); //operator overload to print out the current state of the board