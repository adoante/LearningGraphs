#include "Vertex.h"
#include <iostream>
#include <string>

// Default Constructor
Vertex::Vertex() {

}
// One arg Constructor
Vertex::Vertex(std::vector<std::string> city_data) {
	city_data = city_data;
}

//Functions

// returns vertices ID
std::vector<std::string> Vertex::getCityData() const {
	return city_data;
}

// sets vertices ID
void Vertex::setCityData(std::vector<std::string> city_data) {
	city_data = city_data;
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
void Vertex::addEdge(Vertex* v) {
	edges.push_back(v);
}

// adds an weight to the vertex
void Vertex::addWeight(int w) {
	weights.push_back(w);
}

// print vertex info
void Vertex::printVertex() {
	for (int i = 0; i < 5; i++) {
		std::cout << city_data[i] << std::endl;
	}
}