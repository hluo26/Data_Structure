#include<iostream>
#include<string>
#include"Colosseum.h"
#include"Pokemon.h"
#include"Dice.h"

Colosseum::Colosseum()
{
	d20 = Dice(20);
	d6 = Dice(6);
	d2 = Dice(2);
}

void Colosseum::userBuild(Pokemon& p)
{
	int hp,attack,defense;
	std::string name;
	std::cout<<"Please name your pokemon: "<<std::endl;
	std::cin>>name;
	while(name.size()<=1)
	{
		std::cout<<"Your name must be at least 1 character long: "<<std::endl;
		std::cin>>name;
	}
	p.setName(name);
	
	std::cout<<"How many hit points will it have? (1-50): "<<std::endl;
	std::cin>>hp;
	while(hp<1||hp>50)
	{
		std::cout<<"Sorry. The hit points must be between 1 and 50: "<<std::endl;
		std::cin>>hp;
	}
	p.setHP(hp);

	std::cout<<"Split fifty points between attack level and defense level"<<std::endl;
	std::cout<<"Enter your attack level (1-49):"<<std::endl;
	std::cin>>attack;
	while(attack<1||attack>=50)
	{
		std::cout<<"Sorry. The attack level must be between 1 and 49:"<<std::endl;
		std::cin>>attack;
	}
	p.setattackLevel(attack);

	std::cout<<"Enter your defense level (1-"<<(50-attack)<<"):"<< std::endl;
	std::cin>>defense;
	
	while(defense<1||defense>(50-attack))
	{
		std::cout<<"Sorry. The attack level must be between 1 and "<<(50-attack)<<":"<<std::endl;
		std::cin>>defense;
	}
	p.setdefenseLevel(defense);

}

bool Colosseum::attack(Pokemon& attacker, Pokemon& defender)
{
	if(attacker.getHP())
	{

		int att1=d20.roll();
		int def1=d20.roll();
		int r1=d6.roll();
		int r2=d6.roll();
		int r3=d6.roll();
		int sum1 = r1+r2+r3;

		std::cout<<attacker.getName()<<" is attacking "<<defender.getName()<<std::endl;
		std::cout<<attacker.getName()<<" rolls an attack bonus of "<<att1<<std::endl;
		std::cout<<defender.getName()<<" rolls a defense bonus of "<<def1<<std::endl;

		if(attacker.getattackLevel()+att1>defender.getdefenseLevel()+def1)
		{
			std::cout<<"The attack hits dealing 3-D6 damage!"<<std::endl;
			std::cout<<"The rolls are "<<r1<<", "<<r2<<", "<<r3<<" totaling: "<<sum1<<" damage!"<<std::endl;
			defender.reduceHP(sum1);

			if(defender.getHP()>0)
			{
				std::cout<<defender.getName()<<" has "<<defender.getHP()<<" hit points left"<<std::endl;
				return false;
			}
			else
			{
				std::cout<<defender.getName()<<" have been defeated"<<std::endl;
				return true;
			}
		}
		else
		{
			std::cout<<"The attack missed!"<<std::endl;
			return false;
		}
	}
	else
	{
		std::cout<<attacker.getName()<<" have been defeated"<<std::endl;
		return true;
	}

}

void Colosseum::play(Pokemon& p1,Pokemon& p2)
{
	std::cout<<"Choosing which player to go first:"<<std::endl;

	
		int a=d2.roll();
		int b=d2.roll();
		std::string option = " ";
		while(a==b)
		{
			a=d2.roll();
			b=d2.roll();
		}
			
		if(a>b)
		{
			std::cout<<"Player 1 will go first."<<std::endl;

			for(int i=0;i<10;i++)
			{
				std::cout<<" "<<std::endl;
				std::cout<<"Round "<<i+1<<"!"<<std::endl;
				std::cout<<" "<<std::endl;
				if(attack(p1,p2))
				{
					std::cout<<""<<std::endl;
					std::cout<<p2.getName()<<" has been lost!"<<std::endl;
					i=10;
				}
				if(attack(p2,p1))
				{
					std::cout<<""<<std::endl;
					std::cout<<p1.getName()<<" has been lost!"<<std::endl;
					i=10;
				}
				else if(i==9)
				{
					std::cout<<"they are still alive"<<std::endl;
				}
			}
		}
		else
		{
			std::cout<<"Player 2 will go first."<<std::endl;
			for(int i=0;i<10;i++)
			{
				std::cout<<"Round "<<i+1<<"!"<<std::endl;
				std::cout<<" "<<std::endl;
				if(attack(p2,p1))
				{
					std::cout<<""<<std::endl;
					std::cout<<p1.getName()<<" has been lost!"<<std::endl;
					i=10;
				}
				if(attack(p1,p2))
				{
					std::cout<<""<<std::endl;
					std::cout<<p2.getName()<<" has been lost!"<<std::endl;
					i=10;
				}
				else if(i==9)
				{
					
					std::cout<<"they are still alive"<<std::endl;	
				}
				
			}
		}

}




	
	
