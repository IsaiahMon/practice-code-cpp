//Isaiah Mon Desir NetID: im1175
//Rec09: Intro to inheritance
#include <iostream>
#include <vector>
using namespace std;

class PrintedMaterial {
  // friend ostream& operator<<(ostream& os, PrintedMaterial rhs){
  //   os << rhs.numberOfPages;
  //   return os;
  // }
public:
  // PrintedMaterial(int numberOfPages) : numberOfPages(numberOfPages) {}
  PrintedMaterial(unsigned numPages) : numberOfPages(numPages) {} 
  // virtual void displayNumPages() const { cout << numberOfPages; }
  virtual void displayNumPages() const = 0;
protected:
private:
  unsigned numberOfPages; //Task 2 - This field goes everywhere because fields aren't inherited
  
};

void PrintedMaterial::displayNumPages() const { cout << numberOfPages; }

class Magazine : public PrintedMaterial {
public:
  Magazine(unsigned numPages) : PrintedMaterial(numPages) {}
  void displayNumPages() const {PrintedMaterial::displayNumPages(); }
protected:
  
private:
  // unsigned numberOfPages;
  
};

class Book : public PrintedMaterial {
public:
  Book(unsigned numPages) : PrintedMaterial(numPages) {}
  virtual void displayNumPages() const {PrintedMaterial::displayNumPages(); }
  
protected:
  
private:
  // unsigned numberOfPages;
  
};

class TextBook : public Book {
public:
  TextBook( unsigned numPages, unsigned numIndxPgs)
    : Book(numPages), numOfIndexPages(numIndxPgs) {}
  void displayNumPages() const
  {
    cout << numOfIndexPages << endl;
    // cout << numOfPages; //This wont work. numOfPages is PrintedMaterials field
    PrintedMaterial::displayNumPages(); cout << this << endl;
  }
protected:
  
private:
  unsigned numOfIndexPages;
  
};

class Novel : public Book {
public:
  Novel(unsigned numPages) : Book(numPages) {}
protected:
  
private:
  // unsigned numberOfPages;
  
};

void displayNumberOfPages(const PrintedMaterial& anyPM) {
  anyPM.displayNumPages();
}

// tester/modeler code
int main()
{
  TextBook t(5430, 234);
  Novel n(213);
  Magazine m(6);

  t.displayNumPages();
  n.displayNumPages();
  cout << endl;
  m.displayNumPages();

  cout << endl;
  
  //cout << "t: " <<  t << "\nn: "<< n << "\nm: " << m << endl;

  //PrintedMaterial pm = t; // like putting a t into a vector of PrintedMaterials
  // pm.displayNumPages();
  // cout << endl;

  // PrintedMaterial* pmPtr = &t; // like putting a t into a vector of PrintedMaterials
  // pmPtr -> displayNumPages();
  // cout << endl;

  vector <PrintedMaterial*> pmVect;
  pmVect.push_back(&t);
  pmVect.push_back(&n);
  pmVect.push_back(&m);
  //Test polymorphism
  for(size_t i = 0; i < pmVect.size(); ++i){
    pmVect[i] -> displayNumPages();
    displayNumberOfPages(*pmVect[i]);
  }

  
}
  
