// Lab4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "geninfo_header.h"
#include "gamebase.h"

#include "Sudoku.h"

using namespace std;

int main(int argc, char* argv[])
{
	try
	{
		gamebase::check(argc, argv);
		return gamebase::instance()->play();
	}
	catch (bad_alloc&)
	{
		cout << "bad alloc" << endl;
		return bad_alloc_error;
	}
	catch (result_values e)
	{
		if (e == args_are_not_ints || e == bad_usage || e == incorrect_spelling_of_usage_message || e == wrong_number_of_command_line_arguments)//if first arg is not "Gomoku" or "TicTacToe"
		{
			usage_message("lab4.exe", "lab4.exe TicTacToe / lab4.exe Gomoku / lab4.exe Gomoku [1 <= dimension <= 100] / lab4.exe Gomoku [1 <= dimension <= 100] [win length>=3] / lab4.exe Sudoku / lab4.exe UltimateTicTacToe");
		}
		return e;
	}
	catch (exception e)
	{
		cout << e.what();
		return bad_usage;
	}
}