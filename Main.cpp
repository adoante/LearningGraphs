#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Graph.h"

// Helper Function definitions 
bool getCityData(std::string, std::vector<Vertex*>, std::vector<std::string>&);

int main (int argc, char *argv[]) {

	// Create Graph
	Graph g = Graph("city.txt", "road.txt");

	// Print all nodes
	for (int i = 0; i < g.getNodes().size(); i++) {
		g.getNodes()[i]->printVertex();
		std::cout << "-----------------------------" << std::endl;
	}

	// Get and set input cities
	std::string fromCitycode = argv[1];
	std::string toCitycode = argv[2];

	//vectors hold city data 'from' and 'to' as strings
	std::vector<std::string> from_data;
	std::vector<std::string> to_data;

	// sets 'from' and 'to' city data vector and if it can't then exits the program.
	// Tells the user the which city code is invalid or if both are invalid
	bool fromFlag = getCityData(fromCitycode, g.getNodes(), from_data);
	bool toFlag = getCityData(toCitycode, g.getNodes(), to_data);

	// tells user if both are invalid
	if (!fromFlag & !toFlag) {
		std::cout << "Invalid city code: " << fromCitycode << " and Invalid city code: " << toCitycode << std::endl;
		return 1;
	}
	// tells user if 'to' city code is invalid
	else if (!toFlag) {
		std::cout << "Invalid city code: " << toCitycode << std::endl;
		return 1;
	}
	// tells user if 'from' city code is invalid
	else if (!fromFlag) {
		std::cout << "Invalid city code: " << fromCitycode << std::endl;
		return 1;
	}

	// Setting 'from' city values
	int fromId = stoi(from_data[0]);
	std::string fromName = from_data[2];
	int fromPopulation = stoi(from_data[3]);
	int fromElevation = stoi(from_data[4]);

	// Setting 'to' city values
	int toId = stoi(to_data[0]);
	std::string toName = to_data[2];
	int toPopulation = stoi(to_data[3]);
	int toElevation = stoi(to_data[4]);

	// Print group name and info on the input cities
	std::cout << "Author: Adolfo Sanpedro Gante" << std::endl;
	std::cout << "Date: 11/29/2023" << std::endl;
	std::cout << "Course: CS311 (Data structures and Algorithms)" << std::endl;
	std::cout << "Description : Program to find the shortest route between cities" << std::endl; 
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "From City: " << fromName << ", population " << fromPopulation << ", elevation " << fromElevation << std::endl;
	std::cout << "To City: " << toName << ", population " << toPopulation << ", elevation " << toElevation << std::endl;

	// Prints shortset route
	// TODO
	/*
		Could look something like this.
		Where shortestRoute is function in the graph class
		and returns true or false
		if true it prints the shortest path within the function
		if false it just returns false and we handle it in our main.cpp

		bool path = g.shortestRoute(fromId, toId);
		if (path == false) {
			std::cout << "No route from" << fromName << " and " << toName << "." << std::endl;
		}
	 */

	return 0;
}


/**
 * @brief Finds and sets 'from' or 'to' city data if city is found in city_data vector
 * 
 * @param city_code 2 letter code of city we are searching for
 * @param city_data refrence all city data vector
 * @param data refrence to the vector of strings
 * @return true if found, false if not found
 */
bool getCityData(std::string city_code, std::vector<Vertex*> city_data, std::vector<std::string> &data) {
	// Linear search,100 item array
	for (int i = 0; i < city_data.size(); i++) {
		for (int j = 0; j < city_data[j]->getData().size(); j++) {
			if (city_data[i]->getData()[j] == city_code) {
				data = city_data[i]->getData();
				return true;
			}
		}
	}
	// if city_code not found return false
	return false;
}