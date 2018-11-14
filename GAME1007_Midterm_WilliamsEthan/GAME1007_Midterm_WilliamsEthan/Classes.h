#pragma once
#include <string>
#define ABIL_PLR 4
using namespace std;

/* Structs and classes are nearly identical ways to group variables and functions 
   together to create a template for what becomes an object. The class/struct's name, 
   e.g. 'Ability', becomes like a data type and we can declare variables of this new
   type, e.g. Ability myAbility; and 'myAbility' is what's called an object. We then use
   the member access, a.k.a. dot operator (.) to access the members of the object, thus:
   myAbilty.name = "Kamehameha"; and member functions are called similarly, thus:
   myAbility.AdvCooldown(); */

struct Ability /* In a struct, all members are public by default. Public means we can 
			      access the member through the dot operator. Otherwise we can't. */
{
	/* Member attributes initialized from file. */
	string name;
	short damage;
	short critChance; /* I should have just made the critChance the d20 number to meet or beat. Oh well.*/
	bool autohit;
	short cooldown;
	short currEff[4]; /* Current round effects. */
	short nextEff[4]; /* Effects applied until the end of a players' next turn. */

	short cdTimer = 0; /* Use of in-class initializers (C++11). Many code standards 
					      say this is a no-no. But I'm showing it to you for now. */
	bool onCooldown = false;
	bool selected = false;

	void AdvCooldown()
	{
		if (onCooldown)
		{
			cdTimer--;
			if (cdTimer == 0)
			{
				onCooldown = false;
				selected = true; /* Once the game starts, I used selected to show
								    if the ability is available to use */
			}
		}
	}
	void SetCooldown()
	{
		if (cooldown > 0)
		{
			onCooldown = true;
			selected = false;
			cdTimer = cooldown;
		}
	}
};

class Player /* In a class, all members are private by default meaning we can't use the dot
			    operator to access a member. This allows us to keep our private members 'safe' 
				and provide a public member function only if access to them is required. */
{
	string name;
	short health = 100; /* More in-class initializers here. */
	short bonuses[4] = { 0 }; /* Attack bonus, defense bonus, damage bonus, health bonus. */
	Ability abilities[ABIL_PLR]; /* Array holding the four abilities the player can use. */

public: /* We can add a heading, thus, to specify an access type other than the default. */
	/* All these that follow are member functions, often called methods. */
	string GetName() { return name; }
	short GetHealth() { return health; }
	Ability* GetAbilities() { return abilities; }
	short GetDefense() { return 10 + bonuses[1]; }
	void SetName(const string n) { name = n; }
	void SetAbility(Ability a, short i) { abilities[i] = a;	}
	void SetBonuses(short* e)
	{
		for (int i = 0; i < 4; i++)
			bonuses[i] = e[i];
	}
	void SetHealth(short m)
	{
		health += m;
		health = (health > 100?100:(health < 0 ? 0 : health));
	}
	void ResetBonuses()
	{
		for (int i = 0; i < 4; i++)
			bonuses[i] = 0;
	}
	void PrintStats()
	{
		cout << name << "'s Stats\nHealth: " << health << "  Atk Bonus: " << bonuses[0] 
			 << "  Def Bonus: " << bonuses[1] << "  Dmg Bonus: " << bonuses[2] << endl;
	}
	/* The jacked boi attack function. And the second part of this test. */
	bool DoAttack(Player& target) /* We are passing in a reference to the other player we are attacking. */
	{
		// DONE Define a char called opt
		char opt; 
		int atkRoll = 0, defRoll = 0, dmgRoll = 0, aIndex;
		
		// DONE Call PrintStats() member function of player (in same class in line 87)
		PrintStats(); 
		// DONE While true
		while (true)
		{
			// Output to enter number of ability to use
			cin.get(opt);
			cin.ignore(INT_MAX, '\n');
			// DONE Set aIndex to opt - 48
			aIndex = opt - 48;
			if (!(aIndex >= 0 && aIndex < ABIL_PLR))
			{
				cout << "The number you have entered is invalid. Please try again"; // DONE Output that the number is invalid and try again
				continue; // DONE Put the continue statement here
			}
			else if (abilities[aIndex].onCooldown == true) /* abilities[aIndex] represents the current ability used. */
			{
				cout << "The ability is on cooldown. Please try again"; // DONE Output that the ability is on cooldown and try again
				continue; // DONE Put the continue statement here
			}
			else
			break; 	// DONE Put the break statement here
		}
		// DONE Call SetBonuses() member function with a parameter abilities[aIndex].currEff
		SetBonuses(abilities[aIndex].currEff);
		cout << name << " uses " << abilities[aIndex].name; /* This outputs that the current player uses the current ability. */
		if (abilities[aIndex].autohit == false)		// If abilities[aIndex].autohit is equivalent to false 
		{
			atkRoll = (1 + rand() % 20) + bonuses[0];
			// DONE Set defRoll to be target.GetDefense()
			defRoll = target.GetDefense();
			// DONE If atkRoll is greater than or equal to defRoll
			if (atkRoll >= defRoll)
			{
				cout << " and hits ";
			
			}
			else
				cout << " and misses ";
			cout << '(' << atkRoll << " vs " << defRoll << ")";
		}
		if (abilities[aIndex].damage > 0 && atkRoll >= defRoll)
		{
			for (int i = 0; i < abilities[aIndex].damage; i++)
				dmgRoll = (1 + rand() % 7 + bonuses[2]);	// DONE Increment the dmgRoll by random number of 1 to 6 inclusive (hint: use a += operator)
			// DONE Add bonuses[2] to the dmgRoll (hint: use a += operator)
			int critRoll = 20 - (20.0 * (abilities[aIndex].critChance / 100.0)); /* Which set of parenthesis do I not need? */
			if (atkRoll >= critRoll) // DONE If atkRoll is greater than or equal to critRoll
				dmgRoll *= 2; // DONE Set dmgRoll to be doubled (hint: use the *= operator)
			cout << " for " << dmgRoll << (atkRoll >= critRoll ?" critical ":" ") << "damage";
		}
		cout << '!' << endl; /* The enemy has been alerted to your presence, Snake. */
		SetHealth(bonuses[3]); // DONE Call SetHealth() member function with a parameter bonuses[3]
		target.SetHealth(-dmgRoll); /* Here we are essentially decrementing the target's health by dmgRoll. */
		cout << name << "'s health: " << health << ". " << target.GetName() << "'s health: " << target.GetHealth() << '.' << endl;
		if (target.GetHealth() == 0)
			return 1;// DONE Return 1
		ResetBonuses(); // DONE Call ResetBonuses() member function
		SetBonuses(abilities[aIndex].nextEff); // DONE Call SetBonuses() member function with parameter abilities[aIndex].nextEff
		for (int i = 0; i < ABIL_PLR; i++) // DONE For an integer i = 0, continue while i is less than ABIL_PLR, and increment i by one
		{
			// DONE If i is equivalent to aIndex
			if (i == aIndex)
			{
				abilities[i].SetCooldown();
			}	
			else 
			abilities[i].AdvCooldown();
		}
		return 0; // DONE Return 0
	}
};