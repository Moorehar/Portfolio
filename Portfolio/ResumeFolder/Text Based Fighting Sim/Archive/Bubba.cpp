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
#include "Bubba.hpp"
using namespace std;
/*
creature::creature (int damage1, int outcome1)
{
	damage = damage1;
	outcome = outcome1;
}
*/
bubba::bubba()
{
	damage = 0;
	outcome = 0;
}
bubba::bubba(int damage1, int outcome1)
{
	damage = damage1;
	outcome = outcome1;
}
int bubba::attack()
{
	srand(time(NULL));

	int roll1 = rand() % 6 + 1; //rolls a 1d6, change the seed to get a different number?
	int roll2 = rand() % 6 + 1; //rolls a 1d6, change the seed to get a different number?
	damage = roll1 + roll2;
	return damage;
}

int bubba::defense(int damage)
{
	srand(time(NULL));

	int defense;
	int roll1 = rand() % 6 + 1; //rolls a 1d6, change the seed to get a different number?
	int roll2 = rand() % 6 + 1; //rolls a 1d6, change the seed to get a different number?
	defense = roll1 + roll2;
	outcome = damage - defense;
	if (outcome < 0)
	{
		cout << "Bubba is too strong for petty attacks! Try harder than that!" << endl;
		outcome = 0;
		return outcome;
	}
	else
	{
		cout << "That's what bubba gets for not having any armor!" << endl;
		return outcome;
	}
}

int bubba::strength(int outcome)
{
	int health = 12; //Bubba has 12 health
	health -= outcome;
/*	if (health <= 0)
	{
		health = 0;
		cout << "Rest In Pieces Bubba!" << endl;
	
	}
*/
	return health;
}
