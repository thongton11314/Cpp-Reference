// You add all other appropriate comments. And remove my comments to you.

// While I have done much of this for you, make sure you understand it all.
// Make sure you understand why the parameters are pass by reference
// in evaluatePrefixHelper and toPostfix.

#include "prefix.h"

//-----------------------------------------------------------------------------
// constructor
// initialize the array to the empty string,
// char arrays end with '\0' (null character) so operator<< works properly

Prefix::Prefix() {
    expr[0] = '\0';
}

//-----------------------------------------------------------------------------
// setPrefix
// Set a prefix expression made of single digit operands, operators +,-,*,/
// and no blanks or tabs contained in a file. The expression is valid in
// that each valid operator has two valid operands.

void Prefix::setPrefix(ifstream& infile) {
    infile >> expr;
}

//-----------------------------------------------------------------------------
// evaluatePrefix 
// Evaluate a prefix expr made of single digit operands and operators +,-,*,/
// Return the answer (integer arithmetic).

int Prefix::evaluatePrefix() const {
    if (expr[0] == '\0')                          // empty string
        return 0;

    int index = -1;                               // to walk through expr
    return evaluatePrefixHelper(index);           // evaluate expression
}

//-----------------------------------------------------------------------------
// evaluatePrefixHelper 
// Evaluate a prefix expr made of single digit operands and operators +,-,*,/
// This function will be called in evaluatePrefix

int Prefix::evaluatePrefixHelper(int& index) const {
    char symbol = expr[++index];    // get a symbol from expression
    
    // if the symbol is number, return it's value
    if (isdigit(symbol)) {
        return symbol - '0';
    }

    // if the symbol is operator, get next prefix
    else {

        // check 1st number after symbol
        int leftOp = evaluatePrefixHelper(index);
        
        // check 2nd number after symbol
        int rightOp = evaluatePrefixHelper(index);

        // check for which operator of the symbol
        switch (symbol) {
        case '+':
            return leftOp + rightOp;    // evaluate adding arithmetic
        case '-':
            return leftOp - rightOp;    // evaluate different arithmetic
        case '*':
            return leftOp * rightOp;    // evaluate multiply arithmetic
        case '/':
            return leftOp / rightOp;    // evaluate divide arithmetic
        default:
            return -1;                  // non of the case abover
        }
    }
}

//-----------------------------------------------------------------------------
// outputAsPostfix, toPostfix
// Convert prefix expression to postfix and output

void Prefix::outputAsPostfix(ostream& out) const {
    if (expr[0] == '\0')                      // empty string
        return;

    int index = -1;                           // to walk through expr
    int count = -1;                           // used to build postfix array
    char postfix[MAXSIZE + 1];                // holds postfix expression
    toPostfix(index, postfix, count);         // convert prefix to post fix
    postfix[++count] = '\0';                  // assign last element for array
    out << postfix;                           // assign expression into ostream
}

//-----------------------------------------------------------------------------
// toPostfix
// convert prefix expression to postfix

void Prefix::toPostfix(int& index, char postfix[], int& count) const {
    char symbol = expr[++index];    // get a symbol from expression

    // if the symbol is number, add it into array
    if (isdigit(symbol)) {
        postfix[++count] = symbol;
    }

    // if symbol is operator, recursively check next operant
    else {

        // recursively check left operant
        toPostfix(index, postfix, count);

        // recursively check right operant
        toPostfix(index, postfix, count);

        // add the symbol after left, right operant
        postfix[++count] = symbol;
    }
}

//-----------------------------------------------------------------------------
// operator<<
// display prefix expression as a string (char array)

ostream& operator<<(ostream& output, const Prefix& expression) {
    output << expression.expr;
    return output;
}
