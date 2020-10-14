#include "bintree.h"

//------------------------------- BinTree -------------------------------------
// Initialize the tree
BinTree::BinTree() {
    root = nullptr;
}

//------------------------------- BinTree -------------------------------------
// Copy constructor
// Preconditions: NONE
// Postconditions: Bin tree will have all other's nodes
BinTree::BinTree(const BinTree &other) {

}

//------------------------------- ~BinTree ------------------------------------
// Deconstructor
// Delete all nodes
// Preconditions: NONE
// Postconditions: Bin tree will be empty. Object is deleted
BinTree::~BinTree() {

    // early exit, tree is empty
    if (root == nullptr)
        return;

    // tree not empty
    // delete every node
    makeEmptyHelper(root);

    // root always null pointer
    root = nullptr;
}

//--------------------------------- insert ------------------------------------
// Insert the data into tree
// Lesser data goes to left, greater data go to right
// Preconditions: NONE
// Postconditions: BinTree will have one more node
bool BinTree::insert(NodeData* data) {
    
    // first node if tree is empty
    if (root == nullptr) {

        // add new node data, and assign left and right subtree null pointer
        root = new Node{ data, nullptr, nullptr };
        return true;
    }

    // tree already has root
    else
        return insertHelper(data, root);
}

//------------------------------ insertHelper ---------------------------------
// Helper method for insert
// Preconditions: NONE
// Postconditions: BinTree will have one more node
bool BinTree::insertHelper(NodeData * newNodeData, Node *& current) const {

    // base case
    if (current == nullptr) {
        current = new Node{ newNodeData, nullptr, nullptr };
        return true;
    }

    // travere left
    else if (*newNodeData < *current->data) {
        return insertHelper(newNodeData, current->left);
    }

    // traverse right
    else if (*newNodeData > *current->data) {
        return insertHelper(newNodeData, current->right);
    }

    // duplicate is not allowed
    else {
        return false;
    }
}

//------------------------------- retrieve ------------------------------------
// Make the retriever point to the target address
// Preconditions: NONE
// Postconditions: BinTree remains the same
bool BinTree::retrieve(const NodeData& target, NodeData*& retriever) const {
    
    // find the target by traversing recursively
    return retrieveHelper(root, target, retriever);
}

//---------------------------- retrieveHelper ---------------------------------
// Helper method for retrieve
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
bool BinTree::retrieveHelper(Node* current,
                            const NodeData &target, 
                            NodeData*& retriever) const {
    
    // target not found
    if (current == nullptr) {
        retriever = nullptr;
        return false;
    }

    // travere left-sub tree
    if (target < *current->data) {
        return retrieveHelper(current->left, target, retriever);
    }

    // traverse right-sub tree
    else if (target > *current->data) {
        return retrieveHelper(current->right, target, retriever);
    }

    // target is found
    else {
        retriever = current->data;
        return true;
    }
}

//------------------------------ getHeight ------------------------------------
// Return the node height of target
// Count from 1 up to end. Leaf node is 1
// Preconditions: NONE
// Postconditions: BinTree will be empty
int BinTree::getHeight(const NodeData& target) const {
    return 0;
}

//---------------------------- arrayToBSTree ----------------------------------
// Assign all nodes from array to Bintree
// Preconditions: NONE
// Postconditions: array will be empty
void BinTree::arrayToBSTree(NodeData* []arr) {
    return;
}

//--------------------------- displaySideways ---------------------------------
// Assign all node of Bintree to array
// Preconditions: NONE
// Postconditions: BinTree will be empty
void BinTree::bstreeToArray(NodeData* []arr) {
    return;
}

//--------------------------- displaySideways ---------------------------------
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output
// Preconditions: NONE
// Postconditions: BinTree remains unchanged
void BinTree::displaySideways() const {
    sideways(root, 0);
}

//------------------------------ sideways -------------------------------------
// Helper method for displaySideways
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
}

//--------------------------------- makeEmpty ---------------------------------
// Make tree empty
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
}


//---------------------------- makeEmptyHelper --------------------------------
// Helper method for makeEmpty
// Preconditions: NONE
// Postconditions: BinTree will be empty
void BinTree::makeEmptyHelper() const {
    
    // delete every node
    if (current != nullptr) {
        makeEmptyHelper(current->left);   // traverse left
        makeEmptyHelper(current->right);  // traverse right
        delete current->data;             // delete node data
        delete current;                   // delete node
    }
}

//--------------------------------- isEmpty -----------------------------------
// Check if the tree is empty
// Technically just check root
bool BinTree::isEmpty() const {
    return root == nullptr;
}

//------------------------------- operator= -----------------------------------
// Helper method for makeEmpty
// Preconditions: NONE
// Postconditions: BinTree wil be identical as other Bintree
BinTree& BinTree::operator=(const BinTree& other) {
    return *this;
}

//------------------------------- operator== ----------------------------------
// Helper method for makeEmpty
// Preconditions: NONE
// Postconditions: BinTree remains the same
bool BinTree::operator==(const BinTree& other) const {
    return false;
}

//------------------------------- operator!= ----------------------------------
// Helper method for makeEmpty
// Preconditions: NONE
// Postconditions: BinTree remains the same
bool BinTree::operator!=(const BinTree& other) const {
    return false;
}