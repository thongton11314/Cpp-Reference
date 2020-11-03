#include "polyTestPrep.h"
#include <iostream>
using namespace std;

int main() {
    Poly test;
    test.setCoeff(10, 4);
    test.setCoeff(-7, 2);
    test.setCoeff(3, 0);
    cout << "Original:\t" << test << endl;
    test.integrate();
    cout << "Integrate:\t" << test << endl;
    test.differentiate();
    cout << "Differentiate:\t" << test << endl;
    return 0;
}