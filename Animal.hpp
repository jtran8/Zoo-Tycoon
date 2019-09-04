/*******************************************************************************
** Author:       Jacky Tran
** Date:         04/28/2019
** Description:  Animal class specification file. This is the parent class
**               to the Tiger, Penguin, Turtle, and NewAnimal classes. Data
**               members represent the animal attributes. Member functions are
**               a constructor, a function that increases age and get and set.
*******************************************************************************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{
	protected:
		int age;
		int cost;
		int numberOfBabies;
		int baseFoodCost;
		int payoff;
	public:
		Animal(int);
		int getAge();
		void setAge(int);
		int getCost();
		void setCost(int);
		int getNumberOfBabies();
		void setNumberOfBabies(int);
		int getBaseFoodCost();
		int getPayoff();
		void setPayoff(int);
		void older();
};

#endif