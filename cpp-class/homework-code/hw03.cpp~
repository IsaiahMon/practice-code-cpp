//Created by Isaiah Mon Desir. NetID: im1175
//HW02: Encapsulation, Data Hiding, Delegation, Operator Overloading

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Warrior{
  
  friend ostream& operator<<(ostream& os, const Warrior& rhs){
    os << rhs.name;
    return os;
  }
  //Weapon Class
  class Weapon{
    friend ostream& operator<<(ostream& os, const Weapon& rhs){
      os << rhs.name << ", " << rhs.strength;
      return os;
    }
  private:
    const string name; //Should the name of weapon be const?
    int strength;
    
  public:
    Weapon(const string& name, int strength) : name(name), strength(strength){
    }
    void changeStrength(int enemyStrength){
      //Lose strength based on enemy strength
      strength -= enemyStrength;
      if(strength < 0)
	strength = 0;
    }
    int strengthStatus() const {
      return strength;
    }
    bool alive() const {
      return (strength > 0);
    }
  };

private:
  const string name;
  Weapon weapon; //Weapon shouldnt be const
  
public:
  Warrior(const string& name, const string& weapName, int strength) : name(name), weapon(weapName, strength) {
  }

  const string getName() const{
    return name;
  }
  void changeStrength(int enemyStrength){
    weapon.changeStrength(enemyStrength);
  }
  int weapStrength() const{
    //Return either health or boolean for alive
    return weapon.strengthStatus();
  }
  bool weapAlive() const{
    return weapon.alive();
  }
  const Weapon& getWeapon() const {
    return weapon;
  }
  
};


void createWarrior(const string& name, const string& weapName, int strength, vector <Warrior>& v){
  //Add a warrior struct to vector
  Warrior w (name, weapName, strength);
  v.push_back(w);
}


int findWarrior(const string& name, const vector<Warrior>& v) {
  for(int i = 0; i < v.size(); i++){
    if(v[i].getName() == name){
      return i;
      break;
    }
  }
  return 0;
}


void battle(const string& name1, const string& name2, vector<Warrior>& v){
  //Find warrior in vector and get index
  int warrior1 = findWarrior(name1, v);
  int warrior2 = findWarrior(name2, v);
  
  //If search loop fails, at least one of the warrior indexes will
  //default as the first warrior. So assurance test should occur
  if(!(v[warrior1].getName() == name1)){
    cout << "There is no warrior: " << name1 << endl;
  }
  else if(!(v[warrior2].getName() == name2)){
    cout << "There is no warrior: " << name2 << endl;
  }

  else{ //If everything goes right
    cout << v[warrior1] << " battles " << v[warrior2] << endl;
    //Make sure they are alive
    if(v[warrior1].weapAlive() && v[warrior2].weapAlive()){
      int w1Strength_copy = v[warrior1].weapStrength();  //Copy of the first warrrior's weapon strength
      v[warrior1].changeStrength(v[warrior2].weapStrength());
      v[warrior2].changeStrength(w1Strength_copy);
      
      if(v[warrior1].weapStrength() > v[warrior2].weapStrength())
	cout << v[warrior1] << " defeats " << v[warrior2] << endl;
      else if(v[warrior1].weapStrength() <  v[warrior2].weapStrength())
	cout << v[warrior2] << " defeats " << v[warrior1] << endl;
      else
	cout << "Mututal Annihilation: " <<  v[warrior1]  << " and " << v[warrior2] << " die at each other's hands" << endl;
    }
    //Somebody is dead
    else if(!v[warrior1].weapAlive() && !v[warrior2].weapAlive())
      cout << "Oh, NO! They're both dead! Yuck!" << endl;
    else if(!v[warrior1].weapAlive())
      cout << "He's dead, " << v[warrior2] << endl;
    else if(!v[warrior2].weapAlive())
      cout << "He's dead, " << v[warrior1] << endl;
  }
}

void status(const vector <Warrior>& v){
  cout << "There are: " << v.size() << " warriors" << endl;
  
  for(const Warrior& warrior: v){
    cout << "Warrior: " << warrior  << ", weapon: " << warrior.getWeapon() << endl;
  }
}

int main(){
  
  ifstream ifs("warriors.txt");
  if(!ifs){
    cerr<<"Could not open " << "warriors.txt" << endl;
  }
  
  string command, name, name2, weapName;
  int strength;
  vector <Warrior> warriors;
  
  while(ifs >> command){ //Read first command to determine next course of action
    if(command == "Warrior"){ //Create Warrior
      ifs >> name >> weapName >> strength;
      createWarrior(name,weapName, strength, warriors);
    }
    else if(command == "Status"){ //Return Status of the Warriors
      status(warriors);
    }
    else if(command == "Battle"){ //Call to Warriors to Battle
      ifs >> name >> name2;
      battle(name,name2, warriors);
    }
    else{ //Contingency (i.e: Error in input file, etc.)
      cout << "Function: " << command << " not recognized" << endl;
    }
  }
}
