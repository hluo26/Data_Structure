#ifndef _NODE_H_
#define _NODE_H_

class node
{

public:
  node();
  void setleft(node* left);
  node* getleft()const;
  void setright(node* right);
  node* getright()const;
  void setvalue(int value);
  int getvalue()const;
  void setnext(node* next);
  node* getnext()const;
  void setnode(node* root);
  node* getnode()const;

private:
  node* m_left;
  node* m_right;
  int m_value;
  node* m_next;
  node* m_root;
};

#endif
