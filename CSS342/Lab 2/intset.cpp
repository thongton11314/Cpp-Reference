// file InteSet.h
// Simple class IntSet (for non-negative integers)
// Developed by Thong Ton: UWB CS 342 assignment 2
#include "intset.h"

// ---------------------------------------------------------------------------
// Constructor 
// copy constructor for class IntSet
IntSet::IntSet(const IntSet &other)
{
    // deep copy from other object
    copy(other);
}

// ---------------------------------------------------------------------------
// Constructor 
// Constructor for class IntSet
// Using default paramter take up to five argument
IntSet::IntSet(int value, int value1, int value2
    , int value3, int value4)
{
    size = DEFAULTSIZE;            // set default size to 1
    arr = new bool[size] { false }; // initialize array and set false for all

    // insert value
    insert(value);
    insert(value1);
    insert(value2);
    insert(value3);
    insert(value4);
}

// ---------------------------------------------------------------------------
// insert
// insert element into this class array
bool IntSet::insert(int value) {

    // check if value is negative or already in set
    if (value < 0 || isInSet(value))
        return false;

    // array still have room
    if (value < size)
        arr[value] = true;

    // array out of room, grow size
    else {
        bool *temp = arr;                     // temporary array
        arr = new bool[value + 1]{ false };   // increase the array size

        // copy each element from temp
        for (int i = 0; i < size; i++)
            arr[i] = temp[i];

        // delete temporary array
        delete[] temp;
        temp = nullptr;

        // set insert
        arr[value] = true;

        // new size
        size = value + 1;
    }

    // return true when successfully insert
    return true;
}

// ---------------------------------------------------------------------------
// remove
// remove element from this class array
bool IntSet::remove(int value)
{
    // check value is not negative and lass than size
    if (value > FALSEVALUE && value < size) {
        if (arr[value] == true) {
            arr[value] = false;
            return true;
        }
    }
    return false; // remove not successful nor value is not in set to remove
}

// ---------------------------------------------------------------------------
// isEmpty
// check if this class array is empty
bool IntSet::isEmpty() const
{
    bool flag = true; // true if empty, false if not empty

    // check empty array
    for (int i = 0; i < size && flag == true; i++)
        if (arr[i] == true)
            flag = false;
    return flag;
}

// ---------------------------------------------------------------------------
// isInSet
// check if the element is in this class array
bool IntSet::isInSet(int value) const
{
    // check if passed value is in array or not
    if (value < size && value > FALSEVALUE)
        if (arr[value] == true)
            return true;
    return false;
}

// --------------------------------------------------------------------------
// operator+
// Overloaded plus operator for class IntSet;
IntSet IntSet::operator+(const IntSet &other) const
{
    IntSet temp = *this; // temporary set

    // look for union
    for (int i = 0; i < other.size; i++)
        if (other.arr[i] == true)
            temp.insert(i);
    return temp;
}

// --------------------------------------------------------------------------
// operator*
// Overloaded asterisk operator for class IntSet;
IntSet IntSet::operator*(const IntSet &other) const
{
    IntSet temp;                 // temporary return value
    bool isMaxSize = false;      // use for break loop

    // looking for intersection
    for (int i = 0; i < size && isMaxSize == false; i++) {
        if (i <= other.size) {
            if (arr[i] == true && other.arr[i] == true)
                temp.insert(i);
        }
        else {
            isMaxSize = true;
        }
    }
    return temp;
}

// --------------------------------------------------------------------------
// operator-
// Overloaded - operator for class IntSet;
IntSet IntSet::operator-(const IntSet &other) const
{
    // temporary return value
    IntSet temp;

    // looking for which number is in current object but not in other
    for (int i = 0; i < size; i++) {
        if (i <= other.size) {
            if (arr[i] == true && other.arr[i] == false)
                temp.insert(i);
        }
        else {
            if (arr[i] == true)
                temp.insert(i);
        }
    }
    return temp;
}

// --------------------------------------------------------------------------
// operator=
// Overloaded equal operator for class IntSet;
// Assign other value to this object value
IntSet & IntSet::operator=(const IntSet &other)
{
    // check if two object is not equal
    if (&other != this) {
        delete[] arr;

        // copy other array into this current array
        copy(other);
    }
    return *this;        // enables x = y = z;
}

// --------------------------------------------------------------------------
// operator+=
// Overloaded plus equal operator for class IntSet;
IntSet & IntSet::operator+=(const IntSet &other)
{
    // assign this object by result of this object plus other object
    *this = *this + other;
    return *this;
}

// --------------------------------------------------------------------------
// operator*=
// Overloaded asterisk equal operator for class IntSet;
IntSet & IntSet::operator*=(const IntSet &other)
{
    // assign this object by result interection of this object & other object
    *this = *this * other;
    return *this;
}

// --------------------------------------------------------------------------
// operator-=
// Overloaded minus equal operator for class IntSet;
IntSet & IntSet::operator-=(const IntSet &other)
{
    // assign this object by result of this object minus other object
    *this = *this - other;
    return *this;
}

// --------------------------------------------------------------------------
// operator==
// Overloaded equal operator for class IntSet;
bool IntSet::operator==(const IntSet &other) const
{
    // if two size of object are not equal return false
    if (size != other.size)
        return false;

    // if two size of objects are equal, then check each element
    bool flag = true;
    for (int i = 0; i < size && flag == true; i++)
        if (arr[i] != other.arr[i])
            flag = false;
    return flag;
}

// --------------------------------------------------------------------------
// operator!=
// Overloaded not equal operator for class IntSet;
bool IntSet::operator!=(const IntSet &other) const
{
    // take advantage of operator ==, if not equal return false
    return !(*this == other);
}

// ---------------------------------------------------------------------------
// Destructor 
// Destructor for class IntSet
IntSet::~IntSet()
{
    // delete entire array
    delete[] arr;
    arr = nullptr;
}

// --------------------------------------------------------------------------
// copy
// Called by copy constructor, operator=, operator*=, operator-=
// to do actual copying of array
// Size the array, allocate memory, and copy contents of parameter's array
void IntSet::copy(const IntSet &other)
{
    size = other.size;              // initialize size
    arr = new bool[size] { false }; // create new array by other's array size

    // copy element by element
    for (int i = 0; i < other.size; i++)
        arr[i] = other.arr[i];
}

// --------------------------------------------------------------------------
// operator<< 
// Overloaded output operator for class IntSet
ostream& operator<<(ostream &out, const IntSet &set)
{
    // if object is not empty then go get value
    if (!set.isEmpty() || set.arr != nullptr) {
        out << "{ ";
        for (int i = 0; i < set.size; i++)
            if (set.arr[i] == true)
                out << i << " ";
        out << '}';
    }

    // if object is empty then return {}
    else
        out << "{ " << '}';
    return out; // e.g., enables cout << setA << setB;
}

// --------------------------------------------------------------------------
// operator>> 
// Overloaded input operator for class IntSet;
// inputs values for entire array.
istream & operator>>(istream &in, IntSet &set)
{
    int temp = 0;               // set value equal to 0

    // read all element from user
    while (temp > FALSEVALUE) {

        // get user input
        in >> temp;

        // terminate if user input wrong input and clean buffer
        if (in.fail()) {
            in.clear();
            in.ignore(99, '\n');

            // break of of loop
            temp = FALSEVALUE;
        }

        // teminate if user hit enter
        else if (in.peek() == '\n') {
            set.insert(temp);
            temp = FALSEVALUE;
        }

        // insert value if user type in right input
        else
            set.insert(temp);
    }
    return in;  // e.g., enables cin >> setA
}