#ifndef QUEUE_H
#define QUEUE_H
#include"node.h"

class queue
{
public:
  queue();
  ~queue();
  void enqueue(node* x);
  void dequeue();
  bool isempty();
  node* peek();
  int size()const;

private:
  int m_size;
  node* m_front;
  node* m_back;
};

#endif
