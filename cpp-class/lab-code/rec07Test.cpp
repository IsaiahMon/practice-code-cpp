/*
  Name: Isaiah Mon DesirNetID: im1175
  rec07
  Used to test the Separate compilation of rec07.cpp
*/

#include "Registrar.h"
#include "Course.h"
#include "Student.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using namespace BrooklynPoly;

//put in namespace BrooklynPoly
class Student;
class Registrar;

class Course {
  friend ostream& operator<<(ostream& os, const Course& crs);
public:
  Course(const string& courseName);
  string getName() const;
  void addStudent(Student* studentPtr);
  void purge();
private:
  string name;
  vector<Student*> students;
};

class Student {
  friend ostream& operator<<(ostream& os, const Student& stu);
public:
  Student(const string& name);
  string getName() const;
  void addCourse(Course* coursePtr);
private:
  string name;
  vector<Course*> courses;
};

class Registrar {
  friend ostream& operator<<(ostream& os, const Registrar& rhs);
public:
  Registrar();
  bool addCourse(const string& courseName);
  bool addStudent(const string& studentName);
  bool enrollStudentInCourse(const string& studentName,
			     const string& courseName);
  bool cancelCourse(const string& courseName);
  void purge();

private:
  size_t findStudent(const string& studentName);
  size_t findCourse(const string& courseName);

  vector<Course*> courses;
  vector<Student*> students;
};

int main() {

  Registrar registrar;

  cout << "No courses or students added yet\n";
  cout << registrar << endl;
     
  cout << "AddCourse CS101.001\n";
  registrar.addCourse("CS101.001");
  cout << registrar << endl;

  cout << "AddStudent FritzTheCat\n";
  registrar.addStudent("FritzTheCat");
  cout << registrar << endl;

  cout << "AddCourse CS102.001\n";
  registrar.addCourse("CS102.001");
  cout << registrar << endl;
  
  cout << "EnrollStudentInCourse FritzTheCat CS102.001\n";
  registrar.enrollStudentInCourse("FritzTheCat", "CS102.001");
  cout << "EnrollStudentInCourse FritzTheCat CS101.001\n";
  registrar.enrollStudentInCourse("FritzTheCat", "CS101.001");
  cout << registrar << endl;

  cout << "EnrollStudentInCourse Bullwinkle CS101.001\n";
  cout <<  "Should fail, i.e. do nothing, since Bullwinkle is not a student.\n";
  registrar.enrollStudentInCourse("Bullwinkle", "CS101.001");
  cout << registrar << endl;

  cout << "CancelCourse CS102.001\n";
  registrar.cancelCourse("CS102.001");
  cout << registrar << endl;

  cout << "ChangeStudentName FritzTheCat MightyMouse\n";
  registrar.changeStudentName("FritzTheCat", "MightyMouse");
  cout << registrar << endl;  // or registrar.printReport()

  cout << "DropStudentFromCourse MightyMouse CS101.001\n";
  registrar.dropStudentFromCourse("MightyMouse", "CS101.001");
  cout << registrar << endl;  // or registrar.printReport()

  cout << "RemoveStudent FritzTheCat\n";
  registrar.removeStudent("FritzTheCat");
  cout << registrar << endl;  // or registrar.printReport()

  cout << "Purge for start of next semester\n";
  registrar.purge();
  cout << registrar << endl;
}

//Registrar qualified functions
ostream& operator<<(ostream& os, const Registrar& rhs){
  os << "COURSES: " <<endl;
  if(rhs.courses.size() ==0)
    os << "None" << endl;
  else
    for(Course* c: rhs.courses){
      os << *c <<endl;
    }
  os << "STUDENTS:" <<endl;
  if(rhs.students.size() == 0)
    os<< "None" << endl;
  else
    for(Student* s: rhs.students){
      os << *s << endl;
    }
  return os;
}
Registrar::Registrar(){

}
bool Registrar::addCourse(const string& courseName){
  if(findCourse(courseName) >  -1)
    return false;
  Course* c = new Course(courseName);//What does making a course do
  courses.push_back(c);
  return true;

}
bool Registrar::addStudent(const string& studentName){
  if(findStudent(studentName) > -1)
    return false;
  Student* s = new Student(studentName);
  students.push_back(s);
  return true;
}
bool Registrar::enrollStudentInCourse(const string& studentName,
				      const string& courseName){
  if(findStudent(studentName) == -1 || findCourse(courseName) == -1)
    return false;
  courses[findCourse(courseName)] -> addStudent(students[findStudent(studentName)]);
  return true;
}
bool Registrar::cancelCourse(const string& courseName){
  if(findCourse(courseName) == -1)
    return false;
  courses[findCourse(courseName)] -> purge();//What to do here
  for(size_t i = findCourse(courseName); i < courses.size(); i++){
    courses[i] = courses[i+1];
  }
  courses.pop_back();
  return true;
}
void Registrar::purge(){ //What does the purge method do?
  for(Course*& c: courses){
    c -> purge();
    c = nullptr;
    delete c;
  }
  courses.clear();
  for(Student*& s: students){
    s = nullptr;
    delete s;
  }
  students.clear();
  
}
size_t Registrar::findStudent(const string& studentName){
  for(size_t i = 0; i < students.size(); i++){
    if(students[i] -> getName() == studentName)
      return i;
  }
  return -1;
}
size_t Registrar::findCourse(const string& courseName){
  for(size_t i = 0; i < courses.size(); i++){
    if(courses[i] -> getName() == courseName)
      return i;
  }
  return -1;
}

//Student Qualified functions
ostream& operator<<(ostream& os, const Student& stu){
  os << stu.name << endl;
  return os;
}
Student::Student(const string& name) : name(name){
}
string Student::getName() const{
  return name;
}
void Student::addCourse(Course* coursePtr){
  courses.push_back(coursePtr);
}

//Course Qualified functions
ostream& operator<<(ostream& os, const Course& crs){
  //What prints with courses
  os << crs.name << ": " << endl;
  if(crs.students.size() == 0)
    os << "None" << endl;
  else
    for(Student* s: crs.students){
      os << *s << endl;} //Print each student
  return os;
}
Course::Course(const string& courseName) : name(courseName){
}
string Course::getName() const{
  return name;
}
void Course::addStudent(Student* studentPtr){
  students.push_back(studentPtr);
  studentPtr -> addCourse(this);
}
void Course::purge(){
  for(Student* s: students){
    s = nullptr;
  }
}
