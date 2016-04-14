#ifndef _QUEUE_H_
#define _QUEUE_H_

#include"node.h"
#include"PreconditionViolationException.h"
#include<iostream>

template <typename T>

class queue
{
public:
  queue();
  ~queue();
  void enqueue(const T x);
  T dequeue()throw(PreconditionViolationException);
  bool isempty()const;
  int size()const;
  T peek()const throw(PreconditionViolationException);
  void print()const;
  bool remove(const T x);
  //bool search(T x);

private:
  node<T>* m_front;
  node<T>* m_back;
  int m_size;

};

#include"queue.hpp"
#endif
