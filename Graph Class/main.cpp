// main.cpp

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include "Graph.h"

using namespace std;

int main()
{
	cout << "Use number of vertices to construct:" << endl;
	Graph<int> my_graph(10, 0.7, 10);

	cout << "No. of vertices: " << my_graph.GetNumOfVertices() << endl;
	cout << "No. of edges: " << my_graph.GetNumOfEdges() << endl;

	// Get all the vertices and print
	
	// the difference between declaring using vector<int>& or vector<int>????
	const vector<int>& vertices = my_graph.GetVertices();
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
		cout << "my_graph.SetEdgeValue(1, 2, 5);" << endl;
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
	
	/////////// Test a graph with string vertex names ///////////
	cout << endl << "Use string vertex names to construct:" << endl;
	vector<string> vertex_names{ "A", "B", "C", "D", "E" };
	Graph<string> my_string_graph(vector<string>{ "A", "B", "C", "D", "E" }, 0.7, 10);

	cout << "No. of vertices: " << my_string_graph.GetNumOfVertices() << endl;
	cout << "No. of edges: " << my_string_graph.GetNumOfEdges() << endl;

	// Get all the vertices and print

	// the difference between declaring using vector<int>& or vector<int>????
	const auto string_vertices = my_string_graph.GetVertices();
	cout << "All vertices: ";
	for (auto i = string_vertices.begin(); i != string_vertices.end(); ++i)
		cout << *i << ' ';
	cout << endl;

	// Get the neighbors and print
	auto string_neighbor = my_string_graph.NeighborsOf("A");
	cout << "Neighbors of A: ";
	for (auto i = string_neighbor.begin(); i != string_neighbor.end(); ++i)
		cout << *i << ' ';
	cout << endl;

	// Check the conntecion
	cout << "Check the connection between A and B: "
		<< my_string_graph.CheckConnection("A", "B")
		<< endl;

	// Print the range between 1 and 2, then set it to 5
	if (my_string_graph.CheckConnection("A", "B"))
	{
		cout << "1 and 2 are connected by range: "
			<< my_string_graph.GetEdgeValue("A", "B")
			<< endl;
		my_string_graph.SetEdgeValue("A", "B", 5);
		cout << "my_string_graph.SetEdgeValue(\"A\", \"B\", 5) performed" << endl;
	}

	// Print the new range
	cout << "The range is changed to: "
		<< my_string_graph.GetEdgeValue("A", "B")
		<< endl;

	// Delete an edge
	my_string_graph.DeleteEdge("A", "B");

	cout << "1 and 2 are connected by range: "
		<< my_string_graph.GetEdgeValue("A", "B")
		<< endl;
}