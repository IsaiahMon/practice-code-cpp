/*
  Name: Isaiah Mon Desir
  NetdID: im1175
  HW07 - Inheritance
*/
#include <iostream>
#include <vector>
using namespace std;

class Noble{
  friend ostream& operator<<(ostream& os, Noble& rhs){
    os << rhs.name;
    //What else is printed
    return os;
  }
public:
  Noble(const string& name, int strength) : name(name) {}
  virtual bool battle(Noble& opponent) {
    if(&opponent == this){
      cerr << "Nobles cannnot battle themselves\n;";
      return false;
    }
    int strengthCopy = strength;
    strength -= opponent.getStrength();
    opponent.setStrength(strengthCopy);

    //Write something
    return true;
    
  }
  int findWarrior(const string& warrior) const {
    for(int i = 0; i < warrior.army.size(); i++){
      if(army[i] -> getName() == w){
	return i;
	break;
      }
    }
    return -1;
  }
private:
  string name;
  int strength;
protected:
  int getStrength() const { return strength;}
  bool setStrength(int oppStrength) {
    strength -= oppStrength();
    if(strength <= 0)
      return false; //Only happens if the warrior die
    return true;
  }

};
//Person With Strength to Fight
class PersonWithStrengthToFight : public Noble{
public:
  PersonWithStrengthToFight(const string& name, int strength) : Noble(name, strength) { }
  
private:

};

//Lord
class Lord : public Noble{
public:
  Lord(const string& name) : Noble(name, 0) {
    //Set Noble strength to zero by default
  }
  bool hires(Protector& protector) {
    if(alive() && protector.alive() && !protector.getOwner()){
      army.push_back(protector);
      protector.setOwner(this);
      strength+= protector.getStrength();
      return true;
    }
    return false;
  }
  bool fire(Protector& protector){ //ADJUST FOR HW4
    using Noble::findWarrior;
    if(alive()){
      int index = findWarrior(protector.getName());
      //Remove pointer to warrior from army
      if(index >= 0){
	removeWarrior(index);
	protector.loseOwner();
	strength-= protector.getStrength();
	cout << "You don't work for me anymore " << protector <<"! -- " << name << endl;
	return true;
      }
    }
    return false;
  }
  void removeWarrior(int index){
    for(int i = index; i < army.size()-1; i++){
      army[index] = army[index+1];
    }
    army.pop_back();
  }

private:
  vector <Protector*> army;

};

class Protector{
  friend ostream& operator<<(ostream& os, Protector& rhs){
    os << name;
    //What else is printed
    return os;
  }
public:
  Protector(const string& name, int strength) : name(name), strength(strength) {}
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
  bool alive(){
    return strength > 0;
  }
private:
  const string name;
  int strength;
  Noble* owner = nullptr;
protected:
  void setStrength(double& ratio){
    strength-=(strength*ratio);
  }
  int getStrength() const{
    return strength;
  }
  const Noble* getOwner() const {
    return owner;
  }

};
class Wizard : public Protector{
public:
  Wizard(const string& name, int strength) : Protector(name, strength) {}

private:

};
class Warrior : public Protector{
public:
  Warrior(const string& name, int strength) : Protector(name, strength) {}
private:

};

class Archer : public Warrior {
public:
  Archer(const string& name, int strength) : Warrior(name, strength) {} 
private:

};
class Swordsman : public Warrior {
public:
  Swordsman(const string& name, int strength) : Warrior(name, strength) {} 
private:

};

int main(){
  Lord sam("Sam");
  Archer samantha("Samantha", 200);
  sam.hires(samantha);
  Lord joe("Joe");
  PersonWithStrengthToFight randy("Randolf the Elder", 250); 	
  joe.battle(randy);	
  joe.battle(sam);	
  Lord janet("Janet");	
  Swordsman hardy("TuckTuckTheHardy", 100);
  Swordsman stout("TuckTuckTheStout", 80);
  janet.hires(hardy);	
  janet.hires(stout);	
  PersonWithStrengthToFight barclay("Barclay the Bold", 300);	
  janet.battle(barclay);	
  janet.hires(samantha);	
  Archer pethora("Pethora", 50);	
  Archer thora("Thorapleth", 60);
  Wizard merlin("Merlin", 150);
  janet.hires(pethora);
  janet.hires(thora);
  sam.hires(merlin);
  janet.battle(barclay);	
  sam.battle(barclay);	
  joe.battle(barclay);
}
