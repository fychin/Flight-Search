#ifndef FLIGHTEDGE_H
#define FLIGHTEDGE_H
#include <iostream>
#include "CityNode.h"

using namespace std;

class CityNode;

class FlightEdge
{
private:
	CityNode* destination;
	CityNode* origin;
	double distance;
	double fare;
	string carrier;
	bool isMSTpath;
	bool traversed;	// mark terminal edge as traversed (ending mst path)
public:
	FlightEdge(CityNode* org, CityNode* dest, double miles, double price, string cr) : 
		origin(org), destination(dest), distance(miles), 
		fare(price), carrier(cr), traversed(false), isMSTpath(false) {}
	// Accessor functions
	double getFare() const;
	double getDistance() const;
	string getCarrier() const;
	CityNode* getDestination() const;
	CityNode* getOrigin() const;
	bool getTraversed() const;
	bool getIsMSTpath() const;

	// Mutator functions
	void setTraversed(bool status);
	void setIsMSTpath(bool status);
};

#endif
