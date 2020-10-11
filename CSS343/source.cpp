#include <iostream>
#include "poly.h"
using namespace std;

void testConstructor();
void testCoeff();
void testOperatorPlus();
void testOperatorPlusEqual();
void testOperatorMinus();
void testOperatorMultiple();
void testOperatorMultipleEqual();
void testIfstream();

int main() {

    // Constructor test
    cout << "Constructor test" << endl;
    testConstructor();
    cout << endl;

    // get and setCoeff Test
    cout << "get and setCoeff test" << endl;
    testCoeff();
    cout << endl;

    // test operator+
    cout << "Operator+" << endl;
    testOperatorPlus();
    cout << endl;

    // test operator+=
    cout << "Operator+=" << endl;
    testOperatorPlusEqual();
    cout << endl;

    // test operator-
    cout << "Operator-" << endl;
    testOperatorMinus();
    cout << endl;

    // test operator*
    cout << "Opertor*" << endl;
    testOperatorMultiple();
    cout << endl;

    // test operator*=
    cout << "Opertor*=" << endl;
    testOperatorMultipleEqual();
    cout << endl;

    // test ifstream
    cout << "Test iftream" << endl;
    testIfstream();
    cout << endl;
    return 0;
}

void testConstructor() {
    Poly test11;            // case 1
    Poly test12(20);        // case 2
    Poly test13(20, 20);    // case 3
    Poly test14(20, -1);    // case 4
    Poly test15(-100, 20);  // case 5
    Poly test16(-100, -1);  // case 6
    Poly test17(20, 99);    // case 7

    // Copy contructor case 8
    Poly beingCopy;
    beingCopy.setCoeff(-1, 1);
    beingCopy.setCoeff(0, 0);
    beingCopy.setCoeff(1, 1);
    beingCopy.setCoeff(5, 5);
    beingCopy.setCoeff(25, 25);
    beingCopy.setCoeff(15, 15);
    Poly getCopy(beingCopy);

    // Test constructor case 1
    if (test11.getCoeff(0) == 0)
        cout << "Constructor case 1:" << "\tPASSED" << endl;
    else
        cout << "Constructor case 1:" << "\t*FAILED" << endl;

    // Test constructor case 2
    if ((test12.getCoeff(0) == 20)
        && (test12.getCoeff(-1) == 0)
        && (test12.getCoeff(2) == 0))
        cout << "Constructor case 2:" << "\tPASSED" << endl;
    else
        cout << "Constructor case 2:" << "\tFAILED******" << endl;

    // Test constructor case 3
    if (test13.getCoeff(20) == 20
        && test13.getCoeff(21) == 0
        && test13.getCoeff(19) == 0)
        cout << "Constructor case 3:" << "\tPASSED" << endl;
    else
        cout << "Constructor case 3:" << "\tFAILED******" << endl;

    // Test constructor case 4
    if (test14.getCoeff(-1) == 0
        && test14.getCoeff(0) == 0)
        cout << "Constructor case 4:" << "\tPASSED" << endl;
    else
        cout << "Constructor case 4:" << "\tFAILED******" << endl;

    // Test constructor case 5
    if (test15.getCoeff(20) == -100
        && test15.getCoeff(21) == 0
        && test15.getCoeff(19) == 0)
        cout << "Constructor case 5:" << "\tPASSED" << endl;
    else
        cout << "Constructor case 5:" << "\tFAILED******" << endl;

    // Test constructor case 6
    if (test16.getCoeff(0) == 0
        && test16.getCoeff(-1) == 0)
        cout << "Constructor case 6:" << "\tPASSED" << endl;
    else
        cout << "Constructor case 6:" << "\tFAILED******" << endl;

    // Test constructor case 7
    if (test17.getCoeff(99) == 20
        && test17.getCoeff(1000) == 0
        && test17.getCoeff(-1000) == 0)
        cout << "Constructor case 7:" << "\tPASSED" << endl;
    else
        cout << "Constructor case 7:" << "\tFAILED******" << endl;

    // Test copyconstructor case 8
    if (beingCopy == getCopy)
        cout << "Constructor case 8:" << "\tPASSED" << endl;
    else
        cout << "Constructor case 8:" << "\tFAILED******" << endl;
}

void testCoeff() {
    Poly test11;
    test11.setCoeff(1, 10);
    test11.setCoeff(10, 10);
    test11.setCoeff(20, 20);

    // Case 1 valid exponent
    if (test11.getCoeff(10) == 10
        && test11.getCoeff(20) == 20)
        cout << "set/get case 1:" << "\t\tPASSED" << endl;
    else
        cout << "set/get case 1:" << "\t\tFAILED******" << endl;

    // Case 2, negative exponent
    test11.setCoeff(10, -1);
    if (test11.getCoeff(-1) == 0)
        cout << "set/get case 2:" << "\t\tPASSED" << endl;
    else
        cout << "set/get case 2:" << "\t\tFAILED******" << endl;

    // Case 3, zero exponent
    test11.setCoeff(10, 0);
    if (test11.getCoeff(0) == 10)
        cout << "set/get case 3:" << "\t\tPASSED" << endl;
    else
        cout << "set/get case 3:" << "\t\tFAILED******" << endl;

    // Case 4, very large exponent
    test11.setCoeff(99999, 99999);
    test11.setCoeff(555, 555);
    if (test11.getCoeff(99999) == 99999 && test11.getCoeff(555) == 555)
        cout << "set/get case 4:" << "\t\tPASSED" << endl;
    else
        cout << "set/get case 4:" << "\t\tFAILED******" << endl;

    // Case 5, out of bounce get
    if (test11.getCoeff(5) == 0 && test11.getCoeff(9) == 0)
        cout << "set/get case 5:" << "\t\tPASSED" << endl;
    else
        cout << "set/get case 5:" << "\t\tFAILED******" << endl;

}

