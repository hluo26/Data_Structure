#include"stack.h"
#include"box.h"
#include<iostream>

stack::stack()
{
  m_top=nullptr;
  m_size=0;
}

stack::~stack()
{
  while(m_size>0)
  {
    pop();
  }
  m_top=nullptr;
}

void stack::push(int x)
{
  /*box* temp = new box();
  temp->setvalue(x);
  if(m_size>=1)
  {
    temp->setprevious(m_top);
  }
  else
  {
    temp->setprevious(nullptr);
  }
  m_top=temp;
  //temp=nullptr;
  m_size++;*/
  
  std::cout<<x<<" has been pushed into this stack"<<std::endl;
}

int stack::pop()
{
  if(m_size==0)
  {
    std::cout<<"There is no more stack"<<std::endl;
  }
  else
  {
    int tempval = m_top->getvalue();
    box* temp = m_top;
    m_top=m_top->getprevious();
    //temp=nullptr;
    m_size--;
    return tempval;
  }
}

void stack::print()
{
  if(m_size==0)
  {
    std::cout<<"No elements in this stack"<<std::endl;
  }
  else
  {
    box* temp = m_top;
    while(temp!=nullptr)
    {
      std::cout<<temp->getvalue()<<std::endl;
      temp=temp->getprevious();
    }
  }
}

box* stack::peek()
{
  if(!isempty())
  {
    m_top->getvalue();
  }
  else
  {
    std::cout<<"No elements"<<std::endl;
  }
}

bool stack::isempty()
{
  if(m_size>=1)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int stack::size()const
{
  return m_size;
}
