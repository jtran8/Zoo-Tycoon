/*******************************************************************************
** Author:       Jacky Tran
** Date:         04/28/2019
** Description:  Penguin class implementation file. This class is derived from
**               the Animal class.
*******************************************************************************/

#include "Penguin.hpp"
#include "globalConstants.hpp"

Penguin::Penguin(int a) : Animal(a)
{
	age = a;
	cost = PENGUIN_COST;
	numberOfBabies = PENGUIN_BABIES;
	baseFoodCost = BASE_FOOD_COST * PENGUIN_FEEDING_COST;
	payoff = PENGUIN_PAYOFF;
}