/*
  Name: Isaiah Mon Desir NetID: im1175
  Cyclic Association
*/
#include "Princess.h"
#include "FrogPrince.h"
#include <string>
#include <iostream>

using namespace std;
using namespace Fantasy;

int main() {
  Princess snowy("Snow White");
  snowy.display();
  FrogPrince froggy("Froggy");
  froggy.display();
  snowy.marries(froggy);
  snowy.display();
}

// class FrogPrince; //Foward declaration / Class prototype: Promises to compiler that FrogPrince will be a type

// class Princess {
// public:
//   // Princess(const string& name) : name(name), spouse(nullptr) {}
//   Princess(const string& name); //Initialization list should not be in prototype

//   // void display() const { cout << "Princess: " << name << endl;}
//   // void display(); Wrong
//   void display() const; //If actual function is const, its prototype MUST be const
  
//   // void marries(FrogPrince& betrothed) {
//   //   spouse = &betrothed;
//   //   //betrothed.spouse = this;
//   //   betrothed.setSpouse(this); //This doesn't work. At this point we wont know the functions of FrogPrince
//   // }
//   void marries(FrogPrince& betrothed); //Function prototype
  
// private:
//   string name;
//   FrogPrince* spouse; //This wont work because FrogPrince class comes after Princess Class. Fix using class prototype
//   //FrogPrince spouse;
// };

// class FrogPrince {
// public:
//   FrogPrince(const string& name);
//   void display() const;
//   void setSpouse(Princess* betrothed);
  
// private:
//   string name;
//   Princess* spouse;
// };

/*
  Qualify name of function with class it comes from 
  using [class]::(function)
*/

// //Princess
// Princess::Princess(const string& name) : name(name), spouse(nullptr) {}
// void Princess::display() const { cout << "Princess: " << name << endl;}
// void Princess::marries(FrogPrince& betrothed) {
//   spouse = &betrothed;
//   //betrothed.spouse = this;
//   betrothed.setSpouse(this);
// }

// //Frog Prince
// FrogPrince::FrogPrince(const string& name) : name(name), spouse(nullptr) {};
// void FrogPrince::display() const {cout << "Frog: " << name << endl;}
// void FrogPrince::setSpouse(Princess* betrothed){ //Takes princess pointer
//   spouse = betrothed;
// }
