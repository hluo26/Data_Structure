#ifndef _COLOSSEUM_H_
#define _COLOSSEUM_H_

#include"Pokemon.h"
#include"Dice.h"

class Colosseum
{
	public:

	Colosseum();
	void userBuild(Pokemon& p);
	bool attack(Pokemon& attacker, Pokemon& defender);
	void play(Pokemon &p1, Pokemon &p2);

	private:

	Dice d20;
	Dice d6;
	Dice d2;
};

#endif
