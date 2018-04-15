#include"node.h"
#include"BST.h"
#include<iostream>
#include"queue.h"
//#include<queue>


BST::BST()
{
  root=nullptr;
}

/*node* BST::clean(node* root)
{
  if(root=nullptr)
  {
    return nullptr;
  }
  else
  {
    delete root;
    if(root->getleft()!=nullptr)
    {
      clean(root->getleft());
    }
    if(root->getright()!=nullptr)
    {
      clean(root->getright());
    }
  }
  return nullptr;
}
BST::~BST()
{
  root = clean(root);
}*/

void BST::insert(int x)
{
  //creating first node in BST
  if(root==nullptr)
  {
    root = new node();
    root->setvalue(x);
  }
  else
  {
    //start recursive research to find the location of node
    newnode(root,x);
  }
}

void BST::newnode(node* root,int x)
{
  //if inserting value is less or equal than its root node
  if(x<=root->getvalue())
  {
    //there is no left child of this node
    if(root->getleft()==nullptr)
    {
      node* temp =new node();
      temp->setvalue(x);
      root->setleft(temp);
      temp=nullptr;
    }
    //the left child is existed, recursing...
    else
    {
      newnode(root->getleft(),x);
    }
  }
  //if inserting value is larger than its root node
  else
  {
    //there is no right child of this node
    if(root->getright()==nullptr)
    {
      node* temp =new node();
      temp->setvalue(x);
      root->setright(temp);
      temp=nullptr;
    }
    //the right child is existed, recursing...
    else
    {
      newnode(root->getright(),x);
    }
  }
}

void BST::print(int x)
{
  if(x==1)
  {
    //printing in preorder
    preorder(root);
  }
  else if(x==2)
  {
    //printing in inorder
    inorder(root);
  }
  else if(x==3)
  {
    //printing in postorder
    postorder(root);
  }
  else if(x==4)
  {
    //printing in levelorder
    levelorder(root);
  }
}

void BST::preorder(node* root)
{
  if(root!=nullptr)
  {
    //printing value of current node
    std::cout<<root->getvalue()<<" ";
    //traversing towards left tree
    if(root->getleft()!=nullptr)
    {
      preorder(root->getleft());
    }
    //traversing towards right tree
    if(root->getright()!=nullptr)
    {
      preorder(root->getright());
    }
  }
  else
  {
    std::cout<<"empty tree"<<std::endl;
  }
}

void BST::inorder(node* root)
{
  if(root!=nullptr)
  {
    if(root->getleft()!=nullptr)
    {
      preorder(root->getleft());
    }
    std::cout<<root->getvalue()<<" ";
    if(root->getright()!=nullptr)
    {
      preorder(root->getright());
    }
  }
}

void BST::postorder(node* root)
{
  if(root!=nullptr)
  {
    if(root->getleft()!=nullptr)
    {
      preorder(root->getleft());
    }
    if(root->getright()!=nullptr)
    {
      preorder(root->getright());
    }
    std::cout<<root->getvalue()<<" ";
  }
}


void BST::levelorder(node* root)
{
  if(root==nullptr)
  {
    return ;
  }
  else
  {
    queue* q1 = new queue();
    q1->enqueue(root);
    while(!(q1->isempty()))
    {
      node* current =q1->peek();
      std::cout<<current->getvalue()<<" ";
      if(current->getleft()!=nullptr)
      {
        q1->enqueue(current->getleft());
      }
      if(current->getright()!=nullptr)
      {
        q1->enqueue(current->getright());
      }
      q1->dequeue();
      //current=nullptr;
    }
    delete q1;
  }
}

bool BST::search(int x)
{
  if(root!=nullptr)
  {
    if(find(root,x)==nullptr)
    {
      return false;
    }
    else
    {
      return true;
    }
  }
}

node* BST::find(node* root, int x)
{
  if(root->getvalue()==x)
  {
    std::cout<<"find it!"<<std::endl;
    return root;
  }
  else
  {
    if(x<root->getvalue())
    {
        if(root->getleft()!=nullptr)
        {
          find(root->getleft(),x);
        }
        else
        {
          std::cout<<"There is no this element"<<std::endl;
          return nullptr;
        }
    }
    else
    {
        if(root->getright()!=nullptr)
        {
          find(root->getright(),x);
        }
        else
        {
          std::cout<<"There is no this element"<<std::endl;
          return nullptr;
        }
    }
    //std::cout<<"There is no this element"<<std::endl;
    //return false;
  }
}

void BST::remove(int x)
{
  node* s = find(root,x);
  if(s!=nullptr)
  {
      //std::cout<<root->getvalue()<<std::endl;
      deletenode(x,s);
  }
  else
  {
    return ;
  }
  delete s;
}

