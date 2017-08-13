// main.cpp

#include <cstdlib>
#include <iostream>
#include <vector>
#include "Graph.h"

using namespace std;

int main()
{
	Graph my_graph(5, 0.7, 10);
	vector<int> neighbor = my_graph.NeighborsOf(3);
	for (vector<int>::const_iterator i = neighbor.begin(); i != neighbor.end(); ++i)
		cout << *i << ' ';
}