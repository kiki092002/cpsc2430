#include "bst.h"
#include <iostream>
using namespace std;

BST::BST(): root_(NULL){}

BST::~BST(){

  destructorHelper(root_);
}
void BST::destructorHelper(Node* p){
  if(!p) return;
  destructorHelper(p->left_);
  destructorHelper(p->right_);
  delete p;
}
bool BST::Empty()const{
  return root_ == NULL;
}

bool BST::Insert(int val){
  Node* pa = NULL; // parent node
  Node* curr = root_;
  while(curr && curr->data !=val){
    pa = curr;
    if(val < curr->left){
      curr = curr->left;
    }
    else {
      curr = curr->right;
    }
  }
  if(curr)
    return false;
  Node* p = new Node;
  assert(p);
  p->data = val;
  p->left_ = p->right_ = NULL;
  if(!pa){
    curr  = p;
  }
  else {
    if(pa->data > val){
      pa->left = p;
    }
    pa->right  = p;
  }
  return true;
}

bool BST::recursInsertHelper(Node* &p, int val){
  if(!p){
    p = new Node;
    assert(p);
    p->data = val;
    p->left_ = p->right_ = NULL;
    return true;
  }
  else {
    if(p->data == val){
      return true;
    }
    if(p->left_->data > val){
      return recursInsertHelper(p->left_, val);
    }
    return recursInsertHelper(p->right_,val);

}
int BST::MinElement()const{
  assert(root_);
  Node* ptr = root_;
  while(ptr->left_ != NULL){
    ptr = ptr->left_;
  }
  return ptr->left_->data;
}
  
int BST::MaxElement()const{
  assert(root_);
  Node* tmp = root_;
  while(tmp->right_ !=NULL){
    tmp = tmp->right_;
  }
  return tmp->right_->data;
}

bool BST::Search(int val) const{
  Node* nptr = root_;
  while(nptr!=NULL && nptr->data !=val){
    if(val < nptr ->data){
      nptr = nptr->left_;
    }
    nptr = nptr->right_;
  }
  return nptr->data == val && nptr;
  
}

bool BST::RecurSearch(int val) const{
  Node* ptr = root_;
  if(ptr-data = val){
    return true;
  }
  if(ptr->data >val){
    RecurSearch(ptr->left->data);
  }
  RecurSearch(ptr->right->data);
  
}

void BST::Erase(int val){}

int BST::Successor(int val){}

void BST::RangeQuery(int a, int b)const{}
