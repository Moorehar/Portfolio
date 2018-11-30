/*
 * Harrison Moore
 * 7/25/2017
 * Battle Sim
 *
*/
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Creature.hpp"
#include "Vampire.hpp"
#include "Medusa.hpp"
#include "Bubba.hpp"
using namespace std;

int main()
{
	vampire *v1 = new vampire;
	creature *c1 = v1;
	vampire *v2 = new vampire; //for when vampire has to fight vampire
	creature *c2 = v2;
	
	medusa *m1 = new medusa;
	creature *c3 = m1;
	medusa *m2 = new medusa; //for when medusa has to fight medusa
	creature *c4 = m2;

	bubba *b1 = new bubba;
	creature *c5 = b1;
	bubba *b2 = new bubba; // for when bubba has to fight bubba
	creature *c6 = b2;
	
	int choice = 0;
	do
	{
		cout << "Welcome to the Fisticuffs: Monster vs Monster." << endl;
		cout << "[1] Roster. [2] Fight. [3] Exit" << endl;
		cin >> choice;

		if (choice == 1)
		{
			int pick = 0;
			cout << "Welcome to the Roster. Your choices of Combatants include a: " << endl;
			cout << "Blood Sucking Vampire [1]" << endl;
			cout << "The Gorgan Medusa [2]" << endl;
			cout << "Bubba The Lighthearted [3]" << endl;
			cout << "Which champion do you wish to see more details about? type [1] for Vampire. [2] for Medusa. [3] for Bubba." << endl;
			cin >> pick;

			if (pick == 1)
			{
				cout << "You chose the Vampire!" << endl;
				cout << "Description: " << endl;
				cout << "The Vampire is a quick and lean fighter. What it makes up for its lack of health is great abilities in evasion and charming spells. Truly it is the fastest combatant on the field!" << endl;
				cout << "Attack: 1-12" << endl;
				cout << "Defense: 1-6" << endl;
				cout << "Armor: 3" << endl;
				cout << "Health Points: 8" << endl;
				cout << "Speed: Fast" << endl;
				cout << "Weight: Light" << endl;
				cout << "Special: Charm" << endl;
				cout << "Charm is an ability which gives the Vampire a 50 percent chance to force the opponent to not attack!" << endl;
			}
			else if (pick == 2)
			{
				cout << "You chose Medusa!" << endl;
				cout << "Description: " << endl;
				cout << "Medusa is the medium fighter of the group of three. Well rounded in speed and strength, she focuses on her all out assults to slay any foe which is unlucky enough to look her in the eye!" << endl;
				cout << "Attack: 2-12" << endl;
				cout << "Defense: 1-6" << endl;
				cout << "Armor: 3" << endl;
				cout << "Health Points: 8" << endl;
				cout << "Speed: Average" << endl;
				cout << "Weight: Medium" << endl;
				cout << "Special: Glare" << endl;
				cout << "Glare is an ability which gives Medusa the chance to instantly kill her opponent if she lands a perfect 12 on her attack" << endl;
			}
				else if (pick == 3)
			{
				cout << "You chose Bubba!" << endl;
				cout << "Description: " << endl;
				cout << "Bubba is the juggernaut of the three fighters. What he lacks in any armor, he makes up for a very high defensive scale and health points. Truly a tank of a man!" << endl;
				cout << "Attack: 2-12" << endl;
				cout << "Defence: 2-12" << endl;
				cout << "Armor: 0" << endl;
				cout << "Health Points: 12" << endl;
				cout << "Speed: Slow" << endl;
				cout << "Weight: Heavy" << endl;
				cout << "Special: None" << endl;
				cout << "Bubba is a raw fighter with raw damage and raw defence." << endl;
			}
			else
			{
				cout << "Chosen character has not been unlocked yet." << endl;
			}	
		}

		else if (choice == 2)
		{
			int f1;
			int f2;
			int tick = 2;
			cout << "Choose the combatants you wish to fight!" << endl;
			cout << "[1] Vampire. [2] Medusa. [3] Bubba." << endl;
			cout << "Fighter 1: ";
			cin >> f1;
			cout << "Fighter 2: ";
			cin >> f2;
	
			if (f1 == 1 && f2 == 1)
			{
			//Vampire vs Vampire
			cout << "It looks like we are going to have a match between a Vampire and a Vampire. For the sake of making this simple, we will call one Vampire1 and the other Vampire2." << endl;
				while(1)
				{
					cout << "It looks like Vampire1 is going to make it's attack first." << endl;
					c1->attack(); //returns damage
					cout << "Vampire2 looks to be taking the defensive on this one." << endl;
					c2->defense(c1->attack()/*damage*/); //returns outcome
					c2->strength(c2->defense(c1->attack())/*outcome*/); //returns health
					if (c2->strength(c2->defense(c1->attack())) <= 0)
					{
						cout << "Rut Roh! Vampire1 has died." << endl;
						break;
					}
					cout << "It looks like Vampire2 is looking to retaliate." << endl;
					c2->attack(); //returns damage
					c1->defense(c2->attack()/*damage*/); //returns outcome.
					c1->strength(c1->defense(c2->attack()/*outcome*/)); //returns health
					if (c1->strength(c1->defense(c2->attack())) <=0)
					{
						cout << "Guess Vampire2 has died! Poor poor Vampire2." << endl;
						break;
					}
				}                                                                        
		
			}

	
			else if ((f1 == 1 && f2 == 2) || (f1 == 2 && f2 == 1))
			{
				cout << "It looks like this match we are looking at a fight between a Vampire and a Medusa! This should be interesting!" << endl;
				while(1)
				{
					cout << "It looks like the Vampire is going to make it's attack first." << endl;
					c1->attack(); //returns damage
					cout << "Medusa looks to be taking the defensive on this one." << endl;
					c3->defense(c1->attack()/*damage*/); //returns outcome
					c3->strength(c3->defense(c1->attack()/*outcome*/)); //returns health
					if (c3->strength(c3->defense(c1->attack())) <= 0)
					{
						cout << "Good Gravey! The Winner of this match is the Vampire!" << endl;
						break;
					}
					cout << "It looks like Medusa is looking to retaliate" << endl;
					c3->attack(); //returns damage
					c1->defense(c3->attack()/*damage*/); //returns outcome
					c1->defense(c1->defense(c3->attack())/*outcome*/); //returns health
					if (c1->strength(c1->defense(c3->attack())) <=0)
					{
						cout << "Medusa, The Great Ghastly Gorgan has bitten the dust!" << endl;
						break;
					}
				}  
			}                                                                    
				
			else if ((f1 == 1 && f2 == 3) || (f1 == 3 && f2 == 1))
			{
			//Vampire vs Bubba
				cout << "This fight looks to be a Vampire against Bubba!" << endl;
				while(1)
				{
					cout << "It looks like the Vampire is going to make it's attack first." << endl;
					c1->attack(); //returns damage
					cout << "Bubba looks to be taking the defensive on this one." << endl;
					c5->defense(c1->attack());//damage); //returns outcome
					c5->strength(c5->defense(c1->attack()));//outcome); //returns health
					if (c5->strength(c5->defense(c1->attack())) <= 0)
					{
						cout << "Bubba is dead! No! Not Bubba." << endl;
						break;
					}
					cout << "It looks like Bubba is looking to retaliate" << endl;
					c5->attack(); //returns damage
					c1->defense(c5->attack());//damage); //returns outcome
					c1->defense(c1->defense(c5->attack()));//outcome); //returns health
					if (c1->defense(c1->defense(c5->attack())) <=0)
					{
						cout << "The Vampire was squished. Rip the vampire." << endl;
						break;
					}
				}
			}
       		                                                             
		
			else if (f1 == 2 && f2 == 2)
			{
			//Medusa vs Medusa
				cout << "Looks to be a Medusa fighting a... Medusa? For the sake of simplicity, we will name one Medusa1 and Medusa2." << endl;
				while(1)	
				{
      					cout << "It looks like the Medusa1 is going to make it's attack first." << endl;
       					c3->attack(); //returns damage
       					cout << "Medusa2 looks to be taking the defensive on this one." << endl;
       					c4->defense(c3->attack());//damage); //returns outcome
       					c4->strength(c4->defense(c3->attack()));//outcome); //returns health
     	  				if (c4->strength(c4->defense(c3->attack())) <= 0)
     	 				{
						cout << "Medsua2 has died. Poor poor Medusa2." << endl;
     		  				break;
     					}
     					cout << "It looks like Medusa2 is looking to retaliate" << endl;
     					c4->attack(); //returns damage
     					c3->defense(c4->attack());//damage); //returns outcome
     					c3->defense(c3->defense(c4->attack()));//outcome); //returns health
     					if (c3->defense(c3->defense(c4->attack())) <=0)
     					{
     						cout << "Medusa1 has died. We know who the alpha in this situation is." << endl;
						break;
     					}
      			 	}                                                                     
			}
															
			else if ((f1 == 2 && f2 == 3) || (f1 == 3 && f2 == 2))
			{
			//Medusa vs Bubba
				cout << "Looks to be that Medusa is fighting Bubba this fight!" << endl; 
				while(1)	
				{
      					cout << "It looks like the Medusa is going to make it's attack first." << endl;
       					c3->attack(); //returns damage
       					cout << "Bubba looks to be taking the defensive on this one." << endl;
       					c5->defense(c3->attack());//damage); //returns outcome
       					c5->strength(c5->defense(c3->attack()));//outcome); //returns health
     					if (c5->strength(c5->defense(c3->attack())) <= 0)
     					{
						cout << "Poor Bubba! He has been slain!" << endl;
     						break;
     					}
       					cout << "It looks like Medusa is looking to retaliate" << endl;
       					c3->attack(); //returns damage
       					c5->defense(c3->attack());//damage); //returns outcome
       					c5->defense(c5->defense(c3->attack()));//outcome); //returns health
     					if (c5->defense(c5->defense(c3->attack())) <=0)
     					{
     						cout << "Medusa was squished. Poor poor Medusa." << endl;
						break;
     					}
      			 	}                                                                     
			}
															
			else if (f1 == 3 && f2 == 3)
			{
			//Bubba vs Bubba
				cout << "Looks to be a Bubba fighting himself? For the sake of this strange match, we will call one Bubba1 and the other Bubba2." << endl;
				while(1)	
				{
      					cout << "It looks like the Bubba1 is going to make it's attack first." << endl;
       					c5->attack(); //returns damage
       					cout << "Bubba2 looks to be taking the defensive on this one." << endl;
       					c6->defense(c5->attack());//damage); //returns outcome
       					c6->strength(c6->defense(c5->attack()));//outcome); //returns health
     					if (c6->strength(c6->defense(c5->attack())) <= 0)
     					{
						cout << "Bubba2 has died!" << endl;
     						break;
     					}
       					cout << "It looks like Bubba2 is looking to retaliate." << endl;
       					c6->attack(); //returns damage
       					c5->defense(c6->attack());//damage); //returns outcome
       					c5->defense(c5->defense(c6->attack()));//outcome); //returns health
     					if (c5->defense(c5->defense(c6->attack())) <=0)
     					{
     						cout << "Bubba1 has died." << endl;
						break;
     					}
      			 	}                                                                    
			}
															
			else
			{
				cout << "Those were not choices. Returning to menu." << endl;
				choice = 3;
			}
		
		}
	} while (choice =! 3);
	return 0;
}
