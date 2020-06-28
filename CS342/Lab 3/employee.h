#pragma once
#ifndef _EMPLOYEE_
#define _EMPLOYEE_

// incomplete class and not fully documented
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

const int MAXID = 9999;

class Employee {
    friend ostream& operator<<(ostream &, const Employee &);

public:
    Employee(string = "dummyLast", string = "dummyFirst", int = 0, int = 0);
    Employee(const Employee&);
    ~Employee();
    bool setData(ifstream&);         // fill object with data from file
    Employee& operator=(const Employee&);

    // comparison operators 
    bool operator<(const Employee&) const;
    bool operator<=(const Employee&) const;
    bool operator>(const Employee&) const;
    bool operator>=(const Employee&) const;
    bool operator==(const Employee&) const;
    bool operator!=(const Employee&) const;

private:
    string lastName;                      // employee's last name
    string firstName;                     // employee's first name
    int idNumber;                         // employee's ID number
    int salary;                           // employee's salary
};
#endif // !_EMPLOYEE_