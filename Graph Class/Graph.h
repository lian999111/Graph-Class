// Graph class definition
#pragma once

#include <vector>
#include <cstdint>

class Graph
{
public:
	// Constructor
	// Input:
	//	num_of_vertices:	No. of vertices. Sould be no less than 0
	//	density:			The probabilty of edge formation between two vertices.
	//						Should be between 0 and 1. 
	//	max_range:			The max range of the graph.
	Graph(int num_of_vertices = 0, double density = 0.0, int max_range = 0);

	~Graph();

	// Adds an edge between two vertices
	// Input:
	//	i:		The index of vertex 1, should be > 0
	//	j:		The index of vertex 2, should be > 0 and not equal to i
	//	range:	The range of the edge, should be > 0
	bool AddEdge(int i, int j, int range);

	// Deletes an edge between two vertices
	// Input:
	//	i:		The index of vertex 1, should be > 0
	//	j:		The index of vertex 2, should be > 0 and not equal to i
	bool DeleteEdge(int i, int j);
	
private:
	int num_of_vertices_;
	int num_of_edges_;
	// The max range of the graph
	const int k_max_range_;
	
	// graph is a 2D vector storing the edges with their values
	std::vector<std::vector<int>> edge_matrix_;
};

