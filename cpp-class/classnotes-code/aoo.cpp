/*
Lecture 14
Arithmetic Op Overloading
*/

using namespace std;

class Complex{
  friend ostream& operator <<(ostream& os, const Complex& rhs) {
    os << rhs.real;
    if(rhs.imaginary >= 0) os << '+';
    os << rhs.imaginary << 'i';
    return os;
  }
public:
  Complex(): real(0), imaginary(0) {}
  Complex(double real) : real(real), imaginary(0) {}
  Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}

  
  // c1 += c2;
  // c1.operator+=(c2);
  Complex& operator+=(const Complex& rhs) {
    real += rhs.real;
    imaginary+= rhs.imaginary;
    return *this;
  }

  // ++c1;
  // c1.operator++();
  Complex& operator++() {
    real ++;
    return *this;
  }
  // c1++;
  // c1.operator++(0);
  Complex operator++(int) {
    Complex original(*this);
    real++;
    return original;
  }
  
  operator bool() const { 
    return real != 0 || imaginary !=0;
  }

private:
  double real, imaginary;
};

//Complex& operator+(const Complex& lhs, Complex& rhs){ //Wrong
//^^Don't return a reference or pointer to a local
Complex operator+(const Complex& lhs, Complex& rhs){ 
  Complex result = lhs;
  return result+=rhs;
}

int main(){
  Complex c1; //0+0i
  Complex c2(17); //17+0i
  Complex c3(3, -5); //3-5i
  cout << "c1: " << c1 <<endl
       << "c2: " << c2 << endl
       << "c3: " << c3 << endl;

  //+ operator
  c1 = c2 + c3;
  c2.operator+(c3);
  //c3.operator+(c2); //Wrong
  operator+(c2,c3);

  //+= Operator
  c1 += c2;
  c1.operator+=(c2);
  //operator+=(c1, c2);

  //++ Operator
  ++c1;  //Pre-incriment
  c1.operator++();
 
  c1++;  //Post-incriment
  c1.operator++(0);
 
  
}
//Operators cant be overloaded what operands are primatives
