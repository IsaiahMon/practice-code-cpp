//Created by Isaiah Mon Desir. NetID: im1175
//HW05: Separate Compilation
//Warrior header file

#ifndef WARRIOR_H
#define WARRIOR_H

#include "Noble.h"
#include <iostream>
#include <string>
#include <vector>

namespace WarriorCraft{
  //WARRIOR
  class Noble;
  class Warrior{
    friend std::ostream& operator<<(std::ostream& os, const Warrior& rhs);
  private:
    const std::string name; //Should the name of weapon be const?
    int strength;
    Noble* owner; //No owner by default
  public:
    Warrior(const std::string& name, int strength);

    bool setOwner(Noble* newOwner);
    bool runaway();
    bool loseOwner();
    void kill();
    void setStrength(double& ratio);
    int getStrength() const;
    const std::string getName() const;
    const Noble* getOwner() const;
  };
}
#endif
