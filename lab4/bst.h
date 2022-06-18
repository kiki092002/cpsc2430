#ifndef _BST_H_ 
#define _BST_H_ 
#include <iostream> 
using namespace std; 
 
class BST { 
private: 
 class Node { 
        public: 
          int  data; 
          Node* left_; 
          Node* right_; 
 }; 
      Node* root_;  //root node pointer 
      //you may add your auxiliary functions here!
 public: 
 BST();  //constructor 
 ~BST(); //destructor 
 bool Empty() const;  
 void Insert(int val); 
 int MinElement() const; 
 int MaxElement() const; 
 bool Search(int val) const; 
 bool RecurSearch(int val) const; 
 void Erase(int val);   
      int Successor(int val); 
      void RangeQuery(int a, int b) const; 
}; 
#endif  
