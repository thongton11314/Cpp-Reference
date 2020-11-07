// -------------------------------- graphm.h ----------------------------------
//
// Thong Ton, CSS 343
// Created:       October 27, 2020
// Last Modified:   
// Purpose: This is the header file of Dijkstra's shortest path algorithm
// ----------------------------------------------------------------------------
#ifndef _GRAPH_M_
#define _GRAPH_M_

#include <iostream>
#include <iomanip>
#include "nodedata.h"

const int POSITIVE_MAX_M = 2147483647; // Use to keep the max size of int
const int MAXNODES_M = 101;            // constant type for T and C table

// Class: GraphM
//  This class be able to find the lowest cost paths 
//  and display the cost and path from every node to every other node
//  Assumption:
//      - nodedata.h is already included in GraphM
//      - buildGraph work properly only input file is corrected format
//          - First line tells the number of node,
//            say n, followed by a text description of each 
//            of the 1 through n nodes, one description per line, max 50 chars
//          - Each line consist of 3 integers represent for from, to, distance
//          - There may be manny graph, if first integer is zero, end of graph
//  Implementation:
//      - displayAll needs nodeShortestPath for recursively traverse
//      - display needs nodeShortestPath, nodeDataName for recursively traverse
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
    //Assumption: File must be corrected format
    //            1. Read size
    //            2. Read node name
    //            3. Read node edges:
    //               first digit is from, 
    //               second digit is to,
    //               third digit is distance
    //            4. Terminate by 0 0
    //PRECONDITION: NONE
    //POSTCONDITION: NONE
    void buildGraph(ifstream &);

    //------------------------------- insertEdge ----------------------------------
    //Description: insert an edge into graph between two given nodes.
    //             Return false if one of from, to dist is negative value
    //Precondition: None
    //Poscondition: None
    bool insertEdge(int from, int to, int dist);
    
    //------------------------------- removeEdge ------------------------------
    //Description: Remove an edge between two given nodes
    //Precondition: NONE
    //Poscondition: NONE
    bool removeEdge(int from, int to);

    //------------------------------- findShortestPath ------------------------
    //Description: Find the shortest path between every node to other nodes,
    //             i.e., TableType T is updated with shortest path information
    //Precondition: NONE
    //Poscondition: NONE
    void findShortestPath();

    //------------------------------- displayAll ------------------------------
    //Description: Uses couts to demonstrate that the algorithm works properly
    //Precondition: NONE
    //Poscondition: NONE
    void displayAll();

    //------------------------------- display ---------------------------------
    //Description: Uses couts to display the shortest distance with path info
    //             between the fromNode to toNode
    //Precondition: NONE
    //Poscondition: NONE
    void display(int from, int to);
    
private:

    //------------------------------- Struct TableType ------------------------
    // Description: A struct to keep the current shortest distance 
    //              (and associated path info) known at any point 
    //              in the algorithm.
    //Precondition: NONE
    //Poscondition: NONE
    struct TableType {
        bool visited;   // whether node has been visited
        int dist;       // shortest distance from source known so far           
        int path;       // previous node
    };

    NodeData nodeList[MAXNODES_M];      // data for graph nodes
    int C[MAXNODES_M][MAXNODES_M];      // Cost array, the adjacency matrix
    int size;                           // number of nodes in the 
    TableType T[MAXNODES_M][MAXNODES_M];// stores visited, distance

    //------------------------------- nodePath --------------------------------
    //Description: Find the associated path between from node/to node
    //             print out shortest path node (node's number)
    //Precondition: NONE
    //Poscondition: NONE
    void nodeShortestPath(int from, int to);

    //------------------------------- nodeData --------------------------------
    //Description: Find the associated path between from node/to node
    //             print out node data (node's name)
    //Precondition: NONE
    //Poscondition: NONE
    void nodeDataName(int from, int to);

};
#endif // !_GRAPH_M_