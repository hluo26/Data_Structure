#include"BST.h"
#include<iostream>
using namespace std;

void play()
{
  cout<<"1.insert a number"<<endl;
  cout<<"2.search a number"<<endl;
  cout<<"3.remove a number"<<endl;
  cout<<"4.print"<<endl;
  cout<<"5.deletemin"<<endl;
  cout<<"6.deletemax"<<endl;
  cout<<"7.exit"<<endl;
}

void order()
{
  cout<<"1.preorder"<<endl;
  cout<<"2.inorder"<<endl;
  cout<<"3.postorder"<<endl;
  cout<<"4.levelorder"<<endl;
}

int main()
{
  BST* b1 = new BST();

  bool flag=false;

  int option,insertnum,deletenum,searchnum,order;

  while(!flag)
  {
    play();
    cout<<"Please type your option"<<endl;
    cin>>option;
    if(option==1)
    {
      cout<<"please enter a number"<<endl;
      cin>>insertnum;
      b1->insert(insertnum);
    }
    else if(option==2)
    {
      cout<<"please enter the searching number"<<endl;
      cin>>searchnum;
      b1->search(searchnum);
    }
    else if(option==3)
    {
      cout<<"Please enter the deleting number"<<endl;
      cin>>deletenum;
      b1->remove(deletenum);
    }
    else if(option==4)
    {
      cout<<"please choose a type of order"<<endl;
      cin>>order;
      if(order==1)
      {
        cout<<"1.preorder"<<endl;
        b1->print(1);
      }
      else if(order==2)
      {
        cout<<"2.inorder"<<endl;
        b1->print(2);
      }
      else if(order==3)
      {
        cout<<"3.postorder"<<endl;
        b1->print(3);
      }
      else if(order==4)
      {
        cout<<"4.levelorder"<<endl;
        b1->print(4);
      }
    }
    else if(option==5)
    {
      cout<<"deletemin"<<endl;
      b1->deletemin();
    }
    else if(option==6)
    {
      cout<<"deletemax"<<endl;
      b1->deletemax();
    }
    else if(option==7)
    {
      cout<<"exit"<<endl;
      flag=true;
    }
  }
  delete b1;
}
