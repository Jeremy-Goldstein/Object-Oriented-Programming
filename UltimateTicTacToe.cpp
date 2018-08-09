//implementation of UltimateTicTacToe
#include "stdafx.h"
#include "UltimateTicTacToe.h"

using namespace std;

UltimateTicTacToe::UltimateTicTacToe() : gamebase(ultimate_tictactoe_dimension, num_for_ultimate_tictactoe_win)
{
	previousHeight = -1;
	previousWidth = -1;
	gameType = "UltimateTicTacToe";
	playerturn = first_player;
	p1moves += "X: ";
	p2moves += "O: ";
	string dimensionStr = to_string(dimension);
	longestStringLength = dimensionStr.length() + 1;
	pieces = new string*[dimension];
	for (int i = 0; i < dimension; i++)
	{
		pieces[i] = new string[dimension];
		for (int j = 0; j < dimension; j++)
		{
			pieces[i][j] = " ";
		}
	}
	subsquares = new string*[ultimate_tictactoe_subsquare_count];

	for (int i = 0; i < ultimate_tictactoe_subsquare_count; i++)
	{
		subsquares[i] = new string[ultimate_tictactoe_subsquare_count];
		for (int j = 0; j < ultimate_tictactoe_subsquare_count; j++)
		{
			subsquares[i][j] = " ";
		}
	}
};


bool UltimateTicTacToe::subsquareFilled(int row, int col)
{
	for (int i = 0; i < ultimate_tictactoe_subsquare_count; i++)
	{
		for (int j = 0; j < ultimate_tictactoe_subsquare_count; j++)
		{
			if (subsquares[row*ultimate_tictactoe_subsquare_count + i][col*ultimate_tictactoe_subsquare_count + j]==" ")
			{
				return false;
			}
		}
	}
	subsquares[row][col] = "Filled";
	return true;
}


//see gamebase.h for description of each method

bool UltimateTicTacToe::done()
{
	for (int i = 0; i < ultimate_tictactoe_subsquare_count; i++) {
		for (int j = 0; j < ultimate_tictactoe_subsquare_count; j++) {
			subsquareDone(i, j);
		}
	}
	bool gameover = false;
	if (subsquares[0][0] == "X" && subsquares[0][1] == "X" && subsquares[0][2] == "X") { gameover = true; winner = "X"; }
	if (subsquares[1][0] == "X" && subsquares[1][1] == "X" && subsquares[1][2] == "X") { gameover = true; winner = "X"; }
	if (subsquares[2][0] == "X" && subsquares[2][1] == "X" && subsquares[2][2] == "X") { gameover = true; winner = "X"; }

	if (subsquares[0][0] == "X" && subsquares[1][0] == "X" && subsquares[2][0] == "X") { gameover = true; winner = "X"; }
	if (subsquares[0][1] == "X" && subsquares[1][1] == "X" && subsquares[2][1] == "X") { gameover = true; winner = "X"; }
	if (subsquares[0][2] == "X" && subsquares[1][2] == "X" && subsquares[2][2] == "X") { gameover = true; winner = "X"; }
	if (subsquares[0][0] == "X" && subsquares[1][1] == "X" && subsquares[2][2] == "X") { gameover = true; winner = "X"; }
	if (subsquares[0][2] == "X" && subsquares[1][1] == "X" && subsquares[2][0] == "X") { gameover = true; winner = "X"; }

	if (subsquares[0][0] == "O" && subsquares[0][1] == "O" && subsquares[0][2] == "O") { gameover = true; winner = "O"; }
	if (subsquares[1][0] == "O" && subsquares[1][1] == "O" && subsquares[1][2] == "O") { gameover = true; winner = "O"; }
	if (subsquares[2][0] == "O" && subsquares[2][1] == "O" && subsquares[2][2] == "O") { gameover = true; winner = "O"; }

	if (subsquares[0][0] == "O" && subsquares[1][0] == "O" && subsquares[2][0] == "O") { gameover = true; winner = "O"; }
	if (subsquares[0][1] == "O" && subsquares[1][1] == "O" && subsquares[2][1] == "O") { gameover = true; winner = "O"; }
	if (subsquares[0][2] == "O" && subsquares[1][2] == "O" && subsquares[2][2] == "O") { gameover = true; winner = "O"; }

	if (subsquares[0][0] == "O" && subsquares[1][1] == "O" && subsquares[2][2] == "O") { gameover = true; winner = "O"; }
	if (subsquares[0][2] == "O" && subsquares[1][1] == "O" && subsquares[2][0] == "O") { gameover = true; winner = "O"; }

	return gameover;
}

