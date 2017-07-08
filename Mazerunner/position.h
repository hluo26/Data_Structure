
#ifndef _POSITION_H
#define _POSITION_H

class position{
public:
  position(int x,int y);
  int getrow();
  int getcol();

private:
  int m_row;
  int m_col;
};

#endif
