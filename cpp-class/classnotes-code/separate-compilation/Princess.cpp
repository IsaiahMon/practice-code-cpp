/*
  Implimentation File of Princess
  Contains definitions of the function prototypes in the Princess Header File
*/

//INCLUDE HEADER FILES NOT CPP FILES
#include "Princess.h"
#include "FrogPrince.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

namespace Fantasy{
  //Princess
  Princess::Princess(const string& name) : name(name), spouse(nullptr) {}

  void Princess::display() const { cout << "Princess: " << name << endl;}

  void Princess::marries(FrogPrince& betrothed) {
    spouse = &betrothed;
    //betrothed.spouse = this;
    betrothed.setSpouse(this);
  }
}
