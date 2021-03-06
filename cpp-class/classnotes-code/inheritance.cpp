#include <iostream>
#include <vector>

using namespace std;

class Pet{
private:
  string name;
  
protected:
  /*
    The keyword 'protected' means that children classes can only access 
    fields/methods of other children of their same type.
    Heirarchal privacy

    Try to make fields private, but mark getters/setters as protected
  */
  const string& getName() const { return name;}
  
public:
  Pet(const string& name) : name(name) {}
  virtual void eat() {cout << "eating\n";}
  /*
    Mark method 'virtual' in base class is polymorphism:
    Tells compiler to wait until runtime to see
    what version of eat() should be called.
  */
  virtual ~Pet(){} //Not discussed, used to prevent warnings

  //const string& getName() const { return name;} //Bad since it gives everyone access to names
};

class Cat : public Pet {
public:
  /*
    Constructors and fields are NOT inherited. Unique constructor MUST 
    calling parent constructor (compilation error)
    Initialize parent fields using parent constructor in initialization list
  */
  /*
    Polymorphism is shut off in constructors. 
    Parent constructors can only call methods
    within it's scope.
  */
  Cat(const string& name) : Pet(name) {}  //name(name) {}
  void purr() { cout << "Purr\n";}
  void eat() override { cout << "Cat eating\n";}
  /*
    'override' sends errors in compile time if no 
    matching parent function exists
  */
};

class Slug : public Pet {
public:
  using Pet::Pet;
  /*
    Calls all functions from Pet class called Pet 
    runs constructor without using initialization list.
  */
  
};
class Roach : public Pet {
public:
  using Pet::Pet;
};


/*
  func(ParentClass p)
  Will take instance of Pet class and all Pet children classes
*/

//void silly(Pet aPet) { //Copies don't allow polymorphism
void silly(Pet& aPet) {
  cout << "Passed in a pet" << endl;
  aPet.eat(); //Uses parent class method instead of child class method
}

int main(){
  Pet peeve("Peeve");
  silly(peeve);
  
  Cat felix("Felix");
  felix.eat();
  // Pet peeve;
  // silly(peeve);
  silly(felix);

  Slug sluggo("Sluggo");
  Roach archie;

  //peeve = sluggo; //Works
  //sluggo = peeve; //Does NOT work, cannot change the base of the child object

  /*
    ===PRINCIPLE OF SUBSTITUTIBILITY=== 
    ~GOOD~
    Parent parent = child;
    Parent* parentPtr = &child;
    
    ~BAD~
    Child child = parent;
    Child* childPtr = &parent;
    Child child = anotherTypeChild; 
    
    ===PUBLIC INTERFACE===
    Parent pointers can't call methods of child class.
    It can only access methods that exist in the base class
    (Even though it can access instances of child methods)
  */

  cout << "=====Copies====\n";
  vector<Pet> menagerie; //Vector of copies WONT allow Polymorphism
  menagerie.push_back(felix);
  menagerie.push_back(peeve);
  menagerie.push_back(sluggo);
  menagerie.push_back(archie);
  for(size_t i = 0; i < menagerie.size(); ++i){
    menagerie[i].eat();
  }

  cout << "====Pointers====\n";
  vector<Pet*> menagerie2; //Vector of pointers WILL allow Polymorphism
  menagerie2.push_back(&felix);
  menagerie2.push_back(&peeve);
  menagerie2.push_back(&sluggo);
  menagerie2.push_back(&archie);
  for(size_t i = 0; i < menagerie2.size(); ++i){
    menagerie2[i] ->eat();
  }
}
