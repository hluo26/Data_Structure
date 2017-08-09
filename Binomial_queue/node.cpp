#include"node.h"
#include<iostream>

node::node()
{
  m_left = nullptr;
  m_right = nullptr;
  m_child = nullptr;
  m_key = 0;
  m_order = 0;
}

void node::setleft(node* left)
{
  m_left = left;
}

void node::setright(node* right)
{
  m_right = right;
}

void node::setchild(node* child)
{
  m_child = child;
}

void node::setkey(int x)
{
  m_key = x;
}

void node::setorder(int x)
{
  m_order = x;
}

node* node::getleft()
{
  return m_left;
}

node* node::getright()
{
  return m_right;
}

node* node::getchild()
{
  return m_child;
}

int node::getkey()
{
  return m_key;
}

int node::getorder()
{
  return m_order;
}
