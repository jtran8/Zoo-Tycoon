/*******************************************************************************
** Author:       Jacky Tran
** Date:         04/28/2019
** Description:  This function validates user input by ensuring it is the right
**               type and is in range. Prompts user for another input if
**               required.
*******************************************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <regex>
#include "inputCheck.hpp"

int intCheck(int min, int max)
{
	int userInput = 0;
	std::string strInput = "";
	bool valid = false;

	do
	{
		getline(std::cin, strInput);
		std::stringstream ss(strInput);

		// Converts the string to a int if possible
		// Code source: https://bit.ly/2KXmhzg
		if (ss >> userInput)
		{
			// Checks for non-digits
			// Code source: https://bit.ly/2Ds5hLl
			if (!std::all_of(strInput.begin(), strInput.end(), ::isdigit))
			{
				std::cout << "Not an integer:\n";
			}
			else if (userInput < min || userInput > max)
			{
				std::cout << "Your choice is outside of the range, try again:\n";
			}
			else
			{
				valid = true;
			}
		}
		// First character was not a digit
		else
		{
			std::cout << "Your choice is not an integer, try again:\n";
		}

	} while (!valid);

	return userInput;
}