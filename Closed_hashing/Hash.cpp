#include"Hash.h"
#include<iostream>

Hash::Hash()
{
  m_length = 5;
  table = new hashnode*[100]();
  bool x = false;
  for(int i=0;i<100;i++)
  {
    table[i] = new hashnode(-1, x);
  }
}

Hash::~Hash()
{
  for(int i=0;i<100;i++)
  {
    delete table[i];
  }
  delete []table;
}

void Hash::insert(int x)
{
  if(!contains(x))
  {
    if(isfull())
    {
      int p = x%m_length;
      std::cout<<"key of "<<x<<" is "<<p<<std::endl;
      if(table[p]->getvalue()==-1 && p>=0 && p<m_length)
      {
        table[p] = new hashnode(x, false);
      }
      else
      {
        int count = 1;
        int newkey =p;
        while(table[newkey]->getvalue()!=-1 && newkey>=0 && newkey<m_length)
        {
          newkey = hashing(p,count);
          std::cout<<"new key of "<<x<<" is "<<newkey<<std::endl;
          count ++;
          if(p + count>m_length)
          {
            count = count - m_length;
          }
        }
        table[newkey] = new hashnode(x, false);
      }
    }
    else
    {
      std::cout<<"rehashing for "<<x<<std::endl;
      rehash(x);
    }
  }
}

void Hash::rehash(int x)
{
  int newsize = prime(m_length);
  int c = count();
  int array[c];
  int size = 0;
  for (int i = 0;i<m_length;i++)
  {
    int value = table[i]->getvalue();
    if(value!=-1)
    {
      array[size]=value;
      table[i] = new hashnode(-1,false);
      size++;
    }
  }
  m_length = newsize;
  for(int i=0;i<size;i++)
  {
    insert(array[i]);
  }
  insert(x);
}

int Hash::hashing(int x,int i)
{
  return (x+i)%m_length;
}


bool Hash::contains(int x)
{
  for(int i=0;i<m_length;i++)
  {
    if(table[i]->getvalue()==x && table[i]->getflag()==false)
    {
      std::cout<<"find it"<<std::endl;
      return true;
    }
  }
  return false;
}

void Hash::print()
{
  //std::cout<<"start"<<std::endl;
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
  std::cout<<std::endl;
}

void Hash::remove(int x)
{
  for(int i=0;i<m_length;i++)
  {
    if(table[i]->getvalue()==x && table[i]->getflag()==false)
    {
      table[i] = new hashnode(-1,true);
    }
  }
}

int Hash::count()
{
  int count=0;
  for(int i=0;i<m_length;i++)
  {
    if((table[i]->getvalue())!=-1)
    {
      count++;
    }
  }
  return count;
}

bool Hash::isfull()
{
  double c = count();
  double load = 0.0;
  load = (c+1)/m_length;
  std::cout<<"load is "<<load<<std::endl;
  if(load<=0.5)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int Hash::prime(int x)
{
  int y = 2*x;
  do
  {
    y++;
  }while(!isprime(y));
  return y;
}

bool Hash::isprime(int x)
{
  for(int i=2;i<x;i++)
  {
    if(x%i==0)
    {
      return false;
    }
  }
  return true;
}
