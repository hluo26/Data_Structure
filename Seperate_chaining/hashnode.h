#ifndef HASHNODE_H
#define HASHNODE_H

class hashnode{
public:
  hashnode(int x);
  int getvalue();
  void setnext(hashnode* next);
  hashnode* getnext();

private:
  int m_value;
  hashnode* m_next;
};

#endif
