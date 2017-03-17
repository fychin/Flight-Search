#include <iostream>
#include <fstream>
#include "Graph.h"

using namespace std;

/* Name: Fu Yang Chin
 * Given a city, find all the cheapest flights 
 * that visits all other cities accessible from the city.
 * Usage: ./extension flights_fare_dataset.tsv city_source.tsv output_flight_path.tsv
**/

int main(int argc, char** argv) 
{
	if (argc != 4) {
		cout << "./extension called with invalid arguments." << endl;
		cout << "Usage: ./extension flights_fare_dataset.tsv city_source.tsv output_flight_path.tsv" << endl;
		return -1;
	}
	ifstream inFile(argv[1]);
	Graph flightsGraph(inFile);

	cout << "Finding minimum spanning tree...\n";
	ifstream citysourceFile(argv[2]);
	flightsGraph.findMinimumSpaningTree(citysourceFile);

	cout << "Writing flights to file...\n\n\n";
	ofstream outFile(argv[3]);
	flightsGraph.outputFlightPaths(outFile);

	return 0;
}