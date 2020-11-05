// -------------------------------- graphl.h ----------------------------------
//
// Thong Ton, CSS 343
// Created:       October 27, 2020
// Last Modified:   
// Purpose: Implementation of  Dijkstra's shortest path algorithm
// ----------------------------------------------------------------------------
#ifndef _GRAPH_L_
#define _GRAPH_L_

#include <iostream>
#include <iomanip>
#include "nodedata.h"

const int POSITIVE_MAX = 2147483647; // Use to keep the max size of int
const int MAXNODES_L = 101;          // constant type for T and C table

class GraphL
{
public:

    //------------------------------- GraphL ----------------------------------
    //Constructor
    //Description: Among others that need to be initialized, 
    //             data member T is initialized to sets all dist to infinity, 
    //             sets all visited to false,
    GraphL();
    ~GraphL();

    void buildGraph(ifstream&);
    void displayGraph();
    void depthFirstSearch();
private:

    struct EdgeNode;
    struct GraphNode
    {
        EdgeNode* edgeHead;
        NodeData* data;
        bool visited;
    };

    struct EdgeNode {
        int adjGraphNode;
        EdgeNode* nextEdge;
    };
    GraphNode node[MAXNODES_L];
    int size;

    void makeEmpty();

    void depthFirstSearchHelper(int v);
};

#endif // !_GRAPH_L_