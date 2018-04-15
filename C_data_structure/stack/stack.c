#include"stdio.h"
#include<stdlib.h>

struct node{
  int val;
  struct node* next;
}*temp;

struct node* m_top;
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
  m_top = NULL;
  m_size = 0;
}

void push(int x)
{
  if(m_size==0)
  {
    m_top = createnewnode(x);
  }
  else
  {
    temp = (struct node*)malloc(sizeof(struct node));
    temp->val = x;
    temp->next = m_top;
    m_top = temp;
  }
  m_size++;
}

void print()
{
  struct node* current = m_top;
  while(current!=NULL)
  {
    printf("%d\n",current->val);
    current = current->next;
  }
  free(current);
}

void pop()
{
  if(m_size>0)
  {
    if(m_size==1)
    {
      free(m_top);
    }
    else
    {
      struct node* n = m_top->next;
      free(m_top);
      m_top = n;
    }
    m_size--;
  }
}

int peek()
{
  if(m_size>0)
  {
    return m_top->val;
  }
  else
  {
    printf("error");
    return -1;
  }
}

void remove1(int x)
{
  if(m_size>0)
  {
    struct node* current = m_top;
    if(current->val==x)
    {
      pop();
      m_size--;
    }
    else
    {
      struct node* f = m_top->next;
      while(f!=NULL)
      {
        if(f->val==x)
        {
          if(f->next==NULL)
          {
            current -> next = NULL;
            free(f);
            m_size--;
          }
          else
          {
            current -> next = f->next;
            free(f);
            m_size--;
          }
        }
        current = current->next;
        f = f->next;
      }
    }
  }
}


int main()
{
  build();
  push(10);
  push(12);
  push(9);
  push(36);
  remove1(12);
  remove1(10);
  print();
}
