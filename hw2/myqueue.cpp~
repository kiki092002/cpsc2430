#include <iostream>
#include "myqueue.h"
using namespace std;

/*Initializes an empty queue*/
MyQueue::MyQueue():head(NULL),tail(NULL){}

/*deallocates memory for MyQueue object*/
MyQueue::~MyQueue(){
  while(head){
    Node* p = head;
    head    = head->next;
    delete p;
  }
}

/* determine whether queue is empty by checking its size*/
bool MyQueue::empty() const{
  return size() == 0;
}

/*return the number of elements in queue using traversal meth  */
int MyQueue::size() const{
  int length =0;
  Node* curr = head; // a curr node help avoid head node = tail node after traversing to the end of the queue
  while(curr!=NULL){
    length++; // increasing the length when vising each node
    curr = curr->next;
  }
  return length;
}

/*return the first element from the queue*/
int MyQueue::front() const{
  if(empty()){  
    return 0;
  }
  else {
    return head->data;
  }
}

/*return the last element from the queue*/
int MyQueue::back() const{
  if(empty()){
    return 0;
  }
  else{
    return tail->data;
  }
}

/*inserts the new element at the end of the queue after its current last element*/
void MyQueue::push(int val){
  Node* nptr = new Node; 
  nptr-> data= val;
  nptr->next = NULL;
  if(empty()){ // if this is an empty queue, the nptr node will be the head and tail node of the queue.
    head = nptr;
    tail = nptr;
  }
  else{ // if not an empty queue
    tail->next = nptr;// set tail's next node to nptr 
    tail       = nptr; //tail points to nptr
  }
}

/*removes the first element in the queue*/
void MyQueue::pop(){
  if(empty()){ // if this is an empty queue, return nothing.
    return;
  }
  if(head == NULL){ // if head is null, tail is also null
    
    tail = NULL;
  }
  else{ 
    Node* tmp = head;  // assign tmp node to head
    head      = head->next; // link head to head's next node
    delete tmp;
  }
}
