//implementation of Gomoku
#include "stdafx.h"
#include "Gomoku.h"

using namespace std;

//see gamebase.h for description of each method

Gomoku::Gomoku() : gamebase(default_gomoku_size, default_num_for_gomoku_win)
{
	gameType = "Gomoku";
	playerturn = 1;
	p1moves += "B: ";
	p2moves += "W: ";
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
			for (int i = 0; i < dimension; i++)
			{
				for (int j = 0; j < dimension; j++)
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

Gomoku::Gomoku(const int dim) : gamebase(dim, default_num_for_gomoku_win)
{
	gameType = "Gomoku";
	playerturn = 1;
	p1moves += "B: ";
	p2moves += "W: ";
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
};
Gomoku::Gomoku(const int dim, const int winct) : gamebase(dim, winct)
{
	gameType = "Gomoku";
	playerturn = 1;
	p1moves += "B: ";
	p2moves += "W: ";
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
};


bool Gomoku::done()
{
	bool gameover = false;
	string current_horiz = "", current_vert = "", current_diag_lower = "", current_diag_upper = "";
	int b_count_horiz = 0, w_count_horiz = 0, b_count_vert = 0, w_count_vert = 0, b_count_diag_lower = 0, w_count_diag_lower = 0, b_count_diag_upper = 0, w_count_diag_upper = 0;

	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			b_count_horiz = 0;
			w_count_horiz = 0;
			b_count_vert = 0;
			w_count_vert = 0;
			for (int k = 0; k < numToWin; k++)
			{

				if (i + k >= 0 && i + k < dimension)
				{ // if in range

					current_horiz = pieces[i + k][j];
					if (current_horiz == "B")
					{
						b_count_horiz++;
					}
					else if (current_horiz == "W")
					{
						w_count_horiz++;
					}
				}
				if (j + k >= 0 && j + k < dimension)
				{ // if in range

					current_vert = pieces[i][j + k];
					if (current_vert == "B")
					{
						b_count_vert++;
					}
					else if (current_vert == "W")
					{
						w_count_vert++;
					}
				}
			}


			if (b_count_horiz == numToWin)
			{
				winner = 'B';
				gameover = true;
			}
			else if (w_count_horiz == numToWin)
			{
				winner = 'W';
				gameover = true;
			}

			if (b_count_vert == numToWin)
			{
				winner = 'B';
				gameover = true;
			}
			else if (w_count_vert == numToWin)
			{
				winner = 'W';
				gameover = true;
			}

		}

	}
	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			b_count_diag_lower = 0;
			w_count_diag_lower = 0;
			b_count_diag_upper = 0;
			w_count_diag_upper = 0;
			for (int k = 0; k < numToWin; k++)
			{
				if (i + k >= 0 && i + k < dimension && j + k >= 0 && j + k < dimension)
				{ // if in range

					current_diag_lower = pieces[i + k][j + k];
					if (current_diag_lower == "B")
					{
						b_count_diag_lower++;
					}
					else if (current_diag_lower == "W")
					{
						w_count_diag_lower++;
					}
				}

				if (i + k >= 0 && i + k < dimension && j - k >= 0 && j - k < dimension)
				{ // if in range

					current_diag_upper = pieces[i + k][j - k];
					if (current_diag_upper == "B") {
						b_count_diag_upper++;
					}
					else if (current_diag_upper == "W") {
						w_count_diag_upper++;
					}
				}
			}


			if (b_count_diag_lower == numToWin)
			{
				winner = 'B';
				gameover = true;
			}
			else if (w_count_diag_lower == numToWin)
			{
				winner = 'W';
				gameover = true;
			}
			if (b_count_diag_upper == numToWin)
			{
				winner = 'B';
				gameover = true;
			}
			else if (w_count_diag_upper == numToWin)
			{
				winner = 'W';
				gameover = true;
			}
		}
	}
	return gameover;
}



