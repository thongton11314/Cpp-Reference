#include "bintree.h"

BinTree::BinTree() {

}

BinTree::BinTree(const BinTree &) {

}

BinTree::~BinTree() {

}

bool BinTree::isEmpty() const {
    return false;
}

void BinTree::makeEmpty() {
    return;
}

bool BinTree::insert(NodeData*) {
    return false;
}

bool BinTree::retrieve(const NodeData &, NodeData* &) const {
    return false;
}

int BinTree::getHeight(const NodeData &) const {
    return 0;
}

void BinTree::arrayToBSTree(NodeData* []) {
    return;
}

void BinTree::bstreeToArray(NodeData* []) {
    return;
}

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

        cout << *current->data << endl;   // display information of object
        sideways(current->left, level);
    }
}

BinTree& BinTree::operator=(const BinTree &) {
    return *this;
}

bool BinTree::operator==(const BinTree &) const {
    return false;
}

bool BinTree::operator!=(const BinTree &) const {
    return false;
}
