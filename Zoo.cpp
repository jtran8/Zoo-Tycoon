/*******************************************************************************
** Author:       Jacky Tran
** Date:         04/28/2019
** Description:  Zoo class implementation file. Data members represent game info.
**               Member functions perform all game functions.
*******************************************************************************/

#include "Zoo.hpp"
#include "menu.hpp"
#include "globalConstants.hpp"
#include <iostream>
#include <cstdlib>

/*******************************************************************************
** Default constructor
** Initializes all data members. Uses global constants.
*******************************************************************************/
Zoo::Zoo()
{
	tigerCount = penguinCount = turtleCount  = 0;
	tigerCapacity = penguinCapacity = turtleCapacity = START_ARRAY_SIZE;
	day = feedType = 1;
	bankAccount = pendingBankAccount = START_BANK_BALANCE;
	tigerElem = new Tiger* [START_ARRAY_SIZE];
	penguinElem = new Penguin* [START_ARRAY_SIZE];
	turtleElem = new Turtle* [START_ARRAY_SIZE];
}

/*******************************************************************************
** ~Zoo function
** Frees up memory on the heap and points finished pointers to nullptr.
*******************************************************************************/
Zoo::~Zoo()
{
	for (int i = 0; i < tigerCount; i++)
	{
		delete tigerElem[i];
	}

	for (int i = 0; i < turtleCount; i++)
	{
		delete turtleElem[i];
	}

	for (int i = 0; i < penguinCount; i++)
	{
		delete penguinElem[i];
	}

	delete[] tigerElem;
	tigerElem = nullptr;

	delete[] turtleElem;
	turtleElem = nullptr;

	delete[] penguinElem;
	penguinElem = nullptr;
}

/*******************************************************************************
** setup function
** Prompts player for intial animal purchases and adds them.
*******************************************************************************/
void Zoo::setup()
{
	std::cout << "\nDay 1\n";
	std::cout << "--------------------------------------------------\n\n";
	std::cout << "Welcome to your 1st day on the job!\n";
	std::cout << "Let's start by buying some animals.\n";
	std::cout << "You have $" << bankAccount << " in the the bank to start.\n";
	
	int tigers = startTigers();

	for (int i = 0; i < tigers; i++)
	{
		addTiger(BABY_AGE);
	}

	// std::cout << pendingBankAccount << std::endl; Debugging

	int penguins = startPenguins();

	for (int i = 0; i < penguins; i++)
	{
		addPenguin(BABY_AGE);
	}

	// std::cout << pendingBankAccount << std::endl; Debugging

	int turtles = startTurtles();

	for (int i = 0; i < turtles; i++)
	{
		addTurtle(BABY_AGE);
	}

	// std::cout << pendingBankAccount << std::endl; Debugging
}

/*******************************************************************************
** play function
** The daily game flow. Provides player with information.
*******************************************************************************/
void Zoo::play()
{
		if (day > 1)
		{
			std::cout << "\nDay " << day << std::endl;
			std::cout << "--------------------------------------------------\n";
		}

		increaseAge();
		feed();
		randomEvent(feedType);
		calcProfit();

		std::cout << "\nEnd of Day Status Update:\n";
		
		if (pendingBankAccount > 0)
		{
			std::cout << "Bank Account: $" << bankAccount << std::endl;
		}
		else
		{
			std::cout << "Bank Account: -$" << abs(bankAccount) << std::endl;
		}
		
		std::cout << "Number of Tigers: " << tigerCount << std::endl;
		std::cout << "Number of Penguins: " << penguinCount << std::endl;
		std::cout << "Number of Turtles: " << turtleCount << std::endl;

		buyAnimal();

		day++;
}

/*******************************************************************************
** increaseAge function
** Increases the age of every animal in the zoo.
*******************************************************************************/
void Zoo::increaseAge()
{
	for (int i = 0; i < tigerCount; i++)
	{
		tigerElem[i]->older();
	}

	for (int i = 0; i < penguinCount; i++)
	{
		penguinElem[i]->older();
	}

	for (int i = 0; i < turtleCount; i++)
	{
		turtleElem[i]->older();
	}
}

