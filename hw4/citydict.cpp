#include "citydict.h"
#include <iostream>
using namespace std;

CityDict::CityDict():root(NULL){}

CityDict::~CityDict(){
  helper_destructor(root);
}

void CityDict::helper_destructor(CityNode *p){
  if(!p){
    return;
  }
  helper_destructor(p->left);
  helper_destructor(p->right);
  delete p;
}

void CityDict::insert(string name, string country, int population){
  insert_helper(root, name, country, population);
}

void CityDict::insert_helper(CityNode* &p, string name, string country, int population){
  if(!p){
    p = new CityNode;
    p->name       = name;
    p->country    = country;
    p->population = population;
    p->left = p->right = NULL;
  }
  else {
    if(p->name.compare(name) == 0){
      return;
    }
    else if(p->name.compare(name) > 0){
      insert_helper(p->left, name, country, population);
    }
    else{
      insert_helper(p->right, name, country, population);
    }
  }
}

bool CityDict::remove(string name){
  CityNode* parent = NULL;
  CityNode* curr   = root;
  while(curr && curr->name.compare(name) !=0){
    parent = curr;
    if(curr->name.compare(name) > 0){
      curr = curr->left;
    }
    else{
      curr = curr->right;
    }
  }
  if(!curr){
    return false;
  }
  if(curr->left && curr->right){
    parent         = curr;
    CityNode* succ = curr->right;
    while(succ->left){
      parent = succ;
      succ   = succ->left;
    }
    swap(curr->name,succ->name);
    curr = succ;
  }
  CityNode* gc = curr->left;
  if(!gc){
    gc  = curr->right;
  }
  if(!parent){
    root= gc;
  }
  else{
    if(curr->name.compare(parent->name)>0){
      parent->left = gc;
    }
    else {
      parent->right = gc;
    }
  }
  delete curr;
  return true;
}

string CityDict::getCountry(string name){
  CityNode* curr = root;
  while(curr && curr->name.compare(name)!=0){
    if(curr->name.compare(name) >0){
      curr = curr->left;
    }
    else if(curr->name.compare(name) <0){
      curr = curr->right;
    }
  }
  if(!curr)
    return "NA";
  return curr->country;
}

int CityDict::getPopulation(string city){
  CityNode* curr = root;
  while(curr && curr->name.compare(city) !=0){
    if(curr->name.compare(city) >0){
      curr = curr->left;
    }
    else if(curr->name.compare(city) <0){
      curr = curr->right;
    }
  }
  if(!curr){
    return -1;
  }
  return curr->population;
}

CityDict::CityDict(const CityDict& other){
  root = NULL;
  copyC(other.root);
}

void CityDict::copyC(CityNode* other){
  CityNode* curr = other;
  if(curr){
    insert(curr->name,curr->country,curr->population);
    copyC(curr->left);
    copyC(curr->right);
  }
}

const CityDict& CityDict::operator=(const CityDict& x){
  if(&x != this){
    helper_destructor(root);
    root = NULL;
    copyC(x.root);
  }
  return *this;
}

void CityDict::greater(string name){
  checkGreater(root,name);
}

void CityDict::checkGreater(CityNode* root, string name){
  if(!root){
    return;
  }
  if(root->name.compare(name) < 0){
    checkGreater(root->right,name);
  }
  if(root->name.compare(name) <0){
    cout <<"City: " << root->name << endl;
    cout <<"Country: " << root->country << endl;
    cout <<"Population: " << root->population<<endl<<endl;
  }
  checkGreater(root->left,name);
}
void CityDict::inorder(CityNode* root) const{
  if(!root){
    return;
  }
  inorder(root->left);
  cout << root->name << "  " << root->country << " " << root->population << endl;
  inorder(root->right);
}

void CityDict::display()const{
  inorder(root);
}

