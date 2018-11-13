#include <iostream>
using namespace std;

class Vector{
private:
  size_t theSize;
  size_t theCapacity;
  int* data;

public:
  Vector() : theSize(0), theCapacity(0), data(new int[theCapacity]){}
  
  //To avoid a constructor being used implicitly, it should be 'marked explicit'
  explicit Vector(size_t count) : theSize(count), theCapacity(count), data(new int[theCapacity]){
    for(size_t i = 0; i < theSize; i++)
      data[i] = 0;
  }
  Vector(size_t count, int val) : theSize(count), theCapacity(count), data(new int[theCapacity]){
    for(size_t i = 0; i < theSize; i++)
      data[i] = val;
  }
  //Copy Control
  ~Vector(){
    delete[] data;
  }
  Vector(const Vector& rhs) : theSize(rhs.theSize), theCapacity(rhs.theCapacity), data(new int[theCapacity]){
    for(size_t i =0; i < theSize; i++){
      data[i] = rhs.data[i];
    }
  }
  
  Vector& operator=(const Vector& rhs){
    if(&rhs != this){
      //Free up
      delete[] data;
      //Allocate + Copy
      theSize = rhs.theSize;
      theCapacity = rhs.theCapacity;
      data = new int[theCapacity];
      for(size_t i =0; i < theSize; i++){
	data[i] = rhs.data[i];
      }
    }
    //Return yourself
    return *this;
  }
  
  void push_back(int val){
    if(theCapacity ==0){
      delete [] data;
      data = new int[1];
      theCapacity+=1;
    }
    else if(theSize == theCapacity){
      int* oldData = data;
      data = new int[theCapacity*2];
      for(size_t i = 0; i < theSize; i++){
	data[i] = oldData[i];
      }
      theCapacity*=2;
      delete[] oldData; //Free up an array of pointers(?)
    }
    data[theSize] = val;
    theSize+=1;
  }
  //
  size_t size() const{
    return theSize;
  }

  void clear(){
    theSize =0;
  }
  void pop_back(){
    if(theSize >0)
      theSize-=1;
  }

  //Square brackets?
  int& operator[](size_t index){ //Used as set operator to allow modification of data
    return data[index];
  }
  
  int operator[](size_t index) const{ //Used as get operator to allow retrieval of data
    return data[index];
  }

  int* begin() { return data; }
  int* end(){ return data + theSize; }//Data + theSize utilizes pointer arithmetic &p[k] = p+k
  const int* begin() const { return data; }
  const int* end() const { return data + theSize; }

};

void printVec(const Vector& v) {
   for(size_t i = 0; i < v.size(); i++){
     cout << v[i] << endl;
   }
}
void rangedPrintVec(const Vector& v) {
  for(int x: v){
    cout << x << endl;
  }
}

int main(){
  Vector v;
  v.push_back(14);
  v.push_back(42);
  v.push_back(6);
  v.push_back(28);

  for(size_t i = 0; i < v.size(); i++){
    cout << v[i] << endl;
  }
  v[2] = 100; //Possuble by allowing the [] operator to return data by reference
  //v = 10;


  //=========Translate Ranged-for to Regular for loop=================
  for(int x: v){ //Ranged for makes a COPY of each variable in 'v'
    cout << x << ' ';
  }
  
  for(int* p = v.begin(); p!= v.end(); p++){
    //cout << *p << ' ';
    int x = *p; //This makes a COPY
    cout << x << ' ';
  }
  //=================================================================
}
