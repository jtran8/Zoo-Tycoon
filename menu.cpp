/*******************************************************************************
** Author:       Jacky Tran
** Date:         04/28/2019
** Description:  Functions for the user choices.
*******************************************************************************/

#include <iostream>
#include "menu.hpp"
#include "inputCheck.hpp"
#include "globalConstants.hpp"

/*******************************************************************************
** startMenu function
** Displays starting menu options, prompts user for input and validates input 
** by calling the intCheck function.
*******************************************************************************/
int startMenu()
{
	int start = 0;

	std::cout << "\nSelect one of the options below:\n";
	std::cout << "1. Start Zoo Tycoon\n";
	std::cout << "2. Exit\n";

	start = intCheck(1, 2);

	if (start == 2)
	{
		std::cout << "\nQuitting...Goodbye.\n";
	}

	return start;
}

/*******************************************************************************
** customChoice function
** Asks user for the starting number of tigers and validates input by calling
** the intCheck function.
*******************************************************************************
int customChoice()
{
	int choice = 0;

	std::cout << "\nThis zoo can have tigers, penguins, and turtles.\n";
	std::cout << "Would you like to add another type of animal?\n";
	std::cout << "1. Yes\n";
	std::cout << "2. No\n";

	choice = intCheck(1, 2);

	return choice;
}*/

/*******************************************************************************
** startTigers function
** Asks user for the starting number of tigers and validates input by calling
** the intCheck function.
*******************************************************************************/
int startTigers()
{
	int tigers = 0;

	std::cout << "\nWould you like to purchase 1 or 2 tigers?\n";
	std::cout << "A tiger costs $" << TIGER_COST << ".\n";

	tigers = intCheck(1, 2);

	return tigers;
}

/*******************************************************************************
** startPenguins function
** Asks user for the starting number of penguins and validates input by calling
** the intCheck function.
*******************************************************************************/
int startPenguins()
{
	int penguins = 0;

	std::cout << "\nWould you like to purchase 1 or 2 penguins?\n";
	std::cout << "A penguin costs $" << PENGUIN_COST << ".\n";

	penguins = intCheck(1, 2);

	return penguins;
}

/*******************************************************************************
** startTurtles function
** Asks user for the starting number of turtles and validates input by calling
** the intCheck function.
*******************************************************************************/
int startTurtles()
{
	int turtles = 0;

	std::cout << "\nWould you like to purchase 1 or 2 turtles?\n";
	std::cout << "A turtle costs $" << TURTLE_COST << ".\n";

	turtles = intCheck(1, 2);

	return turtles;
}

/*******************************************************************************
** chooseFeed function
** Asks user for the type of feed and validates input by calling intCheck.
*******************************************************************************/
int chooseFeed()
{
	int feed = 0;

	std::cout << "\nWhat type of feed would you like to give the animals today?\n";
	std::cout << "1. Generic: Just normal food.\n";
	std::cout << "2. Cheap: Half the price of Generic but the animals will be more likely to get sick.\n";
	std::cout << "3. Premium: Twice the price of Generic but the animals will be less likely to get sick.\n";

	feed = intCheck(1, 3);

	return feed;
}

/*******************************************************************************
** buyAnimal function
** Asks user if they want to buy an animal and validates input by calling
** the intCheck function.
*******************************************************************************/
int buyMenu()
{
	int animals = 0;

	std::cout << "\nBefore the day ends, would you like to buy an adult animal?\n";
	std::cout << "Make sure there's enough money left in the bank!\n";
	std::cout << "1. Buy an adult tiger for $" << TIGER_COST << ".\n";
	std::cout << "2. Buy an adult penguin for $" << PENGUIN_COST << ".\n";
	std::cout << "3. Buy an adult turtle for $" << TURTLE_COST << ".\n";
	std::cout << "4. Don't buy any adult animals.\n";

	animals = intCheck(1, 4);

	return animals;
}

/*******************************************************************************
** keepGoing function
** Displays menu options, prompts user for input by calling intCheck
** and returns the valid input or takes an appropriate action.
*******************************************************************************/
int keepGoing()
{
	int cont = 2;

	std::cout << "\nDo you want to keep playing?\n";
	std::cout << "0. No\n";
	std::cout << "1. Yes\n";

	cont = intCheck(0, 1);

	if (cont == 0)
	{
		std::cout << "\nYou retire from the zoo.\n";
	}

	return cont;
}

/*******************************************************************************
** playAgain function
** Displays menu options, prompts user for input by calling intCheck
** and returns the valid input or takes an appropriate action.
*******************************************************************************/
int playAgain()
{
	int again = 2;

	std::cout << "\nDo you want to play again?\n";
	std::cout << "0. Quit\n";
	std::cout << "1. Play Again\n";

	again = intCheck(0, 1);

	if (again == 0)
	{
		std::cout << "\nQuitting...goodbye.\n";
	}

	return again;
}
