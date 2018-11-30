/*
 * Harrison Moore
 * 6/23/2017
 * Creature Battle Sim
 *
*/
#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP
#include "Creature.hpp"

class vampire : public creature
{
	protected: //added private and the double int 
		int damage;
		int outcome;
	public: //removed virtuals before int. added default constrcutor
		vampire();
		vampire(int,int); //takes in damage and outcome
		int attack(); //returns damage
		int defense(int); //takes damage, returns outcome
		int strength(int); //takes outcome, returns health
};
#endif
