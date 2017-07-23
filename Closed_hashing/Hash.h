#include"hashnode.h"
#ifndef HASH_H
#define HASH_H

class Hash{

public:
  Hash();
  ~Hash();
  void insert(int x);
  void remove(int x);
  void print();
  int hashing(int x,int i);
  void rehash(int size);
  bool contains(int x);
  bool isfull();

private:
  hashnode** table;
  int m_length;

};

#endif
