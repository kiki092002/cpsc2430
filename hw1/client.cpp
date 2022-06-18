#include <iostream>
#include "poly.h"
using namespace std;

int main(){
  Poly p1,p2;
  p1.read(cin);
  cout << "p1(x): ";
  p1.write(cout);
  
  p2.read(cin);
  cout << "p2(x): ";
  p2.write(cout);

  Poly p3 = p1 +  p2;
  cout << "p3(x) = p1(x) + p2(x) = ";
  p3.write(cout);

  Poly p4 = p1 - p2;
  cout << "p4(x) = p1(x) - p2(x) = ";
  p4.write(cout);

  Poly p5;
  p5.read(cin);
  cout << "p5(x) : ";
  p5.write(cout);
  int x;
  cout << "Enter x: ";
  cin >> x;
  cout << p5.evaluate(x)<<endl;
  
}
