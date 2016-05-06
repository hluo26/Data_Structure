#ifndef _BST_H_
#define _BST_H_
#include"node.h"

class BST
{
public:
  BST();
  //~BST();
//  node* clean(node* root);
  void insert(int x);
  void newnode(node* root, int x);
  void print(int x);
  void preorder(node* root);
  void inorder(node* root);
  void postorder(node* root);
  void levelorder(node* root);
  int level(node* root);
  bool search(int x);
  node* find(node* root, int x);
  void remove(int x);
  node* searchparent(int x, node* root);
  void deletenode(int x,node* current);
  node* findmin(node* root);
  void deletemin();
  node* findmax(node* root);
  void deletemax();
private:
  node* root;
};

#endif
