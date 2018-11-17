#include <iostream>
#include <vector>

using namespace std;
/*
  Name: Isaiah Mon Desir
  NetID: im1175
  Recitation 11: Linked List Basics
*/

// Node to be used a part of linked list
struct Node {
	Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
	int data;
	Node* next;
};

// listInsertHead: adds a data item to the beginning of a [possibly empty] list
void listInsertHead(Node*& headPtr, int entry) {
	headPtr = new Node(entry, headPtr);
}

// listClear: frees up all the nodes in a list
void listClear(Node*& headPtr) {
    while (headPtr) {
        Node* next = headPtr->next;
        delete headPtr;
        headPtr = next;
    }
}

// listBuild: constructs a list from a vector of data items. Note that
// you can use a curly-braced sequence.
// This may be useful for setting up test cases. Feel free to use it
// or not as you like. 
// Example of using would be:
//    Node* myList = listBuild({1, 4, 9, 16}); // builds a list of: 1 4 9 16
Node* listBuild(const vector<int>& vals) {
    Node* result = nullptr;
    for (size_t index = vals.size(); index > 0; --index) {
        listInsertHead(result, vals[index-1]);
    }
    return result;
}

void splice(Node* list, Node* location){
  if (list != nullptr && location != nullptr){
    Node* spliceListHead = list;
    while(list->next)
       list = list->next;
    list->next = location->next;
    location->next = spliceListHead;
  }
  //Set the last node in the splice-in list to location->next
  //Set first node in splice as location->next
}

Node* isSublist(Node* subList, Node* searchList){
  if(subList == nullptr || searchList == nullptr)
    return nullptr;
  Node* subListHead = subList;
  Node* start = nullptr;
  while(searchList && subList){
    //If this part of the list is the same as the head of the subList
    if (searchList->data == subListHead->data){
      //Set this as the start index pointer
      start = searchList;
      //Incriment values
      searchList = searchList-> next;
      subList = subList -> next;
      //subLoop for testing
      while(searchList && subList){
	//If next val in searchList is next val in subList
	if(searchList->data == subList->data){
	  //Incriment and keep searching
	  searchList = searchList-> next;
	  subList = subList -> next;
	  //If subList reaches it's end return the start
	  if(subList == nullptr)
	    return start;
	}
	//Otherwise set subList back to its original value and break the loop
	else if(searchList->data != subList->data){
	  subList = subListHead;
	  break;
	}
      }
      return start;
    }
    //If the next in the search doesn't exist, there is no reason to search
    else if(searchList-> next == nullptr)
      return nullptr;
    //If it does exist, just incriment
    else{
      searchList = searchList->next;
      subList = subList -> next;
    }
  }
  //If we reach here it means we've failed, return nullptr
  return nullptr;
}

void printList(Node* list){
  while(list){
    cout << list->data << " ";
    list = list->next;
  }
  cout << endl;
}
int main(){

  cout << "Task One" << endl;
  vector<int> list1;
  list1.push_back(7);
  list1.push_back(9);
  list1.push_back(1);

  vector<int> list2;
  list2.push_back(6);
  list2.push_back(3);
  list2.push_back(2);
  
  Node* myList = listBuild(list1);
  
  Node* spliceList = listBuild(list2);
  
  Node* head = new Node(5);
  head->next = myList;

  cout<< "L1: ";
  printList(head);
  cout<< "L2: ";
  printList(spliceList);
  cout << "Target: ";
  printList(myList);
  cout<<"Splicing L2 at target in L1\n";
  splice(spliceList, myList);
  cout<< "L1: ";
  printList(head);
  cout<< "L2: ";
  printList(spliceList);

  cout << "======================\n\nPart Two" << endl;

  vector<int> list3;
  list3.push_back(1);
  list3.push_back(2);
  list3.push_back(3);
  list3.push_back(2);
  list3.push_back(3);
  list3.push_back(2);
  list3.push_back(4);
  list3.push_back(5);
  list3.push_back(6);

  vector<int> sub1;
  sub1.push_back(1);

  vector<int> sub2;
  sub2.push_back(3);
  sub2.push_back(9);

  vector<int> sub3;
  sub3.push_back(2);
  sub3.push_back(9);

  vector<int> sub4;
  sub4.push_back(2);
  sub4.push_back(4);
  sub4.push_back(5);
  sub4.push_back(6);

  vector<int> sub5;
  sub5.push_back(2);
  sub5.push_back(3);
  sub5.push_back(2);
  sub5.push_back(4);

  vector<int> sub6;
  sub6.push_back(5);
  sub6.push_back(6);
  sub6.push_back(7);

  Node* target = listBuild(list3);
  Node* subOne = listBuild(sub1);
  Node* subTwo = listBuild(sub2);
  Node* subThree = listBuild(sub3);
  Node* subFour = listBuild(sub4);
  Node* subFive = listBuild(sub5);
  Node* subSix = listBuild(sub6);

  cout<<"Target: ";
  printList(target);

  cout<<"Attempt match: ";
  printList(subOne);
  if(isSublist(subOne, target))
    printList(isSublist(subOne, target));
  else
    cout << "Failed to match\n";
  
  cout<<"Attempt match: ";
  printList(subTwo);
  if(isSublist(subTwo, target))
    printList(isSublist(subTwo, target));
  else
    cout << "Failed to match\n";

  cout<<"Attempt match: ";
  printList(subThree);
  if(isSublist(subThree, target))
    printList(isSublist(subThree, target));
  else
    cout << "Failed to match\n";

  cout<<"Attempt match: ";
  printList(subFour);
  if(isSublist(subFour, target))
    printList(isSublist(subFour, target));
  else
    cout << "Failed to match\n";

  cout<<"Attempt match: ";
  printList(subFive);
  if(isSublist(subFive, target))
    printList(isSublist(subFive, target));
  else
    cout << "Failed to match\n";

  cout<<"Attempt match: ";
  printList(subSix);
  if(isSublist(subSix, target))
    printList(isSublist(subSix, target));
  else
    cout << "Failed to match\n";
}
