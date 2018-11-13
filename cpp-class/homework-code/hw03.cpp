//Created by Isaiah Mon Desir. NetID: im1175
//HW03: Pointer Basics

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
class Noble;

//WARRIOR
class Warrior{
  
  friend ostream& operator<<(ostream& os, const Warrior& rhs){
    os << rhs.name;
    return os;
  }
private:
  const string name; //Should the name of weapon be const?
  int strength;
  Noble* owner = nullptr; //No owner by default
public:
  Warrior(const string& name, int strength) : name(name), strength(strength){
  }

  bool setOwner(Noble* newOwner){
    if(!owner){
      owner = newOwner;
      return true;
    }
    return false; //Owner hire didnt work
  }
  bool loseOwner(){
    if(owner){
      owner = nullptr;
      return true;
    }
    return false; //If there is no owner to begin with
  }
  void kill(){
    strength = 0;
  }
  void setStrength(double& ratio){
    strength= strength*ratio;
  }
  int getStrength() const{
    return strength;
  }
  const string getName() const{
    return name;
  }
  const Noble* getOwner() const {
    return owner;
  }
};

//NOBLE
class Noble{
  friend ostream& operator<<(ostream& os, const Noble& rhs){
    os << rhs.name;
    return os;
  }
private:
  const string name;
  vector <Warrior*> army; //Save a vector of pointers to warrior instead. //Why doesnt this work?
  int strength = 0;
  
public:
  Noble(string name) : name(name) {}

  int findWarrior(Warrior& w, const vector<Warrior*>& army) const {
    for(int i = 0; i < army.size(); i++){
      if(army[i] == &w){
	return i;
	break;
      }
    }
    return -1;
  }
  bool alive() const {
    return strength >-1;
  }
  bool hire(Warrior& v){
    if(alive() && !v.getOwner()){
      army.push_back(&v);
      v.setOwner(this);
      strength+= v.getStrength();
      return true;
    }
    return false;
  }
  bool fire(Warrior& v){
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
  void removeWarrior(vector <Warrior*>& army, int index){
    for(int i = index; i < army.size()-1; i++){
      army[index] = army[index+1];
    }
    army.pop_back();
  }

  void dies(){
    for(Warrior*& w: army){
      w -> kill();
    }
    strength = -1; //Only happens if warrior dies
  }

  void battle(Noble& challenger){ //Return true if lives, false if dead
    cout << name << " battles " << challenger << endl;
    if(!challenger.alive() && !alive()){
      cout << "Oh, NO! They're both dead! Yuck!" << endl;
    }
    else if(!challenger.alive()){
      cout << "He's dead " << name << endl;
    }
    else if (!alive()){
      cout << "He's dead " << challenger << endl;
    }

    else{
      double ratio = challenger.getStrength()/strength;
      if(ratio > 1){
	dies();//We die
	cout << challenger << " defeats " << name << endl;
      }
      else if(ratio < 1){
	challenger.dies();//They die
	alterHealth(ratio);
	cout << name << " defeats " << challenger << endl;
      }
      else{ //Both die
	dies();
	challenger.dies();
	cout << "Mutual Annihalation: " <<  name << " and " << challenger << " die at each other's hands" << endl;
      }
    }
  }
  void alterHealth(double& ratio){
    for(Warrior* v: army){
      strength-= v -> getStrength();
      v -> setStrength(ratio);
      strength+= v ->getStrength();
    }
  }
  void display() const {
    cout << name << " has an army of " << army.size() << endl;
    for(Warrior* w : army){
      if(w -> getStrength() > 0)
	cout << *w << ": " <<  w -> getStrength() << endl;
    }
  }
  int getStrength() const {
    return strength;
  }
    
};

int main() { //SAMPLE TEST CODE
  Noble art("King Arthur");
  Noble lance("Lancelot du Lac");
  Noble jim("Jim");
  Noble linus("Linus Torvalds");
  Noble billie("Bill Gates");

  Warrior cheetah("Tarzan", 10);
  Warrior wizard("Merlin", 15);
  Warrior theGovernator("Conan", 12);
  Warrior nimoy("Spock", 15);
  Warrior lawless("Xena", 20);
  Warrior mrGreen("Hulk", 8);
  Warrior dylan("Hercules", 3);

  jim.hire(nimoy);
  lance.hire(theGovernator);
  art.hire(wizard);
  lance.hire(dylan);
  linus.hire(lawless);
  billie.hire(mrGreen);
  art.hire(cheetah);

  jim.display();
  lance.display();
  art.display();
  linus.display();
  billie.display();

  art.fire(cheetah);
  art.display();

  art.battle(lance);
  jim.battle(lance);
  linus.battle(billie);
  billie.battle(lance);
}
