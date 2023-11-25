#include "Vertex.h"
#include <iostream>
#include <string>

// Default Constructor
Vertex::Vertex() {

}
// One arg Constructor
Vertex::Vertex(std::vector<std::string> d) {
	data = d;
}

//Functions

// returns vertices ID
std::vector<std::string> Vertex::getData() const {
	return data;
}

// sets vertices ID
void Vertex::setData(std::vector<std::string> d) {
	data = d;
}

// returns a refrence to vertices edges
std::vector<Vertex*> & Vertex::getEdges() {
	return edges;
}

// returns a refrence to vertices weights
std::vector<int> & Vertex::getWeights() {
	return weights;
}

// adds an edge to the vertex
void Vertex::addEdge(Vertex *v) {
	edges.push_back(v);
}

// adds an weight to the vertex
void Vertex::addWeight(int w) {
	weights.push_back(w);
}

// print vertex info
void Vertex::printVertex() {
	std::cout << "DATA: [ ";
	for (int i = 0; i < 5; i++) {
		std::cout << data[i] << " ";
	}
	std::cout << "]" << std::endl;

	std::cout << "EDGES: [ ";
	for (int i = 0; i < edges.size(); i++) {
		std::cout << edges[i]->getData()[0] << " ";
	}
	std::cout << "]" << std::endl;

	std::cout << "WEIGHTS [ ";
	for (int i = 0; i < weights.size(); i++) {
		std::cout << weights[i] << " ";
	}
	std::cout << "]" << std::endl;
}