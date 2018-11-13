/*
  Name: Isaiah Mon Desir NetID: im1175
  Recitation 8: Operator Overloading
*/
#include <iostream>
using namespace std;

class Rational{
  friend ostream& operator<<(ostream& os, const Rational& rhs){
    os << rhs.numerator << "/" << rhs.denominator << endl;
    return os;
  }
  friend istream& operator>>(istream& instream, Rational& lhs){
    char slash;
    instream >> lhs.numerator >>slash  >> lhs.denominator;
    lhs.normalize();
    return instream;
  }
  friend Rational& operator++(Rational& lhs){ //Pre
    lhs.numerator+=lhs.denominator;
    //Normalize
    lhs.normalize();
    return lhs;
  }
  friend Rational operator++(Rational& lhs, int){ //Post
    Rational result(lhs);
    lhs.numerator+=lhs.denominator;

    //Normalize
    lhs.normalize();
    return result;
  }
  friend bool operator==(Rational& lhs, Rational& rhs){
    return(lhs.numerator == rhs.numerator && lhs.denominator == rhs.denominator);
  }
  friend bool operator<(Rational& lhs, Rational& rhs){
    int gcd = lhs.greatestCommonDivisor(rhs.denominator, lhs.denominator);
    return (lhs*gcd < rhs*gcd);
  }

private:
  int numerator, denominator;
  
public:
  Rational(){}
  Rational(int numerator, int denominator = 1) : numerator(numerator) , denominator(denominator) {
    //Normalize number
    normalize();
  }
  Rational(const Rational& rhs) : numerator(rhs.numerator), denominator(rhs.denominator){}
  
  int greatestCommonDivisor(int x, int y) {
    while (y != 0) {
      int temp = x % y;
      x = y;
      y = temp;
    }
    return x;
  }
  void normalize(){ //Not used, here for reference
    int gcd = greatestCommonDivisor(numerator, denominator);
    if(gcd > 1 && (numerator/gcd != 0) && (denominator/ gcd != 0) ){
      numerator/= gcd;
      denominator/= gcd;
    }
  }
  
  Rational& operator+=(Rational& rhs){
    //Make the fractions same denominator
    if(denominator != rhs.denominator){
      numerator*=rhs.denominator;
      denominator*=rhs.denominator;}
    //Add them together
    numerator+=(rhs.numerator);
    
    //Normalize
    normalize();
    return *this;
  }
  operator bool(){
    return (numerator != 0);
  }
};

Rational operator+(Rational& lhs, Rational& rhs){
  Rational result(lhs);
  result+=rhs;
  return result;
}
Rational& operator--(Rational& lhs){//Pre
  Rational neg(-1/1);
  lhs+=neg;
  return lhs;
}
Rational operator--(Rational& lhs, int){//Post
  Rational original(lhs);
  //Do something
  Rational neg(-1/1);
  lhs+=neg;
  return original;
}

bool operator!=(Rational& lhs,  Rational& rhs){
  return !(lhs == rhs);
}
bool operator<=(Rational& lhs,  Rational& rhs){
  return (lhs == rhs || lhs < rhs);
}
bool operator>=(Rational& lhs, Rational& rhs){
  return (lhs == rhs || lhs > rhs);
}
bool operator>(Rational& lhs, Rational& rhs){
  return (lhs != rhs && !(lhs < rhs));
}
// int greatestCommonDivisor(int x, int y) {
//   while (y != 0) {
//     int temp = x % y;
//     x = y;
//     y = temp;
//   }
//   return x;
// }

int main() {
  Rational twoThirds(2,3);
  cout << twoThirds << endl;
    
  Rational a, b;
  cout << "Input two rational numbers.\n";
  cout << "a: ";
  cin >> a;
  cout << "b: ";
  cin >> b;
  Rational one(1);

  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  cout << "one = " << one << endl;
  cout << "a += b: " << (a += b) << endl;	// Implement as member
  cout << "a = " << a << endl;
    
  // Implement as non-member, but not a friend
  cout << "a + one: " << (a + one) << endl;
  cout << "a == one: " << boolalpha << (a == one) << endl;
    
  // How does this manage to work?
  // It does NOT require writing another == operator. 
  cout << "1 == one: " << boolalpha << (1 == one) << endl;
    
  // Do not implement as friend.
  cout << "a != one: " << boolalpha << (a != one) << endl;

  cout << "a = " << a << endl;
  cout << "++a = " << (++a) << endl;
  cout << "a = " << a << endl;
  cout << "a++ = " << (a++) << endl;
  cout << "a = " << a << endl;
  cout << "--a = " << (--a) << endl;
  cout << "a = " << a << endl;
  cout << "a-- = " << (a--) << endl;
  cout << "a = " << a << endl;

  cout << "++ ++a = " << (++ ++a) << endl;
  cout << "a = " << a << endl;
  cout << "-- --a = " << (-- --a) << endl;
  cout << "a = " << a << endl;

  cout << "a < one: " << (a < one) << endl;
  cout << "a > one: " << (a > one) << endl;
  cout << "a <= one: " << (a <= one) << endl;
  cout << "a >= one: " << (a >=one) << endl;
  cout << "a = " << a << endl;

  // cout << "a++ ++ = " << (a++ ++) << endl;
  // cout << "a = " << a << endl;

  // Even though the above example, (a++ ++), compiled, the
  // following shouldn't.
  // But some compiler vendors might let it...  Is your compiler
  // doing the right thing?
  // cout << "a-- -- = " << (a-- --) << endl;
  // cout << "a = " << a << endl;


  if (Rational(1)) {
    cout << "1 is true" << endl;
  } else {
    cout << "1 is false" << endl;
  } 
  if (Rational(0)) {
    cout << "0 is true" << endl;
  } else {
    cout << "0 is false" << endl;
  } 
}

