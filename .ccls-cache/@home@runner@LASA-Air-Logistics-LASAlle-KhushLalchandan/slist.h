/*

Header file for single linked list class library

*/
#ifndef SLIST_H
#define SLIST_H

#include <string>
using namespace std;

class Airport;

struct Node {
  Airport *airport;
  Node *pointer;
};

class LinkedList {
private:
  Node *head;
  int length;

public:
  LinkedList();

  ~LinkedList();

  void add(Airport *a); // Adds a new value to the end of this list.

  void clear(); // Removes all elements from this list.

  bool equals(LinkedList *other); // Returns true if the two lists contain the same elements in the same order.

  Airport *get(int index) const; // Returns the element at the specified index in this list.

  void insert(int index, Airport *a); // Inserts the element into this list before
                                   // the specified index.

  void exchg(int index1, int index2); // Switches the payload data of specified indexex.

  void swap(int index1, int index2); // Swaps node located at index1 with node at index2

  bool isEmpty() const; // Returns true if this list contains no elements.

  void mapAll(string function)		;		//Calls the specified function on each
  // element of the linkedlist in ascending index order.

  void remove(int index); // Removes the element at the specified index from this list.

  void set(int index, Airport *a); // Replaces the element at the specified index
                                // in this list with a new value.
  int size() const;
};
// Returns the number of elements in this list.

// subList(start, length)	//Returns a new list containing elements from a
// sub-range of this list.

// toString()				//Converts the list to a printable
// string representation.

#endif