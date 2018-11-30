/*
 * Harrison Moore
 * 6/23/2017
 * Creature Battle Sim
 *
*/
#ifndef BUBBA_HPP
#define BUBBA_HPP
#include "Creature.hpp"

class bubba : public creature
{
	protected:
		int damage;
		int outcome;
	public:
		bubba();
		bubba(int,int);
		int attack(); //returns damage
		int defense(int); //returns outcome
		int strength(int); //returns health
};
#endif
