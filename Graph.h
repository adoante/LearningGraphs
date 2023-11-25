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
		// One-Arg, creates nodes from file
		Graph(std::string,int, int);
		// Two-Arg, creates nodes from file1 and links nodes from file2
		Graph(std::string, std::string,int, int);

		// Functions

		// Returns nodes vector
		std::vector<Vertex*> getNodes() const;
		// Set nodes vector
		void addNode(Vertex*);
		// Create nodes
		void createNodes(std::string,int, int);
		// Link nodes
		void linkNodes(std::string);
		// Find node in nodes
		Vertex* getNode(int);
		// Shortest Path
		void dijkstra(int,int);

};

#endif // !GRAPH_H

