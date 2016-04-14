#include"list.h"
#include"node.h"
#include<iostream>

list::list()
{
  m_front=nullptr;
  m_size=0;
}

list::~list()
{
  node* temp =m_front;
  while(m_front!=nullptr)
  {
    temp=temp->getnext();
    delete m_front;
    m_front=temp;
  }
  m_front=nullptr;
}

bool list::isempty()const
{
  if(m_size>=1)
  {
    return false;
  }
  else
  {
    return true;
  }
}

int list::size()const
{
  return (m_size);
}

bool list::search(int x)const
{
  if(isempty())
  {
    return false;
  }
  else
  {
    node* temp=m_front;
    while(temp!=nullptr)
    {
      if(temp->getvalue()==x)
      {
        std::cout<<"find it"<<std::endl;
        return true;
      }
      temp=temp->getnext();
    }
    return false;
  }
}

void list::print()const
{
  if(m_front!=nullptr)
  {
    node*temp=m_front;
    while(temp!=nullptr)
    {
      std::cout<<temp->getvalue()<<std::endl;
      temp=temp->getnext();
    }
  }
  else
  {
    std::cout<<"The linked list is empty"<<std::endl;
  }
}

void list::addfront(int x)
{
  if(isempty())
  {
    node* temp=new node();
    temp->setvalue(x);
    temp->setnext(nullptr);
    m_front=temp;
    m_size++;
  }
  else
  {
    node* temp = new node();
    temp->setvalue(x);
    temp->setnext(m_front);
    m_front=temp;
    temp=nullptr;
    m_size++;
  }

}

void list::addback(int x)
{
  if(isempty())
  {
    node* temp = new node();
    temp->setvalue(x);
    temp->setnext(nullptr);
    m_front = temp;
    m_size++;
  }
  else
  {
    node* last = m_front;
    while(last->getnext()!=nullptr)
    {
      last=last->getnext();
    }
    node* t1 = new node();
    t1->setvalue(x);
    last->setnext(t1);
    m_size++;
  }
}

bool list::removeback()
{
  if(isempty())
  {
    std::cout<<"The linked list is empty"<<std::endl;
    return false;
  }
  else
  {
    node* last=m_front;
    node* last1=nullptr;
    while(last->getnext()!=nullptr)
    {
      last1=last;
      last=last->getnext();
    }
    last1->setnext(nullptr);
    delete last;
    last=nullptr;
    m_size--;
    return true;
  }
}

bool list::removefront()
{
  if(isempty())
  {
    std::cout<<"The linked list is empty"<<std::endl;
    return false;
  }
  else
  {
    node* temp=m_front->getnext();
    m_front->setnext(nullptr);
    delete m_front;
    m_front =temp;
    m_size--;
    return true;
  }
}

/*std::vector<int> list::tovector()const
{

}*/
