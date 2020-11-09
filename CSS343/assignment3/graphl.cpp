// -------------------------------- graphl.h ----------------------------------
//
// Thong Ton, CSS 343
// Created:       October 27, 2020
// Last Modified: November 9, 2020  
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

    // use for reading the line after first line, node description
    string tempName;
    getline(inFile, tempName);

    // initialize the node data
    for (int i = 1; i <= size; i++) {
        getline(inFile, tempName);
        nodeList[i].data = new NodeData(tempName);
    }

    // read associate nodes
    int from, to;
    while (inFile >> from >> to && from != 0) {

        // first node
        if (nodeList[from].edgeHead == nullptr) {

            // create a node that have adjacent
            // and last node is null pointer
            nodeList[from].edgeHead = new EdgeNode { to, nullptr };
        }

        // insert next node at front
        else {

            // create a node that have adjacent 
            // and next node is nodeList[from].edgeHead
            nodeList[from].edgeHead = new EdgeNode { to,
                                                    nodeList[from].edgeHead };
            
        }
    }
}

//-------------------------------- makeEmpty ----------------------------------
//Description: Destructor envokes this function
//PRECONDITION: Destructor must exist
//POSTCONDITION: Graph is empty, all node is deleted carefull
void GraphL::makeEmpty(){

    // temporary data uses for walking through list
    EdgeNode *temp = nullptr;

    // deleting every node
    for (int i = 1; i <= size; i++) {

        // delete node data
        delete nodeList[i].data;
        nodeList[i].data = nullptr;

        // set this note as unvisited
        nodeList[i].visited = false;

        // delete every node's edge
        while (nodeList[i].edgeHead != nullptr) {

            // keeping head
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

    // temporary value for walking the list
    EdgeNode* current = nullptr;
    for (int i = 1; i <= size; i++) {

        // print out data
        cout << "Node"
            << i << setw(9)
            << " " << *nodeList[i].data
            << endl << endl;
        current = nodeList[i].edgeHead;

        // print out adjacency
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
//Description: depthFirstSearch funtion envokes this function for traversing
//PRECONDITION: depthFirstSearch must exist
//POSTCONDITION: List remains the same
void GraphL::depthFirstSearchHelper(int v) {

    // print node
    cout << setw(3) << v;

    // mark this node as visited
    nodeList[v].visited = true;

    // temporary value for walking the list
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