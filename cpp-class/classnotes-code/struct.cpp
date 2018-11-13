#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct Person{
  string name;
  int age;
};
int main(){
  vector <Person> people;

  ifstream ifs;
  ifs.open("people");

  if(!ifs){
    cerr<< "failed to open people\n";
    exit(1);
  }

  Person someone;
  
  while(ifs >> someone.name >> someone.age){
    people.push_back(someone);
  }

  for(const Person& anyone: people){
    cout << "Name: " << anyone.name << ", Age: " << anyone.age << endl;
  }
}
