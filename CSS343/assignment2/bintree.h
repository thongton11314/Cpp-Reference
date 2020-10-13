#ifndef _Bin_Tree_
#define _Bin_Tree_
#include <iostream>
#include "nodedata.h"

using namespace std;

class BinTree {

    // overloaded output operator for class Poly
    friend ostream& operator<<(ostream &, const BinTree &);

    // overloaded input operator for class Poly
    friend istream& operator>>(istream &, BinTree &);

public:

    // constructor
    BinTree();					  // constructor
    BinTree(const BinTree &);	  // copy constructor
                        
    // deconstructor
    ~BinTree();

    // true if tree is empty, otherwise false
    bool isEmpty() const;

    // make the tree empty so isEmpty returns true
    void makeEmpty();
    
    // overload operator
    BinTree& operator=(const BinTree &);
    bool operator==(const BinTree &) const;
    bool operator!=(const BinTree &) const;

    // insert node
    bool insert(NodeData*);

    // retrieve node
    bool retrieve(const NodeData &, NodeData* &) const;

    // get node height
    int getHeight(const NodeData &) const;

    // convert tree to array and vice versa
    void arrayToBSTree(NodeData* []);       // array to tree
    void bstreeToArray(NodeData* []);       // bts to tree
    
    // provided below, displays the tree sideways
    void displaySideways() const;
private:
    struct Node {
        NodeData* data;						// pointer to data object
        Node* left;							// left subtree pointer
        Node* right;						// right subtree pointer
    };
    Node* root;								// root of the tree

    // utility functions
    void inorderHelper( ... ) const;
    void sideways(Node*, int) const;		// provided below, helper for displaySideways()
};

//------------------------- displaySideways ---------------------------------
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::displaySideways() const {
    sideways(root, 0);
}

//---------------------------- Sideways -------------------------------------
// Helper method for displaySideways
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::sideways(Node* current, int level) const {
    if (current != NULL) {
        level++;
        sideways(current->right, level);

        // indent for readability, 4 spaces per depth level 
        for (int i = level; i >= 0; i--) {
            cout << "    ";
        }

        cout << *current->data << endl;        // display information of object
        sideways(current->left, level);
    }
}
#endif //!_Bin_Tree_