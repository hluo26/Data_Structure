#include<iostream>
#include"skew.h"

using namespace std;

int main()
{
  skew* l = new skew();
  int array[11] = {4,3,7,9,2,6,1,5,8,10,11};
  for(int i=0;i<11;i++)
  {
    l->insert(array[i]);
  }
  l->printorder(4);
  l->deletemin();
  l->printorder(4);
  l->deletemin();
  l->printorder(1);
  l->printorder(4);
  l->deletemin();
  l->printorder(4);
  l->deletemin();
  l->printorder(4);
  l->deletemin();
  l->printorder(4);

  delete l;
}
