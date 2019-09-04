/*******************************************************************************
** Author:       Jacky Tran
** Date:         04/28/2019
** Description:  Animal class implemetation file. This is the parent class
**               to the Tiger, Penguin, Turtle, and NewAnimal classes. Data
**               members represent the animal attributes. Member functions are
**               a constructor, a function that increases age and get and set.
*******************************************************************************/

#include "Animal.hpp"

/*******************************************************************************
** Parameter constructor
** This constructor should not be used so it assigns the data members invalid
** values.
*******************************************************************************/
Animal::Animal(int a)
{
	age = a;
	cost = numberOfBabies =  baseFoodCost = payoff = -1;
}

int Animal::getAge()
{
	return age;
}

void Animal::setAge(int a)
{
	age = a;
}

int Animal::getCost()
{
	return cost;
}

void Animal::setCost(int c)
{
	cost = c;
}

int Animal::getNumberOfBabies()
{
	return numberOfBabies;
}

void Animal::setNumberOfBabies(int n)
{
	numberOfBabies = n;
}

int Animal::getBaseFoodCost()
{
	return baseFoodCost;
}

int Animal::getPayoff()
{
	return payoff;
}

void Animal::setPayoff(int p)
{
	payoff = p;
}

/*******************************************************************************
** older function
** Completes the day by aging the animal by one day.
*******************************************************************************/
void Animal::older()
{
	age++;
}