/*******************************************************************************
** feed function
** Prompts player for the type of feed, calculates the total cost, subtracts
** cost from bank account.
*******************************************************************************/
void Zoo::feed()
{
	std::cout << "\nTime to feed the animals.\n";
	
	int cost = 0;

	for (int i = 0; i < tigerCount; i++)
	{
		cost += tigerElem[i]->getBaseFoodCost();
	}

	for (int i = 0; i < penguinCount; i++)
	{
		cost += penguinElem[i]->getBaseFoodCost();
	}

	for (int i = 0; i < turtleCount; i++)
	{
		cost += turtleElem[i]->getBaseFoodCost();
	}
	
	switch (chooseFeed())
	{
		case 1: 
		{
			feedType = 1;
			pendingBankAccount -= cost;
			std::cout << "Feeding cost $" << cost << ".\n";
		}
			break;
		case 2:
		{
			feedType = 2;
			pendingBankAccount -= cost / 2;
			std::cout << "Feeding cost $" << (cost / 2) << ".\n";
		}
			break;
		case 3:
		{
			feedType = 3;
			pendingBankAccount -= cost * 2;
			std::cout << "Feeding cost $" << (cost * 2) << ".\n";
		}
	}

	// std::cout << pendingBankAccount << std::endl; Debugging
}

/*******************************************************************************
** randomEvent function
** Generates a random event (sickness, attendance boom, or birth). If birth is
** selected, checks if there are any animals old enough to give birth. Odds of
** sickness depends on type of feed selected that day.
*******************************************************************************/
void Zoo::randomEvent(int feedType)
{
	int event = rand() % 8 + 1;

	// Changes event to nothing happens if there are no animals
	if (tigerCount == 0 && penguinCount == 0 && turtleCount == 0)
	{
		event = 8;
	}

	if (feedType == 1)
	{
		switch (event)
		{
			case 1: sickness();
				break;
			case 2: sickness();
				break;
			case 3: attendanceBoom();
				break;
			case 4: attendanceBoom();
				break;
			case 5: 
			{
				if (oldEnough())
				{
					birth();
				}
				else
				{
					randomEvent(feedType);
				}
			}
				break;
			case 6:
			{
				if (oldEnough())
				{
					birth();
				}
				else
				{
					randomEvent(feedType);
				}
			}
				break;
			default:
			{
				std::cout << "\nZoo Update:\n";
				std::cout << "Nothing special happened today.\n";
			}
		}
	}
	else if (feedType == 2)
	{
		switch (event)
		{
			case 1: sickness();
				break;
			case 2: sickness();
				break;
			case 3: sickness();
				break;
			case 4: sickness();
				break;
			case 5: attendanceBoom();
				break;
			case 6:
			{
				if (oldEnough())
				{
					birth();
				}
				else
				{
					randomEvent(feedType);
				}
			}
				break;
			default:
			{
				std::cout << "\nZoo Update:\n";
				std::cout << "Nothing special happened today.\n";
			}
		}
	}
	else
	{
		switch (event)
		{
			case 1:
			{
				// std::cout << "sick\n"; Debugging
				sickness();
			}
				break;
			case 2:
			{
				// std::cout << "boom\n"; Debugging
				attendanceBoom();
			}
				break;
			case 3:
			{
				// std::cout << "boom\n"; Debugging
				attendanceBoom();
			}
				break;
			case 4:
			{
				// std::cout << "birth"; Debugging
				if (oldEnough())
				{
					birth();
				}
				else
				{
					randomEvent(feedType);
				}
			}
				break;
			case 5:
			{
				// std::cout << "birth"; Debugging
				if (oldEnough())
				{
					birth();
				}
				else
				{
					randomEvent(feedType);
				}
			}
				break;
			case 6:
			{
				// std::cout << "birth"; Debugging
				if (oldEnough())
				{
					birth();
				}
				else
				{
					randomEvent(feedType);
				}
			}
				break;
			default:
			{
				std::cout << "\nZoo Update:\n";
				std::cout << "Nothing special happened today.\n";
			}
		}
	}
}

