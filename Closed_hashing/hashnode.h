#ifndef HASHNODE_H
#define HASHNODE_H

class hashnode{
public:
  hashnode(int x,bool y);
  //void setvalue(int x);
  //void setkey(int x);
  //void setflag(bool x);
  int getvalue();
  //int getkey();
  bool getflag();

private:
  int m_value;
  //int m_key;
  bool m_flag;

};

#endif
