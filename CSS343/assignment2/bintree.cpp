// ------------------------------- BinTree.cpp --------------------------------
// Programmer: Thong Ton
// Course: CSS343
// Creation Date: 10/14/2020
// Date of Last Modification: 10/18/2020
// ----------------------------------------------------------------------------
// Purpose: 
//  - This is implementation of BinTree.h
// ----------------------------------------------------------------------------
#include "bintree.h"

//------------------------------- BinTree -------------------------------------
// Initialize the tree
BinTree::BinTree() {
    root = nullptr;
} // end of constructor

//------------------------------- BinTree -------------------------------------
// Copy constructor
// Preconditions: NONE
// Postconditions: BinTree will have all identical other's BinTree nodes
BinTree::BinTree(const BinTree &other) {

    // invoke helper to recursively traverse tree
    copyHelper(root, other.root);
} // end of copy constructor

//------------------------------- copyHelper ----------------------------------
// Helper function for copy constructor and operator=
// Preconditions: copy constructor and operator= must be called
// Postconditions: BinTree has new identical data as other Bintree 
void BinTree::copyHelper(Node*& current, Node* other) {

    // base case
    if (other != nullptr) {

        // create new node
        // add new NodeData, assign left and right subtree to null pointer
        current = new Node { new NodeData ( *other->data ), nullptr, nullptr };

        // traverse left
        copyHelper(current->left, other->left);

        // traverse right
        copyHelper(current->right, other->right);
    }
} // end of copyHelper

//------------------------------- ~BinTree ------------------------------------
// Deconstructor
// Delete all nodes
// Preconditions: BinTree must be instantiated.
// Postconditions: BinTree left empty. This object is deleted
BinTree::~BinTree() {

    // delete all nodes
    makeEmpty();    
} // end of deconstructor

//--------------------------------- insert ------------------------------------
// Insert the data into tree
// Lesser data goes to left subtree, greater data go to right subtree
// Ignore duplicated node
// Return true if successfully insert, false if not
// Preconditions: data must be given
// Postconditions: BinTree have new node if insert successfully
bool BinTree::insert(NodeData* data) {
    
    // first node if tree is empty
    if (root == nullptr) {

        // add new node data, and assign left and right subtree to null pointer
        root = new Node{ data, nullptr, nullptr };
        return true;
    }
    return insertHelper(data, root);
} // end of insert

//------------------------------ insertHelper ---------------------------------
// Helper function for insert
// Preconditions: insert function must exist
// Postconditions: BinTree will have one more node
bool BinTree::insertHelper(NodeData * newNodeData, Node *& current) {

    // base case
    if (current == nullptr) {

        // add new node data, and assign left and right subtree to null pointer
        current = new Node{ newNodeData, nullptr, nullptr };
        return true;
    }

    // traverse left subtree
    else if (*newNodeData < *current->data) {
        return insertHelper(newNodeData, current->left);
    }

    // traverse right subtree
    else if (*newNodeData > *current->data) {
        return insertHelper(newNodeData, current->right);
    }

    // duplicate is not allowed, being ignore
    else {
        return false;
    }
} // end of insertHelper

//------------------------------- retrieve ------------------------------------
// Make the retriever point to the target address
// Return true if target is matched, false if not
// Preconditions: target and a pointer must be given
// Postconditions: BinTree remains the same
bool BinTree::retrieve(const NodeData& target, NodeData*& retriever) const {
    
    // traversing recursively find target
    return retrieveHelper(root, target, retriever);
} // end of retrieve

//---------------------------- retrieveHelper ---------------------------------
// Helper function for retrieve
// Preconditions: retrieve must be called
// Postconditions: BinTree remains unchanged.
bool BinTree::retrieveHelper(Node* current,
                            const NodeData &target, 
                            NodeData*& retriever) const {
    
    // target not found
    if (current == nullptr) {
        retriever = nullptr;
        return false;
    }

    // traverse left-subtree
    if (target < *current->data) {
        return retrieveHelper(current->left, target, retriever);
    }

    // traverse right-subtree
    else if (target > *current->data) {
        return retrieveHelper(current->right, target, retriever);
    }

    // target is found
    else {
        retriever = current->data;
        return true;
    }
} // end of retrieveHelper

//------------------------------ getHeight ------------------------------------
// Return target's max height value
// Preconditions: node target must be given
// Postconditions: BinTree remains unchanged.
int BinTree::getHeight(const NodeData& target) const {

    // recursively traverse to find target max height
    return getHeightHelper(root, target);
} // end of getHeight

