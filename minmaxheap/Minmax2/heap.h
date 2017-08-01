#ifndef HEAP_H
#define HEAP_H

class heap{
public:
  heap();
  ~heap();
  void build(int size,int arr[]);
  void insert(int x);
  void bubbleup(int i);
  void bubbleupmin(int i);
  void bubbleupmax(int i);
  void remove(int x);
  int maxormin(int x);
  void trickledown(int i);
  void trickledownmin(int i);
  int findsmallest(int i);
  int findlargest(int i);
  bool checkgrand(int i);
  void trickledownmax(int i);
  void deletemax();
  void deletemin();
  void swap(int x,int y);
  void print();
  void levelorder();

private:
  int table[500];
  int m_size;
};

#endif
