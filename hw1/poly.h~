#ifndef POLY_H
#define POLY_H
#include <iostream>
using namespace std;

const int capacity = 101;
class Poly{
 private:
  int coEfficient[capacity];
  int degree;

 public :
  Poly();
  void read(istream& in);
  void write(ostream& out) const;
  Poly operator+(const Poly& p);
  Poly operator-(const Poly& p);
  int evaluate(int x);
  
};

#endif