//------------------------------ getHeightHelper ------------------------------
// Find the target and return it's height to getHeight function if found
// Use pre-order to track target
// Preconditions: getHeight must be called
// Postconditions: BinTree remains unchanged.
int BinTree::getHeightHelper(Node* current, const NodeData& target) const {
    
        
    // base case, if not found data
    if (current == nullptr) {
        return 0;
    }

    // if found data
    else if (*current->data == target) {

        // recursive traverse to find max length of this node
        return findMax(current);
    }

    // keep recursively traversing 
    else {
        int maxLength; // hold max length                               

        // traverse left and hold left max length
        int left = getHeightHelper(current->left, target); 

        // traverse right and hold right max length
        int right = getHeightHelper(current->right, target);

        // find max length
        left > right ? maxLength = left : maxLength = right;
        return maxLength;
    }
} // end of getHeightHelper

//---------------------------------- findMax ----------------------------------
// Return found node's max height to getHeightHelper function
// Preconditions: The node must be found from getHeightHelper
// Postconditions: Node remains unchanged.
int BinTree::findMax(Node* current) const {

    // base case
    if (current == nullptr) {
        return 0;
    }

    // add up if found more node
    else {
        int maxLength;  // hold max length

        // traverse left and hold left max length
        // overwrite left until reach the higest height
        int left = findMax(current->left);

        // traverse right and hold right max length
        // overwrite right until reach the higest height
        int right = findMax(current->right);

        // find max length
        left > right ? maxLength = left : maxLength = right;
        return 1 + maxLength;
    }
} // end of findMax

//---------------------------- arrayToBSTree ----------------------------------
// Assign all nodes from array to BinTree
// Preconditions: dynamic array must be given
// Postconditions: array will be empty, 
//                 old BinTree will be replaced by new BinTree value       
void BinTree::arrayToBSTree(NodeData* arr[]) {
    
    // clear this tree
    makeEmpty();

    // check max index
    int high = 0;
    for (int i = 0; i < MAXSIZE; i++) {
        if (arr[i] != nullptr) {
            high++;
        }
        else {
            arr[i] = nullptr;
        }        
    }
    
    // assign new data from array to this tree
    arrayToBSTHelper(root, arr, 0, high - 1);
    return;
} // end of arrayToBSTree

//---------------------------- arrayToBSTHelper ----------------------------------
// Assign all nodes from array to BinTree
// Preconditions: arrayToBSTree must be called
// Postconditions: array will be empty
void BinTree::arrayToBSTHelper(Node* current, NodeData* arr[], int low, int high) {
    
    // base case
    if (low > high) {
        current = nullptr;
    }

    // recursively add to tree
    else {
        int mid = (low + high) / 2; // get parent node from array
        insert(arr[mid]);           // insert new node

        // fill left
        arrayToBSTHelper(current, arr, low, mid - 1);

        // fill right
        arrayToBSTHelper(current, arr, mid + 1, high);
    }
} // end of arrayToBSTHelper

//--------------------------- bstToArray ---------------------------------
// Assign all node of Bintree to array
// Fill value from BinTree to array by in order traverse
// Preconditions: dynamic array must be given
// Postconditions: BinTree will be empty
void BinTree::bstreeToArray(NodeData* arr[]) {

    // index for array
    int index = -1;

    // assign tree's data to arr
    bstToArrayHelper(root, arr, index);
    
    // last NodeData in array is nullptr
    arr[index + 1] = nullptr;

    // clear this tree
    root = nullptr;
    return;
} // end of bstreeToArray

//--------------------------- bstToArrayHelper --------------------------------
// Assign all node of Bintree to array
// Preconditions: bstreeToArray must be called
// Postconditions: BinTree will be empty, dynamic array hold all BinTree values
void BinTree::bstToArrayHelper(Node* current, NodeData* arr[], int& index) {

    if (current != nullptr) {

         // traverse left
        bstToArrayHelper(current->left, arr, index);

        // assign current node to array
        arr[++index] = current->data;

        // current node data no longer hold any data
        current->data = nullptr;

        // traverse right
        bstToArrayHelper(current->right, arr, index);

        // delete node
        delete current;
    }    
    return;
} // end of bstToArrayHelper

//--------------------------- displaySideways ---------------------------------
// Displays a binary tree as though you are viewing it from the side
// hard coded displaying to standard output
// Preconditions: NONE
// Postconditions: BinTree remains unchanged
void BinTree::displaySideways() const {
    sideways(root, 0);
}

