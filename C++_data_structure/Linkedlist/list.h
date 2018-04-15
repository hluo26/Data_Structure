#ifndef _LIST_H_
#define _LIST_H_
#include"node.h"

class list
{
public:
  list();
  ~list();
  bool isempty()const;
  int size()const;
  bool search(int x)const;
  void print()const;
  void addback(int x);
  void addfront(int x);
  bool removeback();
  bool removefront();
  //std::vector<int>tovector()const;

private:
  node* m_front;
  int m_size;
};

#endif
