// ------------------------------- BinTree.h ----------------------------------
// Programmer: Thong Ton
// Course: CSS343
// Creation Date: 10/14/2020
// Date of Last Modification: 10/16/2020
// ----------------------------------------------------------------------------
// Purpose: 
//  - This project is to create a binary search tree class called BinTree 
//    along with some additional functions.
// ----------------------------------------------------------------------------
#ifndef _Bin_Tree_
#define _Bin_Tree_
#include <iostream>
#include "nodedata.h"

using namespace std;

const int MAXSIZE = 100;

//-----------------------------------------------------------------------------
// Class BinTree
//   - A BinTree is defined as a binary search tree, which no node have more 
//     than two children.
//
// Assumption:
//   - All node to the left-subtree is smaller node.
//   - All node to the right-subtree is greater node.
//   - Discard duplicated node.
//
// Implementation:
//   - These function need helper function to recursively traverse tree:
//      - copy constructor: need copyHelper
//      - insert: need insertHelper
//      - retrieve: need retrieveHelper
//      - getHeight: need getHeightHelper, 
//                   then use findMax to get subtree highest height              
//      - arrayToBSTree: need arrayToBSTHelper
//      - bstreeToArray: need bstToArrayHelper
//      - makeEmpty: need makeEmptyHelper
//  - After the call arrayToBSTree, array is empty, 
//    the BinTree is filled by array value
//  - After the call bstreeToArray, array BinTree is empty, 
//    the array is filled by BinTree value     
//-----------------------------------------------------------------------------
class BinTree {

    // overloaded output operator for class Poly
    friend ostream& operator<<(ostream &, const BinTree&);

public:

    // constructor
    BinTree();                    // default constructor
    BinTree(const BinTree &);     // copy constructor
                        
    // deconstructor
    ~BinTree();

    // insert node
    bool insert(NodeData*);

    // retrieve node
    bool retrieve(const NodeData &, NodeData* &) const;

    // get node height
    int getHeight(const NodeData &) const;

    // convert tree to array and vice versa
    void arrayToBSTree(NodeData* []);   // array to tree
    void bstreeToArray(NodeData* []);   // bts to tree
    
    // displays the tree sideways
    void displaySideways() const;

    // make the tree empty
    void makeEmpty();

    // check if BinTree empty
    bool isEmpty() const;

    // overload operator
    BinTree& operator=(const BinTree &);
    bool operator==(const BinTree &) const;
    bool operator!=(const BinTree &) const;

private:
    struct Node {
        NodeData* data;                         // pointer to data object
        Node* left;	                            // left subtree pointer
        Node* right;					        // right subtree pointer
    };
    Node* root;						            // root of the tree

    // utility functions
    void copyHelper(Node*&, Node*);             // helper for copy constructor
    bool insertHelper(NodeData *, Node *&);     // helper for insert
    bool retrieveHelper(Node*, 
                        const NodeData &,
                        NodeData*&) const;      // helper for retrieve    

    // helper for getHeight
    int getHeightHelper(Node*, const NodeData&) const;

    // helper for getHeightHelper to get subtree max height
    int findMax(Node*) const;

    // helper for bstreeToArray
    void bstToArrayHelper(Node*, NodeData* [], int& index);

    // helper for arrayToBSTree
    void arrayToBSTHelper(Node*, NodeData* [], int low, int high);
    void makeEmptyHelper(Node*&);               // helper for make empty
    bool comparisionHelper(Node*, Node*) const; // helper for comparision
    void inOrderHelper(ostream&, Node*) const;  // helper for ostream
    void sideways(Node*, int) const;            // helper for displaySideways
};
#endif //!_Bin_Tree_