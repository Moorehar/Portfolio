/*
 * Harrison Moore
 * 6/23/2017
 * Creature Battle Sim
 *
*/
#ifndef MEDUSA_HPP
#define MEDUSA_HPP
#include "Creature.hpp"

class medusa : public creature
{
	protected: //added private and the double int
		int damage;
		int outcome;
	public: //removed virtals before int
		medusa();
		medusa(int,int);
		int attack(); //returns damage
		int defense(int); //takes damage, returns outcome
		int strength(int); //takes outcome, returns health
};
#endif
