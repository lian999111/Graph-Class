// Graph class definition
#pragma once

#include <vector>

class Graph
{
public:
	Graph();


	~Graph();

private:
	int num_of_edges;
	int num_of_vertices;
	// graph is a 2D vector storing the edges with their values
	std::vector<std::vector<int>> graph;
};

