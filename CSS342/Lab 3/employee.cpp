#include "employee.h"

// incomplete class and not fully documented

//--------------------------  constructor  -----------------------------------
Employee::Employee(string last, string first, int id, int sal) {
    idNumber = (id >= 0 && id <= MAXID ? id : -1);
    salary = (sal >= 0 ? sal : -1);
    lastName = last;
    firstName = first;
}

//--------------------------  destructor  ------------------------------------
// Needed so that memory for strings is properly deallocated
Employee::~Employee() { }

//---------------------- copy constructor  -----------------------------------
Employee::Employee(const Employee& obj) {
    lastName = obj.lastName;
    firstName = obj.firstName;
    idNumber = obj.idNumber;
    salary = obj.salary;
}

//-------------------------- operator= ---------------------------------------
Employee& Employee::operator=(const Employee& obj) {
    if (&obj != this) {
        idNumber = obj.idNumber;
        salary = obj.salary;
        lastName = obj.lastName;
        firstName = obj.firstName;
    }
    return *this;
}

//-----------------------------  setData  ------------------------------------
// set data from file
bool Employee::setData(ifstream& inFile) {
    inFile >> lastName >> firstName >> idNumber >> salary;
    return idNumber >= 0 && idNumber <= MAXID && salary >= 0;
}

//-------------------------------  <  ----------------------------------------
// < defined by value of name
bool Employee::operator<(const Employee& obj) const {
    return lastName < obj.lastName ||
        (lastName == obj.lastName && firstName < obj.firstName);
}


//-------------------------------  <= ----------------------------------------
// < defined by value of inamedNumber
bool Employee::operator<=(const Employee& obj) const {
    return *this < obj || *this == obj;
}

//-------------------------------  >  ----------------------------------------
// > defined by value of name
bool Employee::operator>(const Employee& obj) const {
    return lastName > obj.lastName ||
        (lastName == obj.lastName && firstName > obj.firstName);
}

//-------------------------------  >= ----------------------------------------
// < defined by value of name
bool Employee::operator>=(const Employee& obj) const {
    return *this > obj || *this == obj;
}

//----------------- operator == (equality) ----------------
// if name of calling and passed object are equal,
//   return true, otherwise false
//
bool Employee::operator==(const Employee& obj) const {
    return lastName == obj.lastName && firstName == obj.firstName;
}

//----------------- operator != (inequality) ----------------
// return opposite value of operator==
bool Employee::operator!=(const Employee& obj) const {
    return !(*this == obj);
}

//-------------------------------  <<  ---------------------------------------
// display Employee object

ostream& operator<<(ostream& output, const Employee& obj) {
    output << setw(4) << obj.idNumber << setw(7) << obj.salary << "  "
        << obj.lastName << " " << obj.firstName << endl;
    return output;
}
