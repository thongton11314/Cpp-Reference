// -------------------------------- graphm.h ----------------------------------
//
// Thong Ton, CSS 343
// Created:       October 27, 2020
// Last Modified:   
// Purpose: Implementation of  Dijkstra's shortest path algorithm
// ----------------------------------------------------------------------------
#ifndef _GRAPH_M_
#define _GRAPH_M_

#include <iostream>
#include <iomanip>
#include "nodedata.h"

using namespace std;

const int POSITIVE_MAX = 2147483647; // Use to keep the max size of int
const int MAXNODES = 101;            // constant type for T and C table

class GraphM {
    
public:

    //------------------------------- GraphM ----------------------------------
    //Constructor
    //Description: Among others that need to be initialized, 
    //             data member T is initialized to sets all dist to infinity, 
    //             sets all visited to false,
    //             and sets all path to 0.
    GraphM();

    //------------------------------- buildGraph ------------------------------
    //Description: Builds up graph node and adjacency matrix of edges 
    //              between each node reading from a data file.
    void buildGraph(ifstream &);

    //------------------------------- insertEdge ------------------------------
    //Description: insert an edge into graph between two given nodes
    bool insertEdge(int from, int to, int dist);
    
    //------------------------------- removeEdge ------------------------------
    //Description: Remove an edge between two given nodes
    bool removeEdge(int from, int to);

    //------------------------------- findShortestPath ------------------------
    //Description: Find the shortest path between every node to other nodes,
    //             i.e., TableType T is updated with shortest path information
    void findShortestPath();

    //------------------------------- displayAll ------------------------------
    //Description: Uses couts to demonstrate that the algorithm works properly
    void displayAll();

    //------------------------------- display ---------------------------------
    //Description: Uses couts to display the shortest distance with path info
    //             between the fromNode to toNode
    void display(int from, int to);

    
private:

    //------------------------------- Struct TableType ------------------------
    // Description: A struct to keep the current shortest distance 
    //              (and associated path info) known at any point 
    //              in the algorithm.
    struct TableType {
        bool visited;   // whether node has been visited
        int dist;       // shortest distance from source known so far           
        int path;       // previous node
    };

    NodeData data[MAXNODES];            // data for graph nodes
    int C[MAXNODES][MAXNODES];          // Cost array, the adjacency matrix
    int size;                           // number of nodes in the 
    TableType T[MAXNODES][MAXNODES];    // stores visited, distance

    //------------------------------- nodePath --------------------------------
    //Description: Find the associated path between from node/to node
    //             print out shortest path node (node's number)
    void nodeShortestPath(int from, int to);

    //------------------------------- nodeData --------------------------------
    //Description: Find the associated path between from node/to node
    //             print out node data (node's name)
    void nodeDataName(int from, int to);

};
#endif // !_GRAPH_M_