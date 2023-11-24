#ifndef GRAPH_H

//imports
#include <vector>
#include "Vertex.h"
#include <string>

#define GRAPH_H

class Graph {
	private:
		// Every vecter in the graph
		std::vector<Vertex*> nodes;

	public:
		// Constructors

		// Default
		Graph();
		// One arg
		Graph(std::string);

		// Functions

		// Returns nodes vector
		std::vector<Vertex*> & getNodes();

};

#endif // !GRAPH_H

