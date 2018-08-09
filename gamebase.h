#pragma once
//Declare a base class from which TicTacToe and Gomoku will extend

#include "geninfo_header.h"
#include <iostream>
#include <string>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iomanip>
#include <memory>

using namespace std;
class gamebase
{
protected:
	int playerturn, num_moves = 0;
	string p1moves, p2moves;
	const int dimension;//length of side of square board 
	string **pieces;
	int longestStringLength = 1;
	string winner;
	const int numToWin;//# of consecutive pieces that is considered a win
	static shared_ptr<gamebase> game_ptr;
	string gameType;

public:
	//constructor- passed in height and width args
	gamebase(const int dim, const int numToWin);

	//return true iff numToWin Xs or Os are in a vertical, horizontal or diagonal line
	virtual bool done() = 0;

	//return false iff there are moves remaining in the game (as defined below) or if the done() method returns true
	virtual bool draw() = 0;

	/*If the user inputs a string with the coordinate of a valid square on the board, the method
	should extract the value to the left of the comma into the first (horizontal) unsigned integer
	parameter that was passed to the method, and extract the value to the right of the comma
	into the second (vertical) unsigned integer parameter that was passed to the method.
	If the user inputs "quit" the method should return a value indicating the user asked to quit*/

	virtual int prompt(unsigned int & x, unsigned int & y);

	//prompt the user for input with prompt() and update the board accordingly with their input
	virtual int turn() = 0;

	//begin the game and call turn() until the game has ended in either a draw, a victory, or someone quitting
	virtual int play();

	//prints out the current state of the game board
	virtual void print() = 0;

	//check the commandline arguments and create a gamebase object whose type, member vars, etc will vary based on the args
	static void check(int argc, char* argv[]);
	
	void saveAndQuit();

	string toFileString();

	static shared_ptr<gamebase> instance();
};
