#include<iostream>
#include"stack.h"

int main()
{
	stack* s1 = new stack();

	int option=0;

	s1->push(1);
	s1->push(3);
	s1->push(5);
	s1->push(7);

	std::cout<<s1->pop()<<" has been removed from this stack"<<std::endl;

	s1->print();

	delete s1;
}
