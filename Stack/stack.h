#ifndef _STACK_H_
#define _STACK_H_

#include"box.h"

class stack
{
public:
  stack();
  ~stack();
  void push(int x);
  int pop();
  box* peek();
  void print();
  bool isempty() ;
  int size() const;

private:
  box* m_top;
  int m_size;
};

#endif
