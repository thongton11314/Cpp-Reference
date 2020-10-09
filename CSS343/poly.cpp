// ------------------------------- poly.cpp -----------------------------------
// Programmer: Thong Ton
// Course: CSS343, assignment 1
// Creation Date: 10/4/2020
// Date of Last Modification: 10/8/2020
// ----------------------------------------------------------------------------
// Purpose: This is the implementation of poly.h
// ----------------------------------------------------------------------------

#include "poly.h" // use to get header function from Poly class

// ----------------------------------- Poly -----------------------------------
// Description: Poly class constructor
// ----------------------------------------------------------------------------
Poly::Poly(int co, int exp) {

    // check nagative
    if (exp >= DEFAULTVALUE) {
        size = exp + 1;
        arr = new int[size];
        for (int i = 0; i < exp; i++) {
            arr[i] = DEFAULTVALUE;
        }
        arr[exp] = co;
    }

    // if exponent negative, coeff will be 0
    else {
        size = DEFAULTSIZE;
        arr = new int[size];
        arr[0] = DEFAULTVALUE;
    }
} // end of constructor


// ----------------------------------- Poly -----------------------------------
// Description: Poly class copy constructor use to copy other Poly to this Poly
// ----------------------------------------------------------------------------
Poly::Poly(const Poly &other) {
    copy(other);
} // end of copy constructor

// ----------------------------------- ~Poly ----------------------------------
// Description: deconstructor use to delete all dynamic array data
// ----------------------------------------------------------------------------
Poly::~Poly() {
    delete[] arr;
    arr = nullptr;
} // end of deconstructor

// ---------------------------------- setCoeff --------------------------------
// Description: use to set coefficient and it's polynomial
// ----------------------------------------------------------------------------
void Poly::setCoeff(int co, int exp) {

    if (exp >= size) {
        int newSize = exp + 1;
        int *temp = arr;
        arr = new int[newSize];

        // assign old array element to new one
        for (int i = 0; i < size; i++) {
            arr[i] = temp[i];
        }

        // assign value to 0
        for (int i = size; i < newSize; i++) {
            arr[i] = DEFAULTVALUE;
        }
        arr[exp] = co;
        size = newSize;

        // delete temporary memory
        delete[] temp;
        temp = nullptr;
    }

    // in boundary of non-negative exponent
    else if (exp >= 0) {
        arr[exp] = co;
    }

    // out of boundary, non-negative exponent
    // ignore negative exponent
} // end of setCoeff

// ---------------------------------- getCoeff --------------------------------
// Description: use to get coefficient
// ----------------------------------------------------------------------------
int Poly::getCoeff(int exp) const {
    if (exp >= size || exp < 0)
        return 0;
    else
        return arr[exp];
} // end of getCoeff

// ----------------------------------- copy -----------------------------------
// Description: use to copy other dynamic array data to this dynamic array data
//              this function will be called in copy constructor and operator=
// ----------------------------------------------------------------------------
void Poly::copy(const Poly &other) {
    size = other.size;  // initial size
    arr = new int[size];// create new array by other size

    // copy element by element
    for (int i = 0; i < other.size; i++)
        arr[i] = other.arr[i];
} // end of copy

// -------------------------------- operator+ ---------------------------------
// Description: overloaded addition operator for class Poly;
// ----------------------------------------------------------------------------
Poly Poly::operator+(const Poly &other) const {

    // create temporary polynomial
    Poly temp;

    // create value for max and min size
    int maxSize = DEFAULTVALUE;
    int minSize = DEFAULTVALUE;

    // get max and min size by ternary operator
    size < other.size ? maxSize = other.size : maxSize = size;
    size > other.size ? minSize = other.size : minSize = size;

    // continuous adding until smallest size
    // add from the last index to the first index
    for (int i = maxSize - 1; i >= 0; i--) {

        // from last index to equal index of arrays
        // decread iter greater than or equal size 
        if (i >= size) {
            temp.setCoeff(other.arr[i], i);
        }

        // decread iter less than
        else {
            if (i >= other.size) {
                temp.setCoeff(arr[i], i);
            }
            else {
                temp.setCoeff(arr[i] + other.arr[i], i);
            }
        }
    }

    // return result
    return temp;
} // end of operator+

