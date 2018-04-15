#include"node.h"

node::node()
{
  m_left=nullptr;
  m_right=nullptr;
  m_value=0;
  m_root=nullptr;
  m_next=nullptr;
}

void node::setleft(node* left)
{
  m_left=left;
}

node* node::getleft()const
{
  return m_left;
}

void node::setright(node* right)
{
  m_right=right;
}

node* node::getright()const
{
  return m_right;
}

void node::setvalue(int value)
{
  m_value=value;
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

void node::setnode(node* root)
{
  m_root=root;
}

node* node::getnode()const
{
  return m_root;
}
