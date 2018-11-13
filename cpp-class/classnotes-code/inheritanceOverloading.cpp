#include <iostream>
using namespace std;

class Parent{};
class Child: public Parent{};
class GrandChild : public Child{};

/*
  Substitutability. This will work for all children of Parent
  if no matching function exists.
*/
void func(Parent& base) {cout << "func(Parent)\n";}
void func(Child& derived) {cout << "func(Child)\n";}

voic otherFunc(Parent& base){
  func(base);
  //Only sees base is Parent so it calls func(Parent).
  //Functions don't engage in polymorphism. Methods do.
}

int main(){
  Parent parent;
  func(parent);
  Child child;
  func(child);
  GrandChild gc;
  func(gc); //Calls the Child implimentation of func()

  otherFunc(child); //
  
}
