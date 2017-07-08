#include"mazebuilder.h"

#ifndef MAZEWALKER_H
#define MAZEWALKER_H

class mazewalker
{
public:
  mazewalker(char** maze,int row, int col, int srow, int scol);
  ~mazewalker();
  void check(int x,int y);
  void print();
  int** getvisited();

private:
  int** visited;
  char** table;
  int m_row,m_col,m_srow,m_scol;
  int count;
  bool solve;


};

#endif
