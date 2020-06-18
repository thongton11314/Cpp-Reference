#include "Graph.h"
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

Graph::Graph(string vertices[], int numVertices, int edges[][3], int numEdges)
{
    for (int i = 0; i < numVertices; i++)
        this->vertices.push_back(vertices[i]);

    this->edges.resize(numVertices);
    for (int i = 0; i < numEdges; i++)
    {
        Edge e{ edges[i][0], edges[i][1], edges[i][2] };
        this->edges.at(edges[i][0]).push_back(e);
    }
}

vector<int> Graph::getNeighbors(int index)
{
    vector<int> results;
    vector<Edge> edges = this->edges.at(index);
    for (Edge e : edges)
    {
        results.push_back(e.end);
    }
    return results;
}

string Graph::getVertex(int index)
{
    return this->vertices.at(index);
}

int Graph::getSize()
{
    return this->vertices.size();
}

void Graph::addVertex(string vertex)
{
    this->vertices.push_back(vertex);
    this->edges.resize(this->edges.size() + 1);
}

void Graph::addEdge(int start, int end, int weight)
{
    if (start < this->vertices.size() && end < this->vertices.size())
    {
        Edge e{ start, end, weight };
        this->edges.at(start).push_back(e);
    }
}

int Graph::getWeight(int start, int end)
{
	vector<Edge> edges = this->edges.at(start);
	for (Edge e : edges)
		if (e.end == end)
			return e.weight;
	return -1;
}

bool Graph::isConnected(int start, int end)
{
	int v;
	stack<int> col;
	vector<int> vis;
	col.push(start);
	while (!col.empty())
	{
		v = col.top();
		if (v == end)
			return true;
		col.pop();
		if (find(vis.begin(), vis.end(), v) == vis.end()) 
		{
			vis.push_back(v);
			//add neighbors of v to col
			vector<int> neighbors = this->getNeighbors(v);
			for (int i : neighbors)
				col.push(i);
		}
	}
	return false;
}

vector<int> Graph::bfsPath()
{
	int v;
	queue<int> col;
	vector<int> vis;
	col.push(0);
	while (!col.empty())
	{
		v = col.front();
		col.pop();
		if (find(vis.begin(), vis.end(), v) == vis.end())
		{
			vis.push_back(v);
			//add neighbors of v to col
			vector<int> neighbors = this->getNeighbors(v);
			for (int i : neighbors)
				col.push(i);
		}
	}
	return vis;
}

vector<int> Graph::dfsPath()
{
	int v;
	stack<int> col;
	vector<int> vis;
	col.push(0);
	while (!col.empty())
	{
		v = col.top();
		col.pop();
		if (find(vis.begin(), vis.end(), v) == vis.end())
		{
			vis.push_back(v);
			//add neighbors of v to col
			vector<int> neighbors = this->getNeighbors(v);
			for (int i : neighbors)
				col.push(i);
		}
	}
	return vis;
}
