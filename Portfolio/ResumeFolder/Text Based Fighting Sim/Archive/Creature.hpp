/*
 * Harrison Moore
 * 7/23/2017
 * Creature Battle Simulator
 *
*/
#ifndef CREATURE_HPP
#define CREATURE_HPP

//#include <iostream>
//#include <time.h>
//using namespace std

class creature
{

	protected:
		int damage; //related to the attack function
		int outcome; //related to the defense funtion

	public:
//		creature();
//		creature(int,int);
		virtual int attack() = 0; //returns damage
		virtual int defense(int) = 0; //Takes damage, reduces it, returns outcome
		virtual int strength(int) = 0; //Takes outcome, Subtract health by outcome, returns health

};
#endif
