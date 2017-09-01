// main.cpp

#include <cstdlib>
#include <iostream>
#include <vector>
#include "Graph.h"

using namespace std;

int main()
{
	Graph<int> my_graph(5, 0.7, 10);

	cout << "No. of vertices: " << my_graph.GetNumOfVertices() << endl;
	cout << "No. of edges: " << my_graph.GetNumOfEdges() << endl;

	// Get all the vertices and print
	vector<int> vertices = my_graph.GetVertices();
	cout << "All vertices: ";
	for (vector<int>::const_iterator i = vertices.begin(); i != vertices.end(); ++i)
		cout << *i << ' ';
	cout << endl;

	// Get the neighbors and print
	vector<int> neighbor = my_graph.NeighborsOf(1);
	cout << "Neighbors of 1: ";
	for (vector<int>::const_iterator i = neighbor.begin(); i != neighbor.end(); ++i)
		cout << *i << ' ';
	cout << endl;

	// Check the conntecion
	cout << "Check the connection between 1 and 2: "
		<< my_graph.CheckConnection(1, 2) 
		<< endl;

	// Print the range between 1 and 2, then set it to 5
	if (my_graph.CheckConnection(1, 2))
	{
		cout << "1 and 2 are connected by range: " 
			<< my_graph.GetEdgeValue(1, 2)
			<< endl;
		my_graph.SetEdgeValue(1, 2, 5);
	}

	// Print the new range
	cout << "The range is changed to: "
		<< my_graph.GetEdgeValue(1, 2)
		<< endl;

	// Delete an edge
	my_graph.DeleteEdge(1, 2);
	
	cout << "1 and 2 are connected by range: "
		<< my_graph.GetEdgeValue(1, 2)
		<< endl;
	
}