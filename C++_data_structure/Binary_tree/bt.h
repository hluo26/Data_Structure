#ifndef BT_H
#define BT_H
#include "node.h"

class bt
{
public:
  bt();
  ~bt();
  void deletion(node* subtree);
  node* findparent(int key,node* subtree);
  void add(int x,int key);
  void insertion(int x,int key,node* subtree);
  void printorder(int order);
  void print(int order,node* subtree);
  int height(node* root);
  void printlevel(int x,node* root);
  void leaves();
  int countleaves(node* root);
  void findlargest();
  int largest(node* root);

private:
  node* m_root;
};

#endif
