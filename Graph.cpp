#include "Graph.h"
#include <fstream>
#include <iostream>
#include <string>

// Default
Graph::Graph() {

}

// One-Arg, creates nodes from file
Graph::Graph(std::string infile) {
	createNodes(infile);
}

// Two-Arg, creates nodes from file1 and links nodes from file2
Graph::Graph(std::string nodeFile, std::string linkFile) {
	createNodes(nodeFile);
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
void Graph::createNodes(std::string file) {
	std::ifstream infile(file);
	if (!infile.is_open()) {
		std::cout << "Error: Cannot open city.txt file." << std::endl;
	}

	Vertex *temp = new Vertex();
	while(!infile.eof()) {
		std::string stemp;
		infile >> stemp;
		temp->getData().push_back(stemp);
		if (infile.peek() == '\n') {
			addNode(temp);
			temp = new Vertex();
		}
		infile.ignore();
	}
	infile.close();
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

	infile.close();
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