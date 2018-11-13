//Created by Isaiah Mon Desir. NetID: im1175
//HW05: Separate Compilation
//Warrior implementation file
#include "Noble.h"
#include "Warrior.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace WarriorCraft{
  ostream& operator<<(ostream& os, const Warrior& rhs){
    os << rhs.name;
    return os;
  }
  Warrior::Warrior(const string& name, int strength) : name(name), strength(strength){
  }

  bool Warrior::setOwner(Noble* newOwner){
    if(!owner){
      owner = newOwner;
      return true;
    }
    return false; //Owner hire didnt work
  }
  bool Warrior::runaway(){
    if(!owner){
      cout << name << " has no owner!" << endl;
      return false;}
    cout<< name << " flees in terror, abandoning his lord, " << owner -> getName() << endl;
    owner -> abandoned(*this);
    return true;
  }
  
  bool Warrior::loseOwner(){
    if(owner){
      owner = nullptr;
      return true;
    }
    return false; //If there is no owner to begin with
  }
  void Warrior::kill(){
    strength = 0;
  }
  void Warrior::setStrength(double& ratio){
    strength= strength*ratio;
  }
  int Warrior::getStrength() const{
    return strength;
  }
  const string Warrior::getName() const{
    return name;
  }
  const Noble* Warrior::getOwner() const {
    return owner;
  }
}
