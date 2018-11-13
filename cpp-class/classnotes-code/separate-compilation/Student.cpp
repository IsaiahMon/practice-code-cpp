/*
  Name: Isaiah Mon DesirNetID: im1175
  rec07
  Student implimentation file rec07.cpp
*/

#include "Registrar.h"
#include "Course.h"
#include "Student.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;
namespace BrooklynPoly{
  class Course;
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
  void Student::setName(const string& newName) {
    name = newName;
  }
  
  void Student::addCourse(Course* coursePtr){
    courses.push_back(coursePtr);
  }
  bool Student::loseCourse(Course* coursePtr){
    for(size_t i =0; i < courses.size(); i++){
      if (courses[i] == coursePtr){
        coursePtr -> loseStudent(name);
	for(size_t j =i; j < courses.size()-1; j++){
	  courses[j] = courses[j+1];
	}
	courses.pop_back();
	return true;
      }
    }
    return false;
  }
}
