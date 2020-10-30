// I will test your BinTree class using either this main or
// a very similar one, and this buildTree.  
// You will want to do thorough testing on your own, 
// which is done by altering the data.

// Windows and unix store files slightly differently. Windows does not
// always store an end-of-line char on the last line, where unix does.
// On windows, always make sure the cursor is on the line after
// the last line of data so it acts like unix/linux.

// presumably bintree.h includes nodedata.h so the include is not needed here
#include "bintree.h"
#include <fstream>
#include <iostream>
using namespace std;

const int ARRAYSIZE = 100;

//global function prototypes
void buildTree(BinTree&, ifstream&);     // 
void initArray(NodeData*[]);
void printArray(NodeData*[]);
void deleteArray(NodeData* ndArray[]);
int main() {

	// the NodeData class must have a constructor that takes a string
    //iii not tttt eee r not and jj r eee pp r sssss eee not tttt ooo ff  m m y z
    BinTree test;
    test.insert(new NodeData("iii"));
    test.insert(new NodeData("not"));
    test.insert(new NodeData("tttt"));
    test.insert(new NodeData("eee"));
    test.insert(new NodeData("r"));
    test.insert(new NodeData("not"));
    test.insert(new NodeData("and"));
    test.insert(new NodeData("jj"));
    test.insert(new NodeData("r"));
    test.insert(new NodeData("eee"));
    test.insert(new NodeData("pp"));
    test.insert(new NodeData("r"));
    test.insert(new NodeData("sssss"));
    test.insert(new NodeData("eee"));
    test.insert(new NodeData("not"));
    test.insert(new NodeData("tttt"));
    test.insert(new NodeData("ooo"));
    test.insert(new NodeData("ff"));
    test.insert(new NodeData("m"));
    test.insert(new NodeData("m"));
    test.insert(new NodeData("y"));
    test.insert(new NodeData("z"));
    test.displaySideways();
    cout << endl << endl << endl << endl << endl;
    BinTree testCopy(test);
    testCopy.displaySideways();
    cout << endl << endl << endl << endl << endl;
    BinTree testOperator;
    testOperator = testCopy;
    testOperator.displaySideways();
    BinTree aaa;
    if (testOperator == testCopy 
        && testCopy == test
        && aaa != test)
        cout << "Operator" << "\t PASSED" << endl;
    else
        cout << "Operator" << "\t FAILED" << endl;
    cout << endl << endl << endl << endl << endl;
    cout << "aaa" << aaa << endl;
    cout << "test: " << test << endl;

    // array
    NodeData* ndArray[ARRAYSIZE];
    initArray(ndArray);

    // bst -> arr
    cout << "Test bst to array" << endl;
	test.bstreeToArray(ndArray);
	printArray(ndArray);
    cout << endl;

    // arr -> bst
    cout << "Test array to bst" << endl;
    test.arrayToBSTree(ndArray);
    test.bstreeToArray(ndArray);
	printArray(ndArray);
    cout << endl;
    
    deleteArray(ndArray);
}


//------------------------------- initArray ----------------------------------
// initialize the array of NodeData* to NULL pointers

void initArray(NodeData* ndArray[]) {
	for (int i = 0; i < ARRAYSIZE; i++)
		ndArray[i] = NULL;
}

void printArray(NodeData* ndArray[]) {
    int size = 0;
    while (ndArray[size] != nullptr)
        cout << *ndArray[size++] << " ";
    cout << endl;
}

void deleteArray(NodeData* ndArray[]) {
    int size = 0;
    while (ndArray[size] != nullptr)
        delete ndArray[size++];
    cout << endl;
}