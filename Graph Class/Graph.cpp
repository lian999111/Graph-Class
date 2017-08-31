// Graph class member function definitions

#include "Graph.h"
#include <ctime>
#include <cassert>

template <class T>
Graph<T>::Graph(int num_of_vertices, double density, int max_range)
	: num_of_vertices_(num_of_vertices)
	, num_of_edges_(0)
	, k_max_range_(max_range)
{

	// Check if parameters are within legal ranges
	assert((num_of_vertices >= 0) && (density >= 0.0) && (density <= 1.0) && (max_range > 0));

	// Initialize the 2D matrix with the given num_of_vertices
	edge_matrix_ = vector<vector<int>>(num_of_vertices_, vector<int>(num_of_vertices_));

	// If density is 0 or no. of vertices is 0,
	// make no edges and return directly
	if (num_of_vertices == 0 || density == 0.0)
	{
		return;
	}

	// Else, make edges
	srand(time(0));
	for (int vert_idx_1 = 0; vert_idx_1 < num_of_vertices; ++vert_idx_1)
	{
		// Start looping from the next vertex
		for (int vert_idx_2 = vert_idx_1 + 1; vert_idx_2 < num_of_vertices; ++vert_idx_2)
		{
			// If the random number is bigger than density, 
			// make no edge and continue to the next loop
			double rand_num = rand() / ((double)RAND_MAX + 1);
			if (rand_num > density)
				continue;
			// Generate the random range
			int range = (rand() % k_max_range_) + 1;
			// Add edge
			AddEdge(vert_idx_1, vert_idx_2, range);
		}
	}
}

template <class T>
Graph<T>::Graph(const std::vector<T>& vec_node_name, double density = 0.0, int max_range = 0)
{
	
}

template <class T>
Graph<T>::~Graph()
{}

template <class T>
bool Graph<T>::AddEdge(int i, int j, int range)
{
	assert((i != j) && (range > 0));

	if (edge_matrix_.at(i).at(j) > 0)
	{
		return false;
	}

	edge_matrix_.at(i).at(j) = range;
	edge_matrix_.at(j).at(i) = range;
	++num_of_edges_;

	return true;
}

template <class T>
bool Graph<T>::DeleteEdge(int i, int j)
{
	assert((i != j));
	if (edge_matrix_.at(i).at(j) == 0)
	{
		return false;
	}

	edge_matrix_.at(i).at(j) = 0;
	edge_matrix_.at(j).at(i) = 0;
	--num_of_edges_;

	return true;
}

template <class T>
std::vector<int> Graph<T>::NeighborsOf(int i) const
{
	vector<int> neighbor_list;
	// If the edge to i-th element is greater than 0, put in the neighbor_list
	for (int idx = 0; idx < num_of_vertices_; ++idx)
	{
		if (edge_matrix_.at(i).at(idx) > 0)
			neighbor_list.push_back(idx);
	}

	return neighbor_list;
}

template <class T>
bool Graph<T>::CheckConnection(int i, int j) const
{
	assert((i != j));
	if (edge_matrix_.at(i).at(j) > 0)
		return true;
	return false;
}

template <class T>
std::vector<int> Graph<T>::GetVertices() const
{
	vector<int> vertices_list;
	for (int idx = 0; idx < num_of_vertices_; ++idx)
	{
		vertices_list.push_back(idx);
	}
	return vertices_list;
}

template <class T>
int Graph<T>::GetEdgeValue(int i, int j) const
{
	return edge_matrix_.at(i).at(j);
}

template <class T>
bool Graph<T>::SetEdgeValue(int i, int j, int range)
{
	assert((i != j) && (range > 0));

	if (edge_matrix_.at(i).at(j) == 0)
		return false;
	
	edge_matrix_.at(i).at(j) = range;
	edge_matrix_.at(j).at(i) = range;
	return true;
}

template <class T>
int Graph<T>::GetNumOfVertices() const
{
	return num_of_vertices_;
}

template <class T>
int Graph<T>::GetNumOfEdges() const
{
	return num_of_edges_;
}

