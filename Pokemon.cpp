#include<iostream>
#include"Pokemon.h"

Pokemon::Pokemon()
{
	this->m_hp=0;
	this->m_attacklevel=0;
	this->m_defenselevel=0;
	std::string m_name=" ";
}

void Pokemon::reduceHP(int amount)
{
	m_hp = m_hp - amount;
	
}

void Pokemon::setHP(int hp)
{
	m_hp = hp;
}

int Pokemon::getHP()const
{
	return m_hp;
}

void Pokemon::setattackLevel(int att)
{
	m_attacklevel = att;
}

int Pokemon::getattackLevel()const
{
	return m_attacklevel;
}

void Pokemon::setdefenseLevel(int def)
{
	m_defenselevel = def;
}

int Pokemon::getdefenseLevel()const
{
	return m_defenselevel;
}

void Pokemon::setName(std::string name)
{
	m_name = name;
}

std::string Pokemon::getName()const
{
	return m_name;
}
