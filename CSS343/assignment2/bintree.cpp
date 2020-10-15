#include "bintree.h"

//------------------------------- BinTree -------------------------------------
// Initialize the tree
BinTree::BinTree() {
    root = nullptr;
} // end of constructor

//------------------------------- BinTree -------------------------------------
// Copy constructor
// Preconditions: NONE
// Postconditions: Bin tree will have all other's nodes
BinTree::BinTree(const BinTree &other) {
    copyHelper(root, other.root);
} // end of copy constructor

//------------------------------- copyHelper ----------------------------------
// Helper method for copy constructor and operator=
// Preconditions: NONE
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
} // end of deconstructor

//--------------------------------- insert ------------------------------------
// Insert the data into tree
// Lesser data goes to left, greater data go to right
// Duplicate data will be deleted
// Preconditions: NONE
// Postconditions: BinTree will have one more node
bool BinTree::insert(NodeData* data) {
    
    // use to check if successful insert
    bool isInsert;

    // first node if tree is empty
    if (root == nullptr) {

        // add new node data, and assign left and right subtree to null pointer
        root = new Node{ data, nullptr, nullptr };
        return true;
    }

    // if not null, insert
    else {
        isInsert = insertHelper(data, root);
    }

    // if duplicate, delete the node
    if (isInsert == false) {
        delete data;
        data = nullptr;
    }

    // return
    return isInsert;
} // end of insert

//------------------------------ insertHelper ---------------------------------
// Helper method for insert
// Preconditions: NONE
// Postconditions: BinTree will have one more node
bool BinTree::insertHelper(NodeData * newNodeData, Node *& current) {

    // base case
    if (current == nullptr) {

        // add new node data, and assign left and right subtree to null pointer
        current = new Node{ newNodeData, nullptr, nullptr };
        return true;
    }

    // traverse left
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

    // traverse left-sub tree
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
    return getHeightHelper(root, target);
}

int BinTree::getHeightHelper(Node* current, const NodeData& target) const {
    return 0;
}

//---------------------------- arrayToBSTree ----------------------------------
// Assign all nodes from array to Bintree
// Preconditions: NONE
// Postconditions: array will be empty
void BinTree::arrayToBST(NodeData* arr[]) {
    
    // clear this tree
    makeEmpty();

    // check max index
    int high = 0;
    for (int i = 0; i < ARRAYSIZE; i++) {
        if (*(arr + i) != nullptr) {
            high++;
        }
        else {
            *(arr + i) = nullptr;
        }        
    }
    
    // assign new data from array to this tree
    arrayToBSTHelper(root, arr, 0, high - 1);

    return;
}

//---------------------------- arrayToBSTHelper ----------------------------------
// Assign all nodes from array to Bintree
// Preconditions: NONE
// Postconditions: array will be empty
void BinTree::arrayToBSTHelper(Node* current, NodeData* arr[], int low, int high) {
    
    // base case
    if (low > high) {
        current = nullptr;
    }

    // recursively add to tree
    else {
        int mid = (low + high) / 2;
        NodeData* newNodeData = *(arr + mid);
        insert(newNodeData);
        *(arr + mid) = nullptr;

        // fill left
        arrayToBSTHelper(current, arr, low, mid - 1);

        // fill right
        arrayToBSTHelper(current, arr, mid + 1, high);
    }
}

//--------------------------- displaySideways ---------------------------------
// Assign all node of Bintree to array
// Preconditions: NONE
// Postconditions: BinTree will be empty
void BinTree::bstToArray(NodeData* arr[]) {

    // assign tree's data to arr
    bstToArrayHelper(root, arr);

    // clear this tree
    makeEmpty();
    return;
}


void BinTree::bstToArrayHelper(Node* current, NodeData* arr[]) {    
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
void BinTree::makeEmptyHelper(Node*& current) {
    
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
// Assign other BinTree to this BinTree
// Preconditions: BinTree must be made to be empty first
// Postconditions: BinTree wil be identical as other Bintree
BinTree& BinTree::operator=(const BinTree& other) {
    
    // check if two root are not identical
    if (root != other.root) {
        makeEmptyHelper(root);
        copyHelper(root, other.root);
    }
    return *this;
}

//------------------------------- operator== ----------------------------------
// Compare two Bin Tree if they are same value and same structure
// Preconditions: NONE
// Postconditions: BinTree remains the same
bool BinTree::operator==(const BinTree& other) const {

    // check if two root are not identical
    if (root != other.root) {
        return comparisionHelper(root, other.root);
    }

    // identical if two root has same address
    else 
        return true;
}

//----------------------------- comparisionHelper -----------------------------
// Helper method for operator==
// Preconditions: NONE
// Postconditions: BinTree remains the same
bool BinTree::comparisionHelper(Node* root, Node* other) const {

    // base case
    if (root == nullptr && other == nullptr) 
        return true; 
    else if (root != nullptr && other == nullptr)
        return false; 
    else if (root == nullptr && other != nullptr)
        return false; 

    // recursively traverse
    else {

        // must be same data, same structure
        if (*root->data == *other->data 
            && comparisionHelper(root->left, other->left) 
            && comparisionHelper(root->right, other->right))
            return true;

        // not same data and same structure
        else
            return false; 
    } 
}

//------------------------------- operator!= ----------------------------------
// Helper method for makeEmpty
// Preconditions: NONE
// Postconditions: BinTree remains the same
bool BinTree::operator!=(const BinTree& other) const {    
    return !(*this == other);
}

ostream& operator<<(ostream& out, const BinTree& tree) {
    tree.inOrderHelper(out, tree.root);
    out << endl;
    return out;
}

//------------------------------- inOrderHelper -------------------------------
// Helper for operator<<
// In-order traverse
// Preconditions: NONE
// Postconditions: BinTree remains the same
void BinTree::inOrderHelper(ostream& out, Node * current) const {
    
    // base case
    if (current == nullptr)
        return;

    // print from left to right subtree
    else {
        inOrderHelper(out, current->left);
        out << *current->data << " ";
        inOrderHelper(out, current->right);
    }
}