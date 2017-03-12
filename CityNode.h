#ifndef CITYNODE_H
#define CITYNODE_H
#include <iostream>
#include <string>
#include <unordered_set>
#include "FlightEdge.h"
using namespace std;

class FlightEdge;

class CityNode
{
private:
	string name;
	unordered_set<FlightEdge*> flightConnections;
	bool done;
	CityNode* prev;

public:
	// Constructor
	CityNode(string city): name(city), done(false), prev(NULL) {}
	// Accessor functions
	string getName() const;
	unordered_set<FlightEdge*> getConnections() const;
	bool getDone() const;
	CityNode* getPrev() const;

	// Mutator functions
	void setDone(bool status);
	void setPrev(CityNode* previous);
	void addConnection(FlightEdge* flight);

};

#endif
