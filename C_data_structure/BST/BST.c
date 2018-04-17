#include<stdlib.h>
#include"stdio.h"

struct node{
  int val;
  struct node* left;
  struct node* right;
}*temp;

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

void preorder(struct node* root)
{
  if(root!=NULL)
  {
    printf("%d",root->val);
    printf(" ");
    if(root->left!=NULL)
    {
      preorder(root->left);
    }
    if(root->right!=NULL)
    {
      preorder(root->right);
    }
  }
}

void inorder(struct node* root)
{
  if(root!=NULL)
  {
    if(root->left!=NULL)
    {
      preorder(root->left);
    }
    printf("%d",root->val);
    if(root->right!=NULL)
    {
      preorder(root->right);
    }
  }
}

void postorder(struct node* root)
{
  if(root!=NULL)
  {
    if(root->left!=NULL)
    {
      preorder(root->left);
    }
    if(root->right!=NULL)
    {
      preorder(root->right);
    }
    printf("%d",root->val);
  }
}

/*to find the smallest element from the right tree of root,
here is another solution: find largest number from the left tree*/
struct node* findsucess(struct node* root)
{
  if(root!=NULL)
  {
    struct node* r = root->right;
    while(r!=NULL)
    {
      r = r->right;
    }
    return r;
  }
  else
  {
    return NULL;
  }
}

struct node* search(struct node* root, int x)
{
  if(root==NULL)
  {
    return NULL;
  }
  if(root->val==x)
  {
    return root;
  }
  else
  {
    if(root->val>x)
    {
      return search(root->left,x);
    }
    else
    {
      return search(root->right,x);
    }
  }
}

void findparent(struct node* pos, struct node* root)
{
  if(root!=NULL)
  {
    if(root->left == pos)
    {
      root->left = NULL;
    }
    if(root->right == pos)
    {
      root->right = NULL;
    }
    findparent(pos,root->left);
    findparent(pos,root->right);
  }
}

/*The most complex case in BST structure, write some comments
to help understanding*/
void remove1(struct node* root,int x)
{
  if(root!=NULL)
  {
    if(search(root,x)!=NULL)
    {
      /*there are more than one node, it's necessary to think about
      three conditions: leaf, one child and two children*/
      //searching for the position of removing node
      struct node* pos = search(root,x);
      if(pos->left!=NULL && pos->right==NULL)
      {
        struct node* l = pos->left;
        while(l!=NULL)
        {
          l = l->right;
        }
        int temp = l->val;
        remove1(root,l->val);
        l -> val = temp;
       }
       else if(pos->left==NULL && pos->right==NULL)
       {
         findparent(pos,root);
         free(pos);
       }
       else if(pos->left==NULL && pos->right)
       {
         struct node* r = findsucess(pos->right);
         int temp = r->val;
         remove1(root,r->val);
         r -> val = temp;
       }
       else
       {

       }
    }
  }
}

int main()
{
  struct node* newtree = NULL;
  newtree = add(newtree,10);
  add(newtree,5);
  add(newtree,17);
  add(newtree,3);
  preorder(newtree);
  remove1(newtree,5);
  preorder(newtree);
  //inorder(newtree);
  //postorder(newtree);
}
