#include<iostream>
#include"heap.h"

using namespace std;

int main()
{
  heap* h = new heap();
  int array[16] = {100,205,150,44,95,117,402,317,82,66,11,17,1,70,87,99};
  h->build(array,16);
  h->levelorder();
  h->deletemin();
  h->levelorder();
  h->deletemin();
  h->levelorder();
  h->insert(2);
  h->levelorder();
  h->deletemax();
  h->levelorder();
  h->remove(66);
  h->levelorder();

  delete h;
}
