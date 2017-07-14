#include"sorts.h"
#include<iostream>
#include <stdio.h>
#include <time.h>
#include <math.h>
using namespace std;

int main()
{
  sorts* s = new sorts();
  int array[7] = {3,7,2,10,9,4,6};
  s->quicksort(array,0,7-1);

  for(int i=0;i<7;i++)
  {
    cout<<array[i]<<" ";
  }

}
