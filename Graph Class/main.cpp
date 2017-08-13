// main.cpp

#include <cstdlib>
#include <iostream>
#include <vector>
#include "Graph.h"

using namespace std;

int main()
{
	Graph my_graph(5, 0.7, 10);

	// Get the neighbors and print
	vector<int> neighbor = my_graph.NeighborsOf(0);
	for (vector<int>::const_iterator i = neighbor.begin(); i != neighbor.end(); ++i)
		cout << *i << ' ';
	cout << endl;

	// Get the vertices and print
	vector<int> vertices = my_graph.GetVertices();
	for (vector<int>::const_iterator i = vertices.begin(); i != vertices.end(); ++i)
		cout << *i << ' ';
	cout << endl;
}