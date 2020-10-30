// ------------------------------- bintree.h ----------------------------------
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
//    the BinTree is filled by array value.
//  - After the call bstreeToArray, array BinTree is empty, 
//    the array is filled by BinTree value.
//-----------------------------------------------------------------------------
class BinTree {

    //------------------------------- operator<< ------------------------------
    // Print out the BinTree
    // Use In-order traverse method
    // Preconditions: NONE
    // Postconditions: BinTree remains the same
    friend ostream& operator<<(ostream &, const BinTree&);

public:

    //------------------------------- BinTree ---------------------------------
    // Default constructor
    // Initialize the tree
    BinTree();


    //------------------------------- BinTree ---------------------------------
    // Copy constructor
    // Preconditions: NONE
    // Postconditions: BinTree will have all identical other's BinTree nodes
    BinTree(const BinTree &);
                        
    //------------------------------- ~BinTree --------------------------------
    // Deconstructor
    // Delete all nodes
    // Preconditions: BinTree must be instantiated.
    // Postconditions: BinTree left empty node. This object is deleted
    ~BinTree();

    //--------------------------------- insert --------------------------------
    // Insert the data into tree
    // Lesser data goes to left subtree, greater data go to right subtree
    // Ignore duplicated node, return false
    // Return: true if successfully insert,
    //         false if not and duplicated node
    // Preconditions: NONE
    // Postconditions: BinTree have new node if insert successfully
    bool insert(NodeData*);

    //------------------------------- retrieve --------------------------------
    // Make the retriever pointer point to the target address
    // Return: true if target is matched, 
    //         false if not
    // Preconditions: NONE
    // Postconditions: BinTree remains the same
    bool retrieve(const NodeData &, NodeData* &) const;

    //------------------------------ getHeight --------------------------------
    // Return target's max height value
    // Preconditions: NONE
    // Postconditions: BinTree remains unchanged.
    int getHeight(const NodeData &) const;

    //---------------------------- arrayToBSTree ------------------------------
    // Assign all nodes from array to BinTree
    // Preconditions: NONE
    // Postconditions: array will be empty, 
    //                 old BinTree will be replaced by new BinTree value
    void arrayToBSTree(NodeData* []);

    //--------------------------- bstreeToArray -------------------------------
    // Assign all node of Bintree to array
    // Use in order traverse to fill value from BinTree to array
    // Preconditions: NONE
    // Postconditions: BinTree will be empty
    void bstreeToArray(NodeData* []);
    
    //--------------------------- displaySideways -----------------------------
    // Displays a binary tree as though you are viewing it from the side
    // hard coded displaying to standard output
    // Preconditions: NONE
    // Postconditions: BinTree remains unchanged
    void displaySideways() const;

    //--------------------------------- makeEmpty -----------------------------
    // Make BinTree empty
    // Preconditions: NONE
    // Postconditions: BinTree remains unchanged
    void makeEmpty();

    //--------------------------------- isEmpty -------------------------------
    // Return: true if tree is empty, 
    //         false if not
    // Preconditions: NONE
    // Postconditions: NONE
    bool isEmpty() const;

    //------------------------------- operator= -------------------------------
    // Assign other BinTree to this BinTree
    // Preconditions: NONE
    // Postconditions: BinTree wil be identical as other Bintree
    BinTree& operator=(const BinTree &);

    //------------------------------- operator== ------------------------------
    // Compare two BinTree if they are same value and structure
    // Return: true if identical, 
    //         false if not
    // Preconditions: NONE
    // Postconditions: BinTree remains the same
    bool operator==(const BinTree &) const;

    //------------------------------- operator!= ------------------------------
    // Compare two BinTree if they aren't same value and structure
    // Return: true if not identical, 
    //         false if identical
    // Preconditions: NONE
    // Postconditions: BinTree remains the same
    bool operator!=(const BinTree &) const;

private:
    struct Node {
        NodeData* data;                         // pointer to data object
        Node* left;	                            // left subtree pointer
        Node* right;					        // right subtree pointer
    };
    Node* root;						            // root of the tree

    /* all bellow are utility functions */

    //------------------------------- copyHelper ------------------------------
    // Helper function for copy constructor and operator=
    // Preconditions: copy constructor and operator= must be called
    // Postconditions: BinTree has new identical data as other Bintree 
    void copyHelper(Node*&, Node*);

    //------------------------------ insertHelper -----------------------------
    // Helper function for insert
    // Preconditions: insert function must exist
    // Postconditions: BinTree will have one more node
    bool insertHelper(NodeData *, Node *&);

    //---------------------------- retrieveHelper -----------------------------
    // Helper function for retrieve
    // Preconditions: retrieve must be exist
    // Postconditions: BinTree remains unchanged.
    bool retrieveHelper(Node*, 
                        const NodeData &,
                        NodeData*&) const;  

    //------------------------------ getHeightHelper --------------------------
    // Find the target and return it's height to getHeight function if found
    // Use pre-order method to track target
    // Preconditions: getHeight must be called
    // Postconditions: BinTree remains unchanged.
    int getHeightHelper(Node*, const NodeData&) const;

    //---------------------------------- findMax ------------------------------
    // Return found node's max height to getHeightHelper function
    // Preconditions: The node must be found from getHeightHelper
    // Postconditions: Node remains unchanged.
    int findMax(Node*) const;

    //--------------------------- bstToArrayHelper ----------------------------
    // Assign all node of Bintree to array
    // Preconditions: bstreeToArray must be exist
    // Postconditions: BinTree will be empty, 
    //                 dynamic array will hold all BinTree's values
    void bstToArrayHelper(Node*, NodeData* [], int& index);

    //---------------------------- arrayToBSTHelper ---------------------------
    // Assign all nodes from array to BinTree
    // Preconditions: arrayToBSTree must be exist
    // Postconditions: array will be empty
    void arrayToBSTHelper(Node*, NodeData* [], int low, int high);

    //---------------------------- makeEmptyHelper ----------------------------
    // Helper function for makeEmpty
    // Preconditions: makeEmpty must exist
    // Postconditions: BinTree will be empty
    void makeEmptyHelper(Node*&);

    //----------------------------- comparisionHelper -------------------------
    // Helper function for operator==
    // Preconditions: comparision operator must exist
    // Postconditions: BinTree remains the same
    bool comparisionHelper(Node*, Node*) const;

    //------------------------------- inOrderHelper ---------------------------
    // Helper for operator<<
    // Preconditions: NONE
    // Postconditions: BinTree remains the same
    void inOrderHelper(ostream&, Node*) const;
    
    //------------------------------ sideways ---------------------------------
    // Helper function for displaySideways
    // Preconditions: NONE
    // Postconditions: BinTree remains unchanged
    void sideways(Node*, int) const;
};
#endif //!_Bin_Tree_