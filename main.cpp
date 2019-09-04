/*******************************************************************************
** Program Name: Zoo Tycoon
** Author:       Jacky Tran
** Date:         04/28/2019
** Description:  A sim management game. Players will manage a zoo by buying and
**               feeding animals. Requires: main.cpp, inputCheck.cpp, menu.cpp,
**               Zoo.cpp, Animal.cpp, Tiger.cpp, Penguin.cpp, and Turtle.cpp 
**               to compile.
*******************************************************************************/

#include <iostream>
#include "menu.hpp"
#include "Zoo.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	if (startMenu() == 2)
	{
		return 0;
	}

	srand(time(NULL));
	std::cout << "\nWelcome to Zoo Tycoon!\n\n";
	std::cout << "You are now the manager of a brand new zoo.\n";
	std::cout << "Keep the books balanced, it's game over if the zoo goes bankrupt.\n";
	std::cout << "Good luck!\n";

	do
	{
		Zoo game;
		game.setup();
		do
		{
			game.play();

			// Ends game if the zoo is bankrupt
			if (game.getPendingBankAccount() <= 0)
			{
				std::cout << "\nThe zoo is bankrupt!\n";
				std::cout << "Game Over\n";
				break;
			}
		} while (keepGoing());
	} while (playAgain());

	return 0;
}
