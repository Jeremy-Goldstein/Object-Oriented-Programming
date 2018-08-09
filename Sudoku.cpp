//implementation of Sudoku
#include "stdafx.h"
#include "Sudoku.h"
#include <set>

using namespace std;

//see sudoku.h for description of each method

Sudoku::Sudoku() : gamebase(default_sudoku_size, default_num_for_sudoku_win)
{
	gameType = "Sudoku";
	playerturn = 1;
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
	//read in the savefile if it exists, or boot up a fresh game from sudoku0.txt if it does not
	string filename = gameType + ".txt";
	string intialGameFilename = "sudoku0.txt";
	ifstream file(filename);
	bool nodata = true;
	if (file)
	{
		string firstWord;
		file >> firstWord;
		if (firstWord != "NODATA")
		{
			nodata = false;
		}
	}

	if (file && !nodata)
	{
		string currStr;
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
	else
	{
		ifstream file(intialGameFilename);
		string currStr;
		for (int i = 0; i < dimension; i++)
		{
			for (int j = 0; j < dimension; j++)
			{
				if (file >> currStr)
				{
					if (currStr != "0")
					{
						pieces[i][j] = currStr + "p";
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
};


bool Sudoku::squaresFilled()
{
	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			if (pieces[i][j] == " ")
			{
				return false;
			}
		}
	}
	return true;
}

bool Sudoku::done()
{
	if (!squaresFilled())
	{
		return false;
	}
	for (int i = 0; i < dimension; i++)
	{
		int row[ultimate_tictactoe_dimension];
		int col[ultimate_tictactoe_dimension];
		for (int j = 0; j < dimension; j++)
		{
			row[j] = stoi(pieces[i][j]);
			col[j] = stoi(pieces[j][i]);
		}
		set<int> row_set(begin(row), end(row));
		set<int> col_set(begin(col), end(col));
		if (col_set.size() != ultimate_tictactoe_dimension || row_set.size() != ultimate_tictactoe_dimension)
		{
			cout << "All squares have been filled, but the board is incorrect" << endl;
			return false;
		}
	}
	
	for (int i = 0; i < sudoku_subgrid_dimension; i++)
	{
		for (int j = 0; j < sudoku_subgrid_dimension; j++)
		{
			int box[ultimate_tictactoe_dimension];
			for (int k = 0; k < dimension / sudoku_subgrid_dimension; k++)
			{
				for (int q = 0; q < dimension / sudoku_subgrid_dimension; q++)
				{
					box[sudoku_subgrid_dimension*k+q] = stoi(pieces[i*sudoku_subgrid_dimension + k][j*sudoku_subgrid_dimension + q]);
				}
			}
			set<int> box_set(begin(box), end(box));
			if (box_set.size() != ultimate_tictactoe_dimension) 
			{
				cout << "All squares have been filled, but the board is incorrect" << endl;
				return false;
			}
		}
	}
	return true;
}



bool Sudoku::draw()
{
	return false;
}

int Sudoku::turn()
{
	int status = waiting;
	unsigned int height, width,num;
	while (true)
	{
		while (status == waiting || !(height >= (unsigned int)0 && height < (unsigned int)dimension&& width >= (unsigned int)0 && width < (unsigned int)dimension && num>=min_sudoku_input && num <= max_sudoku_input))
		{
			status = prompt(height, width,num);
		}
		if (status == quit)
		{
			return quit;
		}
		if (pieces[height][width].length() == 1) 
		{
			pieces[height][width] = to_string(num);
			print();
			return success;
		}
		else {
			cout << "That space is a permanent space,meaning it can't be overriden. Choose a different space." << endl;
		}
		status = waiting;
	}
	return should_not_reach;
}


void Sudoku::print()
{
	cout << *this << endl;
}

ostream & operator<<(ostream &stream, const Sudoku &game)
{
	string barrier;
	for (int i = game.dimension-1; i >= 0; i--)
	{
		cout << i;
		cout << "||";
		for (int j = 0; j < game.dimension ; j++)
		{
			if (game.pieces[i][j] != " ")
			{
				cout << stoi(game.pieces[i][j]);
			}
			else
			{
				cout << game.pieces[i][j];
			}
			cout << "|";
			if ((j + 1) % sudoku_subgrid_dimension == 0)
			{
				cout << "|";
			}
		}
		cout << endl;
		if (i % sudoku_subgrid_dimension == 0)
		{
			barrier = "=";
		}
		else
		{
			barrier = "-";
		}
		cout << barrier + "||";
		for (int j = 0; j < game.dimension; j++)
		{
			cout << barrier;
			cout << "|";
			if ((j + 1) % sudoku_subgrid_dimension == 0)
			{
				cout << "|";
			}
		}
		cout << endl;
	}
	cout << "#||";
	for (int i = 0; i < game.dimension; i++)
	{
		cout << i << "|";
		if ((i + 1) % sudoku_subgrid_dimension == 0)
		{
			cout << "|";
		}
	}
	cout << endl;
	return stream;
}

int Sudoku::prompt(unsigned int &y, unsigned int &x, unsigned int &num)
{
	string input = "";
	while (true)
	{
		cout << "Input valid coordinates in the form \"x coordinate,y coordinate,input\". Or, enter 'quit' to end the game." << endl;
		getline(cin, input);
		size_t firstCommaLoc = input.find(",");
		if (input != "")
		{
			if (input == "quit" || input == "Quit" || input == "QUIT")
			{
				x = 1;
				y = 1;
				
				saveAndQuit(); //throws "quit", so no need to return
			}
			else if (firstCommaLoc != string::npos)//if there is a comma in 'input'
			{
				size_t secondCommaLoc = input.find(",", firstCommaLoc + 1, 1);
				if (secondCommaLoc != string::npos)
				{
					input.replace(firstCommaLoc, 1, " ");
					input.replace(firstCommaLoc+secondCommaLoc-1, 1, " ");
					istringstream iss(input);
					bool xExtracted = (bool)(iss >> x);
					bool yExtracted = (bool)(iss >> y);
					bool nExtracted = (bool)(iss >> num);
					if (xExtracted&&yExtracted&&nExtracted) //if 2 ints were successfully extracted from the input
					{
						return success;
					}
					else
					{
						cout << "The input was invalid" << endl;
					}
				}
				else
				{
					cout << "Missing third argument" << endl;
				}
			}

		}
	}
}

int Sudoku::play()
{
	print();
	while (!done() && turn() != quit)
	{
		//keep calling turn() until done() or draw() return true, or the user quits
	}

	if (done())
	{
		cout << "You won the game!" << endl;
		string filename = gameType + ".txt";
		ofstream ofs(filename, ofstream::out);
		ofs << "NODATA";
		return success;
	}
	else
	{
		saveAndQuit();
		throw quit;
	}

}
