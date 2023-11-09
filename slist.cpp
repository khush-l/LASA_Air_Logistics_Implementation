#include "slist.h"
#include <iostream>
#include <sstream>

/*
Class Library File
*/
class Airport {
public:
  char code[5];
  double longitude;
  double latitude;
};
// Constructor
LinkedList::LinkedList() {
  head = nullptr;
  length = 0;
}
// Destructor
LinkedList::~LinkedList() {
  clear(); 
}

void LinkedList::add(Airport *a) {
  insert(length, a);
} // Adds a new value to the end of this list.

void LinkedList::clear() {
  Node *temp = head;
  for (int i = 0; i < length; i++) {
    Node *prev = temp;
    temp = temp->pointer;
    delete prev;
  }
  head = nullptr;
  length = 0;
} // Removes all elements from this list.

bool LinkedList::equals(LinkedList* other) {
  if(length==other->size()){
    for(int i=0;i<length;i++) {
      if(other->get(i)!=get(i)){
        return false;
      }
    }
      return true;
    }
    return false;
  }
 // Returns true if the two lists contain the same elements in the same order.

Airport* LinkedList::get(int index) const {
  Node *current = head;
  for(int i =0;i<index;i++) {
    current=current->pointer;
  }
    return current->airport;
} // Returns the element at the specified index in this list.

void LinkedList::insert(int index, Airport *a) {
  Node *newNode = new Node();
  newNode->airport = a;
  if (index == 0) {
    newNode->pointer = head;
    head = newNode;
  } else {
    Node *current = head;
    Node *previous = nullptr;

    for (int i = 0; i < index && current != nullptr; i++) {
      previous = current;
      current = current->pointer;
    }
    if (previous) {
      previous->pointer = newNode;
    }
    newNode->pointer = current;
  }
  length++;
}

void LinkedList::exchg(int val1, int val2) {
  Airport* temp = get(val1);
  set(val1,get(val2));
  set(val2, temp);
} // Switches the payload data of specified indexex.

void LinkedList::swap(int index1, int index2) {
  Node *node1 = head;
  Node *prev1 = nullptr;
  for (int i=0;i<index1&&node1!=nullptr;++i) {
    prev1=node1;
    node1=node1->pointer;
  }
  Node* node2 = head;
  Node *prev2 = nullptr;

  for(int i=0;i<index2&&node2!=nullptr;++i) {
    prev2 = node2;
    node2 = node2->pointer;
  }
  if(prev1) {
    prev1->pointer=node2;
  }
  else{
    head=node2;
  }
  Node *temp = node1->pointer;
  node1->pointer=node2->pointer;
  node2->pointer=temp;
} // Swaps node located at index1 with node at index2

bool LinkedList::isEmpty() const {
  return !head;
} // Returns true if this list contains no elements.

void mapAll(string name)		{
}
void LinkedList::remove(int index) {
  Node* temp=head;
  Node* prev = nullptr;
  for(int i=0;i<index;i++) {
    prev=temp;
    temp=temp->pointer;
  }
  prev->pointer = temp ->pointer;
  delete temp;
  length--;
} // Removes the element at the specified index from this list.

void LinkedList::set(int index, Airport* a) {
  Node* current = head;
  for(int i=0;i<index;i++)
    {
      current=current->pointer;
    }
  current->airport = a;
} // Replaces the element at the specified index in this list with a new value.

int LinkedList::size() const {
  return length;
} // Returns the number of elements in this list.

// DO NOT IMPLEMENT >>> subList(start, length)	//Returns a new list containing
// elements from a sub-range of this list.

// DO NOT IMPLEMENT >>> toString()				//Converts the list to a
// printable string representation.