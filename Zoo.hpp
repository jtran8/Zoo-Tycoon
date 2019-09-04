/*******************************************************************************
** Author:       Jacky Tran
** Date:         04/28/2019
** Description:  Zoo class specification file. Data members represent game info.
**               Member functions perform all game functions.
*******************************************************************************/

#ifndef ZOO_HPP
#define ZOO_HPP

#include "Animal.hpp"
#include "Turtle.hpp"
#include "Penguin.hpp"
#include "Tiger.hpp"

class Zoo
{
	private:
		Tiger** tigerElem = nullptr;
		Turtle** turtleElem = nullptr;
		Penguin** penguinElem = nullptr;
		int tigerCapacity;
		int turtleCapacity;
		int penguinCapacity;
		int tigerCount;
		int turtleCount;
		int penguinCount;
		int day;
		int feedType;
		int bankAccount;
		int pendingBankAccount;
	public:
		Zoo();
		~Zoo();
		Animal* addTurtle(int);
		Animal* addTiger(int);
		Animal* addPenguin(int);
		void setup();
		void play();
		void increaseAge();
		void feed();
		void randomEvent(int);
		void sickness();
		void attendanceBoom();
		void birth();
		bool oldEnough();
		void calcProfit();
		void buyAnimal();
		int getPendingBankAccount();
};
#endif