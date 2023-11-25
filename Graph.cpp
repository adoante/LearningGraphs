#include "Graph.h"
#include <fstream>
#include <iostream>
#include <string>

// Default
Graph::Graph() {

}

// One-Arg, creates nodes from file
Graph::Graph(std::string infile, int n, int d) {
	createNodes(infile, n, d);
}

// Two-Arg, creates nodes from file1 and links nodes from file2
Graph::Graph(std::string nodeFile, std::string linkFile, int n, int d) {
	createNodes(nodeFile, n, d);
	linkNodes(linkFile);
}

// Returns nodes vector
std::vector<Vertex*> Graph::getNodes() const {
	return nodes;
}

// Add node to graph
void Graph::addNode(Vertex* n) {
	nodes.push_back(n);
}

// Create nodes
void Graph::createNodes(std::string file, int n, int d) {
	std::vector<std::vector<std::string>> node_data(n, std::vector<std::string>(d, " "));

	std::ifstream infile(file);
	if (!infile.is_open()) {
		std::cout << "Error: Cannot open city.txt file." << std::endl;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < d; j++) {
			infile >> node_data[i][j];
			infile.ignore();
		}
	}

	//add nodes to graph
	for (int i = 0; i < node_data.size(); i++) {
		Vertex *temp = new Vertex();
		temp->setData(node_data[i]);
		addNode(temp);
	}
}

// Link nodes to each other
void Graph::linkNodes(std::string file) {
	//Read from city.txt file to set city_data;
	std::ifstream infile(file);
	if (!infile.is_open()) {
		std::cout << "Error: Cannot open city.txt file." << std::endl;
	}

	int start;
	int end;
	int weight;

	while(!infile.eof()) {
		infile >> start;
		infile.ignore();
		infile >> end;
		infile.ignore();
		infile >> weight;

		getNode(start)->addEdge(getNode(end));
		getNode(start)->addWeight(weight);
	}
}

Vertex* Graph::getNode(int id) {
	for (int i = 0; i < nodes.size(); i++) {
		if (stoi(nodes[i]->getData()[0]) == id) {
			return nodes[i];
		}
	}
}

void Graph::dijkstra(int from, int to) {
	
}