/*******************************************************************************
** oldEnough function
** Returns true if there are animals old enough to give birth in the zoo.
** False if there isn't.
*******************************************************************************/
bool Zoo::oldEnough()
{
	bool breeding = false;
	
	for (int i = 0; i < tigerCount; i++)
	{
		if (tigerElem[i]->getAge() >= MATURE_AGE)
		{
			breeding = true;
		}
	}

	for (int i = 0; i < penguinCount; i++)
	{
		if (penguinElem[i]->getAge() >= MATURE_AGE)
		{
			breeding = true;
		}
	}

	for (int i = 0; i < penguinCount; i++)
	{
		if (penguinElem[i]->getAge() >= MATURE_AGE)
		{
			breeding = true;
		}
	}

	return breeding;
}

/*******************************************************************************
** sickness function
** Possible outcome of randomEvent. Kills one type of animal at random by 
** deleting them.
*******************************************************************************/
void Zoo::sickness()
{
	int n = 0;
	int animal = rand() % 3 + 1;

	switch (animal)
	{
		case 1:
		{
			if (tigerCount)
			{
				delete tigerElem[tigerCount - 1];
				tigerCount--;

				std::cout << "\nZoo Update:\n";
				std::cout << "A tiger fell ill and died.\n";
			}
			else
			{
				sickness();
			}
			break;
		}
		case 2:
		{
			if (penguinCount)
			{
				delete penguinElem[penguinCount - 1];
				penguinCount--;

				std::cout << "\nZoo Update:\n";
				std::cout << "A penguin fell ill and died.\n";
			}
			else
			{
				sickness();
			}
			break;
		}
		case 3:
		{
			if (turtleCount)
			{
				//n = turtleCount - 1;
				delete turtleElem[turtleCount - 1];
				turtleCount--;

				std::cout << "\nZoo Update:\n";
				std::cout << "A turtle fell ill and died.\n";
			}
			else
			{
				sickness();
			}
			break;
		}
	}
}

/*******************************************************************************
** attendanceBoom function
** Possible outcome of randomEvent. Provides a bonus for each tiger in the zoo.
*******************************************************************************/
void Zoo::attendanceBoom()
{
	if (tigerCount)
	{
		int bonus = rand() % 251 + 250; // Range 250 - 500
		int tigerProfit = tigerCount * bonus;
		pendingBankAccount += tigerProfit;

		std::cout << "\nZoo Update:\n";
		std::cout << "There's a boom in attendance today! A new tiger documentary came out recently on WebFlix.\n";
		std::cout << "You made: $" << bonus << " extra for each tiger at the zoo!\n";
	}
}

/*******************************************************************************
** birth function
** Possible outcome of randomEvent. Random type of animal gives birth if there
** is at least one old enough.
*******************************************************************************/
void Zoo::birth()
{
	int animal = rand() % 3 + 1;
	switch (animal)
	{
		case 1:
		{
			for (int i = 0; i < tigerCount; i++)
			{
				if (tigerElem[i]->getAge() >= MATURE_AGE)
				{
					addTiger(BABY_AGE);
					
					std::cout << "\nZoo Update:\n";
					std::cout << "A baby tiger was born!\n";
					break;
				}
				else
				{
					birth();
				}
			}
			break;
		}
		case 2:
		{
			for (int i = 0; i < penguinCount; i++)
			{
				if (penguinElem[i]->getAge() >= MATURE_AGE)
				{
					for (int i = 0; i < PENGUIN_BABIES; i++)
					{
						addPenguin(BABY_AGE);
					}
					
					std::cout << "\nZoo Update:\n";
					std::cout << "5 baby penguins were born!\n";
					break;
				}
				else
				{
					birth();
				}
			}
			break;
		}
		case 3:
		{
			for (int i = 0; i < turtleCount; i++)
			{
				if (turtleElem[i]->getAge() >= MATURE_AGE)
				{	
					for (int i = 0; i < TURTLE_BABIES; i++)
					{
						addTurtle(BABY_AGE);
					}
					
					std::cout << "\nZoo Update:\n";
					std::cout << "10 baby turtles were born!\n";
					break;
				}
				else
				{
					birth();
				}
			}
		}
	}
}

