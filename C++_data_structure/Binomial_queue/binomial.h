#include"node.h"
#include<queue>
using namespace std;

#ifndef BINOMIAL_H
#define BINOMIAL_H

class binomial
{
public:
  binomial()
  ~binomial();
  void insert(int x);
  void unions(node** q1,node** q2);
  void deletemin();

private:
  node** myqueue;
  node** queue1;
  int m_size;
}
