//implementation of TicTacToe
#include "stdafx.h"
#include "TicTacToe.h"

using namespace std;


TicTacToe::TicTacToe() : gamebase(tictactoe_dimension, num_for_tictactoe_win)
{
	gameType = "TicTacToe";
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
	string filename = gameType + ".txt";
	ifstream file(filename);
	if (file)
	{
		string firstWord;
		file >> firstWord;
		if (firstWord != "NODATA")
		{
			string currStr;
			file >> currStr;
			num_moves = stoi(currStr);
			if (num_moves % 2 == 1)
			{
				playerturn = second_player;
			}
			for (int i = 1; i < dimension-1; i++)
			{
				for (int j = 1; j < dimension-1; j++)
				{
					if (file >> currStr)
					{
						if (currStr != "-")
						{
							pieces[i][j] = currStr;
						}
						else
						{
							pieces[i][j] = " ";
						}
					}
					else
					{
						break;
					}
				}
			}
		}
	}
};

//see gamebase.h for description of each method

bool TicTacToe::done()
{
	bool gameover = false;
	if (pieces[1][1] == "X" && pieces[1][2] == "X" && pieces[1][3] == "X") { gameover = true; winner = "X"; }
	if (pieces[2][1] == "X" && pieces[2][2] == "X" && pieces[2][3] == "X") { gameover = true; winner = "X"; }
	if (pieces[3][1] == "X" && pieces[3][2] == "X" && pieces[3][3] == "X") { gameover = true; winner = "X"; }

	if (pieces[1][1] == "X" && pieces[2][1] == "X" && pieces[3][1] == "X") { gameover = true; winner = "X"; }
	if (pieces[1][2] == "X" && pieces[2][2] == "X" && pieces[3][2] == "X") { gameover = true; winner = "X"; }
	if (pieces[1][3] == "X" && pieces[2][3] == "X" && pieces[3][3] == "X") { gameover = true; winner = "X"; }
	if (pieces[1][1] == "X" && pieces[2][2] == "X" && pieces[3][3] == "X") { gameover = true; winner = "X"; }
	if (pieces[1][3] == "X" && pieces[2][2] == "X" && pieces[3][1] == "X") { gameover = true; winner = "X"; }

	if (pieces[1][1] == "O" && pieces[1][2] == "O" && pieces[1][3] == "O") { gameover = true; winner = "O"; }
	if (pieces[2][1] == "O" && pieces[2][2] == "O" && pieces[2][3] == "O") { gameover = true; winner = "O"; }
	if (pieces[3][1] == "O" && pieces[3][2] == "O" && pieces[3][3] == "O") { gameover = true; winner = "O"; }

	if (pieces[1][1] == "O" && pieces[2][1] == "O" && pieces[3][1] == "O") { gameover = true; winner = "O"; }
	if (pieces[1][2] == "O" && pieces[2][2] == "O" && pieces[3][2] == "O") { gameover = true; winner = "O"; }
	if (pieces[1][3] == "O" && pieces[2][3] == "O" && pieces[3][3] == "O") { gameover = true; winner = "O"; }

	if (pieces[1][1] == "O" && pieces[2][2] == "O" && pieces[3][3] == "O") { gameover = true; winner = "O"; }
	if (pieces[1][3] == "O" && pieces[2][2] == "O" && pieces[3][1] == "O") { gameover = true; winner = "O"; }
	return gameover;
}

bool TicTacToe::draw()
{
	bool moves_remaining = false;
	for (int i = dimension - 2; i >= 1; i--)
	{
		for (int j = 1; j < dimension - 1; j++)
		{
			if (pieces[i][j] == " ")
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

int TicTacToe::turn()
{
	int status = waiting;
	unsigned int height, width;
	while (true) {
		while (status == waiting || !(height > 0 && height < (unsigned int) (dimension - 1) && width > 0 && width < (unsigned int)(dimension - 1))) {
			status = prompt(height, width);
		}
		if (status == quit) {
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
void TicTacToe::print()
{
	cout << *this << endl;
}

ostream & operator<<(ostream &stream, const TicTacToe &game)
{
	for (int i = game.dimension - 1; i >= 0; i--)
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