void testOperatorPlus() {
    Poly test1;
    Poly test2;

    // assign test1
    test1.setCoeff(1, 1);
    test1.setCoeff(10, 10);
    test1.setCoeff(20, 20);
    test1.setCoeff(30, 30);

    // assign test2
    test2.setCoeff(1, 1);
    test2.setCoeff(10, 10);
    test2.setCoeff(20, 20);
    test2.setCoeff(30, 30);

    // Case 1, same exponent
    Poly result1(test1 + test2);
    if (result1.getCoeff(1) == 2
        && result1.getCoeff(10) == 20
        && result1.getCoeff(20) == 40
        && result1.getCoeff(30) == 60
        && result1.getCoeff(0) == 0
        && result1.getCoeff(2) == 0)
        cout << "Plus case 1:" << "\t\tPASSED" << endl;
    else
        cout << "Plus case 1:" << "\t\tFAILED******" << endl;

    // Case 2, not same exponent
    Poly anotherOne;
    anotherOne.setCoeff(1, 0);
    anotherOne.setCoeff(2, 2);
    Poly result2;
    result2 = anotherOne + result1;
    if (result2.getCoeff(1) == 2
        && result2.getCoeff(10) == 20
        && result2.getCoeff(20) == 40
        && result2.getCoeff(30) == 60
        && result2.getCoeff(0) == 1
        && result2.getCoeff(2) == 2)
        cout << "Plus case 2:" << "\t\tPASSED" << endl;
    else
        cout << "Plus case 2:" << "\t\tFAILED******" << endl;

    // Case 3, it self plus it self
    result2 = result2 + result2;
    if (result2.getCoeff(1) == 2 * 2
        && result2.getCoeff(10) == 20 * 2
        && result2.getCoeff(20) == 40 * 2
        && result2.getCoeff(30) == 60 * 2
        && result2.getCoeff(0) == 1 * 2
        && result2.getCoeff(2) == 2 * 2)
        cout << "Plus case 3:" << "\t\tPASSED" << endl;
    else
        cout << "Plus case 3:" << "\t\tFAILED******" << endl;
}

void testOperatorPlusEqual() {
    Poly test1;
    Poly test2;

    // assign test1
    test1.setCoeff(1, 1);
    test1.setCoeff(10, 10);
    test1.setCoeff(20, 20);
    test1.setCoeff(30, 30);

    // assign test2
    test2.setCoeff(1, 1);
    test2.setCoeff(10, 10);
    test2.setCoeff(20, 20);
    test2.setCoeff(30, 30);

    // Case 1, test equal exponent
    test1 += test2;
    if (test1.getCoeff(1) == 2
        && test1.getCoeff(10) == 20
        && test1.getCoeff(20) == 40
        && test1.getCoeff(30) == 60
        && test1.getCoeff(0) == 0
        && test1.getCoeff(2) == 0)
        cout << "Plus eual case 1:" << "\tPASSED" << endl;
    else
        cout << "Plus eqal case 1:" << "\tFAILED******" << endl;

    // Case 2, test not equal exponent
    Poly anotherOne;
    anotherOne.setCoeff(1, 1);
    anotherOne.setCoeff(50, 50);
    test1 += anotherOne;
    test1 += test1;
    if (test1.getCoeff(1) == 3 * 2
        && test1.getCoeff(10) == 20 * 2
        && test1.getCoeff(20) == 40 * 2
        && test1.getCoeff(30) == 60 * 2
        && test1.getCoeff(50) == 50 * 2)
        cout << "Plus equal case 2:" << "\tPASSED" << endl;
    else
        cout << "Plus equal case 2:" << "\tFAILED******" << endl;

    // Case 3, it self plus it self
    test1 += test1;
    if (test1.getCoeff(1) == 3 * 4
        && test1.getCoeff(10) == 20 * 4
        && test1.getCoeff(20) == 40 * 4
        && test1.getCoeff(30) == 60 * 4
        && test1.getCoeff(50) == 50 * 4)
        cout << "Plus equal case 3:" << "\tPASSED" << endl;
    else
        cout << "Plus equal case 3:" << "\tFAILED******" << endl;
}

