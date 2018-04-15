#ifndef _NODE_H_
#define _NODE_H_

class node
{
public:
  node();
  void setvalue(int x);
  int getvalue()const;
  void setnext(node* next);
  node* getnext()const;

private:
  int m_value;
  node* m_next;
};

#endif
