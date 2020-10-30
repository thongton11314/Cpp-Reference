// -------------------------------- graphm.h ----------------------------------
//
// Thong Ton, CSS 343
// Created:         October 27, 2020
// Last Modified:   
// Purpose: Implementation of  Dijkstra's shortest path algorithm
// ----------------------------------------------------------------------------
#include "graphm.h"

//-------------------------------- GraphM -------------------------------------
//Constructor
//Description: Among others that need to be initialized, 
//             data member T is initialized to sets all dist to infinity, 
//             sets all visited to false,
//             and sets all path to 0.
GraphM::GraphM() {

    // set default size
    size = 0;

    // initialize data to infinitive,  and all visit path to false,
    for (int i = 1; i < MAXNODES; i++) {
        for (int j = 1; j < MAXNODES; j++) {

            // cost array, the adjacency matrix 
            C[i][j] = POSITIVE_MAX;

            // stores visited, distance, path
            T[i][j].visited = false;
            T[i][j].dist = POSITIVE_MAX;
            T[i][j].path = 0;
        }
    }
}

//------------------------------- buildGraph ----------------------------------
//Description: Builds up graph node and adjacency matrix of edges 
//             between each node reading from a data file.
//Precondition: The file must be in correct format.
//                  - The first line tells the number of nodes
//                  - After that, description for each node, count from 1,
//                    one description per line (50 chars max length). 
//                  - After the description, each line consists of 3 integers 
//                    representing an edge. Data is: from to distance
//                  - If the first integer is zero, it the end of graph
void GraphM::buildGraph(ifstream &infile) {

    // read the first line, it is always a size
    infile >> size;

    // read the line after first line, node description
    string temp;
    getline(infile, temp); // initialize inFile as a string type
    
    // initialize the node data
    for (int i = 1; i <= size; i++) {
        data[i].setData(infile);    // this will handle read next line as well
    }

    // initialize the distance between nodes
    int from, to, dist;
    while (infile >> from >> to >> dist && from != 0) {
        C[from][to] = dist;
    }
}

//------------------------------- insertEdge ----------------------------------
//Description: insert an edge into graph between two given nodes
bool GraphM::insertEdge(int from, int to, int dist) {
    return false;
}

//------------------------------- removeEdge ----------------------------------
//Description: Remove an edge between two given nodes
bool GraphM::removeEdge(int from, int to) {
    return false;
}

//------------------------------- findShortestPath ----------------------------
//Description: Find the shortest path between every node to other nodes,
//             i.e., TableType T is updated with shortest path information
void GraphM::findShortestPath() {

    int v;
    int min;

    for (int source = 1; source <= size; source++) {
        T[source][source].dist = 0;
        T[source][source].visited = true;

        // find the shortest distance from source to all other nodes
        for (int i = 1; i <= size; i++) {
            
            // find v // not visited, shortest distance at this point
            if (C[source][i] != POSITIVE_MAX) {
                T[source][i].dist = C[source][i];
                T[source][i].path = source;
            }           
        }

        // for each adjacent to v
        v = -1;
        while (v != 0) {
            v = 0;
            min = POSITIVE_MAX;
            for (int n = 1; n <= size; n++) {
                if (!T[source][n].visited && (C[source][n] < min)) {
                    min = C[source][n];
                    v = n;
                }
            }

            if (v != 0) {
                T[source][v].visited = true; // node visited
                for (int w = 1; w <= size; w++) {

                    // make sure node is not visited
                    if (!T[source][w].visited) {

                        // make sure there is a path exist
                        if (C[v][w] != POSITIVE_MAX) {

                            // make sure not repeat node
                            if (v != w) {

                                // compare which path is smaller
                                if (T[source][w].dist > T[source][v].dist 
                                                        + C[v][w]) {
                                    
                                    // add up value to distance
                                    T[source][w].dist = T[source][v].dist 
                                                        + C[v][w];

                                    // create path
                                    T[source][w].path = v;
                                }
                            }
                        }
                    }
                }   
            }
        }
    }
}

//-------------------------------- display ------------------------------------
//Description: Uses couts to display the shortest distance with path info
//             between the fromNode to toNode
void GraphM::displayAll() {

    // Title of each colum
    cout << "Description" << setw(18) 
        << "From Node" << setw(10) 
        << "To node" << setw(13) 
        << "Dijkstra's" << setw(9) 
        << "Path"
        << endl;

    // depart node (from node)
    for (int from = 1; from <= size; from++) {

        // depart node name
        cout << data[from] << endl << endl;

        // destination node (to node)
        for (int to = 1; to <= size; to++) {

            // no need to print itself path
            if (from != to) {

                // Using T table not C table,
                // because we later get the shortest path
                if (T[from][to].dist != 0) {
                    cout << setw(25) << from;            // from node
                    cout << setw(10) << to;              // to node

                    // no way from depart node (from node)
                    // to destination node(to node)
                    if (T[from][to].dist == POSITIVE_MAX) {
                        cout << setw(10) << "----" << endl;
                    }

                    // there are ways from depart node to destination node
                    else {
                        cout << setw(10) << T[from][to].dist;
                        cout << setw(13);

                        // find path
                        nodeShortestPath(from, to);
                        cout << endl;
                    }
                }
            }
        }
    }
}

//------------------------------- display ---------------------------------
//Description: Uses couts to display the shortest distance with path info
//             between the fromNode to toNode
void GraphM::display(int from, int to) {

    // path is out of range
    if (from > size || to > size
        || from <= 0 || to <= 0) {
        cout << setw(5) << from 
            << setw(11) << to;
        cout << setw(9) << "----" << endl;
        return;
    }

    // path in range
    else {
        cout << setw(5) << from 
            << setw(11) << to;

        // path exist between two nodes
        if (T[from][to].dist != POSITIVE_MAX) {

            // print out shorest path
            cout << setw(9) << T[from][to].dist 
                << setw(14);

            // print out shortest path node (node's number)
            nodeShortestPath(from, to);
            cout << endl;

            // print out shortest path name (node's name)
            nodeDataName(from, to);
        }

        // path is not exist
        else {
            cout << setw(9) << "----" << endl;
        }
        cout << endl;
    }
}

//------------------------------- findPath ------------------------------------
//Description: Find the associated path between from node/to node
//             print out shortest path node (node's number)
void GraphM::nodeShortestPath(int from, int to) {

    // path is not exist
    if (T[from][to].dist == POSITIVE_MAX) {
        return;
    }

    // path is current path
    else if (from == to) {

        // print out path
        cout << to << " ";
        return;
    }

    // if path exist, recursive find path
    else {
        int nodeNumber = to;        // keep previous node's number
        nodeShortestPath(from, T[from][to].path);

        // print out path
        cout << nodeNumber << " ";
    }
}

//------------------------------- nodeData --------------------------------
//Description: Find the associated path between from node/to node
//             print out node data (node's name)
void GraphM::nodeDataName(int from, int to) {

    // path is not exist
    if (T[from][to].dist == POSITIVE_MAX) {
        return;
    }

    // path is current path
    else if (from == to) {

        // print out name of path
        cout << data[to] << endl << endl;
        return;
    }

    // if path exist, recursive find path
    else {
        nodeDataName(from, T[from][to].path);

        // print out name path
        cout << data[to] << endl << endl;
    }
}