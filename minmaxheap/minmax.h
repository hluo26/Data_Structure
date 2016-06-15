#ifndef MINMAX_H
#define MINMAX_H

class minmax
{
public:
  minmax();
  ~minmax();
  void build();
  void insert(int x);
  void deletemax();
  void deletemin();
  void levelorder();
  void trickledown(int index);
  void tricklemin(int index);
  void tricklemax(int index);
  void bubbleup(int index);
  void bubbleupmin(int index);
  void bubbleupmax(int index);
  void swap(int x,int y);
  bool checkgrand(int index);
  bool checkchild(int index);
  int leftchild(int index);
  int rightchild(int index);
  int findmin(int index);
  int findmax(int index);

private:
  int* m_heap;
  int m_size;
};

#endif
