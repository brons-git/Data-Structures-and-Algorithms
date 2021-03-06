#include "Graph.h"
#include<iostream>
using namespace std;


Graph::Graph()
{
	
}

Graph::Graph(int vcount)
{
	totalVertices = vcount;
	adjacencyMatrix = new bool*[vcount];

	for (int i = 0; i < vcount; i++)
	{
		adjacencyMatrix[i] = new bool[vcount];
		for (int j = 0; j < vcount; j++) //initializing the matrix contents to false
		{
			adjacencyMatrix[i][j] = false;
		}
	}
}


void Graph::AddEdge(int i, int j)
{
	adjacencyMatrix[i][j] = true;//assuming it is 2 way.
	adjacencyMatrix[j][i] = true;//assuming it is 2 way.
}

void Graph::RemoveEdge(int i, int j)
{
	adjacencyMatrix[i][j] = false;
	adjacencyMatrix[j][i] = false;
}

void Graph::DisplayGraph()
{
	cout << endl;
	for (int i = 0; i < totalVertices; i++)
	{
		cout << "\t";
		for (int j = 0; j < totalVertices; j++)
		{
			cout << adjacencyMatrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void Graph::DepthFirstSearch(int startIndex)
{
	bool *arrVisited = new bool[totalVertices];
	for (int i = 0; i < totalVertices; i++)
		arrVisited[i] = false;

	DepthFirstSearch(arrVisited, startIndex);
}

void Graph::DepthFirstSearch(bool arrVisited[], int index)
{
	int j;
	cout << index << " ";
	arrVisited[index] = 1;
	for (j = 0; j < totalVertices; j++) {
		if (arrVisited[j] == 0 && adjacencyMatrix[index][j] == 1)
			DepthFirstSearch(arrVisited, j);
	}
}



Graph::~Graph()
{

	for (int i = 0; i < totalVertices; i++)
		delete[] adjacencyMatrix[i];

	delete[] adjacencyMatrix;
}
