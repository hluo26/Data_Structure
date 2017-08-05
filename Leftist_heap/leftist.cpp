#include"leftist.h"
#include<iostream>

leftist::leftist()
{
  m_root = nullptr;
}

leftist::~leftist()
{
  if(m_root!=nullptr)
  {
    deletion(m_root);
  }
}

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

void leftist::insert(int x)
{
  insertion(x,m_root);
}

void leftist::insertion(int x,node* subtree)
{
    node* newnode = new node();
    newnode->setvalue(x);
    newnode->setdistance(0);
    //std::cout<<"start merge"<<std::endl;
    m_root = merge(m_root,newnode);
}

void leftist::deletemin()
{
  node* old = m_root;
  m_root = merge(m_root->getleft(),m_root->getright());
  delete old;
}

node* leftist::merge(node* root1,node* root2)
{
  if(root1==nullptr && root2!=nullptr)
  {
    //std::cout<<"first node"<<std::endl;
    return root2;
  }
  else if(root2==nullptr && root1!=nullptr)
  {
    return root1;
  }
  else
  {
    if(root1->getvalue()>root2->getvalue())
    {
      return merge1(root2,root1);
    }
    else
    {
      return merge1(root1,root2);
    }
  }
}

node* leftist::merge1(node* root1,node* root2)
{
    node* rightchild = root1->getright();
    root1->setright(merge(rightchild,root2));
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
    if(leftdis < rightdis)
    {
      swapchild(root1);
    }
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
