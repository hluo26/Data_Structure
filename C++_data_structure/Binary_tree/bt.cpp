#include "bt.h"
#include<iostream>
#include<queue>

bt::bt()
{
  m_root = nullptr;
}

bt::~bt()
{
  deletion(m_root);
}

void bt::deletion(node* subtree)
{
  if(subtree!=nullptr)
  {
    node* current = subtree;
    if(current->getleft()!=nullptr)
    {
      deletion(current->getleft());
    }
    if(current->getleft()!=nullptr)
    {
      deletion(current->getright());
    }
    delete current;
  }
}

node* bt::findparent(int key,node* subtree)
{
    if(subtree == nullptr)
    {
      return nullptr;
    }
    else
    {
      std::queue<node* > q;
      q.push(subtree);
      while(q.empty() == false)
      {
        node* current = q.front();
        if(current->getkey() == key)
        {
          //std::cout<<"parent position of "<<key<<" is "<<current->getvalue()<<std::endl;
          return current;
        }
        q.pop();
        if(current->getleft()!=nullptr)
        {
          //std::cout<<"go left to find position "<<key<<" is "<<(current->getleft())->getvalue()<<std::endl;
          q.push(current->getleft());
        }
        if(current->getright()!=nullptr)
        {
          //std::cout<<"go right to find position "<<key<<" is "<<(current->getright())->getvalue()<<std::endl;
          q.push(current->getright());
        }
      }
      return nullptr;
    }

}

void bt::leaves()
{
  int l = countleaves(m_root);
  if(l!=0)
  {
    std::cout<<"Number of leaves: "<<l<<std::endl;
  }
  else
  {
    std::cout<<"Empty tree"<<std::endl;
  }
}

int bt::countleaves(node* root)
{
  if(root == nullptr)
  {
    return 0;
  }
  else
  {
    int leaves = 0;
    std::queue<node*> q;
    q.push(root);
    while(q.empty()==false)
    {
      node* current = q.front();
      if(current->getleft()==nullptr &&current->getright()==nullptr)
      {
        leaves++;
      }
      q.pop();

      if(current->getleft()!=nullptr)
      {
        q.push(current->getleft());
      }
      if(current->getright()!=nullptr)
      {
        q.push(current->getright());
      }
    }
    return leaves;
  }
}

void bt::findlargest()
{
  int l = largest(m_root);
  if(l!=0)
  {
    std::cout<<"Largest element: "<<l<<std::endl;
  }
  else
  {
    std::cout<<"Empty tree"<<std::endl;
  }
}

int bt::largest(node* root)
{
  if(root == nullptr)
  {
    return 0;
  }
  else
  {
    int largest = root->getvalue();
    std::queue<node*> q;
    q.push(root);
    while(q.empty()==false)
    {
      node* current = q.front();
      int value = current->getvalue();
      if(value>=largest)
      {
        largest = value;
      }
      q.pop();

      if(current->getleft()!=nullptr)
      {
        q.push(current->getleft());
      }
      if(current->getright()!=nullptr)
      {
        q.push(current->getright());
      }
    }
    return largest;
  }
}

void bt::add(int x,int key)
{
  insertion(x,key,m_root);
}

void bt::insertion(int x,int key,node* subtree)
{
  if(m_root == nullptr)
  {
    if(x != 0)
    {
      node* newnode = new node();
      newnode->setvalue(x);
      newnode->setkey(key);
      m_root = newnode;
    }
  }
  else
  {
    int p = (key-1)/2;
    //std::cout<<"parent key of "<<x<<" is "<<p<<std::endl;
    node* parent = findparent(p,m_root);
    //std::cout<<"parent of number "<<x<<" is "<<parent->getvalue()<<std::endl;
    if(parent!=nullptr)
    {
        if(key%2 == 1)
        {
          if(x!=0)
          {
            node* newnode = new node();
            newnode->setvalue(x);
            newnode->setkey(key);
            parent->setleft(newnode);
          }
          else
          {
            parent->setleft(nullptr);
          }
        }
        else
        {
          if(x!=0)
          {
            node* newnode = new node();
            newnode->setvalue(x);
            //std::cout<<"node "<<newnode->getvalue()<<" is inserted"<<std::endl;
            newnode->setkey(key);
            parent->setright(newnode);
          }
          else
          {
            parent->setright(nullptr);
          }
        }
    }
  }
}

void bt::printorder(int order)
{
  print(order,m_root);
}

void bt::print(int order,node* subtree)
{
  if(order==1)
  {
    node* current = subtree;
    if(current!=nullptr)
    {
      if(current->getleft()!=nullptr)
      {
        print(order,current->getleft());
      }

      std::cout<<current->getvalue()<<" ";

      if(current->getright()!=nullptr)
      {
        print(order,current->getright());
      }
    }
  }
  if(order==2)
  {
    int h = height(m_root);
      //std::cout<<"height of this tree is "<<h<<std::endl;
      for(int i=1;i<=h;i++)
      {
        std::cout<<std::endl;
        std::cout<<"level "<<i<<" :";
        printlevel(i,m_root);
        std::cout<<std::endl;
      }
  }
}

int bt::height(node* root)
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
    //std::cout<<"node "<<root->getvalue()<<" is "<<lheight<<std::endl;
    //std::cout<<"node "<<root->getvalue()<<" is "<<rheight<<std::endl;
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

void bt::printlevel(int x,node* root)
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
      //std::cout<<root->getvalue()<<" go left"<<std::endl;
      printlevel(x-1,root->getleft());
      //std::cout<<root->getvalue()<<" go right"<<std::endl;
      printlevel(x-1,root->getright());
  }
}
