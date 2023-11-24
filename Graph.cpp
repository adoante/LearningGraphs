#include "Graph.h"
#include <fstream>
#include <iostream>

// Default
Graph::Graph() {

}

// One arg
Graph::Graph(std::string file) {
	// Create Nodes from file 2 with and add them to nodes vector
	for (int i = 0; i < 20; i++) {
		Vertex temp = Vertex();
	}
}

// Functions

// Returns nodes vector
std::vector<Vertex*> & Graph::getNodes() {
	return nodes;
}