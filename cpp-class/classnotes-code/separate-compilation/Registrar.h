/*
  Name: Isaiah Mon DesirNetID: im1175
  rec07
  Registrar header file rec07.cpp
*/

#ifndef REGISTRAR_H
#define REGISTRAR_H

#include "Student.h"
#include "Course.h"
#include <vector>
#include <string>
#include <iostream>

namespace BrooklynPoly{
  class Registrar {
    friend std::ostream& operator<<(std::ostream& os, const Registrar& rhs);
  public:
    Registrar();
    bool addCourse(const std::string& courseName);
    bool addStudent(const std::string& studentName);
    bool enrollStudentInCourse(const std::string& studentName,
			       const std::string& courseName);
    bool cancelCourse(const std::string& courseName);
    void purge();
    bool changeStudentName(const std::string& studentName,
			   const std::string& newName);
    bool dropStudentFromCourse(const std::string& studentName,
			   const std::string& courseName);
    bool removeStudent(const std::string& studentName);

  private:
    size_t findStudent(const std::string& studentName);
    size_t findCourse(const std::string& courseName);

    std::vector<Course*> courses;
    std::vector<Student*> students;
  };
}

#endif
