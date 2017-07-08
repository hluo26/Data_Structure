#include<iostream>
#include "position.h"

position::position(int x,int y)
{
  m_row=x;
  m_col=y;
}

int position::getcol()
{
  return m_col;
}

int position::getrow()
{
  return m_row;
}
