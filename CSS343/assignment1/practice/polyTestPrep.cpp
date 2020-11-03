#include "polyTestPrep.h" // use to get poly header

// ----------------------------------- Poly -----------------------------------
// Description: Poly class constructor, by using default parameter
// ----------------------------------------------------------------------------
Poly::Poly(double co, int exp) {

    // get size for array, if exp > 0 then size is exponent + 1, else size = 1
    exp >= DEFAULTVALUE ? size = exp + 1 : size = DEFAULTSIZE;

    // create a dynamic array
    arr = new double[size];

    // check nagative
    if (exp >= DEFAULTVALUE) {
        for (int i = 0; i < size; i++) {
            arr[i] = DEFAULTVALUE;
        }

        // set input exponent's coefficient
        arr[exp] = co;
    }

    // if exponent negative, coeff will be 0
    else {
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

    // delete dynamic array
    delete[] arr;
    arr = nullptr;
} // end of deconstructor

// ---------------------------------- setCoeff --------------------------------
// Description: use to set coefficient and it's polynomial
// ----------------------------------------------------------------------------
void Poly::setCoeff(double co, int exp) {

    // resize if exp greater than current size
    if (exp >= size) {
        int newSize = exp + 1;     // get new size
        double *temp = arr;        // keep old array's element
        arr = new double[newSize]; // new array

        // assign new value for new array
        for (int i = 0; i < newSize; i++) {

            // copy old array to new array
            if (i < size) {
                arr[i] = temp[i];
            }

            // set default value for new array
            else {
                arr[i] = DEFAULTVALUE;
            }
        }
        arr[exp] = co;  // set coeffient
        size = newSize; // new size

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
    size = other.size;      // initial size
    arr = new double[size];    // create new array by other size

    // copy element by element
    for (int i = 0; i < other.size; i++)
        arr[i] = other.arr[i];
} // end of copy

// -------------------------------- operator+ ---------------------------------
// Description: overloaded addition operator for class Poly
// ----------------------------------------------------------------------------
Poly Poly::operator+(const Poly &other) const {
    int maxSize;    // create value for max

    // using ternary operator to get max
    size < other.size ? maxSize = other.size : maxSize = size;
    Poly temp(DEFAULTVALUE, maxSize);      // create temporary polynomial

    // continuous adding until 0 index
    // add from the last index to the first index
    for (int i = maxSize - 1; i >= 0; i--) {

        // from last index to equal index
        if (i >= size) {
            temp.arr[i] = other.arr[i];
        }

        // from equal to first
        else {
            if (i >= other.size) {
                temp.arr[i] = arr[i]; // copy value
            }
            else {
                temp.arr[i] = arr[i] + other.arr[i]; // perform math
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
    int maxSize;    // check the largest size

    // using ternary operator to get max
    size < other.size ? maxSize = other.size : maxSize = size;
    Poly temp(DEFAULTVALUE, maxSize); // create temporary polynomial

    // continuous adding until largest size
    // add from the last index to the first index
    for (int i = maxSize - 1; i >= 0; i--) {

        // from last index to equal index
        if (i >= size) {
            temp.arr[i] = -other.arr[i];
        }

        // from equal to first
        else {
            if (i >= other.size) {
                temp.arr[i] = arr[i]; // copy value
            }
            else {
                temp.arr[i] = arr[i] - other.arr[i]; // perform math
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

    int sumTwoSize = size + other.size - 2;     // sum of two size, maxSize
    Poly temp(DEFAULTVALUE, sumTwoSize);        // reserve size for return poly

    // get current exponent
    for (int i = size - 1; i >= 0; i--) {

        // check if current coefficient is not zero
        if (arr[i] != 0) {

            // get other polynomial
            for (int j = other.size - 1; j >= 0; j--) {

                // check if other coefficient is not zero
                if (other.arr[j] != 0) {

                    // perform calculation here
                    temp.arr[i + j] += (arr[i] * other.arr[j]);
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

    int maxSize;    // create value for max

    // using ternary operator to get max
    size < other.size ? maxSize = other.size : maxSize = size;

    // continuous adding until smallest size
    // add from the last index to the first index
    for (int i = maxSize - 1; i >= 0; i--) {

        // from last index to equal index
        if (i >= size) {
            setCoeff(other.arr[i], i);  // this also resize
        }

        // from equal to first index
        else {
            arr[i] += other.arr[i];
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
    int maxSize;

    // using ternary operator to get max
    size < other.size ? maxSize = other.size : maxSize = size;

    // continuous adding until largest size
    // add from the last index to the first index
    for (int i = maxSize - 1; i >= 0; i--) {

        // from last index to equal index
        if (i >= size) {
            setCoeff(-other.arr[i], i); // this also resize
        }

        // from equal index to first index
        else {
            arr[i] -= other.arr[i];            
        }
    }

    // return to this class
    return *this;
} // end of operator-=

// -------------------------------- operator*= --------------------------------
// Description: overloaded asterisk equal operator for Poly class
// ----------------------------------------------------------------------------
Poly & Poly::operator*=(const Poly &other) {
    
    // reserve new size
    int sumTwoSize = size + other.size - 2;     // sum of two size, maxSize
    setCoeff(DEFAULTVALUE, sumTwoSize);         // reserve size for return poly

    // get current exponent
    for (int i = size - 1; i >= 0; i--) {

        // check if current coefficient is not zero
        if (arr[i] != 0) {

            // get other polynomial
            for (int j = other.size - 1; j >= 0; j--) {

                // check if other coefficient is not zero
                if (other.arr[j] != 0) {

                    // perform calculation
                    arr[i + j] += (arr[i] * other.arr[j]);
                }
            }
        }
    }
    return *this;
} // end of operator*=

// -------------------------------- operator== --------------------------------
// Description: overloaded equal operator for Poly class
// ----------------------------------------------------------------------------
bool Poly::operator==(const Poly &other) const {
    
    // use to check equal
    bool isEqual = true;

    // early exit if two object addresses are identical
    if (&other == this) {
        return true;
    }

    // continue check each subscript
    else {
       
        // declare max and min size
        int minSize = DEFAULTVALUE;
        int maxSize = DEFAULTVALUE;

        // get max and min size
        size < other.size ? minSize = size : minSize = other.size;
        size > other.size ? maxSize = size : maxSize = other.size;

        // check equal
        for (int i = 0; (i < maxSize) && (isEqual == true); i++) {

            // check until reach minimum size
            if (i < minSize) {
                if (arr[i] != other.arr[i]) {
                    isEqual = false;
                }
            }

            // check from minimum size to max size
            else {

                // check current array
                if (size > other.size) {
                    if (arr[i] != 0) {
                        isEqual = false;
                    }
                }

                // check other array
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
// Description: overloaded output operator for Poly class
// ----------------------------------------------------------------------------
ostream & operator<<(ostream &out, const Poly &poly) {

    // use to check if entire polynomial is zero
    bool isEntireZero = true;

    // check each exponent
    for (int i = poly.size - 1; i >= 0; i--) {

        // check if coefficient is not zero
        if (poly.arr[i] != 0) {

            // one space between each term
            out << ' ';

            // coefficient is positive, add positive sign
            if (poly.arr[i] > 0) {
                out << '+';
            }

            // print polynomial if greater 1
            if (i > 1) {
                out << poly.arr[i] << "x^" << i;
            }

            // not print polynomial if equal 1
            else if (i == 1) {
                out << poly.arr[i] << 'x';
            }

            // polynomial is zero, constant number
            else {
                out << poly.arr[i];
            }

            // non zero polynomial
            isEntireZero = false;
        }
    }

    // entire polynomial is zero return 0
    if (isEntireZero)
        out << 0;
    return out;
} // end of operator<<

// -------------------------------- operator>> --------------------------------
// Description: overloaded input operator for Poly class
// ----------------------------------------------------------------------------
istream & operator>>(istream &in, Poly &expresion) {

    
    // create coefficient, exponent
    int co = DEFAULTVALUE, exp = DEFAULTVALUE;
    
    // loop until user user type -1 -1 in pair
    while (!(co == -1 && exp == -1)) {

        // get coefficient and exponent
        in >> co >> exp;

        // terminate if user input wrong input and clean buffer
        if (in.fail()) {
            in.clear();
            in.ignore(99, '\n');

            // break out of loop
            co = -1;
            exp = -1;
        }

        // insert to polynomial
        else {
            expresion.setCoeff(co, exp);
        }    
    }
    return in;
} // end of operator>>

void Poly::integrate() {
    // Idea: the basic idea is make this integrate this poly
    // Technical: 
    //              Resize by size + 1
    //                  copy all old value to new array new size              
    //              Move exponent of that exponent up one position
    //              Divide coefficient by new exponent
    //              

    // Resize by size + 1
    double *temp = arr;
    arr = new double[size + 1];
    for (int i = 0; i < size; i++) {
        if (temp[i] != 0)
            arr[i] = temp[i];
        else
            arr[i] = 0;
    }
    arr[size] = 0;  // last coefficient = 0
    size += 1;      // new size   

    // the last coefficient is always have no value
    for (int i = size - 1; i >= 0; i--) {
        if (arr[i] != 0) {
            arr[i + 1] = arr[i];
            arr[i + 1] = arr[i + 1] / (i + 1); 
            arr[i] = 0;
        }
    }

    // delete old array
    delete[] temp;
}

void Poly::differentiate() {
    // Idea: the basic idea is   differentiate this poly
    // Technical: 
    //              Don't need to shrink size 
    //              Divide coefficient by new exponent
    //              Exponent minus 1
    // special case for 0
    arr[0] = 0;
    for (int i = 1; i < size; i++) {
        arr[i] = arr[i] * i;
        arr[i - 1] = arr[i];
        arr[i] = 0;
    }
}

