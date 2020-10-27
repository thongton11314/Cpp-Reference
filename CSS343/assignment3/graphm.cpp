//------------------------------- GraphM ----------------------------------
//Constructor
//Description: Among others that need to be initialized, 
//             data member T is initialized to sets all dist to infinity, 
//             sets all visited to false,
//             and sets all path to 0.

#include "graphm.h"

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

//------------------------------- buildGraph ------------------------------
//Description: Builds up graph node and adjacency matrix of edges 
//             between each node reading from a data file.
//Precondition: The file must be in correct format.
//                  - The first line tells the number of nodes
//                  - After that, description for each node, count from 1,
//                    one description per line (50 chars max length). 
//                  - After the description, each line consists of 3 integers 
//                    representing an edge. Data is: from to distance
//                  - If the first integer is zero, it the end of graph
void GraphM::buildGraph(ifstream &inFile) {

    // read the first line, it is always a size
    inFile >> size;

    // read the line after first line, node description
    // initialize the node data
    for (int i = 1; i <= size; i++) {
        data[i].setData(inFile);    // this will handle read next line as well
    }

    // initialize the distance between nodes
    int from, to, dist;
    while (inFile >> from >> to >> dist && from != 0) {
            C[from][to] = dist;
    }
}

void GraphM::displayAll() {
    cout << "Description" 
        << "\t From Node"
        << "\t To node" 
        << "\t Dijkstra's" 
        << "\t Path"
        << endl;

    for (int i = 1; i <= size; i++) {
        cout << data[i] << endl;
        for (int j = 1; j <= size; j++) {
            cout << C[i][j] << " ";
        }
    }
}
