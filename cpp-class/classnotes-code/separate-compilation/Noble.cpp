//Created by Isaiah Mon Desir. NetID: im1175
//HW05: Separate Compilation
//Noble implementation file


#include "Noble.h"
#include "Warrior.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

namespace WarriorCraft{

  ostream& operator<<(ostream& os, const Noble& rhs){
    os << rhs.name << " has an army of " << rhs.army.size() << endl;
    for(Warrior* w : rhs.army){
      if(w -> getStrength() > 0)
	os << "\t" << *w << ": " <<  w -> getStrength() << endl;
    }
    return os;
  }

  Noble::Noble(string name) : name(name) {}

  string Noble::getName() const { return name;}

  int Noble::findWarrior(Warrior& w, const vector<Warrior*>& army) const {
    for(int i = 0; i < army.size(); i++){
      if(army[i] == &w){
	return i;
	break;
      }
    }
    return -1;
  }
  bool Noble::alive() const {
    return strength >-1;
  }
  bool Noble::hire(Warrior& v){
    if(alive() && !v.getOwner()){
      army.push_back(&v);
      v.setOwner(this);
      strength+= v.getStrength();
      return true;
    }
    return false;
  }
  bool Noble::fire(Warrior& v){
    if(alive()){
      int index = findWarrior(v, army);
      //Remove pointer to warrior from army
      if(index >= 0){
	removeWarrior(army, index);
	v.loseOwner();
	strength-= v.getStrength();
	cout << v << ", you're fired! -- " << name << endl;
	return true;
      }
    }
    return false;
  }
  bool Noble::abandoned(Warrior& v){
    if(alive()){
      int index = findWarrior(v, army);
      //Remove pointer to warrior from army
      if(index >= 0){
	removeWarrior(army, index);
	v.loseOwner();
	strength-= v.getStrength();
	return true;
      }
    }
    return false;
  }
  void Noble::removeWarrior(vector <Warrior*>& army, int index){
    for(int i = index; i < army.size()-1; i++){
      army[index] = army[index+1];
    }
    army.pop_back();
  }

  void Noble::dies(){
    for(Warrior*& w: army){
      w -> kill();
    }
    strength = -1; //Only happens if warrior dies
  }

  void Noble::battle(Noble& challenger){ //Return true if lives, false if dead
    cout << name << " battles " << challenger.name << endl;
    if(!challenger.alive() && !alive()){
      cout << "Oh, NO! They're both dead! Yuck!" << endl;
    }
    else if(!challenger.alive()){
      cout << "He's dead " << name << endl;
    }
    else if (!alive()){
      cout << "He's dead " << challenger.name << endl;
    }

    else{
      double ratio = challenger.getStrength()/strength;
      if(ratio > 1){
	dies();//We die
	cout << challenger.name << " defeats " << name << endl;
      }
      else if(ratio < 1){
	challenger.dies();//They die
	alterHealth(ratio);
	cout << name << " defeats " << challenger.name << endl;
      }
      else{ //Both die
	dies();
	challenger.dies();
	cout << "Mutual Annihalation: " <<  name << " and " << challenger.name
	     << " die at each other's hands" << endl;
      }
    }
  }
  void Noble::alterHealth(double& ratio){
    for(Warrior* v: army){
      strength-= v -> getStrength();
      v -> setStrength(ratio);
      strength+= v ->getStrength();
    }
  }
  int Noble::getStrength() const {
    return strength;
  }
}