bool Gomoku::draw()
{
	bool moves_remaining = false;

	string current_horiz = "", current_vert = "", current_diag_lower = "", current_diag_upper = "";
	int b_count_horiz = 0, w_count_horiz = 0, b_count_vert = 0, w_count_vert = 0, b_count_diag_lower = 0, w_count_diag_lower = 0, b_count_diag_upper = 0, w_count_diag_upper = 0;
	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			b_count_horiz = 0;
			w_count_horiz = 0;
			b_count_vert = 0;
			w_count_vert = 0;
			for (int k = 0; k < numToWin; k++)
			{

				if (i + k >= 0 && i + k < dimension)
				{ // if in range

					current_horiz = pieces[i + k][j];
					if (current_horiz == "B" || current_horiz == " ")
					{
						b_count_horiz++;
					}
					else if (current_horiz == "W" || current_horiz == " ")
					{
						w_count_horiz++;
					}
				}
				if (j + k >= 0 && j + k < dimension)
				{ // if in range

					current_vert = pieces[i][j + k];
					if (current_vert == "B" || current_vert == " ")
					{
						b_count_vert++;
					}
					else if (current_vert == "W" || current_vert == " ")
					{
						w_count_vert++;
					}
				}
			}


			if (b_count_horiz == numToWin)
			{
				moves_remaining = true;
			}
			else if (w_count_horiz == numToWin)
			{
				moves_remaining = true;
			}

			if (b_count_vert == numToWin)
			{
				moves_remaining = true;
			}
			else if (w_count_vert == numToWin)
			{
				moves_remaining = true;
			}

		}

	}
	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			b_count_diag_lower = 0;
			w_count_diag_lower = 0;
			b_count_diag_upper = 0;
			w_count_diag_upper = 0;
			for (int k = 0; k < numToWin; k++)
			{
				if (i + k >= 0 && i + k < dimension && j + k >= 0 && j + k < dimension)
				{ // if in range

					current_diag_lower = pieces[i + k][j + k];
					if (current_diag_lower == "B" || current_diag_lower == " ")
					{
						b_count_diag_lower++;
					}
					else if (current_diag_lower == "W" || current_diag_lower == " ")
					{
						w_count_diag_lower++;
					}
				}

				if (i + k >= 0 && i + k < dimension && j - k >= 0 && j - k < dimension)
				{ // if in range

					current_diag_upper = pieces[i + k][j - k];
					if (current_diag_upper == "B" || current_diag_upper == " ")
					{
						b_count_diag_upper++;
					}
					else if (current_diag_upper == "W" || current_diag_upper == " ")
					{
						w_count_diag_upper++;
					}
				}
			}


			if (b_count_diag_lower == numToWin)
			{
				moves_remaining = true;
			}
			else if (w_count_diag_lower == numToWin)
			{
				moves_remaining = true;
			}
			if (b_count_diag_upper == numToWin)
			{
				moves_remaining = true;
			}
			else if (w_count_diag_upper == numToWin)
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

int Gomoku::turn()
{
	int status = waiting;
	unsigned int height, width;
	while (true)
	{
		while (status == waiting || !(height >= (unsigned int)1 && height <= (unsigned int)dimension&& width >= (unsigned int)1 && width <= (unsigned int)dimension))
		{
			status = prompt(height, width);
		}
		if (status == quit)
		{
			return quit;
		}
		if (pieces[height - 1][width - 1] == " ") {

			if (playerturn == first_player)
			{
				pieces[height - 1][width - 1] = "B";
				playerturn = second_player;
				p1moves += " ";
				if (width > 9)
				{
					int firstDigit = (width - (width % 10)) / 10;
					int secondDigit = width % 10;
					p1moves += (firstDigit + digit_to_ascii);
					p1moves += (secondDigit + digit_to_ascii);
				}
				else
				{
					p1moves += (width + digit_to_ascii);
				}
				p1moves += ",";

				if (height > 9)
				{
					int firstDigit = (height - (height % 10)) / 10;
					int secondDigit = height % 10;
					p1moves += (firstDigit + digit_to_ascii);
					p1moves += (secondDigit + digit_to_ascii);
				}
				else
				{
					p1moves += (height + digit_to_ascii);
				}

				p1moves += ";";
			}
			else if (playerturn == second_player)
			{
				pieces[height - 1][width - 1] = "W";
				playerturn = first_player;
				p2moves += " ";
				if (width > 9)
				{
					int firstDigit = (width - (width % 10)) / 10;
					int secondDigit = width % 10;
					p2moves += (firstDigit + digit_to_ascii);
					p2moves += (secondDigit + digit_to_ascii);
				}
				else
				{
					p2moves += (width + digit_to_ascii);
				}
				p2moves += ",";

				if (height > 9)
				{
					int firstDigit = (height - (height % 10)) / 10;
					int secondDigit = height % 10;
					p2moves += (firstDigit + digit_to_ascii);
					p2moves += (secondDigit + digit_to_ascii);
				}
				else
				{
					p2moves += (height + digit_to_ascii);
				}

				p2moves += ";";
			}
			print();
			if (playerturn == first_player) { cout << p2moves << endl; }//switched because if it's == first_player, second_player's turn just ended
			else if (playerturn == second_player) { cout << p1moves << endl; }
			num_moves++;
			return success;
		}
		cout << "That space is already taken!" << endl; //Added this
		status = waiting;
	}
	return should_not_reach;
}


void Gomoku::print()
{
	cout << *this << endl;
}

ostream & operator<<(ostream &stream, const Gomoku &game)
{
	for (int i = game.dimension; i >= 1; i--)
	{
		cout << setw(game.longestStringLength) << i;
		for (int j = 0; j < game.dimension; j++)
		{
			cout << setw(game.longestStringLength) << game.pieces[i - 1][j];
		}
		cout << endl;
	}
	cout << setw(game.longestStringLength) << "X";
	for (int i = 1; i <= game.dimension; i++)
	{
		cout << setw(game.longestStringLength) << i;
	}
	cout << endl;
	return stream;
}