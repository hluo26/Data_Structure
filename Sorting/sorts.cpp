#include"sorts.h"
#include<iostream>

void sorts::bubble(int arr[],int size)
{
  bool check = true;
  int n = size;
  while(check)
  {
    check = false;
    for(int i=0;i<n-1;i++)
    {
      if(arr[i]>arr[i+1])
      {
        std::cout<<"swap!"<<std::endl;
        swap(arr[i],arr[i+1]);
        check = true;
      }
    }
    //n = n-1;
  }
}

void sorts::insertion(int arr[],int size)
{
  int j;
  for(int i=0;i<size-1;i++)
  {
    j=i;
    while(j>=0&&arr[j]>arr[j+1])
    {
      if(arr[j]>arr[j+1])
      {
        swap(arr[j],arr[j+1]);
      }
      j--;
    }
  }
}

void sorts::selection(int arr[],int size)
{
  int min;
  for(int i=0;i<size-1;i++)
  {
    min = i;
    for(int j=i+1;j<size;j++)
    {
      if(arr[j]<arr[min])
      {
        swap(arr[j],arr[min]);
      }
    }
  }
}

void sorts::mergesort(int arr[],int start,int end)
{
  if(start<end)
  {
    int median = start+(end-start)/2;
    /*std::cout<<"start is "<<start<<std::endl;
    std::cout<<"end is "<<end<<std::endl;
    std::cout<<"median is "<<median<<std::endl;
    std::cout<<std::endl;*/
    mergesort(arr,start,median);
    mergesort(arr,median+1,end);
    merge(arr,start,median,end);
  }
}

void sorts::merge(int arr[],int s,int m,int e)
{
  int i=0;
  int j=0;
  int k=s;
  int size1 = m-s+1;
  int size2 = e-m;
  int arrayA[size1];
  int arrayB[size2];
  for(int a =0;a<size1;a++)
  {
    arrayA[a] = arr[s+a];
    //std::cout<<arrayA[a]<<" ";
  }
  //std::cout<<std::endl;
  for(int b = 0;b<size2;b++)
  {
    arrayB[b] = arr[m+b+1];
    //std::cout<<arrayB[b]<<" ";
  }

  while(i<size1&&j<size2)
  {
    if(arrayA[i]<=arrayB[j])
    {
      arr[k] = arrayA[i];
      i++;
    }
    else
    {
      arr[k] = arrayB[j];
      j++;
    }
    k++;
  }

  while(i<size1)
  {
    arr[k] = arrayA[i];
    i++;
    k++;
  }

  while(j<size2)
  {
    arr[k] = arrayB[j];
    j++;
    k++;
  }
  /*std::cout<<std::endl;
  for(int c=s;c<k;c++)
  {
    std::cout<<arr[c]<<" ";
  }
  std::cout<<std::endl;*/
}

void sorts::quicksort(int arr[],int start,int end)
{
  if(start<end)
  {
    int pivot = partition(arr,start,end);
    quicksort(arr,start,pivot-1);
    quicksort(arr,pivot+1,end);
  }
}

int sorts::partition(int arr[],int s,int e)
{
  int i = s-1;
  int j;
  for(j = s;j<=e-1;j++)
  {
    if(arr[j]<arr[e])
    {
      i++;
      swap(arr[j],arr[i]);
    }
  }
  swap(arr[e],arr[i+1]);
  return i+1;
}

void sorts::swap(int &x, int &y)
{
  int temp = x;
  x = y;
  y = temp;
}
