#pragma once
//Purpose: header for commonly used variables/return values 
#pragma once
using namespace std;
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

int usage_message(char *, char *);

enum info
{
	name_of_lab = 0,
	gametype = 1,
	gamedimension = 2,
	gamewinlength = 3,
	one_argument = 2,
	two_arguments = 3,
	three_arguments = 4,
	tictactoe_dimension = 5,
	default_gomoku_size = 19,
	num_for_tictactoe_win = 3,
	default_num_for_gomoku_win = 5,
	default_sudoku_size = 9, 
	sudoku_subgrid_dimension = 3,
	default_num_for_sudoku_win = 0,
	minDim = 1,
	minWinCt = 3,
	maxDim = 100,
	first_player = 1,
	second_player = 2,
	digit_to_ascii = 48,
	min_sudoku_input = 1,
	max_sudoku_input = 9,
	ultimate_tictactoe_dimension = 9,
	num_for_ultimate_tictactoe_win=0,
	ultimate_tictactoe_subsquare_count = 3
};

enum result_values
{
	bad_usage = -4,
	incorrect_spelling_of_usage_message = -3,
	wrong_number_of_command_line_arguments = -2,
	quit = -1,
	success = 0,
	waiting = 3,
	stalemate = 4,
	should_not_reach = -5,
	bad_board_size = -6,
	bad_win_ct = -7,
	null_gameptr = -8,
	notnull_gameptr = -9,
	bad_alloc_error = -10,
	args_are_not_ints = -11
};