#include<iostream>
#include"Hash.h"

using namespace std;

int main()
{
  Hash* h = new Hash();
  h->insert(64);
  h->print();
}
