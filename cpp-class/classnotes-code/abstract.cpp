#include <iostream>
using namespace std;

class Shape {//Abstract class
public:
  Shape(int x, int y) : x(x), y(y) {}
  void move(int x, int y) { this->x = x; this->y = y;}
  virtual void draw() = 0;
  /*
    ABSTRACT METHODS
    virtual func(x) = 0 means the function is pure virtual/ abstract
    If any child function doesn't have a matching draw function
    there will be a compilation error.
  */
  //void commonDrawCode(){ cout << " Common Draw Code\n";}
private:
  int x,y;
};

void Shape::draw(){cout << " Common Draw Code\n";}
/*
  A method can still be pure virtual if function 
  is qualified on the outside of the class
*/

class Triangle : public Shape {
public:
  Triangle(int x, int y) : Shape(x,y){}
  void draw() {
    Shape::draw(); //Uses qualified implimentation of Shape::draw()
    cout << "Triangle Drawing. " <<endl;
  }

};


class IsoscelesTriangle : public Triangle {
public:
  using Triangle::Triangle;
  // void draw() {
  //   cout << "Triangle Drawing. " <<endl;
  // }
  /*
    Implementation of an abstract method is not 
    required if the current class is a child of 
    a child of the abstract class.
  */

};

//WILL CAUSE AN ERROR BECAUSE IT DOESN'T HAVE DRAW METHOD
// class Circle : public Shape {
// public:
//   Circle(int x, int y) : Shape(x,y){}
// };

class Circle : public Shape {
public:
  Circle(int x, int y) : Shape(x,y){}
  void draw() {
    cout << "Triangle Drawing. " <<endl;
  }
};

int main(){
  Triangle t(3,4);
  t.draw();
  Circle t(2,3);
  c.draw();
}
