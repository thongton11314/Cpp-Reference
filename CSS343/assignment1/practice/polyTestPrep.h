#ifndef _POLYPREP_
#define _POLYPREP_
#include <iostream> // provide output or input stream
using namespace std;

// constant varibale
const int DEFAULTVALUE = 0; // use to set all array's element to zero
const int DEFAULTSIZE = 1;  // use for set initialsize

class Poly {

    // overloaded output operator for class Poly
    friend ostream& operator<<(ostream &, const Poly &);

    // overloaded input operator for class Poly
    friend istream& operator>>(istream &, Poly &);

public:

    // constructor
    Poly(double = DEFAULTVALUE, int = DEFAULTVALUE);

    // deep copy
    Poly(const Poly &);

    // deconstructor
    ~Poly();

    // setter
    void setCoeff(double, int); // use to set set coefficient and it's polynomial

    // getter
    int getCoeff(int) const; // use to get coefficient

    // integrate
    void integrate();   // use to calculate integrate, integral in calculus

    // differentiate
    void differentiate();

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
    double *arr = nullptr;     // dynamic array
    int size;               // size of array
    void copy(const Poly&); // use to copy other polynomial
};
#endif // !_POLY_