//------------------------------ sideways -------------------------------------
// Helper function for displaySideways
// Preconditions: NONE
// Postconditions: BinTree remains unchanged
void BinTree::sideways(Node* current, int level) const {
    if (current != NULL) {
        level++;
        sideways(current->right, level);

        // indent for readability, 4 spaces per depth level 
        for (int i = level; i >= 0; i--) {
            cout << "    ";
        }

        cout << *current->data << endl;   // display information of object
        sideways(current->left, level);
    }
} // end of sideways

//--------------------------------- makeEmpty ---------------------------------
// Make BinTree empty
// Preconditions: NONE
// Postconditions: BinTree remains unchanged
void BinTree::makeEmpty() {

    // early exit, tree is empty
    if (root == nullptr)
        return;

    // tree not empty
    // delete every node
    makeEmptyHelper(root);

    // root always null pointer
    root = nullptr;
} // end of makeEmpty

//---------------------------- makeEmptyHelper --------------------------------
// Helper function for makeEmpty
// Preconditions: NONE
// Postconditions: BinTree will be empty
void BinTree::makeEmptyHelper(Node*& current) {
    
    // delete every node
    if (current != nullptr) {
        makeEmptyHelper(current->left);   // traverse left
        makeEmptyHelper(current->right);  // traverse right

        // delete node data
        if (current->data != nullptr) {
            delete current->data;
        }

        delete current;                   // delete node
    }
} // end of makeEmptyHelper

//--------------------------------- isEmpty -----------------------------------
// Return true if tree is empty, false if not
// Preconditions: NONE
// Postconditions: NONE
bool BinTree::isEmpty() const {
    return root == nullptr;
} // end of isEmpty

//------------------------------- operator= -----------------------------------
// Assign other BinTree to this BinTree
// Preconditions: Other BinTree must be given
// Postconditions: BinTree wil be identical as other Bintree
BinTree& BinTree::operator=(const BinTree& other) {
    
    // check if two root are not identical
    if (root != other.root) {
        makeEmpty();
        copyHelper(root, other.root);
    }
    return *this;
} // end of operator=

//------------------------------- operator== ----------------------------------
// Compare two BinTree if they are same value and structure
// Return true if identical, else false
// Preconditions: NONE
// Postconditions: BinTree remains the same
bool BinTree::operator==(const BinTree& other) const {

    // check if two root address are not identical
    if (root != other.root) {
        return comparisionHelper(root, other.root);
    }

    // identical if two root has same address
    else 
        return true;
}

//----------------------------- comparisionHelper -----------------------------
// Helper function for operator==
// Preconditions: NONE
// Postconditions: BinTree remains the same
bool BinTree::comparisionHelper(Node* current, Node* otherCurrent) const {

    // base case, early exit
    if (current == nullptr && otherCurrent == nullptr) 
        return true; 
    else if (current != nullptr && otherCurrent == nullptr)
        return false; 
    else if (current == nullptr && otherCurrent != nullptr)
        return false; 

    // recursively traverse
    else {

        // must be same data, same structure
        if (*current->data == *otherCurrent->data 
            && comparisionHelper(current->left, otherCurrent->left) 
            && comparisionHelper(current->right, otherCurrent->right))
            return true;

        // not same data and same structure
        else
            return false; 
    } 
} // end of comparisionHelper

//------------------------------- operator!= ----------------------------------
// Compare two BinTree if they aren't same value and structure
// Return true if not identical, else false
// Preconditions: NONE
// Postconditions: BinTree remains the same
bool BinTree::operator!=(const BinTree& other) const {    
    return !(*this == other);
} // end of operator!=

//------------------------------- operator<< ----------------------------------
// Print out the BinTree
// In-order traverse
// Preconditions: NONE
// Postconditions: BinTree remains the same
ostream& operator<<(ostream& out, const BinTree& tree) {
    tree.inOrderHelper(out, tree.root);
    return out;
} // end of operator<<

//------------------------------- inOrderHelper -------------------------------
// Helper for operator<<
// Preconditions: NONE
// Postconditions: BinTree remains the same
void BinTree::inOrderHelper(ostream& out, Node * current) const {
    
    // base case
    if (current == nullptr)
        return;

    // get from left to right subtree
    else {
        inOrderHelper(out, current->left);
        out << *current->data << " ";
        inOrderHelper(out, current->right);
    }
} // end of inOrderHelper