// -------------------------------- operator- ---------------------------------
// Description: overloaded subtraction operator for Poly class
// ----------------------------------------------------------------------------
Poly Poly::operator-(const Poly &other) const {

    // create temporary polynomial
    Poly temp;

    // check the largest size
    int maxSize = DEFAULTVALUE;
    int minSize = DEFAULTVALUE;
    size < other.size ? maxSize = other.size : maxSize = size;
    size > other.size ? minSize = other.size : minSize = size;

    // continuous adding until largest size
    // add from the last index to the first index
    for (int i = maxSize - 1; i >= 0; i--) {

        // from last index to equal index of arrays
        // decread iter greater than or equal size 
        if (i >= size) {
            temp.setCoeff(-other.arr[i], i);
        }

        // decread iter less than
        else {
            if (i >= other.size) {
                temp.setCoeff(arr[i], i);
            }
            else {
                temp.setCoeff(arr[i] - other.arr[i], i);
            }
        }
    }

    // return result
    return temp;
} // end of operator-

// -------------------------------- operator* ---------------------------------
// Description: overloaded multiple operator for Poly class
// ----------------------------------------------------------------------------
Poly Poly::operator*(const Poly &other) const {

    Poly temp;
    for (int i = size - 1; i >= 0; i--) {
        if (arr[i] != 0) {
            for (int j = other.size - 1; j >= 0; j--) {
                if (other.arr[j] != 0) {
                    if (temp.getCoeff(i + j) != 0) {
                        int coeff = temp.arr[i + j] + (arr[i] * other.arr[j]);
                        temp.setCoeff(coeff, i + j);
                    }                    
                    else {
                        temp.setCoeff(arr[i] * other.arr[j], i + j);
                    }                    
                }
            }
        }
    }
    return temp;
} // end of operator*

// -------------------------------- operator= ---------------------------------
// Description: overloaded assign operator for Poly class
// ----------------------------------------------------------------------------
Poly & Poly::operator=(const Poly &other) {

    // check if two object is not equal
    if (&other != this) {
        delete[] arr;

        // copy other array into this current array
        copy(other);
    }
    return *this;        // enables A = B = C;
}

// -------------------------------- operator+= --------------------------------
// Description: overloaded plus equal operator for Poly class
// ----------------------------------------------------------------------------
Poly & Poly::operator+=(const Poly &other) {

    // check the largest size
    int maxSize = DEFAULTVALUE;
    int minSize = DEFAULTVALUE;
    size < other.size ? maxSize = other.size : maxSize = size;
    size > other.size ? minSize = other.size : minSize = size;

    // continuous adding until smallest size
    // add from the last index to the first index
    for (int i = maxSize - 1; i >= 0; i--) {

        // from last index to equal index of arrays
        // decread iter greater than or equal size 
        if (i >= size) {
            this->setCoeff(other.arr[i], i);
        }

        // decread iter less than
        else {
            if (i >= other.size) {
                this->setCoeff(arr[i], i);
            }
            else {
                this->setCoeff(arr[i] + other.arr[i], i);
            }
        }
    }

    // return to this class
    return *this;
} // end of operator+=

// -------------------------------- operator-= --------------------------------
// Description: overloaded minus equal operator for Poly class
// ----------------------------------------------------------------------------
Poly & Poly::operator-=(const Poly &other) {

    // check the largest size
    int maxSize = DEFAULTVALUE;
    int minSize = DEFAULTVALUE;
    size < other.size ? maxSize = other.size : maxSize = size;
    size > other.size ? minSize = other.size : minSize = size;

    // continuous adding until largest size
    // add from the last index to the first index
    for (int i = maxSize - 1; i >= 0; i--) {

        // from last index to equal index of arrays
        // decread iter greater than or equal size 
        if (i >= size) {
            this->setCoeff(-other.arr[i], i);
        }

        // decread iter less than
        else {
            if (i >= other.size) {
                this->setCoeff(arr[i], i);
            }
            else {
                this->setCoeff(arr[i] - other.arr[i], i);
            }
        }
    }

    // return to this class
    return *this;
} // end of operator-=

