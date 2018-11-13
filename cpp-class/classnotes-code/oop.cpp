#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Person{//class instead of struct when you encapsulate/hide some data.
private:
  string name;
  int age;

public:
  Person(const string& name, const int& age) : name(name), age(age){ //variable(parameter) --> variable = parameter
    //
  }

  void string& getName() const {
    return name;
  }
  
  void display() const {
    cout<<"Name: " << name << endl;
  }
};

int main(){

  Person john("John", 20);
  john.display();
  string hisName = john.getName();
}
