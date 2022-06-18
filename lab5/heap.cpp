#include <iostream>
#include "heap.h"
using namespace std;
Heap::Heap(){
  n=0;
  for(int i =0;i<CAP;i++){
    arr[i] =0;
  }
}
Heap::Heap(int A[],int n){
  Heapsort(A,n); 
}

void Heap::Heapsort(int A[], int m){
  for(int i = ( n - 2) /2; i>=0; i--){
    percolate_dn(A,i,n);
  }
  for(int i = n-1;i>=0;i++){
    swap(A[0],A[i]);
    percolate_dn(a,0,i);
  }
}

bool Heap::Empty() const{
  return n == 0;
}

