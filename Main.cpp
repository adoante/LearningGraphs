#include <iostream>
// Going to need to create a Graph class
//#include "Graph.h"
// vector because c-style arrays yuck ew 
#include <vector>
// need this for stoi() converts string to int
#include <string>
// need this for reading files
#include <fstream>

#include "Graph.h"

// Using defines for city.txt sizes
// Could hard code 20 and 5, condsidering our input will always be a 20 and 5
#define CITY 20
#define DATA 5

// Helper Function definitions 
bool getCityData(std::string, std::vector<std::vector<std::string>>&, std::vector<std::string>&);

int main (int argc, char *argv[]) {

	// Create Graph from raod.txt file
	Graph g = Graph("road.txt");

	// Extract data from city.txt
	std::vector<std::vector<std::string>> city_data(CITY, std::vector<std::string>(DATA, " "));

	//Read from city.txt file to set city_data;
	std::ifstream infile("city.txt");
	if (!infile.is_open()) {
		std::cout << "Error: Cannot open city.txt file." << std::endl;
	}

	// Instead of using this nested for loop to set the 2d vector 'city_data' we
	// could just hard code this like this (this is what the nest loop does):
	/*
		std::vector<std::vector<std::string>> city_data =
			{{"0"}, {"AN"}, {"ANAHEIM"}, {"1273000"}, {"310"}}
			{{"1"}, {"BK"},	{"BAKERSFIELD"}, {"31100"},	{"390"}}
			etc.

	 */
	for (int i = 0; i < CITY; i++) {
		for (int j = 0; j < DATA; j++) {
			infile >> city_data[i][j];
			infile.ignore();
		}
	}

	// Get and set input cities
	std::string fromCitycode = argv[1];
	std::string toCitycode = argv[2];

	//vectors hold city data 'from' and 'to' as strings
	std::vector<std::string> from_data;
	std::vector<std::string> to_data;

	// sets 'from' and 'to' city data vector and if it can't then exits the program.
	// Tells the user the which city code is invalid or if both are invalid
	bool fromFlag = getCityData(fromCitycode, city_data, from_data);
	bool toFlag = getCityData(toCitycode, city_data, to_data);

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
	std::cout << "Author: Adolfo Sanpedro Gante, Caleb Gutierrez and Jack Walker" << std::endl;
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
bool getCityData(std::string city_code, std::vector<std::vector<std::string>> &city_data, std::vector<std::string> &data) {
	// Linear search,100 item array
	for (int i = 0; i < CITY; i++) {
		for (int j = 0; j < DATA; j++) {
			if (city_data[i][j] == city_code) {
				data = city_data[i];
				return true;
			}
		}
	}
	// if city_code not found return false
	return false;
}