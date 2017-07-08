#include<iostream>
#include<fstream>
#include<sstream>
#include"mazebuilder.h"
using namespace std;


mazebuilder::mazebuilder()
{
  ifstream myfile("input.txt");
  string a ;
  if(myfile.is_open())
  {
    getline(myfile,a);
    istringstream is(a);
    int b;
    int c=0;
    while(is>>b)
    {
      c++;
      if(c==1)
      {
        if(c<1)
        {
          cout<<"if rows are less than 1"<<endl;
          break;
        }
        else
        {
          row=b;
        }
      }
      if(c==2)
      {
        if(c<1)
        {
          cout<<"if cols are less than 1"<<endl;
          break;
        }
        else
        {
          col=b;
        }
      }
    }
    string aaa;
    getline(myfile,aaa);
    istringstream start(aaa);
    int d;
    int e=0;
    while(start>>d)
    {
      e++;
      if(e==1)
      {
        if(e>row||e<=0)
        {
          cout<<"if start position is not in a passage"<<endl;
          break;
        }
        else
        {
          srow=d;
        }
      }
      if(e==2)
      {
        if(e>col||e<=0)
        {
          cout<<"if start position is not in a passage"<<endl;
          break;
        }
        else
        {
          scol=d;
        }
      }
    }
  }
  table = new char*[row];
  for(int i=0;i<row;i++)
  {
    table[i] = new char[col];
  }
}

mazebuilder::~mazebuilder()
{
  for(int i=0;i<row;i++)
  {
    delete[] table[i];
  }
  delete[] table;
}

void mazebuilder::build()
{
  ifstream myfile("input.txt");
  string line;
  //char c =' ';
  if(myfile.is_open())
  {
    getline(myfile,line);
    getline(myfile,line);
    char c =' ';
      for(int i=0;i<row;i++)
      {
        for(int j=0;j<col;j++)
        {
          myfile>>c;
          table[i][j]=c;
        }

    }
  }
  myfile.close();
  if(!isexit())
  {
    cout<<"there is no exit"<<endl;
  }
}

void mazebuilder::print()
{
  for(int i=0;i<row;i++)
  {
    for(int j=0;j<col;j++)
    {
      cout<<table[i][j]<<" ";
    }
    cout<<endl;
  }
  //cout<<"The row and col is"<<row<<" "<<col<<endl;
  //cout<<"start point is"<<srow<<" "<<scol<<endl;
}

bool mazebuilder::isexit()
{
  for(int i=0;i<row;i++)
  {
    for(int j=0;j<col;j++)
    {
      if(table[i][j]=='E')
      {
        return true;
      }
    }
  }
  return false;
}

char** mazebuilder::getmaze()
{
  return table;
}

int mazebuilder::getrow()
{
  return row;
}

int mazebuilder::getcol()
{
  return col;
}

int mazebuilder::getstartcol()
{
  return scol;
}

int mazebuilder::getstartrow()
{
  return srow;
}
