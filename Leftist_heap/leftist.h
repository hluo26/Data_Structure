#ifndef LEFTIST_H
#define LEFTIST_H
#include"node.h"

class leftist
{
public:
  leftist();
  ~leftist();
  void deletion(node* subtree);
  void insert(int x);
  void insertion(int x,node* subtree);
  void deletemin();
  node* merge(node* root1,node* root2);
  node* merge1(node* root1,node* root2);
  void swap(node* x,node* y);
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
