#include"heap.h"
#include<iostream>
#include <math.h>

heap::heap()
{
  for(int i=0;i<500;i++)
  {
    table[i] = -1;
  }
  m_size = 0;
}

heap::~heap()
{

}

void heap::build(int arr[],int size)
{
  m_size = size;
  for(int i=0;i<m_size;i++)
  {
    if(table[i]==-1)
    {
      table[i]=arr[i];
    }
  }
  heapsort();
}

void heap::heapsort()
{
  int index = m_size/5 - 1;
  //std::cout<<"index is "<<index<<std::endl;
  for(int i=index;i>=0;i--)
  {
    heapify(i);
  }
}

void heap::insert(int x)
{
  table[m_size] = x;
  m_size++;
  heapsort();
}

void heap::heapify(int x)
{
    int largest = x;
    int l = largest*5+1;
    if(table[l]!=-1)
    {
      for(int j = largest*5 + 1;j<=largest*5 + 5;j++)
      {
        if(table[l]>=table[j] && table[j]!=-1 && table[l]!=-1)
        {
          l = j;
        }
      }
      //std::cout<<"smallest one for index "<<x<<" is "<<table[l]<<std::endl;
      if(table[l]<table[largest])
      {
        swap(l,largest);
        heapify(l);
      }
    }
}

void heap::deletemin()
{
  swap(m_size-1,0);
  table[m_size-1]=-1;
  m_size--;
  heapify(0);
}

void heap::deletemax()
{
  int large = 0;
  for(int i=1;i<m_size;i++)
  {
    if(table[i]>=table[large])
    {
      large = i;
    }
  }
  swap(large,m_size-1);
  table[m_size-1]=-1;
  m_size--;
  heapsort();
}

void heap::remove(int x)
{
  int found = -1;
  for(int i=0;i<m_size;i++)
  {
    if(table[i]==x)
    {
      found = i;
    }
  }
  if(found == -1)
  {
    std::cout<<"couldn't remove this value"<<std::endl;
  }
  else
  {
    swap(found,m_size-1);
    table[m_size-1]=-1;
    m_size--;
    heapsort();
  }
}

void heap::swap(int x,int y)
{
  int temp = table[x];
  table[x] = table[y];
  table[y] = temp;
}

void heap::levelorder()
{
  int height = log(m_size)/log(5);
  int counter = 0;
  for(int i=0;i<=height;i++)
  {
    int j = pow(5,i);
    std::cout<<"level "<<i<<": ";

      for(int k=counter;k<counter+j;k++)
      {
        if(table[k]!=-1)
        {
          std::cout<<table[k]<<" ";
        }
      }
      counter = counter+j;
    std::cout<<std::endl;
  }
  //std::cout<<"counter is"<<counter<<std::endl;
  if(m_size-1>counter)
  {
    std::cout<<"level "<<height+1<<": ";
    for(int i=counter;i<m_size;i++)
    {
      if((i-counter)%5==0 && i!=counter)
      {
        std::cout<<" - "<<table[i]<<" ";;
      }
      else
      {
        std::cout<<table[i]<<" ";
      }
    }
  }

  std::cout<<std::endl;
}
