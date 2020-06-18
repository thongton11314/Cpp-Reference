#include <iostream>
#include <string>
#include <vector>
#include "Graph.h"

using namespace std;

int main()
{
    string towns[] = {
        "Blaxhall",
        "Clacton",
        "Dunwich",
        "Feering",
        "Harwich",
        "Maldon",
        "Tiptree",
		"Seattle",
		"Lynnwood"
    };	
    int roads[][3] = 
	//Vertice, edgese, weight
	{
		//Colum
        {0, 2, 2}, {0, 3, 2}, {0, 4, 4},//Row
        {1, 4, 2}, {1, 5, 3}, {1, 6, 1},
        {2, 0, 2}, {2, 4, 3},
        {3, 0, 2}, {3, 5, 3}, {3, 6, 1},
        {4, 0, 4}, {4, 1, 2}, {4, 2, 3}, {4, 6, 2},
        {5, 1, 3}, {5, 3, 3}, {5, 6, 2},
        {6, 1, 1}, {6, 3, 1}, {6, 4, 2}, {6, 5, 2},
		{7, 8, 10},
		{8, 7, 10}
    };

	//Graph(string vertices[], int numVertices, int edges[][3], int numEdges)
    Graph graph(towns, 9, roads, 24);
    cout << "Towns: " << endl;
    for (int i = 0; i < 9; i++)
        cout << "    " << i << " - " << towns[i] << endl;
    cout << "Enter the index of a town: ";
    int town = 0;
    cin >> town;
    getchar();
    vector<int> neighbors = graph.getNeighbors(town);
    cout << "Neighbors: " << endl;
    for (int i = 0; i < neighbors.size(); i++)
        cout << "    " << towns[neighbors.at(i)] << 
		" (" << graph.getWeight(town, neighbors.at(i)) << ")" << endl;
    /*graph.addVertex("Burger");
    graph.addEdge(7, 3, 5);
    graph.addEdge(3, 7, 5);
    graph.addEdge(7, 5, 6);
    graph.addEdge(5, 7, 6);
    char newTowns[][25] = {
            "Blaxhall",
            "Clacton",
            "Dunwich",
            "Feering",
            "Harwich",
            "Maldon",
            "Tiptree",
            "Burger"
    };
    neighbors = graph.getNeighbors(town);
    cout << "Burger Added - New Neighbors: " << endl;
    for (int i = 0; i < neighbors.size(); i++)
		cout << "    " << newTowns[neighbors.at(i)] <<
		" (" << graph.getWeight(town, neighbors.at(i)) << ")" << endl;*/
    //end
	cout << "Towns: " << endl;
	for (int i = 0; i < 9; i++)
		cout << "    " << i << " - " << towns[i] << endl;
	cout << "Enter the indices of two towns: ";
	int town1;
	int town2;
	cin >> town1 >> town2;
	getchar();
	if (graph.isConnected(town1, town2))
		cout << "You can get there from here." << endl;
	else
		cout << "You can't get there from here." << endl;
	vector<int> path = graph.bfsPath();
	cout << "BFS Path:" << endl;
	for (int i : path)
		cout << graph.getVertex(i) << endl;
	cout << "DFS Path:" << endl;
	path = graph.dfsPath();
	for (int i : path)
		cout << graph.getVertex(i) << endl;
	getchar();
}