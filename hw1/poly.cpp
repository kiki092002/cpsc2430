#include "poly.h"
#include <math.h>
#include <limits.h>

Poly::Poly(){
  degree      = 0;
  for(int i = 0 ; i < capacity; i++) {
    coEfficient[i] = 0;
  }
}

void Poly::read(istream &in){
  cout << "Enter the highest degree: ";
  in >> degree;
  for (int i = 0;i<degree+1; i++){
    in >> coEfficient[i];
  }
}

void Poly::write(ostream &out) const{
  if(coEfficient[0] == 0) {
    out << coEfficient[1] << "x";
  }
  else {
    out << coEfficient[0];
    out << " + " << coEfficient[1] << "x";
  }
  for ( int i =2; i < degree  + 1; i++){
    if (coEfficient[i] > 0) {
      out << " + ";
    }
    else if( coEfficient[i] <0){
      out << " - ";
    }
    else if(coEfficient[i] == 0){
      continue;
    }
    out << abs(coEfficient[i]) <<"x^" << i;
  }
  out << endl;
}

Poly Poly::operator+(const Poly &p){
  Poly tmp;
  int i ;
  if(degree >= p.degree){
    tmp.degree= degree;
    for( i = 0; i < degree+1; i++){
      tmp.coEfficient[i] =coEfficient[i];
    }
  }
  else{
    tmp.degree = p.degree;
    for( i = 0 ; i < p.degree +1 ; i++) {
      tmp.coEfficient[i] = p.coEfficient[i];
    }
  }
  tmp.degree = degree + p.degree;
  for ( i = 0 ; i <= tmp.degree; i++) {
    tmp.coEfficient[i] = coEfficient[i] + p.coEfficient[i];
  }
  return tmp;
}

Poly Poly::operator-(const Poly &p){
  Poly ans;
  int i ;
  if ( degree >= p.degree){
    ans.degree  = degree;
    for(  i = 0; i < degree +1 ; i++) {
      ans.coEfficient[i] = coEfficient[i];
    }
  }
  else {
    ans.degree = p.degree;
    for(i = 0; i < p.degree + 1; i++){
      ans.coEfficient[i] = p.coEfficient[i];
    }
  }
  ans.degree = degree + p.degree;
  for ( i = 0 ; i <= ans.degree  ; i++){
    ans.coEfficient[i] = coEfficient[i] - p.coEfficient[i];
  }
 
  return ans;
}

int Poly::evaluate(int v){
  if ( v > INT_MIN && v < INT_MAX){
    int result = 0;
    for(int i  = 0; i< degree + 1; i++){
      result   = result + coEfficient[i] * pow(v,i);
    }
  return 0;
}
