#ifndef HEAP_H
#define HEAP_H
#include <iostream>
using namespace std;

#define CAP 1000
typedef int ElementType;
class Heap{
private:
  ElementType a[CAP];
  int n;
  void percolate_dn(int pos);
  
public:
  Heap();
  Heap(int A[], int m);
  ~Heap();
  bool Empty() const;
  ElementType RemoveMax();
  ElementType getMinimum(int val);
};

#endif
