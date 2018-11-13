/*
  Name: Isaiah Mon DesirNetID: im1175
  rec07
  Registrar implementation file rec07.cpp
*/

#include "Registrar.h"
#include "Course.h"
#include "Student.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

namespace BrooklynPoly{
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
    if(findCourse(courseName) >  students.size())
      return false;
    Course* c = new Course(courseName);//What does making a course do
    courses.push_back(c);
    return true;

  }
  bool Registrar::addStudent(const string& studentName){
    if(findStudent(studentName) > students.size())
      return false;
    Student* s = new Student(studentName);
    students.push_back(s);
    return true;
  }
  bool Registrar::enrollStudentInCourse(const string& studentName,
					const string& courseName){
    if(findStudent(studentName) == students.size() || findCourse(courseName) == students.size())
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
    return students.size();
  }
  size_t Registrar::findCourse(const string& courseName){
    for(size_t i = 0; i < courses.size(); i++){
      if(courses[i] -> getName() == courseName)
	return i;
    }
    return students.size();
  }
  bool Registrar::changeStudentName(const string& studentName,
				    const string& newName){
    if(findStudent(newName) > students.size() || findStudent(studentName) == students.size())
      return false;
    students[findStudent(studentName)] -> setName(newName);
    return true;
    
  }
  bool Registrar::dropStudentFromCourse(const string& studentName,
				    const string& courseName){
    if(findStudent(studentName) == students.size() || findCourse(courseName) == students.size())
      return false;
    students[findStudent(studentName)] -> loseCourse(courses[findCourse(courseName)]);
    return true;
    
  }
  bool Registrar::removeStudent(const string& studentName){
    if(findStudent(studentName) == students.size())
      return false;
    for(Course* c: courses){
      students[findStudent(studentName)] -> loseCourse(c);
    }
    for(size_t i = findStudent(studentName); i < students.size(); i++){
      students[i] = students[i+1];
    }
    students.pop_back();
    return true;
  }

}
