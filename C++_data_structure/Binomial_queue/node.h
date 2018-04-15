#ifndef NODE_H
#define NODE_H

class node{
public:
  node();
  void setleft(node* left);
  void setright(node* right);
  void setkey(int x);
  void setorder(int x);
  void setchild(node* child);
  node* getleft();
  node* getright();
  int getkey();
  int getorder();
  node* getchild();

private:
  int m_key;
  int m_order;
  node* m_left;
  node* m_right;
  node* m_child;

}；

#endif
