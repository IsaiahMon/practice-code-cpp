/*
  Implimentation File of FrogPrince
*/

#include "FrogPrince.h"
//#include "Princess.h"
//^^Not needed now because Princess is only required as a pointer in this class, not as an object
#include <string>
#include <iostream>
using namespace std;

namespace Fantasy{

  //Frog Prince
  FrogPrince::FrogPrince(const string& name) : name(name), spouse(nullptr) {};

  void FrogPrince::display() const {cout << "Frog: " << name << endl;}

  void FrogPrince::setSpouse(Princess* betrothed){ //Takes princess pointer
    spouse = betrothed;
  }
}
