#ifndef CITYNODE_H
#define CITYNODE_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CityNode
{
private:
	string name;
	vector<CityNode*> connections;
public:
	// Constructor
	CityNode(string city): name(city) {}
	// Accessor functions
	string getName() const;
	vector<CityNode*> getConnections() const;

};

#endif
