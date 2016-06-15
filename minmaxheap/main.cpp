#include<iostream>
#include"minmax.h"

int main()
{
  minmax* m1 = new minmax();
  m1->build();
  m1->levelorder();
  m1->deletemin();
  m1->levelorder();
  m1->deletemax();
  m1->levelorder();
  m1->insert(1);
  m1->levelorder();
  m1->insert(20);
  m1->levelorder();
  m1->insert(15);
  m1->levelorder();
  m1->insert(30);
  m1->levelorder();
  m1->insert(12);
  m1->levelorder();
  m1->insert(13);
  m1->levelorder();
  m1->insert(14);
  m1->levelorder();
  m1->deletemin();
  m1->levelorder();

  delete m1;
}
