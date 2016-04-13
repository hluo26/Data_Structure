
#include<iostream>
#include<string>
#include"Colosseum.h"
#include"Pokemon.h"
#include"Dice.h"

int main()
{
	Pokemon poke1;
	Pokemon poke2;

	Colosseum c1;

	bool ending =false;

	std::string option= "";

	while(!ending)
	{
		std::cout<<"Player 1, build your Pokemon!"<<std::endl;

		c1.userBuild(poke1);

		std::cout<<"Player 2, build your Pokemon!"<<std::endl;

		c1.userBuild(poke2);

		c1.play(poke1,poke2);

		std::cout<<"Do you want to play again? (y/n): "<<std::endl;

		std::cin>>option;

		while(option !="n"&&option!="y")
		{
			std::cout<<"Wrong options!"<<std::endl;
			std::cin>>option;
			
		}
		if(option=="n")
		{
			std::cout<<"Thanks for playing!"<<std::endl;
			ending =true;
		}
	}
		
		
}

		
			

