# Simple makefile for extension.cpp

CC=g++
CXXFLAGS=-std=c++11

Graph.o: Graph.h
FlightEdge.o: FlightEdge.h
CityNode.o: CityNode.h

extension: extension.cpp Graph.o FlightEdge.o CityNode.o

clean: rm -f extension *.o