bool UltimateTicTacToe::subsquareDone(int row, int col)
{
	bool gameover = false;
	if (pieces[row*ultimate_tictactoe_subsquare_count + 0][col*ultimate_tictactoe_subsquare_count + 0] == "X" && pieces[row*ultimate_tictactoe_subsquare_count + 0][col*ultimate_tictactoe_subsquare_count + 1] == "X" && pieces[row*ultimate_tictactoe_subsquare_count + 0][col*ultimate_tictactoe_subsquare_count + 2] == "X") { gameover = true; subsquares[row][col] = "X"; }
	if (pieces[row*ultimate_tictactoe_subsquare_count + 1][col*ultimate_tictactoe_subsquare_count + 0] == "X" && pieces[row*ultimate_tictactoe_subsquare_count + 1][col*ultimate_tictactoe_subsquare_count + 1] == "X" && pieces[row*ultimate_tictactoe_subsquare_count + 1][col*ultimate_tictactoe_subsquare_count + 2] == "X") { gameover = true; subsquares[row][col] = "X"; }
	if (pieces[row*ultimate_tictactoe_subsquare_count + 2][col*ultimate_tictactoe_subsquare_count + 0] == "X" && pieces[row*ultimate_tictactoe_subsquare_count + 2][col*ultimate_tictactoe_subsquare_count + 1] == "X" && pieces[row*ultimate_tictactoe_subsquare_count + 2][col*ultimate_tictactoe_subsquare_count + 2] == "X") { gameover = true; subsquares[row][col] = "X"; }

	if (pieces[row*ultimate_tictactoe_subsquare_count + 0][col*ultimate_tictactoe_subsquare_count + 0] == "X" && pieces[row*ultimate_tictactoe_subsquare_count + 1][col*ultimate_tictactoe_subsquare_count + 0] == "X" && pieces[row*ultimate_tictactoe_subsquare_count + 2][col*ultimate_tictactoe_subsquare_count + 0] == "X") { gameover = true; subsquares[row][col] = "X"; }
	if (pieces[row*ultimate_tictactoe_subsquare_count + 0][col*ultimate_tictactoe_subsquare_count + 1] == "X" && pieces[row*ultimate_tictactoe_subsquare_count + 1][col*ultimate_tictactoe_subsquare_count + 1] == "X" && pieces[row*ultimate_tictactoe_subsquare_count + 2][col*ultimate_tictactoe_subsquare_count + 1] == "X") { gameover = true; subsquares[row][col] = "X"; }
	if (pieces[row*ultimate_tictactoe_subsquare_count + 0][col*ultimate_tictactoe_subsquare_count + 2] == "X" && pieces[row*ultimate_tictactoe_subsquare_count + 1][col*ultimate_tictactoe_subsquare_count + 2] == "X" && pieces[row*ultimate_tictactoe_subsquare_count + 2][col*ultimate_tictactoe_subsquare_count + 2] == "X") { gameover = true; subsquares[row][col] = "X"; }
	if (pieces[row*ultimate_tictactoe_subsquare_count + 0][col*ultimate_tictactoe_subsquare_count + 0] == "X" && pieces[row*ultimate_tictactoe_subsquare_count + 1][col*ultimate_tictactoe_subsquare_count + 1] == "X" && pieces[row*ultimate_tictactoe_subsquare_count + 2][col*ultimate_tictactoe_subsquare_count + 2] == "X") { gameover = true; subsquares[row][col] = "X"; }
	if (pieces[row*ultimate_tictactoe_subsquare_count + 0][col*ultimate_tictactoe_subsquare_count + 2] == "X" && pieces[row*ultimate_tictactoe_subsquare_count + 1][col*ultimate_tictactoe_subsquare_count + 1] == "X" && pieces[row*ultimate_tictactoe_subsquare_count + 2][col*ultimate_tictactoe_subsquare_count + 0] == "X") { gameover = true; subsquares[row][col] = "X"; }

	if (pieces[row*ultimate_tictactoe_subsquare_count + 0][col*ultimate_tictactoe_subsquare_count + 0] == "O" && pieces[row*ultimate_tictactoe_subsquare_count + 0][col*ultimate_tictactoe_subsquare_count + 1] == "O" && pieces[row*ultimate_tictactoe_subsquare_count + 0][col*ultimate_tictactoe_subsquare_count + 2] == "O") { gameover = true; subsquares[row][col] = "O"; }
	if (pieces[row*ultimate_tictactoe_subsquare_count + 1][col*ultimate_tictactoe_subsquare_count + 0] == "O" && pieces[row*ultimate_tictactoe_subsquare_count + 1][col*ultimate_tictactoe_subsquare_count + 1] == "O" && pieces[row*ultimate_tictactoe_subsquare_count + 1][col*ultimate_tictactoe_subsquare_count + 2] == "O") { gameover = true; subsquares[row][col] = "O"; }
	if (pieces[row*ultimate_tictactoe_subsquare_count + 2][col*ultimate_tictactoe_subsquare_count + 0] == "O" && pieces[row*ultimate_tictactoe_subsquare_count + 2][col*ultimate_tictactoe_subsquare_count + 1] == "O" && pieces[row*ultimate_tictactoe_subsquare_count + 2][col*ultimate_tictactoe_subsquare_count + 2] == "O") { gameover = true; subsquares[row][col] = "O"; }

	if (pieces[row*ultimate_tictactoe_subsquare_count + 0][col*ultimate_tictactoe_subsquare_count + 0] == "O" && pieces[row*ultimate_tictactoe_subsquare_count + 1][col*ultimate_tictactoe_subsquare_count + 0] == "O" && pieces[row*ultimate_tictactoe_subsquare_count + 2][col*ultimate_tictactoe_subsquare_count + 0] == "O") { gameover = true; subsquares[row][col] = "O"; }
	if (pieces[row*ultimate_tictactoe_subsquare_count + 0][col*ultimate_tictactoe_subsquare_count + 1] == "O" && pieces[row*ultimate_tictactoe_subsquare_count + 1][col*ultimate_tictactoe_subsquare_count + 1] == "O" && pieces[row*ultimate_tictactoe_subsquare_count + 2][col*ultimate_tictactoe_subsquare_count + 1] == "O") { gameover = true; subsquares[row][col] = "O"; }
	if (pieces[row*ultimate_tictactoe_subsquare_count + 0][col*ultimate_tictactoe_subsquare_count + 2] == "O" && pieces[row*ultimate_tictactoe_subsquare_count + 1][col*ultimate_tictactoe_subsquare_count + 2] == "O" && pieces[row*ultimate_tictactoe_subsquare_count + 2][col*ultimate_tictactoe_subsquare_count + 2] == "O") { gameover = true; subsquares[row][col] = "O"; }

	if (pieces[row*ultimate_tictactoe_subsquare_count + 0][col*ultimate_tictactoe_subsquare_count + 0] == "O" && pieces[row*ultimate_tictactoe_subsquare_count + 1][col*ultimate_tictactoe_subsquare_count + 1] == "O" && pieces[row*ultimate_tictactoe_subsquare_count + 2][col*ultimate_tictactoe_subsquare_count + 2] == "O") { gameover = true; subsquares[row][col] = "O"; }
	if (pieces[row*ultimate_tictactoe_subsquare_count + 0][col*ultimate_tictactoe_subsquare_count + 2] == "O" && pieces[row*ultimate_tictactoe_subsquare_count + 1][col*ultimate_tictactoe_subsquare_count + 1] == "O" && pieces[row*ultimate_tictactoe_subsquare_count + 2][col*ultimate_tictactoe_subsquare_count + 0] == "O") { gameover = true; subsquares[row][col] = "O"; }


	return gameover;
}

