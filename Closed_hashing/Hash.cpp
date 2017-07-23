#include"Hash.h"
#include<iostream>

Hash::Hash()
{
  m_length = 5;
  table = new hashnode*[m_length]();
  bool x = false;
  for(int i=0;i<m_length;i++)
  {
    table[i] = new hashnode(-1, x);
  }
}

Hash::~Hash()
{
  for(int i=0;i<m_length;i++)
  {
    delete table[i];
  }
  delete []table;
}

void Hash::insert(int x)
{
  int p = x%m_length;
  std::cout<<"key of "<<x<<" is "<<p<<std::endl;
  if(table[p]->getvalue()==-1 && !contains(x))
  {
    table[p] = new hashnode(x, false);
  }
  else
  {
    int newkey;
    int count = 1;
    do
    {
      newkey = hashing(p,count);
      count ++;
      if(p + count>m_length)
      {
        count = count - m_length;
      }
    }while(table[newkey]->getvalue()==-1 && table[newkey]);
    table[newkey] = new hashnode(x, false);
  }
}

int Hash::hashing(int x,int i)
{
  return (x+i)%m_length;
}


bool Hash::contains(int x)
{
  for(int i=0;i<m_length;i++)
  {
    if(table[i]->getvalue()==x)
    {
      std::cout<<"find it"<<std::endl;
      return true;
    }
  }
  return false;
}

void Hash::print()
{
  std::cout<<"start"<<std::endl;
  for(int i=0;i<m_length;i++)
  {
    if((table[i]->getflag())==true)
    {
      std::cout<<i<<": "<<table[i]->getvalue()<<" flag = true"<<std::endl;
    }
    else
    {
      std::cout<<i<<": "<<table[i]->getvalue()<<" flag = false"<<std::endl;
    }
  }
}
