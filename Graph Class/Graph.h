// Graph class definition
#pragma once

#include <vector>
#include <algorithm>
#include <cstdint>
#include <ctime>
#include <cassert>
#include <exception>

// An arbitrary type for the node name
template <class T>
class Graph
{
private:
	int num_of_vertices_;
	int num_of_edges_;
	// The max range of the graph
	const int k_max_range_;

	// A 2D vector storing the edges with their values
	std::vector<std::vector<int>> edge_matrix_;

	// A map storing the mapping between the node names and their integer index
	std::vector<T> symbol_table_;

	// Helps to initialize symbol_table_ from num_of_vertices
	static std::vector<int> MakeSymbolTable(int num_of_vertices)
	{
		std::vector<int> vec;
		for (int i = 0; i < num_of_vertices; ++i)
		{
			vec.push_back(i);
		}
		return vec;
	}

	// Helps to get the index of the given node name
	int GetIndex(const T& node_name) const
	{
		auto ite = std::find(symbol_table_.begin() , symbol_table_.end(), node_name);
		if (ite == symbol_table_.end())
			throw out_of_range("Given node doesn't exist.");

		return std::distance(symbol_table_.begin(), ite);
	}

public:
	// Constructs a graph with given inputs
	// Inputs:
	//	num_of_vertices:	No. of vertices. Sould be no less than 0
	//	density:			The probabilty of edge formation between two vertices
	//						Should be between 0 and 1
	//						0 means no edges will be created
	//	max_range:			The max range of the graph
	Graph(int num_of_vertices = 0, double density = 0.0, int max_range = 0);

	// Constructs a graph with given vector of node names
	// Inputs:
	//	vec_node_name:		The vector containing a list of node names
	//	density:			The probabilty of edge formation between two vertices
	//						Should be between 0 and 1
	//						0 means no edges will be created
	//	max_range:			The max range of the graph
	Graph(const std::vector<T>& vec_node_name, double density = 0.0, int max_range = 0);

	~Graph();

	// Adds an edge between two vertices
	// Inputs:
	//	i:		The name of vertex 1 (can be int), should be in the symbol table
	//	j:		The name of vertex 2 (can be int), should be in the symbol table and not equal to i
	//	range:	The range of the edge, should be > 0
	// Output:
	//	True when adding successfully the edge
	bool AddEdge(const T& i_node_name, const T& j_node_name, int range);

	// Deletes an edge between two vertices
	// Inputs:
	//	i:		The name of vertex 1 (can be int), should be in the symbol table
	//	j:		The name of vertex 2 (can be int), should be in the symbol table and not equal to i
	// Output:
	//	True when deleting successfully the edge
	bool DeleteEdge(const T& i_node_name, const T& j_node_name);

	// Gets the neighbors of the vertex of interest
	// Inputs:
	//	i:		The index of vertex of interest, should be > 0
	// Output:
	//	A vector containing the neighbor indices of the specified vertex
	std::vector<T> NeighborsOf(const T& node_name) const;

	// Checks the connection between two vertices
	// Inputs:
	//	i:		The index of vertex of interest, should be > 0
	//	j:		The index of vertex of interest, should be > 0 and not equal to i
	// Output:
	//	True when the two vertices connected
	bool CheckConnection(const T& i_node_name, const T& j_node_name) const;

	// Gets all the vertices
	// Output:
	//	A vector containing the names of the vertices
	const std::vector<T>& GetVertices() const;

	// Gets the edge value between 2 vertices
	// Inputs:
	//	i:		The index of vertex of interest, should be > 0
	//	j:		The index of vertex of interest, should be > 0 and not equal to i
	// Output:
	//	The value of the edge specified
	int GetEdgeValue(const T& i_node_name, const T& j_node_name) const;