bool UltimateTicTacToe::draw()
{
	bool moves_remaining = false;
	for (int i = ultimate_tictactoe_subsquare_count - 1; i >= 0; i--)
	{
		for (int j = 0; j < ultimate_tictactoe_subsquare_count; j++)
		{
			if (subsquares[i][j] == " ")
			{
				moves_remaining = true;
			}
		}
	}
	if (done() || moves_remaining)
	{
		return false;
	}
	return true;
}

bool UltimateTicTacToe::attemptedMoveValid(int height, int width, int previousheight, int previouswidth) {
	int boxheight =-1, boxwidth =-1;
	int subsquare_length = ultimate_tictactoe_dimension / ultimate_tictactoe_subsquare_count;
	if (previousheight%3==0 ) 
	{
		boxheight = 0;
	}
	else if(previousheight %3==1){
		boxheight = 1;
	}
	else {
		boxheight = 2;
	}
	if (previouswidth%3==0) {
		boxwidth = 0;
	}
	else if (previouswidth %3==1) {
		boxwidth = 1;
	}
	else {
		boxwidth = 2;
	}
	string s = subsquares[boxheight][boxwidth];

	bool ret = ((previousHeight == -1 && previousWidth == -1) || (ultimate_tictactoe_subsquare_count * boxheight <= height && ultimate_tictactoe_subsquare_count * boxheight + subsquare_length  >= height && ultimate_tictactoe_subsquare_count * boxwidth <= width && ultimate_tictactoe_subsquare_count * boxwidth + subsquare_length  >= width)) && s == " " ;
	
	return ret;
}

