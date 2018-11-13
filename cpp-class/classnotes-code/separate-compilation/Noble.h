//Created by Isaiah Mon Desir. NetID: im1175
//HW05: Separate Compilation
//Noble header file

#ifndef NOBLE_H
#define NOBLE_H

#include "Warrior.h"
#include <iostream>
#include <string>
#include <vector>

namespace WarriorCraft{
  class Warrior;
  class Noble{
    friend std::ostream& operator<<(std::ostream& os, const Noble& rhs);
  
  private:
    const std::string name;
    std::vector <Warrior*> army;
    int strength;
  
  public:
    Noble(std::string name);
    std::string getName() const;
    int findWarrior(Warrior& w, const std::vector<Warrior*>& army) const;
    bool alive() const;
    bool hire(Warrior& v);
    bool fire(Warrior& v);
    bool abandoned(Warrior& v);
    void removeWarrior(std::vector <Warrior*>& army, int index);

    void dies();

    void battle(Noble& challenger);
    void alterHealth(double& ratio);
    int getStrength() const;
    
  };
}
#endif
