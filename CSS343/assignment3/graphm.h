#ifndef _GRAPH_M_
#define _GRAPH_M_

#include <iostream>
#include "nodedata.h"

using namespace std;
const int MAXNODES = 9999;
class GraphM {

    public:

    //------------------------------- GraphM ----------------------------------
    // among others that need to be initialized, 
    // the data member T is initialized to sets all dist to infinity, 
    // sets all visited to false,
    // and sets all path to 0.
    GraphM();

    //------------------------------- buildGraph ------------------------------
    // builds up graph node information and adjacency matrix of edges 
    // between each node reading from a data file.
    void buildGraph(ifstream &);

    //------------------------------- insertEdge ------------------------------
    // insert an edge into graph between two given nodes
    bool insertEdge();
    
    //------------------------------- removeEdge ------------------------------
    // remove an edge between two given nodes
    bool removeEdge();

    //------------------------------- findShortestPath ------------------------------
    // find the shortest path between every node to every other node in the graph
    // , i.e., TableType T is updated with shortest path information
    void findShortestPath();

    //------------------------------- displayAll ------------------------------
    // uses couts to demonstrate that the algorithm works properly
    void displayAll();

    //------------------------------- display ---------------------------------
    // uses couts to display the shortest distance with path info 
    // between the fromNode to toNode
    void display();
    
    private:

    //------------------------------- TableType ------------------------------
    // TableType is a struct to keep the current shortest distance (and associated path info) 
    // known at any point in the algorithm.
    struct TableType {
        bool visited;   // whether node has been visited
        int dist;       // shortest distance from source known so far           
        int path;       // previous node in path of min dist
    };

    NodeData data[MAXNODES];            // data for graph nodes
    int C[MAXNODES][MAXNODES];          // Cost array, the adjacency matrix
    int size;                           // number of nodes in the 
    TableType T[MAXNODES][MAXNODES];    // stores visited, distance
};
#endif