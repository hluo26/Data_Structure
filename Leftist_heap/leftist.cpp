#include"leftist.h"
#include<iostream>

/*constructor*/
leftist::leftist()
{
  m_root = nullptr;
}

/*destructor which calls the deletion*/
leftist::~leftist()
{
  if(m_root!=nullptr)
  {
    deletion(m_root);
  }
}

/*traverse the heap and delete each element*/
void leftist::deletion(node* subtree)
{
  if(subtree!=nullptr)
  {
    node* current = subtree;
    if(current->getleft()!=nullptr)
    {
      deletion(current->getleft());
    }
    if(current->getright()!=nullptr)
    {
      deletion(current->getright());
    }
    delete current;
  }
}

/*the function to call insertion*/
void leftist::insert(int x)
{
  insertion(x,m_root);
}

/*while inserting a new element, we perform merge(root,newnode),
  the root is the top of this heap, and newnode will be seemed
  as a leftist heap which contains only one element x*/
void leftist::insertion(int x,node* subtree)
{
    node* newnode = new node();
    newnode->setvalue(x);
    newnode->setdistance(0);
    m_root = merge(m_root,newnode);
}

/*while deleting the min element of heap, we just remove the top
  of the leftist heap, the do merge for its left child and right
  child*/
void leftist::deletemin()
{
  node* old = m_root;
  m_root = merge(m_root->getleft(),m_root->getright());
  delete old;
}

/*The merge function takes two leftist heaps,root1 and root2,
  and returns one leftist heap which contains the union of elements
  from root1 and root2*/
node* leftist::merge(node* root1,node* root2)
{
  if(root1==nullptr && root2!=nullptr)
  {
    return root2;
  }
  else if(root2==nullptr && root1!=nullptr)
  {
    return root1;
  }
  else
  {
    /*if root1's value is larger than root2, we will swap them to make
      sure the smallest element is on the top of heap*/
    if(root1->getvalue()>root2->getvalue())
    {
      node* temp = root1;
      root1 = root2;
      root2 = temp;
    }
    /*operate merge function on the right side of root1, if root1 doesn't have
      a right child, it will returns root2 as its right child, otherwise merge
      function will operate recursively until it finds the root without right child*/
    node* rightchild = root1->getright();
    root1->setright(merge(rightchild,root2));
    /*initialize the distance from root to a null path as -1*/
    int leftdis = -1;
    int rightdis = -1;
    if(root1->getleft()!=nullptr)
    {
      leftdis = (root1->getleft())->getdistance();
    }
    if((root1->getright()!=nullptr))
    {
      rightdis = (root1->getright())->getdistance();
    }
    /*comparing the root's distance(from root to a external node) to the left side
      and the right side, if right one is larger, swap them*/
    if(leftdis < rightdis)
    {
      swapchild(root1);
    }
    /*while root doesn't have a right child,it means it is a external, then its
      distance will be 0. Otherwise, it will be the distance from an external node
      + 1*/
    if(root1->getright()==nullptr)
    {
      root1->setdistance(0);
    }
    else
    {
      root1->setdistance((root1->getright())->getdistance()+1);
    }
    return root1;
  }
}

/*swapping left child and right child for one node*/
void leftist::swapchild(node* subtree)
{
  if(subtree!=nullptr)
  {
    node* left = subtree->getleft();
    subtree->setleft(subtree->getright());
    subtree->setright(left);
  }
}

void leftist::printorder(int x)
{
  print(m_root,x);
}

int leftist::height(node* root)
{
  if(m_root==nullptr)
  {
    return 0;
  }
  else if(root->getleft()==nullptr && root -> getright() == nullptr)
  {
    return 1;
  }
  else
  {
    int lheight = 0;
    int rheight = 0;
    if(root->getleft()!=nullptr)
    {
      lheight = height(root->getleft());
    }
    if(root->getright()!=nullptr)
    {
      rheight = height(root->getright());
    }
    if(lheight>rheight)
    {
      return lheight +1;
    }
    else
    {
      return rheight +1;
    }
  }
}

void leftist::printlevel(int x,node* root)
{
  if(root == nullptr)
  {
    return;
  }
  else if(x == 1)
  {
    std::cout<<root->getvalue()<<" ";
  }
  else
  {
      printlevel(x-1,root->getleft());
      printlevel(x-1,root->getright());
  }
}

void leftist::print(node* root, int x)
{
  if(root!=nullptr)
  {
    if(x==1)
    {
      std::cout<<root->getvalue()<<" ";
      print(root->getleft(),x);
      print(root->getright(),x);
    }
    else if(x==2)
    {
      print(root->getleft(),x);
      std::cout<<root->getvalue()<<" ";
      print(root->getright(),x);
    }
    else if(x==3)
    {
      print(root->getleft(),x);
      print(root->getright(),x);
      std::cout<<root->getvalue()<<" ";
    }
    else if(x==4)
    {
      int h = height(m_root);
      for(int i=1;i<=h;i++)
      {
        std::cout<<std::endl;
        std::cout<<"level "<<i<<" :";
        printlevel(i,m_root);
        std::cout<<std::endl;
      }
      std::cout<<std::endl;
    }
    else
    {
      std::cout<<"Wrong order"<<std::endl;
    }
  }
}
