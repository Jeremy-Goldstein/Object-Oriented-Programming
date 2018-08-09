//Purpose: all-purpose code to be used in multiple assignments (usage message, etc.)

#include "stdafx.h"
#include "geninfo_header.h"
#include <iostream>
#include <string>

using namespace std;

int usage_message(char * filename, char * proper_input)
{
	cout << "usage: <" << filename << "> " << proper_input << " | encountered above error" << endl;
	return bad_usage;
}
