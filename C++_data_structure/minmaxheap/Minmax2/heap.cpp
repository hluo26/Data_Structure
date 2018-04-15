#include<iostream>
#include"heap.h"
#include<math.h>

heap::heap()
{
  for(int i=0;i<500;i++)
  {
    table[i]=-1;
  }
}

heap::~heap()
{

}

void heap::build(int size,int arr[])
{
  m_size = size;
  for(int i=0;i<m_size;i++)
  {
    table[i]=arr[i];
  }
  for(int j=m_size/2-1;j>=0;j--)
  {
    trickledown(j);
    //std::cout<<"trickledown "<<j<<std::endl;
  }
  //std::cout<<findsmallest(5)<<std::endl;
}

void heap::insert(int x)
{
  m_size++;
  table[m_size-1] = x;
  bubbleup(m_size-1);
}

void heap::deletemax()
{
  if(table[1]>=table[2])
  {
    table[1]=table[m_size-1];
    table[m_size-1]=-1;
    m_size--;
    trickledown(1);
  }
  else
  {
    table[2]=table[m_size-1];
    table[m_size-1]=-1;
    m_size--;
    trickledown(2);
  }
}

void heap::deletemin()
{
  table[0]=table[m_size-1];
  table[m_size-1]=-1;
  m_size--;
  trickledown(0);
}

void heap::bubbleup(int i)
{
  if(maxormin(i)==0)
  {
    int parent = (i-1)/2;
    if(table[parent]<table[i])
    {
      swap(parent,i);
      bubbleupmax(parent);
    }
    else
    {
      bubbleupmin(i);
    }
  }
  else
  {
    int parent = (i-1)/2;
    if(table[parent]>table[i])
    {
      swap(parent,i);
      bubbleupmin(parent);
    }
    else
    {
      bubbleupmax(i);
    }
  }
}

void heap::bubbleupmin(int i)
{
  if(table[(i-3)/4]!=-1)
  {
    int grand = (i-3)/4;
    if(table[grand]>table[i])
    {
      swap(grand,i);
      bubbleupmin(grand);
    }
  }
}

void heap::bubbleupmax(int i)
{
  if(table[(i-3)/4]!=-1 && (i-3)/4>0)
  {
    int grand = (i-3)/4;
    //std::cout<<"grand is"<<table[grand]<<std::endl;
    if(table[grand]<table[i])
    {
      swap(grand,i);
      bubbleupmax(grand);
    }
  }
}

void heap::trickledown(int i)
{
  if(maxormin(i)==0)
  {
    std::cout<<"its on the min index"<<std::endl;
    trickledownmin(i);
  }
  else
  {
    std::cout<<"its on the max index"<<std::endl;
    trickledownmax(i);
  }
}

void heap::trickledownmin(int i)
{
  if(table[i*2+1]!=-1)
  {
    int a = findsmallest(i);
    if(a>=4*i+3)
    {
      if(table[a]<table[i])
      {
        swap(a,i);
        if(table[a]>table[(a-1)/2])
        {
          swap(a,(a-1)/2);
        }
        trickledownmin(a);
      }
    }
    else
    {
      if(table[a]<table[i])
      {
        swap(a,i);
      }
    }
  }
}

void heap::trickledownmax(int i)
{
  if(table[i*2+1]!=-1)
  {
    int a = findlargest(i);
    if(a>=4*i+3)
    {
      if(table[a]>=table[i])
      {
        swap(a,i);
        if(table[a]<table[(a-1)/2])
        {
          swap(a,(a-1)/2);
        }
        trickledownmax(a);
      }
    }
    else
    {
      if(table[a]>=table[i])
      {
        swap(a,i);
      }
    }
  }
}

bool heap::checkgrand(int i)
{
  if(table[4*i+3]!=-1)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int heap::findsmallest(int i)
{
  int s = 0;
  int g = i*4+3;
  if(table[i*2+1]!=-1)
  {
    if(table[2*i+1]>table[2*i+2] && table[2*i+2]!=-1)
    {
      s = 2*i+2;
      if(checkgrand(i))
      {
        for(int k=i*4+3;k<=i*4+7;k++)
        {
          if(table[g]>=table[k] && table[k]!=-1)
          {
            g=k;
          }
        }
        //std::cout<<"smallest one in grand is "<<table[g]<<std::endl;
        if(table[s]>table[g])
        {
          s = g;
        }
      }
    }
    else
    {
      s = 2*i+1;
      if(checkgrand(i))
      {
        for(int k=i*4+3;k<=i*4+7;k++)
        {
          if(table[g]>=table[k] && table[k]!=-1)
          {
            g=k;
          }
        }
        if(table[s]>table[g])
        {
          s = g;
        }
      }
    }
  }
  return s;
}


int heap::findlargest(int i)
{
  int s = 0;
  int g = i*4+3;
  if(table[i*2+1]!=-1)
  {
    if(table[2*i+1]>table[2*i+2] && table[2*i+2]!=-1)
    {
      s = 2*i+1;
      if(checkgrand(i))
      {
        for(int k=i*4+3;k<=i*4+7;k++)
        {
          if(table[g]<=table[k] && table[k]!=-1)
          {
            g=k;
          }
        }
        //std::cout<<"largest one in grand is "<<table[g]<<std::endl;
        if(table[s]<=table[g])
        {
          s = g;
        }
      }
    }
    else
    {
      s = 2*i+1;
      if(checkgrand(i))
      {
        for(int k=i*4+3;k<=i*4+7;k++)
        {
          if(table[g]<=table[k] && table[k]!=-1)
          {
            g=k;
          }
        }
        if(table[s]<=table[g])
        {
          s = g;
        }
      }
    }
  }
  return s;
}

int heap::maxormin(int x)
{
  int index = (floor(log2(x+1)));
  if(index%2==0)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

void heap::swap(int x,int y)
{
  int temp = table[x];
  table[x] = table[y];
  table[y] = temp;
}

void heap::print()
{
  for(int i=0;i<m_size;i++)
  {
    std::cout<<table[i]<<" ";
  }
  std::cout<<std::endl;
}

void heap::levelorder()
{
  int level=0;
  int j=1;
  for(int i=0;i<m_size;i++)
  {
    std::cout<<table[i]<<" ";
    if(i==level)
    {
      std::cout<<" "<<std::endl;
      level=level+pow(2,j);
      j++;
    }
  }
  std::cout<<""<<std::endl;
}
