#include "FlightEdge.h"

double FlightEdge::getFare() const
{
	return fare;
}

double FlightEdge::getDistance() const
{
	return distance;
}

string FlightEdge::getCarrier() const
{
	return carrier;
}

CityNode* FlightEdge::getDestination() const
{
	return destination;
}

CityNode* FlightEdge::getOrigin() const
{
	return origin;
}

bool FlightEdge::getTraversed() const
{
	return traversed;
}

bool FlightEdge::getIsMSTpath() const
{
	return isMSTpath;
}

void FlightEdge::setTraversed(bool status)
{
	traversed = status;
}

void FlightEdge::setIsMSTpath(bool status)
{
	isMSTpath = status;
}
