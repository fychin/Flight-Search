#include "Graph.h"
#include <string>
#include <sstream>
#include <iomanip>
#include <stack>

void Graph::buildGraph(ifstream & inputData)
{
	if (!inputData) {
		cout << "Error reading input file.\n";
		return;
	}

	// Parse header
	string header;
	getline(inputData, header);

	while (inputData) {
		string line;
		if (!getline(inputData, line)) break;

		// Parse data fields
		istringstream ss(line);
		vector<string> record;
		while (ss) {
			string field;

			if (!getline(ss, field, '\t')) break;
			record.push_back(field);
		}

		if (record.size() != 6) {
			continue;
		}

		string city1_name(record[0]);
		string city2_name(record[1]);
		double nmiles = stod(record[2]);
		double fare = stod(record[4]);
		string carrier(record[5]);

		CityNode* origin_city = cities[city1_name];
		CityNode* destination_city = cities[city2_name];

		if (!origin_city) {
			cities[city1_name] = new CityNode(city1_name);
			origin_city = cities[city1_name];
		}
		if (!destination_city) {
			cities[city2_name] = new CityNode(city2_name);
			destination_city = cities[city2_name];
		}
		// Add connections to cities
		FlightEdge* currFlight = new FlightEdge(origin_city, destination_city, nmiles, fare, carrier);
		flightFares.push(currFlight);
		origin_city->addConnection(currFlight);
	}

	if (!inputData.eof()) {
		cerr << "Failed to read input data!\n";
		return;
	}
	inputData.close();
}

CityNode* Graph::readCitySource(ifstream & citySourceData)
{
	if (!citySourceData) {
		cout << "Failed to read city source input file.\n";
		return NULL;
	}
	string cityName;
	getline(citySourceData, cityName);
	return cities[cityName];
}

Graph::Graph(ifstream & inputData)
{
	totalFareCost = 0;
	citySource = NULL;
	buildGraph(inputData);
}

void Graph::findMinimumSpaningTree(ifstream & citySourceData)
{
	citySource = readCitySource(citySourceData);
	// Check for valid city name
	if (!citySource) {
		cout << "Invalid city provided, please provide an existing city name from the dataset.\n";
		return;
	}

	// Perform Prim's Algorithm
	citySource->setDone(true);
	priority_queue<FlightEdge*, vector<FlightEdge*>, CompareFare> pq;
	for (auto edge : citySource->getConnections()) {
		pq.push(edge);
	}
	while (!pq.empty()) {
		FlightEdge* currEdge = pq.top();
		pq.pop();
		CityNode* adjacentNode = currEdge->getDestination();
		if (!adjacentNode->getDone()) {
			adjacentNode->setDone(true);
			adjacentNode->setPrev(currEdge);
			currEdge->setIsMSTpath(true);
			mstPaths.insert(currEdge);
			for (auto adjEdge : adjacentNode->getConnections()) {
				pq.push(adjEdge);
			}
		}
	}

}

void Graph::outputFlightPaths(ofstream & outFile)
{
	if (!outFile) {
		cout << "Error opening output file.\n";
		return;
	}

	// Check every mstPath for terminal edge
	for (auto mstIt : mstPaths) {
		FlightEdge* currEdge = mstIt;
		// Check if current edge is a terminal, if yes, back track and print path
		bool isTerminalEdge = true;
		auto outgoingEdges = currEdge->getDestination()->getConnections();
		// Find mstPath from outgoing edges of adjacent node to check for terminal node
		for (auto adjNodeEdge : outgoingEdges) {
			if (adjNodeEdge->getIsMSTpath()) {
				isTerminalEdge = false;	// not a terminal node
				break;
			}
		}
		// Bactrack from terminal edge and print path
		if (isTerminalEdge && !currEdge->getTraversed()) {
			FlightEdge* prevEdge = currEdge;
			currEdge->setTraversed(true);
			while (prevEdge->getOrigin() != citySource) {
				outFile << prevEdge->getOrigin()->getName()
					<< "--" << prevEdge->getCarrier() << "-->"
					<< prevEdge->getDestination()->getName()
					<< "\t\tFare: " << prevEdge->getFare() << endl;
				prevEdge = prevEdge->getOrigin()->getPrev();
				totalFareCost += prevEdge->getFare();
			}
			outFile << prevEdge->getOrigin()->getName()
				<< "--" << prevEdge->getCarrier() << "-->"
				<< prevEdge->getDestination()->getName()
				<< "\t\tFare: " << prevEdge->getFare() << endl;
			outFile << "\n------------------------------------------------------------------------------\n\n";
			totalFareCost += prevEdge->getFare();
		}
	}
	// Print total cost
	outFile << "\n\nLowest cost to visit all cities from " << citySource->getName() << ":\n" << totalFareCost << endl;
}

Graph::~Graph()
{
	for (auto it = cities.begin(); it != cities.end(); ++it) {
		unordered_set<FlightEdge*> connections = it->second->getConnections();
		for (FlightEdge* edge : connections) {
			delete edge;
		}
		delete it->second;
	}
}