void BST::deletenode(int x,node* current)
{
      //std::cout<<root->getvalue()<<std::endl;
      if(current->getleft()==nullptr&&current->getright()==nullptr)
      {
        if(current!=root)
        {
          node* parent = searchparent(x,root);
          if(current->getvalue()<=parent->getvalue())
          {
            parent->setleft(nullptr);
          }
          else
          {
            parent->setright(nullptr);
          }
        }
        else
        {
          std::cout<<"go"<<std::endl;
          //delete root;
          root=nullptr;
        }
      }
      else if(current->getleft()==nullptr&&current->getright()!=nullptr)
      {
        if(current!=root)
        {
          node* parent = searchparent(x,root);
          if(current->getvalue()<=parent->getvalue())
          {
            parent->setleft(current->getright());
          }
          else
          {
            parent->setright(current->getright());
          }
        }
        else
        {
          root=root->getright();
        }
      }
      else if(current->getright()==nullptr&&current->getleft()!=nullptr)
      {
        if(current!=root)
        {
          node* parent = searchparent(x,root);
          if(current->getvalue()<=parent->getvalue())
          {
            parent->setleft(current->getleft());
          }
          else
          {
            parent->setright(current->getleft());
          }
        }
        else
        {
          root=root->getleft();
        }
      }
      else if(current->getright()!=nullptr&&current->getleft()!=nullptr)
      {
        if(current!=root)
        {
            //node* parent = searchparent(x,root);
            /*node* temp = findmin(current->getright());
            int b = current->getvalue();
            int a = temp->getvalue();
            current->setvalue(a);
            temp->setvalue(b);
            deletenode(b,current->getright());*/
            node* temp = findmin(current->getright());
            int a = temp->getvalue();
            node* p = searchparent(a,root);
            //std::cout<<p->getvalue()<<std::endl;
            std::cout<<a<<std::endl;
            if(a<=p->getvalue())
            {
              p->setleft(nullptr);
            }
            else
            {
              p->setright(nullptr);
            }
            current->setvalue(a);
            delete temp;
        }
        else
        {
          /*node* temp = findmin(root->getright());
          int b = root->getvalue();
          int a = temp->getvalue();
          root->setvalue(a);
          temp->setvalue(b);
          deletenode(b,root->getright());*/
          node* temp = findmin(root->getright());
          int a = temp->getvalue();
          node* p = searchparent(a,root);
          //std::cout<<p->getvalue()<<std::endl;
          std::cout<<a<<std::endl;
          if(a<=p->getvalue())
          {
            p->setleft(nullptr);
          }
          else
          {
            p->setright(nullptr);
          }
          root->setvalue(a);
          delete temp;
        }
      }
}

node* BST::searchparent(int x, node* root)
{
  if(root==nullptr)
  {
    return nullptr;
  }
  else if (root->getleft()==nullptr&&root->getright()==nullptr)
  {
    return nullptr;
  }
  else
  {
    if(root->getleft()!=nullptr&&x==(root->getleft())->getvalue())
    {
      return root;
    }
    else if(root->getright()!=nullptr&&x==(root->getright())->getvalue())
    {
      return root;
    }
    else
    {
      if(root->getleft()!=nullptr&&x<root->getvalue())
      {
        return searchparent(x,root->getleft());
      }
      if(root->getright()!=nullptr&&x>root->getvalue())
      {
        return searchparent(x,root->getright());
      }
    }
  }
}


void BST::deletemin()
{
  node* t = findmin(root);
  if(root!=nullptr)
  {
    std::cout<<t->getvalue()<<std::endl;
    deletenode(t->getvalue(),t);
  }
  else
  {
    std::cout<<"It is an empty tree"<<std::endl;
  }
  delete t;
}

node* BST::findmin(node* root)
{
  if(root!=nullptr)
  {
    node* temp = root;
    std::cout<<root->getvalue()<<std::endl;
    while(temp->getleft()!=nullptr)
    {
      temp=temp->getleft();
    }
    return temp;
    std::cout<<temp->getvalue()<<std::endl;
  }
  else
  {
    std::cout<<"empty tree"<<std::endl;
  }
}

node* BST::findmax(node* root)
{
  if(root!=nullptr)
  {
    node* temp = root;
    while(temp->getright()!=nullptr)
    {
      temp=temp->getright();
    }
    return temp;
    std::cout<<temp->getvalue()<<std::endl;
  }
  else
  {
    std::cout<<"empty tree"<<std::endl;
  }
}

void BST::deletemax()
{
  node* t = findmax(root);
  if(root!=nullptr)
  {
    std::cout<<t->getvalue()<<std::endl;
    deletenode(t->getvalue(),t);
  }
  else
  {
    std::cout<<"It is an empty tree"<<std::endl;
  }
  delete t;
}
