//main.cpp
#include <iostream>
#include <cassert>
#include "number.h"
using namespace std;

int main(){
  int a,b;
  cout << "Input the first integer (>=0): ";
  cin >> a;
  cout << "Input the second integer(>=0): ";
  cin >> b;
  assert(a >=0 && b >=0);
  Node *ha = Convert(a);
  Node *hb = Convert(b);
  Node *head = Add(a,b,0);
  cout << a << " + " << b << " = " << (a+b) << endl;
  Display(head);
  Destroy(ha);
  Destroy(hb);
  Destroy(head);
  return 0;
}
