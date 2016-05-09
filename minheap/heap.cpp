#include"heap.h"
#include<cmath>
#include"iostream"

heap::heap()
{
  m_heap = new int[500];

  for(int i=0;i<500;i++)
  {
    m_heap[i]=-1;
  }

  m_size=0;

}

heap::~heap()
{
  delete []m_heap;
}

void heap::build()
{

  int array[16] ={100,205,150,44,95,117,402,317,82,66,11,17,1,70,87,99};


  for(int j=0;j<16;j++)
  {
    m_heap[j]=array[j];
    heapify(j);
    m_size++;
  }

}

void heap::insert(int x)
{
  //std::cout<<m_size<<std::endl;
  m_size++;
  m_heap[m_size-1]=x;
  //print();
  heapify(m_size-1);
}

void heap::heapify(int index)
{

  if(index>0)
  {
      int p = floor(index-1)/5;
      if(m_heap[index]<m_heap[p]&&m_heap[index]!=-1&&m_heap[p]!=-1)
      {
        //std::cout<<"parent is "<<p<<std::endl;
        swap(index,p);
        heapify(p);
      }

  }
}

void heap::print()
{
  for(int i=0;i<m_size;i++)
  {
    std::cout<<m_heap[i]<<" ";
  }
  std::cout<<" "<<std::endl;
}

void heap::levelorder()
{
  int level=1;
  int j=1;
  for(int i=1;i<=m_size;i++)
  {
    std::cout << m_heap[i-1]<<" ";
    if(i==level)
    {
      std::cout << "" << std::endl;
      level=level+pow(5,j);
      j++;
    }
  }
  std::cout<<" "<<std::endl;
}

void heap::deletemin()
{
  if(m_size==0)
  {
    std::cout<<"Empty heap"<<std::endl;
  }
  else
  {
    //std::cout<<"size is"<<m_size<<std::endl;
    swap(0,m_size-1);
    m_heap[m_size-1]=-1;
    m_size--;
    topdown(0);
  }
}

void heap::deletemax()
{
  if(m_size==0)
  {
    std::cout<<"Empty heap"<<std::endl;
  }
  else
  {
    int m = findmax();
    //std::cout<<"size is "<<m_size<<std::endl;
    swap(m,m_size-1);
    m_heap[m_size-1]=-1;
    m_size--;
    heapify(m);
  }
}

int heap::findmax()
{
  int mindex = 0;
  for(int i=0;i<m_size;i++)
  {
    if(m_heap[mindex]!=-1&&m_heap[i]!=-1&&m_heap[mindex]<m_heap[i])
    {
      mindex = i;
    }
  }
  //std::cout<<mindex<<std::endl;
  return mindex;
}


void heap::topdown(int index)
{
  int s=index*5+1;
  int e=index*5+5;
  //std::cout<<s<<std::endl;
  //std::cout<<e<<std::endl;
  int l = findleast(s,e);
  //std::cout<<"The leastnumber is "<<m_heap[l]<<std::endl;

  if(l==-1)
  {
    std::cout<<"there is no child for this element"<<std::endl;
  }
  else
  {
    if(m_heap[l]<m_heap[index])
    {
      swap(l,index);
      //std::cout<<"The top down number is "<<m_heap[l]<<std::endl;
      topdown(l);
    }
  }
}

void heap::remove(int x)
{
  for(int i=0;i<m_size;i++)
  {
    if(m_heap[i]==x)
    {
      if(i==0)
      {
        swap(0,m_size-1);
        m_heap[m_size-1]=-1;
        m_size--;
        topdown(0);
      }
      else
      {
        swap(i,m_size-1);
        m_heap[m_size-1]=-1;
        m_size--;
        topdown(i);
        heapify(i);
      }
    }
  }
}


int heap::findleast(int x, int y)
{
  if(m_heap[x]==-1)
  {
    return -1;
  }
  else
  {
    int sindex=x;
    //std::cout<<"size is "<<m_size<<std::endl;
    for(int i=x;i<=y&&i<m_size;i++)
    {
      if(m_heap[sindex]!=-1&&m_heap[i]!=-1&&m_heap[sindex]>m_heap[i])
      {
        sindex=i;
        //std::cout<<"index is"<<sindex<<std::endl;
      }
    }

    return sindex;
  }
}

void heap::swap(int x,int y)
{
  int temp = m_heap[x];
  m_heap[x]=m_heap[y];
  m_heap[y]=temp;
}
