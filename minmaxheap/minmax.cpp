#include"minmax.h"
#include<iostream>
#include<cmath>

minmax::minmax()
{
  m_heap = new int [500];
  m_size = 0;

  for(int i=0;i<500;i++)
  {
    m_heap[i]=-1;
  }
}

minmax::~minmax()
{
  delete []m_heap;
}

void minmax::build()
{
  int array[10] = {6,8,5,2,7,10,3,9,12,1};


  for(int i=0;i<10;i++)
  {
    m_heap[i]=array[i];
    m_size++;
  }

  for(int i=m_size/2-1;i>=0;i--)
  {
    trickledown(i+1);
  }

}

bool minmax::checkgrand(int index)
{
  int child = 4*index+3;
  if(child<=m_size)
  {
    std::cout<<"having grandchild"<<std::endl;
    return true;
  }
  else
  {
    std::cout<<"no grandchild"<<std::endl;
    return false;
  }
}

int minmax::leftchild(int index)
{
  return (index*2+1);
}

int minmax::rightchild(int index)
{
  return (index*2+2);
}

bool minmax::checkchild(int index)
{
  if(index<=m_size-1)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void minmax::insert(int x)
{
  if(m_size==0)
  {
    std::cout<<"Empty heap"<<std::endl;
    m_heap[0]=x;
    m_size++;
  }
  else
  {
    m_size++;
    m_heap[m_size-1]=x;
    bubbleup(m_size);
  }
}

void minmax::deletemax()
{
  if(m_heap[1]>m_heap[2])
  {
    swap(1,m_size-1);
    m_heap[m_size-1]=-1;
    m_size--;
    std::cout<<"go!!!"<<std::endl;
    trickledown(2);
  }
  else
  {
    swap(2,m_size-1);
    m_heap[m_size-1]=-1;
    m_size--;
    std::cout<<"go!!!"<<std::endl;
    trickledown(3);
  }
}

void minmax::deletemin()
{
  swap(0,m_size-1);
  m_heap[m_size-1]=-1;
  m_size--;
  trickledown(1);
}

void minmax::levelorder()
{
  int level=0;
  int j=1;
  for(int i=0;i<m_size;i++)
  {
    std::cout<<m_heap[i]<<" ";
    if(i==level)
    {
      std::cout<<" "<<std::endl;
      level=level+pow(2,j);
      j++;
    }
  }
  std::cout<<""<<std::endl;
}

void minmax::bubbleup(int index)
{
  int a = fmod(floor(log2(index)),2);
  if(a==0)
  {
    bubbleupmin(index-1);
  }
  else if(a==1)
  {
    bubbleupmax(index-1);
  }
  else
  {
    std::cout<<"error"<<std::endl;
  }
}

void minmax::bubbleupmax(int index)
{
  if(index<=2)
  {
    int p = (index-1)/2;
    if(m_heap[p]>m_heap[index])
    {
      swap(p,index);
    }
  }
  else
  {
    int p = (index-1)/2;
    if(m_heap[p]>m_heap[index])
    {
      swap(p,index);
      int g = (p-3)/4;
      if(m_heap[p]<=m_heap[g])
      {
        swap(p,g);
      }
      bubbleupmin(g);
    }
    else
    {
      int g = (index-3)/4;
      if(m_heap[index]>m_heap[g])
      {
        swap(index,g);
      }
      bubbleupmax(g);
    }
  }
}

void minmax::bubbleupmin(int index)
{
  if(index!=0)
  {
    int p = (index-1)/2;
    if(m_heap[p]<=m_heap[index])
    {
      swap(p,index);
      int g = (p-3)/4;
      if(m_heap[p]>m_heap[g])
      {
        swap(p,g);
      }
      bubbleupmax(g);
    }
    else
    {
      int g = (index-3)/4;
      if(m_heap[index]<=m_heap[g])
      {
        swap(index,g);
      }
      bubbleupmin(g);
    }
  }
}

void minmax::trickledown(int index)
{
  int a = fmod(floor(log2(index)),2);
  if(a==0)
  {
    tricklemin(index-1);
    std::cout<<"min is executing!"<<std::endl;
  }
  else if(a==1)
  {
    tricklemax(index-1);
    std::cout<<"max is executing!"<<std::endl;
  }
  else
  {
    std::cout<<"error"<<std::endl;
  }
}

void minmax::tricklemax(int index)
{
  //std::cout<<"go!!!"<<std::endl;
  int c = checkgrand(index);
  if(c==true)
  {
    int max = findmax(index);
    if(m_heap[index]<m_heap[max])
    {
      swap(index,max);
      int p = (max-1)/2 ;
      if(m_heap[max]<m_heap[p])
      {
        swap(max,p);
      }
    }
    tricklemax(max);
  }
  else
  {
    int l = leftchild(index);
    int r = rightchild(index);
    if(checkchild(l))
    {
      if(checkchild(r))
      {
        if(m_heap[index]<m_heap[l]&&m_heap[l]>m_heap[r])
        {
          swap(index,l);
        }
        else if(m_heap[index]<m_heap[r]&&m_heap[l]<=m_heap[r])
        {
          swap(index,r);
        }
      }
      else
      {
        if(m_heap[index]<m_heap[l])
        {
          swap(index,l);
        }
      }
    }
  }
}

void minmax::tricklemin(int index)
{
  int c = checkgrand(index);
  if(c==true)
  {
    int min = findmin(index);
    std::cout<<"min is "<<min<<std::endl;
    if(m_heap[index]>m_heap[min])
    {
      swap(index,min);
      int p = (min-1)/2 ;
      if(m_heap[min]>m_heap[p])
      {
        swap(min,p);
      }
    }
    tricklemin(min);
  }
  else
  {
    int l = leftchild(index);
    int r = rightchild(index);
    if(checkchild(l))
    {
      if(checkchild(r))
      {
        if(m_heap[index]>m_heap[l]&&m_heap[l]<=m_heap[r])
        {
          swap(index,l);
        }
        else if(m_heap[index]>m_heap[r]&&m_heap[l]>m_heap[r])
        {
          swap(index,r);
        }
      }
      else
      {
        if(m_heap[index]>m_heap[l])
        {
          swap(index,l);
        }
      }
    }
  }
}

int minmax::findmin(int index)
{
  int c1 = 4*index+3;
  int min=c1;
  for(int i=c1;i<m_size&&i<=c1+3;i++)
  {
    if(m_heap[i]!=-1&&m_heap[min]!=-1&&m_heap[i]<=m_heap[min])
    {
      min=i;
    }
  }
  return min;
  //std::cout<<"The min is "<<min<<std::endl;
}

int minmax::findmax(int index)
{
  int c1 = 4*index+3;
  int max=c1;
  std::cout<<"max is "<<max<<std::endl;
  for(int i=c1;i<m_size&&i<=c1+3;i++)
  {
    if(m_heap[i]!=-1&&m_heap[max]!=-1&&m_heap[i]>m_heap[max])
    {
      max=i;
    }
  }

  return max;
}

void minmax::swap(int x, int y)
{
  int temp = m_heap[x];
  m_heap[x]=m_heap[y];
  m_heap[y]=temp;
}
