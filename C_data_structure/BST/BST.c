#include<stdlib.h>
#include"stdio.h"

struct node{
  int val;
  struct node* left;
  struct node* right;
}*temp;

static int m_size=0;

struct node* cretenewnode(int x)
{
  temp = (struct node*)malloc(sizeof(struct node));
  temp -> val = x;
  temp -> left = NULL;
  temp -> right = NULL;
  return temp;
}

struct node* add(struct node* root,int x)
{
  if(root==NULL)
  {
    return cretenewnode(x);
  }
  else
  {
    if(root->val<=x)
    {
      root->right = add(root->right,x);
    }
    else
    {
      root->left = add(root->left,x);
    }
  }
  return root;
}

int main()
{
  struct node* newtree = NULL;
  newtree = add(newtree,10);
  add(newtree,5);
  add(newtree,17);
}
