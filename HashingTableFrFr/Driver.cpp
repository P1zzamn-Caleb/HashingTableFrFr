//*********************************************************************************
// Authors: Caleb Ellis, Tori Dean, Chloe Byrd, Jay Goodroe
// Start Date: March 5. 2026
// Name: CS 355 HashingTable Group Assignment
// Description: This file contains the main driver program that interacts with
// the user and performs operations on HashingTable class.
//*********************************************************************************
#include "HashingTable.h"
#include <iostream>
using namespace std;

char getMenuInput();
void performDesiredOp(char inVal, HashingTable<int>& table);

int main()
{
	char menuInput = ' ';
	int keyVal = 0;

	/*cout << "How big do you want your hash table?" << endl;
	cin >> size;	should be updated to do this later */
	HashingTable<int> nums;

	// she may not want the menu to show repeatedly,
	// maybe just once at the start - Tori
	while (menuInput != 'Q')
	{
		menuInput = getMenuInput();
		performDesiredOp(menuInput, nums);
	}

	return 0;
}

//********************************************************************************
// Author: Caleb Ellis, Tori Dean (adjusted for this project)
// Name: getMenuInput()
// Purpose: Gets input from the menu
// Incoming: none
// Outgoing: input char
// Return: char input
//********************************************************************************
char getMenuInput()
{
	char input;

	cout << endl << "****************************" << endl;
	cout << "Select an option:" << endl;
	cout << "\"+\" - Insert" << endl;
	cout << "\"-\" - Remove" << endl;
	cout << "\"?\" - Search" << endl;
	cout << "\"P\" - Print" << endl;
	cout << "\"L\" - Load Factor" << endl;
	cout << "\"Q\" - Quit" << endl;
	cout << "****************************" << endl;
	cin >> input;
	input = toupper(input);
	return input;
}

/*
// Author: Caleb Ellis, Tori Dean (adjusted for this project)
// Name: performDesiredOp
// Purpose: Performs the user’s desired operation
// Incoming: input (char) and table (ref HashingTable)
// Outgoing: none
// Return: none
*/
void performDesiredOp(char input, HashingTable<int>& table)
{
	int inVal = 0, location = 0;

	switch (input)
	{
	case '+':
		cin >> inVal;
		table.Insert(inVal);
		break;
	case '-':
		cin >> inVal;
		if (!table.Remove(inVal))
			cout << inVal << " was not found." << endl;
		break;
	case '?':
		cin >> inVal;
		if (table.Search(inVal, location))
			cout << inVal << " located in " << location << endl;
		break;
	case 'P':
		table.Print();
		cout << endl;
		break;
	case 'L':
		table.loadFactor();
		cout << endl;
		break;
	case 'Q':
		break;
	default:
		cout << "INVALID INPUT! TRY AGAIN!" << endl;
	}
}