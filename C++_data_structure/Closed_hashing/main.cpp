#include<iostream>
#include"Hash.h"

using namespace std;

int main()
{
  Hash* h = new Hash();
  h->insert(64);
  h->insert(26);
  h->insert(56);
  h->insert(72);
  h->insert(8);
  h->remove(26);
  h->insert(19);
  h->remove(8);
  h->insert(19);
  h->print();

  delete h;
}
