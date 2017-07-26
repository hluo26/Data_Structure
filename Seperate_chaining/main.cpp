#include<iostream>
#include"Hash.h"

using namespace std;

int main()
{
  Hash* h = new Hash();
  h->insert(16);
  h->insert(12);
  h->insert(17);
  h->insert(4);
  h->insert(2);
  h->insert(16);
  h->insert(14);
  h->insert(3);
  h->insert(8);
  h->insert(15);
  h->remove(17);
  h->remove(14);
  h->insert(2);
  h->insert(25);
  //h->remove(8);
  h->insert(13);
  h->print();

  delete h;
}
