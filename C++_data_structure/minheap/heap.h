#ifndef _HEAP_H_
#define _HEAP_H_

class heap{
public:
  heap();
  ~heap();
  void build();
  void heapify(int index);
  void insert(int x);
  void print();
  void swap(int x, int y);
  void deletemin();
  void deletemax();
  int findmax();
  void topdown(int index);
  int findleast(int x, int y);
  void levelorder();
  void remove(int x);

private:
  int *m_heap;
  int m_size;

};

#endif