	// Sets the edge value between 2 vertices
	// Inputs:
	//	i:		The index of vertex of interest, should be > 0
	//	j:		The index of vertex of interest, should be > 0 and not equal to i
	//	range:	The desired range
	// Output:
	//	True if seccessfully set
	//	If the edge does not exist previously, the setting aborts.
	bool SetEdgeValue(const T& i_node_name, const T& j_node_name, int range);

	int GetNumOfVertices() const;

	int GetNumOfEdges() const;
};

template <class T>
Graph<T>::Graph(int num_of_vertices, double density, int max_range)
	: num_of_vertices_(num_of_vertices)
	, symbol_table_(MakeSymbolTable(num_of_vertices))
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
	: num_of_vertices_(vec_node_name.size())
	, symbol_table_(vec_node_name)
	, num_of_edges_(0)
	, k_max_range_(max_range)
{

	// Check if parameters are within legal ranges
	assert((vec_node_name.size() >= 0) && (density >= 0.0) && (density <= 1.0) && (max_range > 0));

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
Graph<T>::~Graph()
{}

template<class T>
bool Graph<T>::AddEdge(const T& i_node_name, const T& j_node_name, int range)
{
	assert((i_node_name != j_node_name) && (range > 0));

	// Find the indices of the node
	int i_idx = 0;
	int j_idx = 0;
	try
	{
		i_idx = GetIndex(i_node_name);
		j_idx = GetIndex(j_node_name);
	}
	catch (const out_of_range &e)
	{
		throw;
	}

	if (edge_matrix_.at(i_idx).at(j_idx) > 0)
	{
		return false;
	}

	edge_matrix_.at(i_idx).at(j_idx) = range;
	edge_matrix_.at(j_idx).at(i_idx) = range;
	++num_of_edges_;

	return true;
}

template <class T>
bool Graph<T>::DeleteEdge(const T& i_node_name, const T& j_node_name)
{
	assert((i_node_name != j_node_name));

	// Find the indices of the node
	int i_idx = 0;
	int j_idx = 0;
	try
	{
		i_idx = GetIndex(i_node_name);
		j_idx = GetIndex(j_node_name);
	}
	catch (const out_of_range &e)
	{
		throw;
	}

	if (edge_matrix_.at(i_idx).at(j_idx) == 0)
	{
		return false;
	}

	edge_matrix_.at(i_idx).at(j_idx) = 0;
	edge_matrix_.at(j_idx).at(i_idx) = 0;
	--num_of_edges_;

	return true;
}

template <class T>
std::vector<T> Graph<T>::NeighborsOf(const T& node_name) const
{
	// Find the index of the node
	int i_idx = 0;
	try
	{
		i_idx = GetIndex(node_name);
	}
	catch (const out_of_range &e)
	{
		throw;
	}
	
	vector<T> neighbor_list;
	// If the edge to i-th element is greater than 0, put in the neighbor_list
	for (int j_idx = 0; j_idx < num_of_vertices_; ++j_idx)
	{
		if (edge_matrix_.at(i_idx).at(j_idx) > 0)
			neighbor_list.push_back(symbol_table_.at(j_idx));
	}

	return neighbor_list;
}

template <class T>
bool Graph<T>::CheckConnection(const T& i_node_name, const T& j_node_name) const
{
	assert((i_node_name != j_node_name));

	// Find the indices of the node
	int i_idx = 0;
	int j_idx = 0;
	try
	{
		i_idx = GetIndex(i_node_name);
		j_idx = GetIndex(j_node_name);
	}
	catch (const out_of_range &e)
	{
		throw;
	}

	if (edge_matrix_.at(i_idx).at(j_idx) > 0)
		return true;
	return false;
}

template <class T>
const std::vector<T>& Graph<T>::GetVertices() const
{
	return symbol_table_;
}

// Todo: continue here
template <class T>
int Graph<T>::GetEdgeValue(const T& i_node_name, const T& j_node_name) const
{
	return edge_matrix_.at(i).at(j);
}

template <class T>
bool Graph<T>::SetEdgeValue(const T& i_node_name, const T& j_node_name, int range)
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


