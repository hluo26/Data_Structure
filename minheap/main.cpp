/* A min heap, building by the topdown function, and inserting by the bottom-up function.*/

#include<iostream>
#include"heap.h"

int main()
{
  heap* h1 = new heap();
  h1->build();
  h1->levelorder();
  std::cout<<" "<<std::endl;
  std::cout<<"deletemin"<<std::endl;
  h1->deletemin();
  h1->levelorder();
  std::cout<<" "<<std::endl;
  std::cout<<"deletemin"<<std::endl;
  h1->deletemin();
  h1->levelorder();
  std::cout<<" "<<std::endl;
  std::cout<<"insert"<<std::endl;
  h1->insert(2);
  h1->levelorder();
  std::cout<<" "<<std::endl;
  std::cout<<"deletemax"<<std::endl;
  h1->deletemax();
  h1->levelorder();
  std::cout<<" "<<std::endl;
  std::cout<<"remove"<<std::endl;
  h1->remove(66);
  h1->levelorder();
  std::cout<<" "<<std::endl;

  delete h1;
}
