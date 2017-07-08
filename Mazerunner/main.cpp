#include<iostream>
#include"mazebuilder.h"
#include"mazewalker.h"

using namespace std;

int main()
{
  mazebuilder* maze = new mazebuilder();
  maze->build();

  mazewalker* walk = new mazewalker(maze->getmaze(),maze->getrow(),maze->getcol(),maze->getstartrow(),maze->getstartcol());
  walk->print();

  delete maze;
  delete walk;  

}
