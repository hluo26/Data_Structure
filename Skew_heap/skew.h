#ifndef SKEW_H
#define SKEW_H
#include"node.h"

class skew
{
public:
  skew();
  ~skew();
  void deletion(node* subtree);
  void insert(int x);
  void insertion(int x,node* subtree);
  void deletemin();
  node* merge(node* root1,node* root2);
  void swapchild(node* subtree);
  void print(node* root, int x);
  int height(node* root);
  void printorder(int x);
  void printlevel(int x,node* root);


private:
  node* m_root;
  //int m_size;
};

#endif
