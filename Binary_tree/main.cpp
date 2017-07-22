#include<iostream>
#include"bt.h"

using namespace std;

int main()
{
  bt* newtree = new bt();

  newtree->add(10,0);
  newtree->add(5,1);
  newtree->add(8,2);
  newtree->add(17,3);
  newtree->add(2,4);
  newtree->add(0,5);
  newtree->add(40,6);
  newtree->add(6,7);
  newtree->add(12,8);
  newtree->add(0,9);
  newtree->add(0,10);
  newtree->add(3,13);
  newtree->add(0,14);
  newtree->printorder(1);
  newtree->printorder(2);

  delete newtree;
}
