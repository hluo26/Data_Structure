#include"stdio.h"
#include<stdlib.h>

struct node{
  int val;
  struct node* next;
}*m_front,*m_back,*temp;

static int m_size;

struct node* createnewnode(int x)
{
  temp = (struct node*)malloc(sizeof(struct node));
  temp->val = x;
  temp->next = NULL;
  return temp;
}

void build()
{
  m_front = NULL;
  m_back = NULL;
  m_size = 0;
}

void push(int x)
{
  if(m_size==0)
  {
    m_front = createnewnode(x);
    m_back = m_front;
    m_size++;
  }
  else
  {
    struct node* a = createnewnode(x);
    a->next = m_back;
    m_back = a;
    m_size++;
  }
}

void pop()
{
  if(m_size>0)
  {
    if(m_size==1)
    {
      free(m_front);
      free(m_back);
      m_size--;
    }
    else
    {
      struct node* x = m_back;
      while(x->next!=m_front)
      {
        x=x->next;
      }
      x->next = NULL;
      m_front = x;
      m_size--;
    }
  }
}

int peek()
{
  if(m_size>0)
  {
    return m_front->val;
  }
}

void print()
{
  if(m_size>0)
  {
    struct node* current = m_back;
    while(current!=NULL)
    {
      printf("%d",current->val);
      current=  current->next;
    }
  }
}

int main()
{
  build();
  push(3);
  push(6);
  push(5);
  pop();
  print();
}
