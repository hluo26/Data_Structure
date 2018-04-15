#include"node.h"

node::node()
{
  m_value=0;
  m_next=nullptr;
}

void node::setvalue(int x)
{
  m_value=x;
}

int node::getvalue()const
{
  return m_value;
}

void node::setnext(node* next)
{
  m_next=next;
}

node* node::getnext()const
{
  return m_next;
}
