happy#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

struct Molecule{
  vector <string> names; //vector of all names 
  int carbons; //number of carbons
  int hydrogens; //number of hydrogents
};

ifstream fileStream(){
  ifstream ifs;
  string fileName;

  cout << "What file will be read" << endl;
  cin >> fileName;
  ifs.open(fileName);

  while(!ifs){
    cerr<< "File could not be opened try again" << endl;
    cin >> fileName;
    ifs.clear();
    ifs.open(fileName);
  }
  return ifs;
}

void listMolecules (ifstream& ifs, vector<Molecule>& molecules){
  string moleculeName;
  char carb, hydro;
  int carbNum,hydroNum;

  while(ifs >> moleculeName >> carb >> carbNum >> hydro >> hydroNum){ //Read all the molecule info
     Molecule mol; //Create molecule
     bool exists = false;

     for(Molecule& mol: molecules){ //Test if there is another molecule  with the same carbHydro number
       if((mol.carbons == carbNum) && (mol.hydrogens == hydroNum)){ //If so, add this name to the vector for that mol
	 mol.names.push_back(moleculeName);
	 exists = true;
	 break;
       }
     }

     if(!exists){
       //else, create a new molecule
       mol.names.push_back(moleculeName);
       mol.carbons = carbNum;
       mol.hydrogens = hydroNum;
       molecules.push_back(mol);
     }
  }
}

void sortList(vector <molecules>& molecules){
 //Sort the list at the end
  for(int i = 0; i < molecules.size(); ++i){
    bool done = true;
    Molecule tempMol, tempMol2;
    for(int j = 0; j < molecules.size()-1-i; ++j){
      if(molecules[j].carbons > molecules[j+1].carbons){
	tempMol = molecules[j];
	tempMol2 = molecules[j+1];
	molecules[j+1] = tempMol;
	molecules[j] = tempMol2;
	done = false;
      }
      else if(molecules[j].carbons ==  molecules[j+1].carbons){
	if(molecules[j].hydrogens > molecules[j+1].hydrogens){
	  tempMol = molecules[j];
	  tempMol2 = molecules[j+1];
	  molecules[j+1] = tempMol;
	  molecules[j] = tempMol2;
	  done = false;
	}
      }
    }
    if(done){
      i = molecules.size();
    }
  }
}

void display(const vector<Molecule>& molecules){
  //Print molecule
  cout<<"Sorted List" <<endl;
  for(const Molecule& m: molecules){
    cout << "C" << m.carbons << "H" << m.hydrogens << ' ';
    for(const string& name: m.names){
      cout << name << ' ';
    }
    cout << endl;
  }
}

int main (){
  vector <Molecule> molecules; //Collection of all molecules

  ifstream ifs = fileStream();

  listMolecules(ifs, molecules);

  sortList(molecules);

  display(molecules);
}
