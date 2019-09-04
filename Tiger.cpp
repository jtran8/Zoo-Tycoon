/*******************************************************************************
** Author:       Jacky Tran
** Date:         04/28/2019
** Description:  Tiger class implementation file. This class is derived from
**               the Animal class.
*******************************************************************************/

#include "Tiger.hpp"
#include "globalConstants.hpp"

Tiger::Tiger(int a) : Animal(a)
{
	age = a;
	cost = TIGER_COST;
	numberOfBabies = TIGER_BABIES;
	baseFoodCost = BASE_FOOD_COST * TIGER_FEEDING_COST;
	payoff = TIGER_PAYOFF;
}