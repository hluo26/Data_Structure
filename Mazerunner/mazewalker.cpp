#include<iostream>
#include"mazewalker.h"

using namespace std;

mazewalker::mazewalker(char** maze,int row, int col, int srow, int scol)
{
  m_row = row;
  m_col = col;
  m_srow = srow;
  m_scol = scol;
  count = 0;
  solve = false;
  table = maze;
  visited = new int* [m_row];
  for(int i=0;i<m_row;i++)
  {
    visited[i] = new int [m_col];
  }

  for(int i=0;i<m_row;i++)
  {
    for(int j=0;j<m_col;j++)
    {
      visited[i][j]=0;
    }
  }

  check(m_srow,m_scol);
}

mazewalker::~mazewalker()
{
  for(int i=0;i<m_row;i++)
  {
    delete[] visited[i];
  }
  delete[] visited;
}

void mazewalker::check(int x, int y)
{
  if(!solve)
  {
    count++;
    visited[x][y] = count;
    cout<<"It starts from ("<<x<<","<<y<<")"<<endl;
    //cout<<"The total row is "<<m_row<<" and col is "<<m_col<<endl;
    cout<<"It runs "<<count<<" times"<<endl;
    if('E' == table[x][y])
    {
      cout<<"We gotta go"<<endl;
      solve = true;
    }
    else
    {
      if(x>=0 && x<=m_row && y>=0 && y<=m_col )
      {
        cout<<"starting recursion"<<endl;
        //up
        if(x>0)
        {
          if((table[x-1][y]=='P'|| table[x-1][y]=='E')&& visited[x-1][y]==0)
          {
            cout<<"go up "<<"("<<x-1<<","<<y<<")"<<endl;
            check(x-1,y);
          }
        }
        //down
        if(x<m_row)
        {
          if((table[x+1][y]=='P' || table[x+1][y]=='E')&& visited[x+1][y]==0)
          {
            cout<<"go down "<<"("<<x+1<<","<<y<<")"<<endl;
            check(x+1,y);
          }
        }
        //left
        if(y>0)
        {
          if((table[x][y-1]=='P' || table[x][y-1]=='E')&& visited[x][y - 1]==0)
          {
            cout<<"go left "<<"("<<x<<","<<y-1<<")"<<endl;
            check(x,y-1);
          }
        }
        if(y<m_col)
        {
          if((table[x][y+1]=='P'|| table[x][y+1]=='E')&& visited[x][y + 1]==0)
          {
            cout<<"go right "<<"("<<x<<","<<y+1<<")"<<endl;
            check(x,y+1);
          }
        }
        //backtracking
        //count--;
        if(!solve)
        {
          visited[x][y]=0;
        }
      }
    }
  }

}

void mazewalker::print()
{
  for(int i=0;i<m_row;i++)
  {
    for(int j=0;j<m_col;j++)
    {
      cout<<visited[i][j]<<" ";
    }
    cout<<endl;
  }
}
