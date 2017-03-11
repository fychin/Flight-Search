#include "CityNode.h"

string CityNode::getName() const
{
	return name;
}

vector<CityNode*> CityNode::getConnections() const
{
	return connections;
}
