#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;


class Person { 
  class Date{
    friend ostream& operator<<(ostream& os, const Date& rhs){//gives outside methods/functions access to private fields
      os << rhs.month << "/" << rhs.day << "/" << rhs.year << endl;
      return os;
    }
  private:
    int month,day,year;
  public:
    Date(int m, int d, int y) : month(m), day(d), year(y){

    }
  };
  friend ostream& operator<<(ostream& os, const Person& rhs){//gives outside methods/functions access to private fields
    os << "Person: " << rhs.name << endl;
    return os;
  }
  
private:
  string name;
  Date dob;

public:
  Person(const string& name, int m, int d,int y) : name(name), dob(m,d,y) {}

  const string& getName() const {
    return name;
  }
};


int main(){
  Person john("John",11,10,1999);
  cout << john << endl;
  //operator<<(cout, john)

  Date someday(11,10,1999);

  vector <vector<int> > board (5,  vector<int> (6,0)); //quick empty 2d vector
  
}
