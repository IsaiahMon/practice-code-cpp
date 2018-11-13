#include <iostream>
#inlcude <string>

using namespace std;

class Foo{
public:
  Foo(int x){int p = new int(x);}
  void display() const {cout << *p << endl;}
  void setValue(int val) { *p = val;}
  Foo(const Foo yetAnotherFoo){ //copy constructor initializes one thing from another thing of same type
    p = new int(*yetAnotherFoo.p);
  }

  ~Foo() {delete p;} //Destructor
  Foo& operator=(const Foo& rhs) {
    //Self assignment check
    //if(rhs != *this) //Bad because '!=' is not definied for Foo object unless written
    if(&rhs !=this){ 
      //1. Free up
      delete p;
      //2. Allocate
      // p = new int();
      //3. Copy
      //*p = *rhs.p;
      //4. Return left-hand side of chain
      p = new int(*rhs.p); //From copy constructor
    }
    return *this;
  }
private:
  int *p;
};

void doNothing(Foo someFoo){}

void simpleFunc(){
  Foo aFoo(17);
  aFoo.display;
  doNothing(aFoo);
  aFoo.display();
  Foo another(aFoo);
  
  Foo a(6);
  Foo b(28);
  a = b;
  //operator=(a,b); //c++ wont accept.
  a.operator=(b);
  
  //cout << aFoo << endl;
  //operator<<(cout, aFoo);
  
}

int main(){
  simpleFunc();

  Foo a(6); //Constructor
  Foo b(a); //Copy constructor

  a = b; //Assignment operator

  Foo c = a; //copy constructor 
  
}
