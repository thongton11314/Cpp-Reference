#ifndef _Bin_Tree_
#define _Bin_Tree_
#include <iostream>
#include "nodedata.h"

using namespace std;

// Assumption:
//  - Duplicate notes will be discard
//  - Smaller note will be stored at left, bigger will be stored at right
class BinTree {

    // overloaded output operator for class Poly
    friend ostream& operator<<(ostream &, const BinTree &);

    // overloaded input operator for class Poly
    friend istream& operator>>(istream &, BinTree &);

public:

    // constructor
    BinTree();                    // constructor
    BinTree(const BinTree &);	  // copy constructor
                        
    // deconstructor
    ~BinTree();
    

    // true if tree is empty, otherwise false
    bool isEmpty() const;

    // make the tree empty so isEmpty returns true
    void makeEmpty();

    // insert node
    bool insert(NodeData*);

    // retrieve node
    bool retrieve(const NodeData &, NodeData* &) const;

    // get node height
    int getHeight(const NodeData &) const;

    // convert tree to array and vice versa
    void arrayToBSTree(NodeData* []);   // array to tree
    void bstreeToArray(NodeData* []);   // bts to tree
    
    // provided below, displays the tree sideways
    void displaySideways() const;

    // overload operator
    BinTree& operator=(const BinTree &);
    bool operator==(const BinTree &) const;
    bool operator!=(const BinTree &) const;
    
    // Hi there
private:
    struct Node {
        NodeData* data;                 // pointer to data object
        Node* left;	                    // left subtree pointer
        Node* right;					// right subtree pointer
    };
    Node* root;						    // root of the tree

    // utility functions
    void inorderHelper() const;
    void sideways(Node*, int) const;    // helper for displaySideways()
};
#endif //!_Bin_Tree_