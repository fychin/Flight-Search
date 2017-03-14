#include "CityNode.h"

string CityNode::getName() const
{
	return name;
}

unordered_set<FlightEdge*> CityNode::getConnections() const
{
	return flightConnections;
}

bool CityNode::getDone() const
{
	return done;
}

FlightEdge* CityNode::getPrev() const
{
	return prev;
}

void CityNode::setDone(bool status)
{
	done = status;
}

void CityNode::setPrev(FlightEdge* previous)
{
	prev = previous;
}

void CityNode::addConnection(FlightEdge * flight)
{
	flightConnections.insert(flight);
}
