#include"node.h"
#include"binomial.h"

binomial::binomial()
{
  m_size = 0;
  myqueue = new node*[m_size];

  for(int i=0;i<m_size;i++)
  {
    myqueue[i] = nullptr;
    queue1[i] = nullptr;
  }
}

binomial::~binomial()
{
  for(int i=0;i<m_size;i++)
  {
    delete myqueue[i];
    delete queue1[i];
  }
  delete []myqueue;
  delete []queue1;
}

void binomial::insert(int x)
{
  node* newnode = new node();
  newnode->setkey(x);
  newnode->setorder(0);
  queue1[0]=newnode;
  myqueue = unions(myqueue,queue1);
  queue1[0] = nullptr;
}

void binomial::unions(node** q1,node** q2)
{
  for(int i=0;i<m_size;i++)
  {
    
  }
}

node* binimial::merge(node* x, node* y)
{
  if(x==nullptr && y!=nullptr)
  {
    return y;
  }
  else if(x!=nullptr && y==nullptr)
  {
    return x;
  }

  if(x->getkey()<=y->getkey())
  {
    node* temp = x;
    x = y;
    y = temp;
  }

  if(x->getorder()==0)
  {
    x->setchild(y);
    x->setorder(x->getorder()+1);
    return x;
  }
  else
  {
    node* childsibling = (x->getchild())->getright();
    y->setleft(childsibling);
    childsibling->setright(y);
    (x->getchild())->setleft(y);
    return x;
  }
}
