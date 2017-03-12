#include <iostream>
#include <fstream>
#include "Graph.h"

using namespace std;

/* Problem: 
 * If you live in a city, what is the lowest amount of money you can spend to travel
 * all the cities that are accessible through your city?
 * What are the paths
**/

int main(int argc, char** argv) 
{
	ifstream inFile("flights_fare_2016q2.txt");
	Graph flightsGraph(inFile);

	cout << "Finding minimum spanning tree...\n";
	ifstream citysourceFile("city_source.txt");
	flightsGraph.findMinimumSpaningTree(citysourceFile);

	cout << "Writing flights to file...\n";
	ofstream outFile("flight_paths.txt");
	flightsGraph.outputFlightPaths(outFile);

	return 0;
}