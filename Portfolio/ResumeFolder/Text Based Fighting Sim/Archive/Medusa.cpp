/*
 * Harrison Moore
 * 6/23/2017
 * Creature Battle Sim
 *
*/
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Creature.hpp"
#include "Medusa.hpp"
using namespace std;
/*
creature::creature (int damage1, int outcome1)
{
	damage = damage1;
	outcome = outcome1;
}
*/
medusa::medusa()
{
	damage = 0;
	outcome = 0;
}
medusa::medusa(int damage1, int outcome1)
{
	damage = damage1;
	outcome = outcome1;
}

int medusa::attack()
{
	srand(time(NULL));

	int roll1 = rand() % 6 + 1; //rolls a 1d6, change the seed to get a different number?
	int roll2 = rand() % 6 + 1; //rolls a 1d6, change the seed to get a different number?
	damage = roll1 + roll2;
	if (damage == 12)
	{
		cout << "It seems that Medusa used her finisher 'Stone Gaze'! Is there any hope left for her target to survive?" << endl;
		damage = 1000;
		return damage;
	}
	else
	{
		return damage;
	}
}

int medusa::defense(int damage)
{
	srand(time(NULL));

	int defend = rand() % 6 + 4; //rolls a 1d6 + 3 for armor, change the seed to get a different number?
	outcome = damage - defend;
	if (outcome < 0)
	{
		cout << "You're gonna have to try harder than that to get through the Medusa's scales!" << endl;
		outcome = 0;
		return outcome;
	}
	else
	{
		cout << "That's gonna leave a mark on that Medusa." << endl;
		return outcome;
	}
}

int medusa::strength(int outcome)
{
	int health = 8; //medusa has 8 health
	health -= outcome;
/*	if (health <= 0) //if health is negative
	{
		health = 0;
		cout << "The Great Gorgan Medusa has been slain!" << endl;
	}
*/
	return health;
}
	