// -------------------------------- operator*= --------------------------------
// Description: overloaded asterisk equal operator for Poly class
// ----------------------------------------------------------------------------
Poly & Poly::operator*=(const Poly &other) {

    Poly temp;
    for (int i = size - 1; i >= 0; i--) {
        if (arr[i] != 0) {
            for (int j = other.size - 1; j >= 0; j--) {
                if (other.arr[j] != 0) {
                    if (temp.getCoeff(i + j) != 0) {
                        int coeff = temp.arr[i + j] + (arr[i] * other.arr[j]);
                        temp.setCoeff(coeff, i + j);
                    }
                    else {
                        temp.setCoeff(arr[i] * other.arr[j], i + j);
                    }
                }
            }
        }
    }

    delete[] arr;
    this->copy(temp);
    return *this;
} // end of operator*=

// -------------------------------- operator== --------------------------------
// Description: overloaded equal operator for Poly class
// ----------------------------------------------------------------------------
bool Poly::operator==(const Poly &other) const {
    
    // use to check equal
    bool isEqual = true;

    // early exit if two object address is dentical
    if (&other == this) {
        return true;
    }

    // continue check each subscrip
    else {
       
        // declare max and min size
        int minSize = DEFAULTVALUE;
        int maxSize = DEFAULTVALUE;

        // get max and min size
        size < other.size ? minSize = size : minSize = other.size;
        size > other.size ? maxSize = size : maxSize = other.size;

        // check equal
        for (int i = 0; i < maxSize && isEqual == true; i++) {

            // check until reach minumum size
            if (i < minSize) {
                if (arr[i] != other.arr[i]) {
                    isEqual = false;
                }
            }

            // must check until the end of max size
            else {

                // this size as termination point
                if (size > other.size) {
                    if (arr[i] != 0) {
                        isEqual = false;
                    }
                }

                // other's size as termination point
                else {
                    if (other.arr[i] != 0) {
                        isEqual = false;
                    }
                }
            }
        }
    }
    return isEqual;
} // end of operator==

// -------------------------------- operator!= --------------------------------
// Description: overloaded not equal operator for Poly class
// ----------------------------------------------------------------------------
bool Poly::operator!=(const Poly &other) const {
    return !(*this == other);
} // end of operator!=

// -------------------------------- operator<< --------------------------------
// Description: overloaded input operator for Poly class
// ----------------------------------------------------------------------------
ostream & operator<<(ostream &out, const Poly &exp) {
    bool checkEntireZero = true;
    for (int i = exp.size - 1; i >= 0; i--) {
        if (exp.arr[i] != 0) {
            if (exp.arr[i] > 0)
                out << '+';
            if (i > 1) {
                out << exp.arr[i] << "x^" << i << ' ';
            }
            else if (i == 1) {
                out << exp.arr[i] << 'x' << ' ';
            }
            else {
                out << exp.arr[i];
            }
            checkEntireZero = false;
        }
    }
    if (checkEntireZero)
        out << 0;
    return out;
} // end of operator<<

// -------------------------------- operator>> --------------------------------
// Description: overloaded output operator for Poly class
// ----------------------------------------------------------------------------
istream & operator>>(istream &in, Poly &expresion) {
    int co = DEFAULTVALUE, exp = DEFAULTVALUE;
    
    // loop until user user type -1 -1 in pair
    while ((co != -1) || (exp != -1)) {
        in >> co >> exp;

        // terminate if user input wrong input and clean buffer
        if (in.fail()) {
            in.clear();
            in.ignore(99, '\n');

            // break out of loop
            co = -1, exp = -1;
        }

        // insert to polynomial
        else {
            expresion.setCoeff(co, exp);
        }    
    }
    return in;
} // end of operator>>