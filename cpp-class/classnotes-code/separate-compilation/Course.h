/*
  Name: Isaiah Mon DesirNetID: im1175
  rec07
  Course header file rec07.cpp
*/

#ifndef COURSE_H
#define COURSE_H
#include "Student.h"
#include <iostream>
#include <string>
#include <vector>

namespace BrooklynPoly{
  class Student;
  
  class Course {
    friend std::ostream& operator<<(std::ostream& os, const Course& crs);
  public:
    Course(const std::string& courseName);
    std::string getName() const;
    void addStudent(Student* studentPtr);
    void loseStudent(const std::string& studentPtr);
    void purge();
  private:
    std::string name;
    std::vector<Student*> students;
  };
}
#endif
