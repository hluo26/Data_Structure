#include"list.h"
#include<iostream>

int main()
{

  list* l1 = new list();

  l1->addfront(3);
  l1->addfront(5);
  l1->addfront(7);
  l1->addback(1);
  l1->addback(10);
  l1->removeback();
  l1->removefront();
  l1->print();
  l1->search(5);


  delete l1;
}
