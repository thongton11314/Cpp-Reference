// -------------------------------- graphl.h ----------------------------------
//
// Thong Ton, CSS 343
// Created:       October 27, 2020
// Last Modified: November 7, 2020  
// Purpose: This is the header file of depth first search algorithm
// ----------------------------------------------------------------------------
#ifndef _GRAPH_L_
#define _GRAPH_L_

#include <iostream>
#include <iomanip>
#include "nodedata.h"

const int POSITIVE_MAX_L = 2147483647; // Use to keep the max size of int
const int MAXNODES_L = 101;            // constant type for T and C table

// Class: GraphL
//  This class be able to find the lowest cost paths 
//  and display the cost and path from every node to every other node
//  Assumption:
//      - nodedata.h is already included in GraphL
//      - buildGraph work properly only input file is corrected format
//          - First line tells the number of node,
//            say n, followed by a text description of each 
//            of the 1 through n nodes, one description per line, max 50 chars
//          - Each line consist of 2 integers represent for from, to
//          - There may be manny graph, if first integer is zero, end of graph
//  Implementation:
//      - depthFirstSearch will always walk from the first node
//      - deconstructor needs makeEmpty for recursively delete node, data
//      - display needs nodeShortestPath, nodeDataName for recursively traverse
class GraphL {
public:

    //------------------------------- GraphL ----------------------------------
    //Constructor
    //Description: Among others that need to be initialized, 
    //             data member T is initialized to sets all dist to infinity, 
    //             sets all visited to false,
    GraphL();

    //------------------------------- ~GraphL ---------------------------------
    //Deconstructor
    ~GraphL();

    //------------------------------- buildGraph ------------------------------
    //Description: Builds up graph node and adjacency matrix of edges 
    //             between each node reading from a data file.
    //Assumption: File must be corrected format
    //            1. Read size
    //            2. Read node name
    //            3. Read node edges, first digit is from, second digit is to
    //            4. Terminate by 0 0
    //PRECONDITION: NONE
    //POSTCONDITION: NONE
    void buildGraph(ifstream&);

    //------------------------------- displayGraph ----------------------------
    //Description: Display the graph
    //PRECONDITION: NONE
    //POSTCONDITION: NONE
    void displayGraph();
    
    //------------------------------- depthFirstSearch ------------------------
    //Description: Display out the path, always walk from the first node
    //PRECONDITION: NONE
    //POSTCONDITION: NONE
    void depthFirstSearch();
private:

    // struct prototype
    struct EdgeNode;

    //------------------------------- Struct GraphNode ------------------------
    //Description: Use to store nodes
    struct GraphNode {
        EdgeNode* edgeHead;
        NodeData* data;
        bool visited;
    };

    //------------------------------- Struct EdgeNode ------------------------
    //Description: Use to store associted nodes
    struct EdgeNode {
        int adjGraphNode;
        EdgeNode* nextEdge;
    };
    GraphNode nodeList[MAXNODES_L];     // list of adjacency
    int size;                           // number of nodes in the

    //------------------------------- makeEmpty -------------------------------
    //Description: Destructor envokes this function
    //PRECONDITION: Destructor must exist
    //POSTCONDITION: Graph is empty
    void makeEmpty();

    //------------------------------- depthFirstSearchHelper ------------------
    //Description: depthFirstSearch funtion envokes this function for recursive
    //PRECONDITION: depthFirstSearch must exist
    //POSTCONDITION: NONE
    void depthFirstSearchHelper(int v);
};

#endif // !_GRAPH_L_