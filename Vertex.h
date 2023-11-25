#ifndef VERTEX_H

//imports
#include <vector>
#include <string>

#define VERTEX_H

class Vertex {
	private:
		// City Data
		std::vector<std::string> data;
		// All vertices connected to this vertex, one-to-one to weights
		std::vector<Vertex*> edges;
		// All weights leading to this vertex, one-to-one to edges
		std::vector<int> weights;

	public:
		// Constructors

		// Default Constructor
		Vertex();
		// One arg Constructor
		Vertex(std::vector<std::string>);

		//Functions

		// returns vertices ID
		std::vector<std::string> getData() const;
		// sets vertices ID
		void setData(std::vector<std::string>);
		// returns a refrence to vertices edges
		std::vector<Vertex*> & getEdges();
		// returns a refrence to vertices weights
		std::vector<int> & getWeights();
		// adds an edge to the vertex
		void addEdge(Vertex*);
		// adds an weight to the vertex
		void addWeight(int);
		// print vertex info
		void printVertex();


};

#endif // !VERTEX_H

