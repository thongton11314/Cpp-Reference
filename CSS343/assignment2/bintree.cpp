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
    
    // first node if tree is empty
    if (root == nullptr) {

        // add new node data, and assign left and right subtree to null pointer
        root = new Node{ data, nullptr, nullptr };
        return true;
    }
    return insertHelper(data, root);
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
// Return target's height
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
int BinTree::getHeight(const NodeData& target) const {
    return getHeightHelper(root, target);
}

//------------------------------ getHeightHelper ------------------------------
// Find the target and return it's height to getHeight function if found
// Use pre-order to track target
// Preconditions: NONE
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
}

//---------------------------------- findMax ----------------------------------
// Return found node's max height to getHeightHelper function
// Preconditions: The node must be found
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
        int left = findMax(current->left);

        // traverse right and hold right max length
        int right = findMax(current->right);

        // find max length
        left > right ? maxLength = left : maxLength = right;
        return 1 + maxLength;
    }
}

//---------------------------- arrayToBSTree ----------------------------------
// Assign all nodes from array to Bintree
// Preconditions: NONE
// Postconditions: array will be empty
void BinTree::arrayToBSTree(NodeData* arr[]) {
    
    // clear this tree
    makeEmpty();

    // check max index
    int high = 0;
    for (int i = 0; i < MAXSIZE; i++) {
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
        //NodeData* newNodeData = arr[mid];
        insert(arr[mid]);

        // fill left
        arrayToBSTHelper(current, arr, low, mid - 1);

        // fill right
        arrayToBSTHelper(current, arr, mid + 1, high);
    }
}

//--------------------------- bstToArray ---------------------------------
// Assign all node of Bintree to array
// Preconditions: NONE
// Postconditions: BinTree will be empty
void BinTree::bstreeToArray(NodeData* arr[]) {

    // index for array
    int index = 0;

    // assign tree's data to arr
    bstToArrayHelper(root, arr, index);
    
    // last NodeData in array is nullptr
    arr[index] = nullptr;

    // clear this tree
    root = nullptr;
    return;
}

//--------------------------- bstToArrayHelper ---------------------------------
// Assign all node of Bintree to array
// Preconditions: NONE
// Postconditions: BinTree will be empty
void BinTree::bstToArrayHelper(Node* current, NodeData* arr[], int& index) {

    if (current != nullptr) {

         // traverse left
        bstToArrayHelper(current->left, arr, index);

        // assign current node to array
        arr[index++] = current->data;

        // current node no long point to data
        current->data = nullptr;

        // traverse right
        bstToArrayHelper(current->right, arr, index);

        // delete node
        delete current;
    }    
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

        // delete node data
        if (current->data != nullptr) {
            delete current->data;
        }

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
// Compare two Bin Tree if they are same value and structure
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
// Compare two BinTree if they aren't same value and structure 
// Preconditions: NONE
// Postconditions: BinTree remains the same
bool BinTree::operator!=(const BinTree& other) const {    
    return !(*this == other);
}

//------------------------------- operator<< ----------------------------------
// Print out the BinTree
// Preconditions: NONE
// Postconditions: BinTree remains the same
ostream& operator<<(ostream& out, const BinTree& tree) {
    tree.inOrderHelper(out, tree.root);
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