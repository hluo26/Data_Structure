#include<iostream>
#include"queue.h"

int main()
{
  queue<int>* q1 = new queue<int>();

  q1->enqueue(3);
  q1->enqueue(5);
  q1->enqueue(7);
  q1->enqueue(9);
  q1->dequeue();
  q1->print();
  q1->remove(7);
  q1->print();

  delete q1;
}
