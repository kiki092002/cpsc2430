#include <iostream>
#ifndef MY_QUEUE_H
#define MY_QUEUE_H
using namespace std;
typedef int ElementType;
class MyQueue{
 private:
  class Node{
  public:
    ElementType data;
    Node* next;
  };
  Node* head;
  Node* tail;
 public:
  MyQueue();
  ~MyQueue();
  bool empty() const;
  int size() const;
  int front() const;
  int back() const;
  void push(int val);
  void pop();
};
#endif
