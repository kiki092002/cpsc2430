//number.h
#ifndef _NUMBER_H
#define _NUMBER_H
struct Node{
  int digit;
  Node *next;
};

Node *Convert(int x);
Node *Add(Node* h1, Node* h2, int carry_over);
void Display(Node *head);
void Destroy(Node* head);
#endif

