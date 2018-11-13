/*
  Name: Isaiah Mon DesirNetID: im1175
  rec07
  Student header file rec07.cpp
*/

#ifndef STUDENT_H
#define STUDENT_H

#include "Course.h"
#include <string>
#include <iostream>
#include <vector>

namespace BrooklynPoly{
  class Student {
    friend std::ostream& operator<<(std::ostream& os, const Student& stu);
  public:
    Student(const std::string& name);
    std::string getName() const;
    void setName(const std::string& newName);
    void addCourse(Course* coursePtr);
    bool loseCourse(Course* coursePtr);
  private:
    std::string name;
    std::vector<Course*> courses;
  };
}

#endif
