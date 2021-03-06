#include <iostream>
#include <fstream>
#include <sstream>
#include "citydict.h"
using namespace std;

int main(){
  CityDict dict;
  ifstream myFile;
  myFile.open("cities.csv");
  string line;
  string name;
  string country;
  int population;
  getline(myFile,line);
  while(getline(myFile,line)){
    stringstream iss(line);
    getline(iss,name, ',');
    getline(iss,country, ',');
    iss >> population;
    string token;
    dict.insert(name,country,population);
  }
  myFile.close();
  int n;
  cout << "How many city do you want to check? ";
  cin >> n;
  cin.ignore();
  string name_;
  for(int i = 0 ;i<n;i++){
    getline(cin,name_);
    cout << "Country: " <<  dict.getCountry(name_)<<endl;
    cout << "Population: " << dict.getPopulation(name_)<<endl;
  }
  cout << "Step4" << endl;
  for(int i = 0 ; i< n;i++){
    getline(cin,name_);
    dict.greater(name_);
  }
  cout<< "Step5" <<endl;
  for(int i = 0 ; i< n;i++){
    getline(cin,name_);
    cout << dict.remove(name_)<<endl;
    
  }
  cout <<"Step6" << endl;
  for(int i =0 ;i< n ;i++){
    getline(cin,name_);
    cout << "Country: " <<  dict.getCountry(name_)<<endl;
    cout << "Population: " << dict.getPopulation(name_)<<endl;
    dict.remove(name_);
  }

  cout << "Step 7: " ;
  for(int i = 0 ; i< n;i++){
    getline(cin,name_);
    dict.greater(name_);
    cout << "Country: " <<  dict.getCountry(name_)<<endl;
    cout << "Population: " << dict.getPopulation(name_)<<endl;
    dict.remove(name_);
  }

  cout << "Step 8: " ;
  CityDict dict2(dict);
  CityDict dict3;
  dict3 = dict;

  cout << "Step 9:";
  int n1;
  cout << "How many city do you want to check?(dict 2) ";
  cin >> n1;
  cin.ignore();
  string secondN;
  for(int i = 0 ;i<n1;i++){
    getline(cin,secondN);
    cout << "Country: " <<  dict2.getCountry(secondN)<<endl;
    cout << "Population: " << dict2.getPopulation(secondN)<<endl;
  }

  for(int i = 0 ; i< n1;i++){
    getline(cin,secondN);
    dict2.greater(secondN);
  }

  for(int i = 0 ; i< n1;i++){
    getline(cin,secondN);
    cout << dict2.remove(secondN)<<endl;

  }

  for(int i =0 ;i< n1 ;i++){
    getline(cin,secondN);
    cout << "Country: " <<  dict2.getCountry(secondN)<<endl;
    cout << "Population: " << dict2.getPopulation(secondN)<<endl;
    dict2.remove(secondN);
  }
  for(int i = 0 ; i< n1;i++){
    getline(cin,secondN);
    dict2.greater(secondN);
    cout << "Country: " <<  dict2.getCountry(secondN)<<endl;
    cout << "Population: " << dict2.getPopulation(secondN)<<endl;
    dict2.remove(secondN);
  }

  int n2;
  cout << "How many city do you want to check?(dict 3) ";
  cin >> n2;
  cin.ignore();
  string thirdN;
  for(int i = 0 ;i<n2;i++){
    getline(cin,thirdN);
    cout << "Country: " <<  dict3.getCountry(thirdN)<<endl;
    cout << "Population: " << dict3.getPopulation(thirdN)<<endl;
  }

  for(int i = 0 ; i< n2;i++){
    getline(cin,thirdN);
    dict3.greater(thirdN);
  }
  for(int i =0 ;i< n2 ;i++){
    getline(cin,thirdN);
    cout << "Country: " <<  dict3.getCountry(thirdN)<<endl;
    cout << "Population: " << dict3.getPopulation(thirdN)<<endl;
    dict3.remove(thirdN);
  }
  for(int i = 0 ; i< n2;i++){
    getline(cin,thirdN);
    dict3.greater(thirdN);
    cout << "Country: " <<  dict3.getCountry(thirdN)<<endl;
    cout << "Population: " << dict3.getPopulation(thirdN)<<endl;
    dict3.remove(thirdN);
  
  return 0;
}
