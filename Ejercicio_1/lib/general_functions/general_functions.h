#ifndef GENERAL_FUNCTIONS_H
#define GENERAL_FUNCTIONS_H

#include <iostream>

using std::string;


struct EDGE_POSITIONS
{
	int top;
	int bot;
	int left;
	int right;
};

void showCreationMessage(string objectName, bool articleMale, unsigned int lines = 0);
void showDestructionMessage(string objectName, bool articleMale, unsigned int lines = 0);

#endif // !GENERAL_FUNCTIONS_H
