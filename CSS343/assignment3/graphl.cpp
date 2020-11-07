// -------------------------------- graphl.h ----------------------------------
//
// Thong Ton, CSS 343
// Created:       October 27, 2020
// Last Modified: November 7, 2020  
// Purpose: This is implementation of depth first search algorithm
// ----------------------------------------------------------------------------

#include "graphl.h"

//---------------------------------- GraphL -----------------------------------
//Constructor
//Description: Among others that need to be initialized, 
//             data member T is initialized to sets all dist to infinity, 
//             sets all visited to false,
GraphL::GraphL() {
    size = 0;
    for (int i = 1; i < MAXNODES_L; i++){
        nodeList[i].edgeHead = nullptr; 
        nodeList[i].data = nullptr;
        nodeList[i].visited = false;
    }
}

//--------------------------------- ~GraphL -----------------------------------
//Deconstructor
GraphL::~GraphL() {
    makeEmpty();
}

//-------------------------------- buildGraph ---------------------------------
//Description: Builds up graph node and adjacency matrix of edges 
//             between each node reading from a data file.
//Assumption: File must be corrected format
//            1. Read size
//            2. Read node name
//            3. Read node edges, first digit is from, second digit is to
//            4. Terminate by 0 0
//PRECONDITION: NONE
//POSTCONDITION: NONE
void GraphL::buildGraph(ifstream& inFile) {

    // read the first line, it is always a size
    inFile >> size;

    // read the line after first line, node description
    string tempName;
    getline(inFile, tempName);

    // initialize the node data
    for (int i = 1; i <= size; i++) {
        getline(inFile, tempName);
        nodeList[i].data = new NodeData(tempName);
    }

    int from, to;
    EdgeNode* temp = nullptr;
    while (inFile >> from >> to && from != 0) {

        // first node in array
        if (nodeList[from].edgeHead == nullptr) {

            // create a node that have adjacent 
            // and next node is nullptr
            temp = new EdgeNode { to, nullptr };
            nodeList[from].edgeHead = temp;
        }

        // next node in array
        else {

            // create a node that have adjacent 
            // and next node is nodeList[from].edgeHead
            temp = new EdgeNode { to, nodeList[from].edgeHead };
            nodeList[from].edgeHead = temp;
        }
    }
}

//-------------------------------- makeEmpty ----------------------------------
//Description: Destructor envokes this function
//PRECONDITION: Destructor must exist
//POSTCONDITION: Graph is empty
void GraphL::makeEmpty(){

    EdgeNode *temp = nullptr;
    for (int i = 1; i <= size; i++) {

        // delete node data
        delete nodeList[i].data; 
        nodeList[i].data = nullptr;

        // set this note as un visited
        nodeList[i].visited = false;

        // delete every node's edge
        while (nodeList[i].edgeHead != nullptr) {

            // temporary value
            temp = nodeList[i].edgeHead;

            // next node
            nodeList[i].edgeHead = nodeList[i].edgeHead->nextEdge;

            // delete edge
            delete temp;
            temp = nullptr;         
        }
    }
}

//--------------------------------- displayGraph ------------------------------
//Description: Display the graph
//PRECONDITION: NONE
//POSTCONDITION: NONE
void GraphL::displayGraph() {
    cout << endl << "Graph:" << endl;
    EdgeNode* current = nullptr;
    for (int i = 1; i <= size; i++) {
        cout << "Node"
            << i << setw(9)
            << " " << *nodeList[i].data
            << endl << endl;
        current = nodeList[i].edgeHead;
        while (current != nullptr) {
            cout << setw(6) << "edge"
                << setw(3) << i
                << setw(3) << current->adjGraphNode
                << endl;
            current = current->nextEdge;
        }
    }
}

//--------------------------------- depthFirstSearch --------------------------
//Description: Display out the path, always walk from the first node
//PRECONDITION: NONE
//POSTCONDITION: NONE
void GraphL::depthFirstSearch() {
    cout << endl;
    cout << "Depth-fisrt ordering:";

    // walking from first node
    for (int i = 1; i <= size; i++) {

        // node is not visited
        if (!nodeList[i].visited) {

            // recursively traverse
            depthFirstSearchHelper(i);
        }
    }
    cout << endl;
}

//------------------------------- depthFirstSearchHelper ----------------------
//Description: depthFirstSearch funtion envokes this function for recursive
//PRECONDITION: depthFirstSearch must exist
//POSTCONDITION: NONE
void GraphL::depthFirstSearchHelper(int v) {

    // print node
    cout << setw(3) << v;

    // mark this node as visited
    nodeList[v].visited = true;

    // point to the parent node
    EdgeNode *current = nodeList[v].edgeHead;

    // walk from parent node
    while (current != nullptr) {

        // if node is not visited
        if (!nodeList[current->adjGraphNode].visited) {

            // keep traversing recursively
            depthFirstSearchHelper(current->adjGraphNode);
        }

        // next node
        current = current->nextEdge;
    }
}