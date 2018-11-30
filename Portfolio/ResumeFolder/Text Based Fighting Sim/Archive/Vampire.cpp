/*
 * Harrison Moore
 * 6/23/2017
 * Creature Battle Sim
 *
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Creature.hpp"
#include "Vampire.hpp"
using namespace std;
/*
creature::creature (int damage1, int outcome1)
{
	damage = damage1;
	outcome = outcome1;
}
*/
vampire::vampire()
{
	damage = 0;
	outcome = 0;
}
vampire::vampire(int damage1, int outcome1)
{
	damage = damage1;
	outcome = outcome1;
}

int vampire::attack()
{
	srand(time(NULL));

	int damage = rand() % 12 + 1; //rolls a 1d12. Enter seed for rand to be different?
	return damage;
}

int vampire::defense(int damage)
{
	srand(time(NULL));
	
	int roll = rand() % 100 + 1; //rolls a 1d2. Enter seed for rand to be different?
	if (roll <= 50)
	{
		cout << "The vampire has charmed their opponent into not attacking with a wink of his boyish charm!" << endl;
		outcome = 0; //outcome of damage delt to vampire is 0
		return outcome;
	}
	else if (roll > 50)
	{
		int defense = rand() % 6 + 4; //rolls a 1d6 and adds 3. Enter seed for rand to be different?
		outcome = damage - defense;
		if (outcome < 0) //if outcome is a negative...
		{
			cout << "That attack didn't even look like it tickle the Vampire!" << endl;
			outcome = 0; //outcome is 0
			return outcome;
		}
		else
		{
			cout << "That's gonna leave a bruise!" << endl;
			return outcome; //returns damage calculation outcome
		}
	}
}

int vampire::strength (int outcome) 
{
	int health = 8; //vampires have 8 health
	health -= outcome; //Health - the damage calculated outcome
/*	if (health <= 0)
	{
		health = 0;
		cout << "It looks as if the boyish charm of this vampire couldn't save him from death." << endl;
		
	}
*/
	return health;
}

