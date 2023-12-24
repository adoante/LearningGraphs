#ifndef GRAPH_H

//imports
#include <vector>
#include "Vertex.h"
#include <string>

#define GRAPH_H

class Graph {
	private:
		// Every vector in the graph
		std::vector<Vertex*> nodes;

	public:
		// Constructors

		// Default
		Graph();
		// One-Arg, creates nodes from file
		Graph(std::string);
		// Two-Arg, creates nodes from file1 and links nodes from file2
		Graph(std::string, std::string);

		// Functions

		// Returns nodes vector
		std::vector<Vertex*> getNodes() const;
		// Returns number of vertices(
		int vert_count();
		// Set nodes vector
		void addNode(Vertex*);
		// Create nodes
		void createNodes(std::string);
		// Link nodes
		void linkNodes(std::string);
		// Find node in nodes
		Vertex* getNode(int);
		// Shortest Path
		void dijkstra(int,int);
		
		void DFS(int v);

		void BFS(int s);

		void BellmanFord(int s);

};

#endif // !GRAPH_H

