#ifndef _POKEMON_H_
#define _POKEMON_H_

class Pokemon
{
	public:
	
	Pokemon();
	void reduceHP(int amount);
	void setHP(int hp);
	int getHP()const;
	void setattackLevel(int att);
	int getattackLevel()const;
	void setdefenseLevel(int def);
	int getdefenseLevel()const;
	void setName(std::string name);
	std::string getName()const;
	

	private:

	int m_hp;
	int m_attacklevel;
	int m_defenselevel;
	std::string m_name;

};

#endif
