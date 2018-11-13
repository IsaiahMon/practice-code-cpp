/*
  Name: Isaiah Mon Desir
  NetID: im1175
  Rec10: Inheritance
*/
#include <vector>
#include <iostream>
using namespace std;

class Instrument {
public:
  Instrument() {}
  virtual void makeSound() const = 0;
  virtual void play() const = 0;

private:
  
};
void Instrument::makeSound() const{ cout << "To make a sound...";}


//Brass Instrument
class Brass : public Instrument {
public:
  Brass(unsigned mouthPieceSize) : mouthPieceSize(mouthPieceSize) {}
  //Uniform for all brass in Part One
  void makeSound() const { cout << "To make a sound... blow on a mouthpiece of size "
				<< mouthPieceSize << endl;}
private:
  unsigned mouthPieceSize;
protected:
  unsigned getMouthPieceSize() const { return mouthPieceSize; }
};

//Trumpet
class Trumpet : public Brass {
public:
  Trumpet(unsigned mouthPieceSize) : Brass(mouthPieceSize) {}
  void play() const {cout << "Toot";}
private:
  
};

//Trombone
class Trombone : public Brass {
public:
  Trombone(unsigned mouthPieceSize) : Brass(mouthPieceSize) {}
  void play() const {cout << "Blat";}
private:
  
};

//Strings
class String : public Instrument {
public:
  String(unsigned pitch) : pitch(pitch) {}
  void makeSound() const { cout << "To make a sound... bow a string with pitch "
				<< pitch << endl;}
private:
  const unsigned pitch;
protected:
  unsigned getPitch() const { return pitch; }

};

//Cello
class Cello : public String {
public:
  Cello (unsigned pitch) : String(pitch) {}
  void play() const {cout << "Squawk";}
private:
  
};

//Violin
class Violin : public String {
public:
  Violin (unsigned pitch) : String(pitch) {}
  void play() const {cout << "Screech";}
private:
  
};

//Percussion
class Percussion : public Instrument {
public:
  Percussion() {} //Is the constructor needed? No data members
  void makeSound() const { cout << "To make a sound... hit me!\n";}
private:
  //No data members

};

//Drum
class Drum : public Percussion {
public:
  Drum() : Percussion() {} //Calling Percussion Constructor is done default
  void play() const {cout << "Boom";}
};

//Cymbal
class Cymbal : public Percussion {
public:
  Cymbal() : Percussion() {} //Calling Percussion Constructor is done default
  void play() const {cout << "Crash";}
};

//Musician
class Musician {
public:
  Musician() : instr(nullptr) {}

  void acceptInstr(Instrument* instPtr) { instr = instPtr; }

  Instrument* giveBackInstr() { 
    Instrument* result(instr); 
    instr = nullptr;
    return result;
  }

  void testPlay() const {
    if (instr) instr->makeSound(); 
    else cerr << "have no instr\n";
  }
  void play() const {
    if (instr) instr->play();
  }

private:
  Instrument* instr;
};

//MILL
class MILL{
public:
  MILL() {}
  bool receiveInstr(Instrument& instr) {
    //Test Instrument
    instr.makeSound();
    
    //Place instrument at first available place in inventory
    if(inventory.size() > 0)
      for(size_t i = 0; i < inventory.size(); ++i){
	if(!inventory[i]){
	  inventory[i] = &instr;
	  return true;
	}
      }
    //Only gets here if there was no space
    inventory.push_back(&instr);
    return true;
  }

  Instrument* loanOut(){
    Instrument* instrPtr = nullptr;
    //Go through inventory
    for(size_t i = 0; i < inventory.size(); ++i){
      //If any inventory has an instrument, loan it out, free the space with nullptr
      if(inventory[i]){
	instrPtr = inventory[i];
	inventory[i] = nullptr;
	break;
      }
    }
    return instrPtr;
  }
  void dailyTestPlay() const {
    for (Instrument* instr: inventory)
      if(instr) {instr->makeSound();}
  }

private:
  vector <Instrument*> inventory;

protected:
};

class Orch{
public:
  Orch() {}
  bool addPlayer(Musician& player){
    //Test if they are in already
    for(size_t i = 0; i < musicians.size(); ++i){
      if(musicians[i] == &player){
	cerr<< "This player is already in the orchestra\n";
	return false;
      }
    }
    musicians.push_back(&player);
    return true;
  }
  void play() const{
    for(Musician* musician: musicians)
      musician -> play();
    cout << endl;
  }
private:
  vector<Musician*>musicians;

};

// PART TWO
int main() {
    // The initialization phase

    Drum drum;
    Cello cello(673);
    Cymbal cymbal;
    Trombone tbone(4);
    Trumpet trpt(12);
    Violin violin(567);

    MILL mill;
    mill.receiveInstr(trpt);
    mill.receiveInstr(violin);
    mill.receiveInstr(tbone);
    mill.receiveInstr(drum);
    mill.receiveInstr(cello);
    mill.receiveInstr(cymbal);

    Musician bob;
    Musician sue;
    Musician mary;
    Musician ralph;
    Musician jody;
    Musician morgan;

    Orch orch;

    // THE SCENARIO

    //Bob joins the orchestra without an instrument.
    orch.addPlayer(bob);

    //The orchestra performs
    cout << "orch performs\n";
    orch.play();

    //Sue gets an instrument from the MIL2 and joins the orchestra.
    sue.acceptInstr(mill.loanOut());
    orch.addPlayer(sue);

    //Ralph gets an instrument from the MIL2.
    ralph.acceptInstr(mill.loanOut());

    //Mary gets an instrument from the MIL2 and joins the orchestra.
    mary.acceptInstr(mill.loanOut());
    orch.addPlayer(mary);

    //Ralph returns his instrument to the MIL2.
    mill.receiveInstr(*ralph.giveBackInstr());

    //Jody gets an instrument from the MIL2 and joins the orchestra.
    jody.acceptInstr(mill.loanOut());
    orch.addPlayer(jody);

    // morgan gets an instrument from the MIL2
    morgan.acceptInstr(mill.loanOut());

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    //Ralph joins the orchestra.
    orch.addPlayer(ralph);

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
	
    // bob gets an instrument from the MIL2
    bob.acceptInstr(mill.loanOut());

    // ralph gets an instrument from the MIL2
    ralph.acceptInstr(mill.loanOut());

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    //Morgan joins the orchestra.
    orch.addPlayer(morgan);

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

} // main

