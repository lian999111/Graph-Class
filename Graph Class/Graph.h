// Graph class definition
#pragma once

#include <vector>
#include <cstdint>

class Graph
{
public:
	// Constructs a graph with given inputs
	// Inputs:
	//	num_of_vertices:	No. of vertices. Sould be no less than 0
	//	density:			The probabilty of edge formation between two vertices.
	//						Should be between 0 and 1. 
	//	max_range:			The max range of the graph.
	Graph(int num_of_vertices = 0, double density = 0.0, int max_range = 0);

	~Graph();

	// Adds an edge between two vertices
	// Inputs:
	//	i:		The index of vertex 1, should be > 0
	//	j:		The index of vertex 2, should be > 0 and not equal to i
	//	range:	The range of the edge, should be > 0
	// Output:
	//	True when adding successfully the edge
	bool AddEdge(int i, int j, int range);

	// Deletes an edge between two vertices
	// Inputs:
	//	i:		The index of vertex 1, should be > 0
	//	j:		The index of vertex 2, should be > 0 and not equal to i
	// Output:
	//	True when deleting successfully the edge
	bool DeleteEdge(int i, int j);

	// Gets the neighbors of the vertex of interest
	// Inputs:
	//	i:		The index of vertex of interest, should be > 0
	// Output:
	//	A vector containing the neighbor indices of the specified vertex
	std::vector<int> NeighborsOf(int i) const;

	// Checks the connection between two vertices
	// Inputs:
	//	i:		The index of vertex of interest, should be > 0
	//	j:		The index of vertex of interest, should be > 0 and not equal to i
	// Output:
	//	True when the two vertices connected
	bool CheckConnection(int i, int j) const;

	// Gets all the vertices
	// Output:
	//	A vector containing the indices of the vertices
	std::vector<int> GetVertices() const;
	
private:
	int num_of_vertices_;
	int num_of_edges_;
	// The max range of the graph
	const int k_max_range_;
	
	// graph is a 2D vector storing the edges with their values
	std::vector<std::vector<int>> edge_matrix_;
};

