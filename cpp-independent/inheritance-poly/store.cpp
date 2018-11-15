/*
  Written by: Isaiah Mon Desir
  Goal: Practice fundamentals of Inheritance and Polymorphism
*/

/*
  Create a Store that stores and sells, inventory.
  
  Store object should be able to stock up on:
  -Shirts
  -Pants
  -Shoes
  Store objects are managed by a Person object, who can also hire/fire multiple
  other people objects.
  Managers can only manage one shop, and employees can only have one job.
  
  Consider for Future implimentation: 
  -Allow inclusion of more shops of different kinds;
  -Expansion of this Store to become a chain, with reigonal managers and CEOs
  -Expansion of inventory to include other things.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Person; //Forward Declaration of Person type
class Clothing;

//===Store Object===//
class Store {
  //friend bool Person::stockUp(Clothing& clothing);
  friend ostream& operator<<(ostream& os, Store& rhs){
    os << "Welcome to " << rhs.name <<"\nWe are managed by ";
    if(rhs.manager)
      os << *rhs.manager << "."; //Note: why doesn't using dereferenced object here work?-IM 11/14
    else{
      os << "nobody!";
      return os;
    }
    os<< *rhs.manager << ". We have " << rhs.employees.size()
      <<" employees on staff!\n";
    if(rhs.employees.size() >0)
      for(Person* employee: rhs.employees)
	os << *employee << "\n";

    //Lets print out our stock too
    os << "\nOur Stock: ";
    if(rhs.inventory.size() == 0)
      os << "Nothing yet! Check back later!" << endl;
    else
      for(Clothing* clothing: rhs.inventory)
	os << *clothing << "\n";
    return os;
  }
  bool stockUp(Clothing& clothing){
    if(employees.size() == 0)
      return false;
    inventory.push_back(&clothing);
    return true;
  }
public:
  Store(const string& name) : name(name){}
  bool hire(Person& candidate, const string& position);
private:
  Person* manager = nullptr;
  vector<Clothing*> inventory;
  vector<Person*> employees;
  const string name;
protected:
  
};

class Person{//When shoud Person become different manager and Employee classes?
  friend ostream& operator<<(ostream& os, Person& rhs){
    os<< rhs.name <<" from " << rhs.hometown;
    return os;
  }
public:
  Person(const string& name, const string& hometown) : name(name), hometown(hometown) {}
  bool setJob(Store* workPlace){
    if(this->workplace)
      return false;
    this -> workplace = workPlace;
    return true;
  }
  bool employed() const { return workplace != nullptr; }
private:
  const string name;
  const string hometown; //Just added for fun
  Store* workplace = nullptr;
protected:
  //What would a person need to do
};

bool Store::hire(Person& candidate, const string& position = "") {
  //Should a shop object hire an employee? Maybe only managers should
  if(position == "manager"){
    if (manager){ //If there's already a manager
      return false;
    }
    if(candidate.setJob(this))
      manager = &candidate;
  }
  else
    if(candidate.setJob(this))
      employees.push_back(&candidate);
  return true;
}

//===Clothing Object===//
class Clothing{
  friend ostream& operator<<(ostream& os, Clothing& rhs){
    os << "Size: " << rhs.size << ", Color: " << rhs.color;
    return os;
  }
public:
  Clothing(const char& size, const string& color) : size(size), color(color){}
private:
  char size;
  string color;
};

class Shirt : public Clothing {
public:
  Shirt(const char& size, const string& color) : Clothing(size, color) {}
  
private:
};
class Pants : public Clothing{
public:
  Pants(const char& size, const string& color) : Clothing(size, color) {}
private:
};
class Shoes : public Clothing {
public:
  Shoes(const char& size, const string& color) : Clothing(size, color) {}
private:
};

int main() {//Test code
  Store clothesMart("Clothes-Mart"); //Let's create a test store called Clothes-Mart
  Person mike("Mike", "Ohio"); //We'll let Mike be the manager of Clothes-Mart
  Person dan("Dan", "New York");

  clothesMart.hire(mike, "manager");
  clothesMart.hire(dan);
  cout << clothesMart;

  
}
