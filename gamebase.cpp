//Define the base class from which TicTacToe and Gomoku will extend
#include "stdafx.h"

#include "geninfo_header.h"

#include "gamebase.h"
#include "TicTacToe.h"
#include "Gomoku.h"
#include "Sudoku.h"
#include "UltimateTicTacToe.h"
using namespace std;

shared_ptr<gamebase> gamebase::game_ptr = nullptr;

gamebase::gamebase(const int dim, const int winct)
	:dimension(dim), numToWin(winct), p1moves("Player "), p2moves("Player ")
{
	//dynamically allocate the 2D array which represents the state of the board
	pieces = new string*[dimension];
	for (int i = 0; i < dimension; i++)
	{
		pieces[i] = new string[dimension];
		for (int j = 0; j < dimension; j++)
		{
			pieces[i][j] = " ";
		}
	}
}

//See comments in gamebase.h for explanations of each method

int gamebase::prompt(unsigned int & y, unsigned int & x)
{
	string input = "";
	unsigned int a = -1, b = -1;
	while (true)
	{
		cout << "Input valid coordinate of form: #,#. Or, enter 'quit' to end the game." << endl;
		getline(cin, input);
		size_t commaLoc = input.find(",");
		if (input != "")
		{
			if (input == "quit" || input == "Quit" || input == "QUIT")
			{
				x = 1;
				y = 1;
				cout << num_moves << " moves were taken before the players quit." << endl;
				saveAndQuit();

			}
			else if (commaLoc != string::npos)//if there is a comma in 'input'
			{
				input.replace(commaLoc, 1, " ");
				istringstream iss(input);
				bool xExtracted = (bool)(iss >> x);
				bool yExtracted = (bool)(iss >> y);
				if (xExtracted&&yExtracted) //if 2 ints were successfully extracted from the input
				{
					return success;
				}
			}

		}
	}
}

int gamebase::play()
{
	print();
	while (!done() && !draw() && turn() != quit)
	{
		//keep calling turn() until done() or draw() return true, or the user quits
	}	
	if (done())
	{
		cout << winner << " won the game!" << endl;
		string filename = gameType + ".txt";
		ofstream ofs(filename, ofstream::out);
		ofs << "NODATA";
		return success;
	}
	else if (draw())
	{
		string filename = gameType + ".txt";
		ofstream ofs(filename, ofstream::out);
		ofs << "NODATA";
		cout << num_moves << " moves were taken, but no moves remain. The game is a draw." << endl;
		return stalemate;
	}
	else
	{
		if (gameType != "UltimateTicTacToe")
		{
			saveAndQuit();
		}
		cout << num_moves << " moves were taken before the players quit." << endl;
		throw quit;
	}

}

void gamebase::saveAndQuit()
{
	string answer;
	bool answered = false;
	string filename = gameType + ".txt";
	ofstream ofs(filename, ofstream::out);
	while (!answered)
	{
		cout << "Would you like to save the game?" << endl;
		cin >> answer;
		if (answer == "Yes" || answer == "yes")
		{
			answered = true;
			ofs << toFileString();
		}
		if (answer == "No" || answer == "no")
		{
			answered = true;
			ofs << "NODATA";
		}
	}
	ofs.close();
	throw quit;
}

