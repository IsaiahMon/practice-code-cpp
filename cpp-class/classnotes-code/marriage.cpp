#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Person {
  //'friend' gives outside methods/functions access to private fields
  
  friend ostream& operator<<(ostream& os, const Person& rhs){
    os << "Person: " << rhs.name;
    os << ". Marital Status: ";
    if(rhs.spouse != nullptr){
      os << "Married to " << rhs.spouse->name << endl;
      //'->' accesses a field/method of the object being pointed to.
      //ie: [pointer]->(field/method)
    }
    else{
      os << "Single." << endl;
    }
    return os;
  }
private:
  string name;
  //Person spouse; //Wrong because this person object will have an infinite depth of spouses
  Person* spouse = nullptr; //Spouse is a pointer. Points to null-pointer 'nullptr' by default

public:
  Person(const string& name) : name(name){}

  bool marries(Person& betrothed){
    if(spouse == nullptr && betrothed.spouse == nullptr){
      spouse = &betrothed; //Spouse is address of betrothed
      betrothed.spouse = this; // 'this' holds address of object
      //betrothed.marries(*this);
      return true;
    }
    return false; //We don't want funciton to fail 'silently'
  }
  
};

int main(){
  Person john("John");
  Person mary("Mary");
  Person sally("Sally");
  john.marries(mary);
  sally.marries(john);
  cout << john << mary << endl;

  int x = 17;
  cout << x << endl;
  cout << &x << endl;
  //ampersand before variable name gets hexidecimal address to x : & = "address of" Operator

  int* p = &x;
  //Asterisk after type means 'p' is a pointer.

  cout << p << endl;

  cout << *p << endl;
  //Asterisk after a pointer is a 'dereference.' Gets value at pointer

  const int* q = &x; //'q' cant be used to make changes to 'x'
  int* const r = &x; //'r' is a constant pointer to a mutable integer 'x'
  const int* const yapv = &x; //'yapv' is a constant pointer that cannot be used to modify 'x'


  vector<Person*> peoplePtr;
  ifstream ifs ("people");
  string name;
  while(ifs >> name){
    Person* someone = new Person (name); //Ensures it uses a new address each time
    peoplePtr.push_back(someone);
  }
  for(const Person* aPerson : peoplePtr){
    aPerson->display();
  }
  for(Person* aPerson: peoplePtr){
    delete aPerson; //Clears up this address in the heap.
  }
}

  
  
