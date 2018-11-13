//Created by Isaiah Mon Desir. NetID: im1175
//HW01: Functions, structs, vectors and file I/O

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Warrior{
  const string name;
  int strength;
  bool alive = true;

  Warrior(const string& name, int strength) : name(name), strength(strength) {
  }

  void changeStrength(int enemyStrength){
    strength-=enemyStrength;
    if(strength <=0){
      strength = 0;
      alive = false;
    }
  }
  
};

void createWarrior(const string& name, int strength, vector <Warrior>& v){
  //Add a warrior struct to vector
  Warrior w (name, strength);
  v.push_back(w);
}

int findWarrior(const string& name, const vector<Warrior>& v){
  for(int i = 0; i < v.size(); i++){
    if(v[i].name == name){
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
  if(!(v[warrior1].name == name1)){
    cout << "There is no warrior: " << name1 << endl;
  }
  else if(!(v[warrior2].name == name2)){
    cout << "There is no warrior: " << name2 << endl;
  }

  else{ //If everything goes right
    cout << name1 << " battles " << name2 << endl;
    //Make sure they are alive
    if(v[warrior1].alive && v[warrior2].alive > 0){
      int w1Strength_copy = v[warrior1].strength;  //Copy of the first warrrior strength
      v[warrior1].changeStrength(v[warrior2].strength);
      v[warrior2].changeStrength(w1Strength_copy);
      
      if(v[warrior1].strength > v[warrior2].strength)
	cout << name1 << " defeats " << name2 << endl;
      else if(v[warrior1].strength <  v[warrior2].strength)
	cout << name2 << " defeats " << name1 << endl;
      else
	cout << "Mututal Annihilation: " <<  name1  << " and " << name2 << " die at each other's hands" << endl;
    }
    //Somebody is dead
    else if(!v[warrior1].alive && !v[warrior2].alive)
      cout << "Oh, NO! They're both dead! Yuck!" << endl;
    else if(!v[warrior1].alive)
      cout << "He's dead, " << name2 << endl;
    else if(!v[warrior2].alive)
      cout << "He's dead, " << name1 << endl;
  }
}

void status(const vector <Warrior>& v) {
  cout << "There are: " << v.size() << " warriors" << endl;
  
  for(const Warrior& warrior: v){
    cout << "Warrior: " << warrior.name << ", strength: " << warrior.strength << endl; 
  }
}

int main(){
  
  ifstream ifs("warriors.txt");
  if(!ifs){
    cerr<<"Could not open " << "warriors.txt" << endl;
  }
  
  string command, name, name2;
  int strength;
  vector <Warrior> warriors;
  
  while(ifs >> command){ //Read first command to determine next course of action
    if(command == "Warrior"){ //Create Warrior
      ifs >> name >> strength;
      createWarrior(name,strength, warriors);
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
