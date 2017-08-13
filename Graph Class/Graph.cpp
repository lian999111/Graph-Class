// Graph class member function definitions

#include "Graph.h"
#include <ctime>
#include <cassert>

using namespace std;

// 
Graph::Graph(int num_of_vertices, double density) :
	num_of_vertices_(num_of_vertices), 
	num_of_edges_(0)
{

	// Check if parameters are within legal ranges
	assert((num_of_vertices >= 0) && (density >= 0.0) && (density <= 1.0));

	// Initialize the 2D matrix with the given num_of_vertices
	edge_matrix_ = vector<vector<int>>(num_of_vertices, vector<int>(num_of_vertices));

	// If density is 0 or no. of vertices is 0,
	// make no edges and return directly
	if (num_of_vertices == 0 || density == 0.0)
	{
		return;
	}

	// Else, make edges
	srand(time(0));
	for (int vert_idx = 1; vert_idx <= num_of_vertices; ++vert_idx)
	{
		
	}

	



}

Graph::~Graph()
{}

void Graph::AddEdge(uint8_t i, uint8_t j, uint8_t range)
{
	assert((i != j) && (range > 0));
	edge_matrix_.at(i).at(j) = range;
	edge_matrix_.at(j).at(i) = range;
}
