/*******************************************************************************
** Author:       Jacky Tran
** Date:         04/28/2019
** Description:  Turtle class implementation file. This class is derived from
**               the Animal class.
*******************************************************************************/

#include "Turtle.hpp"
#include "globalConstants.hpp"

Turtle::Turtle(int a) : Animal(a)
{
	age = a;
	cost = TURTLE_COST;
	numberOfBabies = TURTLE_BABIES;
	baseFoodCost = BASE_FOOD_COST * TURTLE_FEEDING_COST;
	payoff = TURTLE_PAYOFF;
}