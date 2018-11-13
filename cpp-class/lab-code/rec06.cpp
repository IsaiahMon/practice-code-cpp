//Isaiah Mon Desir NetID: im1175
//Recitation 6: Dynamic Arrays and Copy Control

#include <string>
#include <iostream>
using namespace std;

class Position {
  friend ostream& operator<<(ostream& os, const Position& rhs) {
    os << '[' << rhs.title << ',' << rhs.salary << ']';
    return os;
  }
public:
  Position(const string& aTitle, double aSalary)
    : title(aTitle), salary(aSalary) {}
  const string& getTitle() const { return title; }
  double getSalary() const { return salary; }
  void changeSalaryTo(double d) { salary = d; }
private:
  string title;
  double salary;
}; // class Position

class Entry {
  friend ostream& operator<<(ostream& os, const Entry& rhs) {
    os << rhs.name << ' ' << rhs.room
       << ' ' << rhs.phone << ", " << *rhs.pos;
    return os;
  }
public:
  Entry(const string& name, unsigned room, unsigned phone, Position& position)
    : name(name), room(room), phone(phone), pos(&position) {
  }
  const string& getName() const { return name; }
  unsigned getPhone() const { return phone; }
private:
  string name;
  unsigned room;
  unsigned phone;
  Position* pos;
}; // class Entry

class Directory {
  // Overload output operator
  friend ostream& operator<<(ostream& os, const Directory& rhs) {
    os << "This directory has " << rhs.size << " entries: " <<endl;
    for(size_t i = 0; i < rhs.size; i++){
      os << *rhs.entries[i] << endl;;
    }
    return os;
  }
public:
  Directory(): size(0), capacity(1), entries(new Entry*[capacity]) {//How do i make this *
  }
  Directory(const Directory& rhs) //Copy Constructor
    :size(rhs.size), capacity(rhs.capacity), entries(new Entry*[capacity]){//How do i make this *

    cout << "Copy Constructing" << endl;
    for(size_t i = 0; i < size; i++){
      entries[i] =  new Entry(*rhs.entries[i]);
    }
  }
  ~Directory(){ //Destructor
    cout << "Destructing" << endl;
    for(size_t i =0; i < size; i++){
      delete entries[i];
    }
    delete[] entries;
  }
      
  Directory& operator=(const Directory& rhs) {//Assignment operator
    cout << "Assignment Operator" << endl;
    if(&rhs != this){
      for(size_t i =0; i < size; i++){
	delete entries[i];
      }
      delete[]entries;
      entries = new Entry*[rhs.capacity];
      size = rhs.size;
      capacity = rhs.capacity;
      for(size_t i = 0; i < size; i++){
	entries[i] = new Entry(*rhs.entries[i]);
      }
    }
    return *this;
  }
  
  unsigned operator[](const string& rhs) const{//Find person number from Name (dont modify)
    unsigned fail = 0;
    for(size_t i = 0; i < size; i++){
      if(entries[i] -> getName() == rhs)
	return entries[i] -> getPhone();
    }
    return fail; //What happens when the search fails?
  }
  void add(const string& name, unsigned room, unsigned ph, Position& pos) {
    if (size == capacity) {
      Entry** oldEntries = entries; //Copy old dynamic array
      entries = new Entry*[capacity*2]; //Make original dynamic array with new size?
      //Change the capacity
      for(size_t i = 0; i < size; i++){
	entries[i] = oldEntries[i];
      }
      capacity*=2;
      delete[] oldEntries;
    }
    entries[size] = new Entry(name, room, ph, pos);
    ++size;
  }

private:	
  size_t size;
  size_t capacity;
  Entry** entries;
}; // class Directory

void doNothing(Directory dir) { cout << dir << endl; }

int main() {
	
  // Note that the Postion objects are NOT on the heap.
  Position boss("Boss", 3141.59);
  Position pointyHair("Pointy Hair", 271.83);
  Position techie("Techie", 14142.13);
  Position peon("Peonissimo", 34.79);
	
  // Create a Directory
  Directory d;
  d.add("Marilyn", 123, 4567, boss);
  cout << d << endl;

  Directory d2 = d;	// What function is being used??
  d2.add("Gallagher", 111, 2222, techie);
  d2.add("Carmack", 314, 1592, techie);
  cout << d << endl;

  cout << "Calling doNothing\n";
  doNothing(d2);
  cout << "Back from doNothing\n";

  Directory d3;
  d3 = d2;
  cout << d3 << endl;

  // Should display 1592
  cout << d2["Carmack"] << endl;
	
} // main
