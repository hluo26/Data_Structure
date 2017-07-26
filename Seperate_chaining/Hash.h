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
  void rehash(int x);
  bool contains(int x);
  bool isfull();
  int prime(int x);
  bool isprime(int x);
  int count();

private:
  hashnode** table;
  int m_length;

};

#endif
