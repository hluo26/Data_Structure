#ifndef NODE_H
#define NODE_H

class node
{
public:
  node();
  void setvalue(int x);
  void setleft(node* left);
  void setright(node* right);
  void setkey(int key);
  int getvalue();
  int getkey();
  node* getleft();
  node* getright();

private:
  int m_value;
  node* m_left;
  node* m_right;
  int m_key;
};

#endif