void testOperatorMinus() {
    Poly test1;
    Poly test2;

    // assign test1
    test1.setCoeff(1, 1);
    test1.setCoeff(10, 10);
    test1.setCoeff(20, 20);
    test1.setCoeff(30, 30);

    // assign test2
    test2.setCoeff(1, 1);
    test2.setCoeff(10, 10);
    test2.setCoeff(20, 20);
    test2.setCoeff(30, 30);

    // Case 1, same exponent
    Poly result(test1 - test2);
    if (result.getCoeff(1) == 0
        && result.getCoeff(10) == 0
        && result.getCoeff(20) == 0
        && result.getCoeff(30) == 0)
        cout << "Minus case 1:" << "\t\tPASSED" << endl;
    else
        cout << "Minus case 1:" << "\t\tFAILED******" << endl;

    // Case 2, different exponent
    Poly other; // 
    other.setCoeff(1, 1);
    other.setCoeff(10, 10);
    other.setCoeff(5, 5);
    Poly anotherResult(5, 10);

    anotherResult = anotherResult - other;
    cout << anotherResult << endl;
}

void testOperatorMultiple() {
    Poly test1; // 2x^2+4x^4+6x^6
    Poly test2; // 2x^2+4x^4+5x^5
    test1.setCoeff(2, 2);
    test1.setCoeff(4, 4);
    test1.setCoeff(6, 6);
    test2.setCoeff(2, 2);
    test2.setCoeff(4, 4);
    test2.setCoeff(5, 5);


    // Case 1, two test has positive value
    Poly result(test1 * test2);
    Poly result1; //+30x^11 +24x^10 +20x^9 +28x^8 +10x^7 +16x^6 +4x^4
    result1.setCoeff(30, 11);
    result1.setCoeff(24, 10);
    result1.setCoeff(20, 9);
    result1.setCoeff(28, 8);
    result1.setCoeff(10, 7);
    result1.setCoeff(16, 6);
    result1.setCoeff(4, 4);
    if (result == result1)
        cout << "Multiple case 1:" << "\tPASSED" << endl;
    else
        cout << "Multiple case 1:" << "\tFAILED******" << endl;

    // Case 2, two test has negative value
    Poly test11;
    Poly test12;
    test11.setCoeff(-1, 1);
    test11.setCoeff(-3, 3);
    test11.setCoeff(-5, 5);
    test12.setCoeff(2, 2);
    test12.setCoeff(4, 4);
    test12.setCoeff(6, 6);
    Poly result11(test11 * test12); //-30x^11 -38x^9 -28x^7 -10x^5 -2x^3
    if (result11.getCoeff(11) == -30
        && result11.getCoeff(9) == -38
        && result11.getCoeff(7) == -28
        && result11.getCoeff(5) == -10
        && result11.getCoeff(3) == -2)
        cout << "Multiple case 2:" << "\tPASSED" << endl;
    else
        cout << "Multiple case 2:" << "\tFAILED******" << endl;

    // Case 3, test zero multiple
    Poly testZero1;
    Poly testZero2;
    Poly testZeroResult;
    if (testZeroResult == testZero1 * testZero2)
        cout << "Multiple case 3:" << "\tPASSED" << endl;
    else
        cout << "Multiple case 3:" << "\tFAILED******" << endl;

    // Case 4, test one zero other has value
    Poly thisZero;
    Poly thisValue;
    Poly thisTestZeroValue;
    thisValue.setCoeff(2, 2);
    thisValue.setCoeff(4, 4);
    thisValue.setCoeff(6, 6);
    if (thisTestZeroValue == thisZero * thisValue)
        cout << "Multiple case 4:" << "\tPASSED" << endl;
    else
        cout << "Multiple case 4:" << "\tFAILED******" << endl;
}

void testOperatorMultipleEqual() {

    // Case 1, two test has positive value
    Poly test1;
    Poly test2;
    test1.setCoeff(10, 10);
    test1.setCoeff(5, 5);
    test2.setCoeff(1, 1);
    test2.setCoeff(2, 2);
    test2 *= test1; //20x^12 +10x^11 +10x^7 +5x^6
    if (test2.getCoeff(12) == 20
        && test2.getCoeff(11) == 10
        && test2.getCoeff(7) == 10
        && test2.getCoeff(6) == 5)
        cout << "Multiple case 1:" << "\tPASSED" << endl;
    else
        cout << "Multiple case 1:" << "\tFAILED******" << endl;

    // Case 2, two test has negative value
    Poly test11;
    Poly test12;
    test11.setCoeff(-10, 10);
    test11.setCoeff(5, 5);
    test12.setCoeff(1, 1);
    test12.setCoeff(-2, 2);
    test12 *= test11; //20x^12 -10x^11 -10x^7 +5x^6
    if (test12.getCoeff(12) == 20
        && test12.getCoeff(11) == -10
        && test12.getCoeff(7) == -10
        && test12.getCoeff(6) == 5)
        cout << "Multiple case 2:" << "\tPASSED" << endl;
    else
        cout << "Multiple case 2:" << "\tFAILED******" << endl;

    // Case 3, test zero multiple
    // Case 4, test one zero other has value
}

void testIfstream() {
    cout << "Type in poly, exit -1 -1:" << endl;
    Poly test;
    cin >> test;
    cout << test;
}
