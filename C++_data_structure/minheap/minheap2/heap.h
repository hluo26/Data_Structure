#ifndef HEAP_H
#define HEAP_H

class heap{
public:
  heap();
  ~heap();
  void build(int arr[],int size);
  void insert(int x);
  void heapsort();
  void deletemin();
  void deletemax();
  void heapify(int x);
  void remove(int x);
  void levelorder();
  void swap(int x,int y);

private:
  int table[500];
  int m_size;
};

#endif
