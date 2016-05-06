#include<iostream>
#include"queue.h"

queue::queue()
{
  m_size=0;
  m_back=nullptr;
  m_front=nullptr;
}

queue::~queue()
{
  while(m_size>=1)
  {
    dequeue();
  }
}

void queue::enqueue(node* x)
{
  if(m_size==0)
  {
    node* temp = new node();
    temp->setnode(x);
    m_back=temp;
    m_front=temp;
    temp=nullptr;
  }
  else
  {
    node* temp = new node();
    temp->setnode(x);
    m_back->setnext(temp);
    m_back=temp;
    temp=nullptr;
  }
  m_size++;
}

void queue::dequeue()
{
  if(m_size==0)
  {
    return;
  }
  /*else if(m_size==1)
  {
    m_front=nullptr;
    m_back=nullptr;
    m_size--;
  }*/
  else
  {
    node* temp = m_front;
    m_front=m_front->getnext();
    delete temp;
    m_size--;
  }
}

node* queue::peek()
{
  if(!isempty())
  {
    node* a = m_front->getnode();
    return a;
  }
  else
  {
    std::cout<<"empty"<<std::endl;
  }
}

int queue::size()const
{
  return m_size;
}


bool queue::isempty()
{
  if(m_size==0)
  {
    return true;
  }
  else
  {
    return false;
  }
}
