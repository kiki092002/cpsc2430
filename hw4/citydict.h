#ifndef CITYDICT_H
#define CITYDICT_H
#include <iostream>
using namespace std;

class CityDict{
 private:
  struct CityNode{
    string name;
    string country;
    int population;
    CityNode* left;
    CityNode* right;
  };
  CityNode* root;
  void copyC(CityNode* other);
  void checkGreater(CityNode* other,string name);
  void helper_destructor(CityNode* p);
  void inorder(CityNode* root)const;
  void insert_helper(CityNode* &p, string name, string country, int population);

 public:
  CityDict();
  ~CityDict();
  CityDict(const CityDict& other);
  void insert(string name, string country, int population);
  bool remove(string name);
  string getCountry(string name);
  int getPopulation(string city);
  void greater(string name);
  void display()const;
  const CityDict& operator=(const CityDict& x);
};

#endif
  
  