/*******************************************************************************
** calcProfit function
** Calculates the profit at the end of the day but before the end day prompt 
** for buying an adult animal.
*******************************************************************************/
void Zoo::calcProfit()
{
	int n = 0, profit = 0;

	if (tigerCount)
	{
		n = tigerElem[0]->getPayoff();

		for (int i = 0; i < tigerCount; i++)
		{
			pendingBankAccount += n;
		}
	}
	
	if (penguinCount)
	{
		n = penguinElem[0]->getPayoff();

		for (int i = 0; i < penguinCount; i++)
		{
			pendingBankAccount += n;
		}
	}
	
	if (turtleCount)
	{
		n = turtleElem[0]->getPayoff();

		for (int i = 0; i < turtleCount; i++)
		{
			pendingBankAccount += n;
		}
	}
	
	profit = pendingBankAccount - bankAccount;

	std::cout << "\nProfitability Report!\n";

	if (profit > 0)
	{
		std::cout << "The zoo made $" << profit << " today.\n";
	}
	else if (profit < 0)
	{
		std::cout << "The zoo loss $" << abs(profit) << " today.\n";
	}
	else
	{
		std::cout << "The zoo broke even today.\n";
	}
	
	bankAccount = pendingBankAccount;
}

/*******************************************************************************
** buyAnimal function
** Prompts user to buy an adult animal. Cost is rolled into the following day's
** profit calculation.
*******************************************************************************/
void Zoo::buyAnimal()
{
	switch (buyMenu())
	{
		case 1: addTiger(MATURE_AGE);
			break;
		case 2: addPenguin(MATURE_AGE);
			break;
		case 3: addTurtle(MATURE_AGE);
	}

	// std::cout << pendingBankAccount << std::endl; Debugging
}

/*******************************************************************************
** addTiger function
** Adds a tiger to the zoo. Expands the array if neccessary by replacing it
** with one twice as big.
*******************************************************************************/
Animal* Zoo::addTiger(int a)
{
	if (tigerCount >= tigerCapacity)
	{
		tigerCapacity *= 2;
		Tiger** temp = new Tiger* [tigerCapacity];

		for (int i = 0; i < tigerCount; i++)
		{
			temp[i] = tigerElem[i];
		}

		delete[] tigerElem;
		tigerElem = temp;
	}

	Tiger* tiger = new Tiger(a);
	tigerElem[tigerCount++] = tiger;
	pendingBankAccount -= TIGER_COST;
	return tiger;
}

/*******************************************************************************
** addPenguin function
** Adds a penguin to the zoo. Expands the array if neccessary by replacing it
** with one twice as big.
*******************************************************************************/
Animal* Zoo::addPenguin(int a)
{
	if (penguinCount >= penguinCapacity)
	{
		penguinCapacity *= 2;
		Penguin** temp = new Penguin* [penguinCapacity];

		for (int i = 0; i < penguinCount; i++)
		{
			temp[i] = penguinElem[i];
		}

		delete[] penguinElem;
		penguinElem = temp;
	}

	Penguin* penguin = new Penguin(a);
	penguinElem[penguinCount++] = penguin;
	pendingBankAccount -= PENGUIN_COST;
	return penguin;
}

/*******************************************************************************
** addTurtle function
** Adds a turtle to the zoo. Expands the array if neccessary by replacing it
** with one twice as big.
*******************************************************************************/
Animal* Zoo::addTurtle(int a)
{
	if (turtleCount >= turtleCapacity)
	{
		turtleCapacity *= 2;
		Turtle** temp = new Turtle* [turtleCapacity];

		for (int i = 0; i < turtleCount; i++)
		{
			temp[i] = turtleElem[i];
		}

		delete[] turtleElem;
		turtleElem = temp;
	}

	Turtle* turtle = new Turtle(a);
	turtleElem[turtleCount++] = turtle;
	pendingBankAccount -= TURTLE_COST;
	return turtle;
}

int Zoo::getPendingBankAccount()
{
	return pendingBankAccount;
}