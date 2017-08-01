#include<iostream>
#include"heap.h"

using namespace std;

int main()
{
  heap* h = new heap();
  int array[10] = {6,8,5,2,7,10,3,9,12,1};
  h->build(10,array);
  h->levelorder();
  h->deletemin();
  h->levelorder();
  h->deletemax();
  h->levelorder();
  h->insert(1);
  h->insert(20);
  h->levelorder();
  h->insert(15);
  h->insert(30);
  h->insert(12);
  h->insert(13);
  h->insert(14);
  h->levelorder();
  h->deletemin();
  h->levelorder();

  delete h;
}
