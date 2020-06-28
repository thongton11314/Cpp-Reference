//////////////////////////////  nodedata.h  //////////////////////////////////
// Simple object containing one integer and one character

#ifndef NODEDATA_H
#define NODEDATA_H

#include <iostream>
#include <fstream>
using namespace std;

//---------------------------  class NodeData  ------------------------------
class NodeData {                                 // incomplete class
    friend ostream& operator<<(ostream &, const NodeData &);

public:
    NodeData(int n = 0, char c = 'z');       // default constructor
    bool setData();                          // sets data by prompting user
    bool setData(ifstream&);                 // reads data from file

    // <, > are defined by order of num; if nums are equal, ch is compared
    bool operator<(const NodeData& N) const;
    bool operator>(const NodeData& N) const;
    bool operator==(const NodeData& N) const;
    bool operator!=(const NodeData& N) const;

    // other operators: >=, <= are left to the reader

private:
    int num;
    char ch;
};

#endif