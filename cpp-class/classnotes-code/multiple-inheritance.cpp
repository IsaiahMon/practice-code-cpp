//Multiple Inheritance
#include <iostream>
#include <vector>
using namespace std;

/* 
   Flier is a 'Mixin' Class: Just a lightweight class added to a child 
   for classes with multiple behaviors.
   I.e. Bat is an Animal and Flier
 */
class Flier {
public:
  virtual void display() { cout << "I can fly!!!\n";}

};
class Animal {
public:
  virtual void display() { cout << "Animal\n";}
};

class Bat : public Animal, public Flier {};

class Insect : public Animal, public Flier {
public:
  void fly { cout << "Bzzzz. "; Flier::fly();}
};

class Plane : public Flier {};

//=============================================//
/*
~ Diamond Inheritance~
    Person
    /    \
Student Instructor
      \ /
      TA
*/
class Person {
public:
  Person(const string& name) : name(name) {}
  virtual void display() const { cout << "Person\n";}
private:
  string name;
};


/*
  Marking inheritance as 'virtual' means that 

*/
class Student : public virtual Person {
public:
  Student(const string& name) : Person(name) {}
  virtual void display() const { cout << "Student\n";}
private:
  //string name;
};

class Instructor : public virtual Person {
public:
  Instructor(const string& name) : Person(name) {}
  virtual void display() const { cout << "Instructor\n";}
private:
  //string name;
};

class TA : public Student, public Instructor {
public:
  /*
    Two copies of the same information in different classes:
    -Is a waste of space
    -Requires consistency when changing data in both classes
    Just dont do it.
  */

  //Make both parent classes inherit their parent publicly virtual (in their classes)
  TA(const string& name) : Person(name), Student(name), Instructor(name){
    /*
      Creates a Person object with name 'name,'
      then Student and Instructor names POINT to the name stored
      in Person
    */
  }
  // using Student::display;
  // using Instructor::display;
  // void display(){
  //   Student::display();
  // }
  void display(){
    //Some code before
    Student::display();
    //Some code in between
    Instructor::display();
    //Some code after
  }

};

int main(){

  TA rohit("Rohit");
  //rohit.display; //Error, ambiguous
  //rohit.Student::display();
  rohit.display();
