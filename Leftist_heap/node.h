#ifndef NODE_H
#define NODE_H

class node
{
public:
  node();
  void setvalue(int x);
  void setdistance(int x);
  void setleft(node* left);
  void setright(node* right);
  int getvalue();
  int getdistance();
  node* getleft();
  node* getright();

private:
  int m_value;
  int m_distance;
  node* m_left;
  node* m_right;
};

#endif
