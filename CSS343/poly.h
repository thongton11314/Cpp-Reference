// ------------------------------- poly.h -------------------------------------
// Programmer: Thong Ton
// Course: CSS343
// Creation Date: 10/4/2020
// Date of Last Modification: 10/8/2020
// ----------------------------------------------------------------------------
// Purpose: This is the first assignment of CSS343 class
// ----------------------------------------------------------------------------

#ifndef _POLY_
#define _POLY_
#include <iostream> // provide output or input stream
using namespace std;

// constant varibale
const int DEFAULTVALUE = 0; // use to set all array's element to zero
const int DEFAULTSIZE = 1;  // use for set initialsize


//---------------------------------------------------------------------------
// Poly class:
//
//
// Implementation and assumptions:
//  - Any input exponent less than 0 then their coefficient will be set 0
//---------------------------------------------------------------------------
class Poly {

    // overloaded input operator for class Poly
    friend ostream& operator<<(ostream &, const Poly &);

    // overloaded output operator for class Poly
    friend istream& operator>>(istream &, Poly &);

public:

    // constructor
    Poly(int = DEFAULTVALUE, int = DEFAULTVALUE);

    // deep copy
    Poly(const Poly &);

    // deconstructor
    ~Poly();

    // setter
    void setCoeff(int, int); // use to set set coefficient and it's polynomial

    // getter
    int getCoeff(int) const; // use to get coefficient

    // arithmetic operators
    Poly operator+(const Poly&) const;  // get addition polynomials
    Poly operator-(const Poly&) const;  // get substraction polynomials
    Poly operator*(const Poly&) const;  // get multiplication polynomials
    Poly& operator=(const Poly&);       // assign polynomial
    Poly& operator+=(const Poly&);      // assign addition polynomials
    Poly& operator-=(const Poly&);      // assign substraction polynomials
    Poly& operator*=(const Poly&);      // assign multiplication polynomials

    // boolean arithmetic comparision
    bool operator==(const Poly&) const; // equality, polynomials are identical
    bool operator!=(const Poly&) const; // not equal, polynomials different

private:
    int *arr = nullptr;     // dynamic array
    int size;               // size of array
    void copy(const Poly&); // use to copy other polynomial
};
#endif // !_POLY_