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

//===Store Object===//
class Store {
public:
  Store(const string& name) : name(name){}
  bool hire(Person* candidate, string position) {
    //Should a shop object hire an employee? Maybe only managers should
    if(position == "manager"){
      if (manager){ //If there's already a manager
	cerr << *candidate << " can't be hired because "
	     <<name << " already has a manager.\n";
	return false;
      }
      manager = candidate;
      candidate -> setJob(this); //SetJob method doesnt exist yet -IM 11/12
    }
    else{
      if(candidate -> employed()){
	cerr << *candidate << " is already employed!\n";
	return false;
      }
      employees.push_back(candidate);
      candidate ->setJob(this);
    }
    return true;
  }
private:
  Person* manager = nullptr;
  vector<Clothing*> inventory;
  vector<Person*> employees;
  const string name;
protected:
};

class Person{

};

//===Clothing Object===//
class Clothing{
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
  Person mike("Mike"); //We'll let Mike be the manager of Clothes-Mart
  
}
