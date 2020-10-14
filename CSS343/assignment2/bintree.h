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

    // make the tree empty so isEmpty returns true
    void makeEmpty();

    // true if tree is empty, otherwise false
    bool isEmpty() const;

    // overload operator
    BinTree& operator=(const BinTree &);
    bool operator==(const BinTree &) const;
    bool operator!=(const BinTree &) const;

private:
    struct Node {
        NodeData* data;                    // pointer to data object
        Node* left;	                       // left subtree pointer
        Node* right;					   // right subtree pointer
    };
    Node* root;						       // root of the tree

    // utility functions
    void copyHelper(Node*&, Node*);                      // copy other Bintree
    bool insertHelper(NodeData *, Node *&);          // helper for insert
    void makeEmptyHelper(Node*&);          // helper for make empty
    bool retrieveHelper(Node*, 
                        const NodeData &,
                        NodeData*&) const; // helper for retrieve
    void sideways(Node*, int) const;       // helper for displaySideways()
};
#endif //!_Bin_Tree_