int UltimateTicTacToe::turn()
{
	int status = waiting;
	unsigned int height, width;
	unsigned int oldHeight, oldWidth;
	bool runOnce = false;
	while (true)
	{
		while (status == waiting || !(height >= 0 && height < (unsigned int)(dimension ) && width >= 0 && width < (unsigned int)(dimension ))) 
		{
			if (runOnce)
			{
				oldHeight = height;
				oldWidth = width;
			}
			status = prompt(height, width);
			if (!runOnce)
			{
				oldHeight = height;
				oldWidth = width;
			}
			runOnce = true;
			if (!attemptedMoveValid(height, width, previousHeight, previousWidth)) {
				status = waiting;
				height = oldHeight;
				width = oldWidth;
			}
		}
		if (status == quit) 
		{
			return quit;
		}
		if (pieces[height][width] == " ") {
			if (playerturn == first_player) {

				pieces[height][width] = "X";
				playerturn = second_player;
				p1moves += " ";
				p1moves += (width + digit_to_ascii);
				p1moves += ",";
				p1moves += (height + digit_to_ascii);
				p1moves += ";";
			}
			else if (playerturn == second_player) {
				pieces[height][width] = "O";
				playerturn = first_player;
				p2moves += " ";
				p2moves += (width + digit_to_ascii);
				p2moves += ",";
				p2moves += (height + digit_to_ascii);
				p2moves += ";";
			}
			previousHeight = height;
			previousWidth = width;
			print();
			if (playerturn == first_player) { cout << p2moves << endl; }//switched because playerturn==first_player -> second_player's turn just ended
			else if (playerturn == second_player) { cout << p1moves << endl; }
			num_moves++;
			return success;
		}
		cout << "That space is already taken!" << endl; //Added this
		status = waiting;
	}
	return should_not_reach;
}
void UltimateTicTacToe::print()
{
	cout << *this << endl;
}

ostream & operator<<(ostream &stream, const UltimateTicTacToe &game)
{
	int barrierInterval = ultimate_tictactoe_dimension / ultimate_tictactoe_subsquare_count;
	for (int i = game.dimension-1; i >= 0; i--)
	{
		cout << setw(game.longestStringLength) << i;
		for (int j = 0; j < game.dimension; j++)
		{
			cout << setw(game.longestStringLength) << game.pieces[i][j];
		}
		cout << endl;
	}
	cout << setw(game.longestStringLength) << " ";
	for (int i = 0; i < game.dimension; i++)
	{
		cout << setw(game.longestStringLength) << i;
	}

	cout << endl;
	return stream;
}
