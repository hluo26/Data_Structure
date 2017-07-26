#include"Hash.h"
#include<iostream>

Hash::Hash()
{
  m_length = 5;
  table = new hashnode*[100]();
  for(int i=0;i<100;i++)
  {
    table[i] = new hashnode(-1);
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
      if(table[p]->getvalue()==-1)
      {
        table[p] = new hashnode(x);
        table[p] ->setnext(nullptr);
        //m_count++;
      }
      else
      {
          hashnode* current = table[p];
          hashnode* prev = current;
          while(current->getnext()!=nullptr)
          {
            prev = current;
            current = current ->getnext();
          }
          //std::cout<<"current node is"<<current->getvalue()<<std::endl;
          hashnode* newnode = new hashnode(x);
          newnode->setnext(nullptr);
          //current = new hashnode(current->getvalue());
          current->setnext(newnode);
          if(prev->getvalue() == table[p]->getvalue())
          {
            table[p]=prev;
          }
          else
          {
            prev->setnext(current);
          }
          //m_count++;
          //std::cout<<"value of chain is"<<current->getnext()->getvalue()<<std::endl;
        }
    }
    else
    {
      std::cout<<"rehashing"<<std::endl;
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
    //int value = table[i]->getvalue();
    if(table[i]->getvalue()!=-1)
    {
      if(table[i]->getnext()==nullptr)
      {
        array[size]=table[i]->getvalue();
        size++;
      }
      else
      {
        hashnode* current = table[i];
        while(current!=nullptr)
        {
          array[size]=current->getvalue();
          size++;
          current = current->getnext();
        }
      }
    }
  }
  for(int i=0;i<size;i++)
  {
    remove(array[i]);
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
  int p = x%m_length;

    if(table[p]->getvalue()==x)
    {
      return true;
    }
    else if(table[p]->getvalue()!=-1 &&table[p]->getnext()!=nullptr)
    {
      hashnode* current = table[p];
      while(current!=nullptr)
      {
        //std::cout<<current->getvalue()<<" ";
        if(current->getvalue()==x)
        {
          return true;
        }
        current = current->getnext();
        //std::cout<<"value of next is "<<current->getvalue()<<std::endl;
      }
    }
  return false;
}

void Hash::print()
{
  for(int i=0;i<m_length;i++)
  {
    std::cout<<i<<" :";
    hashnode* current = table[i];
    if(current->getnext()==nullptr)
    {
      std::cout<<current->getvalue()<<" ";
    }
    else
    {
      //std::cout<<"chain"<<std::endl;
      while(current!=nullptr)
      {
        std::cout<<current->getvalue()<<" ";
        current = current->getnext();
        //std::cout<<"value of next is "<<current->getvalue()<<std::endl;
      }
    }
    //std::cout<<"value of next is "<<table[1]->getvalue()<<std::endl;
    //std::cout<<"value of next is "<<table[1]->getnext()->getvalue()<<std::endl;
    std::cout<<std::endl;
  }
}

void Hash::remove(int x)
{
  if(contains(x))
  {
    int p = x%m_length;
    if(table[p]->getvalue()==x)
    {
      if(table[p]->getnext()==nullptr)
      {
        table[p] = new hashnode(-1);
      }
      else
      {
        hashnode* next = table[p]->getnext();
        table[p] = new hashnode(-1);
        table[p] ->setnext(nullptr);
        table[p] = next;
      }
    }
    else if(table[p]->getvalue()!=-1 &&table[p]->getnext()!=nullptr)
    {
      hashnode* current = table[p];
      hashnode* prev = current;
      while(current->getvalue()==x)
      {
        //std::cout<<current->getvalue()<<" ";
        prev = current;
        current = current->getnext();
        //std::cout<<"value of next is "<<current->getvalue()<<std::endl;
      }
      if(current->getnext()!=nullptr)
      {
        hashnode* next = current->getnext();
        current ->setnext(nullptr);
        delete current;
        prev -> setnext(next);
      }
      else
      {
        delete current;
        prev -> setnext(nullptr);
      }
    }
  }
}

int Hash::count()
{
  double count;
  for(int i=0;i<m_length;i++)
  {
    if((table[i]->getvalue())!=-1 && table[i]->getnext()==nullptr)
    {
      count++;
    }
    else if((table[i]->getvalue())!=-1 && table[i]->getnext()!=nullptr)
    {
      std::cout<<"dfjdkfdjf"<<std::endl;
      hashnode* current = table[i];
      while(current!=nullptr)
      {
        count++;
        current = current->getnext();
      }
    }
  }
  return count;
}

bool Hash::isfull()
{
  double c = count();
  std::cout<<"current count is "<<c<<std::endl;
  double load = 0.0;
  //std::cout<<"m_length is "<<m_length<<std::endl;
  load = (c+1)/m_length;
  std::cout<<"load is "<<load<<std::endl;
  if(load<=1)
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
