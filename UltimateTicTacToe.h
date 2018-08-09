#pragma once
#include "gamebase.h"

using namespace std;
class UltimateTicTacToe :public gamebase
{
public:
	UltimateTicTacToe(); //constructor
	bool done(); //see gamebase.h for descriptions of methods
	bool draw();
	int turn();
	void print();
	bool subsquareDone(int row, int col);
	bool subsquareFilled(int row, int col);
	bool attemptedMoveValid(int height, int width, int previousheight, int previouswidth);
	friend ostream & operator<<(ostream &stream, const UltimateTicTacToe &ultimatetictactoe);
	string **subsquares;
	int previousHeight;
	int previousWidth;
};
ostream & operator<<(ostream &stream, const UltimateTicTacToe &ultimatetictactoe); //operator overload to print out the current state of the board