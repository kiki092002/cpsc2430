#include <iostream>
#include "fib.h"
using namespace std;

int main() {
  int n ;
  cout << "Input number of Fibonacci numbers you want to generate (positve integer < 100): ";
  cin >> n;
  
  int p[n];
  int *a = &p;
  fibSequence(&a,n);
  for ( int i = 0 ; i < n ; i ++) {
    cout << p[i] << " ";

  }
  


  return 0;
}
