#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Date{

private:
  int month,day,year;
  
public:
  Date(int m, int d, int y) : month(m), day(d), year(y){

  }

};

class Person {
  friend ostream& operator<<(ostream& os, const Person& rhs); //gives outside methods/functions access to private fields
private:
  string name;
  Date dob;

public:
  Person(const string& name, int m, int d,int y) : name(name), dob(m,d,y) {}

  const string& getName() const {
    return name;
  }
};

ostream& operator<<(ostream& os, const Person& rhs){
  os << "Person: " << rhs.name << endl;
  return os;
}

int main(){
  Person john("John",11,10,1999);
  cout << john << endl;
  //operator<<(cout, john)

  Date someday(11,10,1999);
  
}
