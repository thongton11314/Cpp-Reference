// file InteSet.h
// Simple class IntSet (for non-negative integers)
// Developed by Thong Ton: UWB CS 342 assignment 2

#ifndef _INT_SET_
#define _INT_SET_
#include <iostream>
using namespace std;

//---------------------------------------------------------------------------
// IntSet class: 
//   -- allows input and output of the whole set
//   -- allows for comparison of 2 set, element by element
//   -- allows for assignment of 2 set
//   -- size is part of the class, it is always a highest number when insert
//   -- when remove the higest value in set, the size is not being resize
//
// Implementation and assumptions:
//   -- size defaults to a size of 1 if size is not specified or invalid
//   -- array elements are initialized to false
//   -- user must enter valid integers when using >>
//   -- in <<, integers are displayed in curly bracket such as { }
//   -- in >>, read positive integer only, 
//      terminate if input alphabet, negative number or enter
//---------------------------------------------------------------------------

const int DEFAULTSIZE = 1;  // hold default size
const int FALSEVALUE = -1;  // hold value that not being added to set

class IntSet
{
	friend ostream& operator<<(ostream &, const IntSet &);	
	friend istream& operator>>(istream &, IntSet &);
public:
//---------------------------------------------------------------------------
	IntSet(const IntSet&);                 // constructor, takes array size
	IntSet(int = FALSEVALUE, 
		int = FALSEVALUE, 
		int = FALSEVALUE, 
		int = FALSEVALUE, 
		int = FALSEVALUE);                 // constructor by default value
	~IntSet();                             // destructor
	
	bool insert(int);                      // insert value
	bool remove(int);                      // remove value
	bool isEmpty() const;                  // check array empty
	bool isInSet(int) const;               // check if value in array
	
	// arithmetic operators
	IntSet operator+(const IntSet&) const; // get union of objects
	IntSet operator*(const IntSet&) const; // get intersection of two objects
	IntSet operator-(const IntSet&) const; // get differnt of two objects
	IntSet& operator=(const IntSet&);	   // assign IntSet objects
	IntSet& operator+=(const IntSet&);     // assign Intset union objects
	IntSet& operator*=(const IntSet&);     // assign Intset intersection objects
	IntSet& operator-=(const IntSet&);     // assign Intset intersection objects

	// boolean comparison operators
	bool operator==(const IntSet&) const;  // equality, 2 IntSet are identical
	bool operator!=(const IntSet&) const;  // not equal, 2 IntSet differ

private:
	bool *arr = nullptr;                   // array to hold boolean of object
	int size;                              // size of the array 
	void copy(const IntSet&);              // copy IntSet object
};

#endif // !_INT_SET_