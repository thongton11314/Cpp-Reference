// You add all appropriate comments describing the ADT 
// and class assumptions/limitations/implementation here.
// Add all member (data and functions) comments as well in this file.

#ifndef PREFIX_H
#define PREFIX_H
#include <iostream>
#include <fstream>
using namespace std;

int const MAXSIZE = 100;    // max size of exression

class Prefix {

    // print out the expression as postfix
    friend ostream& operator<<(ostream&, const Prefix&);

public:
    Prefix();                               // constructor
    void setPrefix(ifstream& infile);       // read expression from file
    int evaluatePrefix() const;             // evaluate expression
    void outputAsPostfix(ostream&) const;   // print expression by postfix

private:
    char expr[MAXSIZE + 1];                 // initialize expression with size

    //------------------------------------------------------------------------
    // evaluatePrefixHelper 
    // Evaluate a prefix expr made of single digit operands and operators +,-,*,/
    // This function will be called in evaluatePrefix
    int evaluatePrefixHelper(int&) const;

    //------------------------------------------------------------------------
    // toPostfix
    // convert prefix expression to postfix
    void toPostfix(int&, char[], int&) const;
};

#endif