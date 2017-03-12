#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <queue>
#include "CityNode.h"
#include "FlightEdge.h"

using namespace std;

// Functor for flightFares priority queue to compare the lower fares
struct CompareFare
{
	bool operator() (const FlightEdge* lhs, const FlightEdge* rhs) {
		return lhs->getFare() > rhs->getFare();
	}
};

class Graph
{
private:
	double totalFareCost;
	unordered_map<string, CityNode*> cities;
	priority_queue<FlightEdge*, vector<FlightEdge*>, CompareFare> flightFares;	// Sort flights by lowest fares

	void buildGraph(ifstream& inputData);
	CityNode* readCitySource(ifstream& citySourceData);
public:
	Graph(ifstream& inputData);
	void findMinimumSpaningTree(ifstream& citySourceData);
	void outputFlightPaths(ofstream& outFile);
	~Graph();
};

#endif