void gamebase::check(int argc, char* argv[])
{
	if (gamebase::game_ptr != nullptr)
	{
		throw notnull_gameptr;
	}
	
	gamebase* game = nullptr;
	string gamemode = "";
	int dimInput;
	int winCtInput;
	if (argc == one_argument)
	{
		gamemode = argv[gametype];
		if (gamemode == "TicTacToe")
		{
			game = new TicTacToe();
			gamebase::game_ptr = make_shared<TicTacToe>();
		}
		else if (gamemode == "Gomoku")
		{
			game = new Gomoku();
			gamebase::game_ptr = make_shared<Gomoku>();
		}
		else if (gamemode == "Sudoku")
		{
			game = new Sudoku();
			gamebase::game_ptr = make_shared<Sudoku>();
		}
		else if (gamemode =="UltimateTicTacToe") {
			game = new UltimateTicTacToe();
			gamebase::game_ptr = make_shared<UltimateTicTacToe>();
		}
		else
		{
			throw incorrect_spelling_of_usage_message;
		}
	}
	else if (argc == two_arguments)
	{
		gamemode = argv[gametype];
		try
		{
			dimInput = stoi(argv[gamedimension]);
		}
		catch (invalid_argument)
		{
			throw args_are_not_ints;
		}
		if (gamemode == "Gomoku" && dimInput >= minDim && dimInput <= maxDim)
		{
			game = new Gomoku(dimInput);
			gamebase::game_ptr = make_shared<Gomoku>();
		}
		else if (gamemode == "Gomoku" && (dimInput < minDim || dimInput > maxDim))
		{
			cout << "Board dimensions must be >= " << minDim << " and <= " << maxDim << endl;
			throw bad_board_size;
		}
		else
		{
			throw bad_usage;
		}
	}
	else if (argc == three_arguments)
	{
		gamemode = argv[gametype];
		try
		{
			dimInput = stoi(argv[gamedimension]);
			winCtInput = stoi(argv[gamewinlength]);
		}
		catch(invalid_argument) //if dimInput and winCt input are not ints
		{
			throw args_are_not_ints;
		}
		if (gamemode == "Gomoku" && dimInput >= minDim && dimInput <= maxDim && winCtInput >= minWinCt)
		{
			game = new Gomoku(dimInput, winCtInput);
			gamebase::game_ptr = make_shared<Gomoku>();
		}
		else if (gamemode == "Gomoku" && (dimInput < minDim || dimInput > maxDim))
		{
			cout << "Board dimensions must be >= " << minDim << " and <= " << maxDim << endl;
			throw bad_board_size;
		}
		else if (gamemode == "Gomoku" && winCtInput < minWinCt)
		{
			cout << "Num of consecutive pieces to win must be >=" << minWinCt << endl;
			throw bad_win_ct;
		}
		else
		{
			throw bad_usage;
		}
	}
	else if (argc >= one_argument)
	{
		gamemode = argv[gametype];
		if (gamemode != "Gomoku" && gamemode != "TicTacToe" && gamemode != "UltimateTicTacToe" && gamemode != "Sudoku")
		{
			throw incorrect_spelling_of_usage_message;
		}
		else
		{
			cout << "Wrong number of commandline arguments" << endl;
			throw wrong_number_of_command_line_arguments;
		}
	}
	else
	{
		cout << "Wrong number of commandline arguments" << endl;
		throw wrong_number_of_command_line_arguments;
	}
}

shared_ptr<gamebase> gamebase::instance()
{
	if (gamebase::game_ptr != nullptr)
	{
		return gamebase::game_ptr;
	}
	else
	{
		throw null_gameptr;
	}
}

string gamebase::toFileString()
{
	string s = "";
	s += gameType + " ";
	if (gameType == "TicTacToe")
	{
		s += to_string(num_moves) + " ";
		for (int i = 1; i < dimension - 1; i++)
		{
			for (int j = 1; j < dimension - 1; j++)
			{
				if (pieces[i][j] != " ")
				{
					s += pieces[i][j];
				}
				else
				{
					s += "-";
				}
				s += " ";
			}
		}
	}
	else
	{
		if (gameType == "Gomoku" || gameType == "UltimateTicTacToe")
		{
			s += to_string(num_moves) + " ";
		}
		for (int i = 0; i < dimension; i++)
		{
			for (int j = 0; j < dimension; j++)
			{
				if (pieces[i][j] != " ")
				{
					s += pieces[i][j];
				}
				else
				{
					s += "-";
				}
				s += " ";
			}
		}
	}
	return s;
}