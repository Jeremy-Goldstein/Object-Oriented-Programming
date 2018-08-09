

Test cases:
	Tested each game's save functionality by playing, quitting mid-game, looking through
	save file, rerunning game to confirm it loaded properly, and completing game

	Tested Sudoku
		-Entered badly formed input (text, numbers out of bound, numbers that don't match the input format of "<int>,<int>,<int>", etc.)
		-Ensured that the user would be notified if the board was filled, but incorrectly
		-Ensured that the user could not overwrite tiles that were a part of the original puzzle, whether on the original run or after quitting, saving, and re-opening
		-Ensured that the program would behave correctly upon successful completion of the program

The format of our savefiles for each game were for the first word to be NODATA (if the user had previously opted to not save the game) or the gametype (which is more of a placeholder), followed by the board
representation from [0,0] to [n,n], with dashes representing empty spaces; in the Sudoku board, the pieces were written as either, for example, "5" (if it was a user-entered 5 that could be overwritten) or "5p"
(if it was a tile that was predetermined by the game and could not be changed by the user). In all turn-based gametypes (i.e. games that are not Sudoku), we also print out the number of moves that have elapsed since the beginning of the game
so that we can use that with %2 to determine whose turn it was when the user decided to quit.

COPY CONTROL DESIGN DECISIONS:

Copy constructors:
	Since we only need one instance of a game in this project each time the program runs, 
	we did not implement copy constructors in this lab for any of our games. All the information
	needed is loaded from a save file if it exists upon instantiation of the game instance, and if 
	the save file does not exist, a blank/"fresh" game is started.

Move constructors:
	We did not think that our program was memory-intensive enough, or that it involved enough dynamic
	allocation, for us to need to implement move semantics; therefore we did not use a move constructor
	in any of our games.

Copy-assignment constructors:
	Not implementing copy constructors meant that copy-assignment constructors were also unnecessary; therefore
	we did not implement them.

Move-assignment operators:
	Not implementing move constructors meant that move-assignment constructors were also unnecessary; therefore
	we did not implement them.

Destructor:
	We did not implement our own destructors for any of the games, as the default destructor was sufficient; we would have needed to
	write our own if we used custom data types, but we did not, therefore rendering the feature irrelevant to our project.
	
========================================================================
    CONSOLE APPLICATION : Lab4 Project Overview
========================================================================

AppWizard has created this Lab4 application for you.

This file contains a summary of what you will find in each of the files that
make up your Lab4 application.


Lab4.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

Lab4.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

Lab4.cpp
    This is the main application source file.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named Lab4.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" comments to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////
