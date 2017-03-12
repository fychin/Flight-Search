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
