/*
  Header File of Princess
  Contains prototypes for the Princess class
*/

#ifndef PRINCESS_H //If PRINCESS_H isn't defined
#define PRINCESS_H //Define it

#include <string>
#include <iostream>

//using namespce std;
//Dont use 'using namespace std;' in header.
//Use 'std::' for each type that would need it

namespace Fantasy {//Create namespace fantasy
  
  class FrogPrince; //Forward declare frog prince to avoid infinite cyclic references. Must be inside

  class Princess {
  public:
    Princess(const std::string& name);
    void display() const;
    void marries(FrogPrince& betrothed);
  
  private:
    std::string name;
    FrogPrince* spouse;
  };

}

#endif //End
