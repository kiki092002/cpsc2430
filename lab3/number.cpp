
//number.cpp
#include <iostream>
#include <cassert>
#include "number.h"
using namespace std;
Node *Convert(int x){
  Node* p = new Node;
  assert(p);
  p->digit = x%10;
  p->next  = NULL;
  x/=10;
  if(x > 0) {
    p->next = Convert(x);
  }
  return p;
}

Node *Add(Node* h1, Node* h2, int carry_over=0){
  if(!h1 && !h2)
    return NULL;
  if(h1)
    carry_over += h1->digit;
  if(h2)
    carry_over += h2->digit;
  Node* p = new Node;
  assert(p);
  p->digit = carry_over %10;
  p->next  = Add(h1? h1->next : h1,h2? h2->next: h2,carry_over/10);
}

void Display(Node* head){
  if(!head){
    return ;
  }
  Display(head->next);
  cout << head->digit %10;
}

void Destroy(Node* head){
  if(!head){
    return;
  }
  Destroy(head->next);
  delete head;
}

    
  
