#ifndef _NODE_H_
#define _NODE_H_

#include<iostream>

template <typename T>

class node
{
public:
  node();
  void setvalue(T x);
  T getvalue()const;
  void setnext(node<T>* next);
  node<T>* getnext()const;
private:
  T m_value;
  node<T> * m_next;
};

#include"node.hpp"
#endif
