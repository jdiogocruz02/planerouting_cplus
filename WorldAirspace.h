#ifndef PROJETO2_WORLDAIRSPACE_H
#define PROJETO2_WORLDAIRSPACE_H

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include "Graph.h"
#include <cmath>
#include <vector>
using namespace std;

#define AIRPORTS "../data/airports.csv" // Nodes
#define FLIGHTS "../data/flights.csv" // Links




class WorldAirspace {
private:

    /**
     * @var graph - a Graph class containing all data
     */
    Graph graph;

    /**
     * @var airports - a map, to manage all airports
     */
    map<string, int> airports;

    /**
     * @var flights - a vector, the flight values, source, target and airline, to manage all flights
     */
    vector<Flight> flights;

    /**
     * Function that reads and creates all airports
     * Time Complexity: O(A), which S is the number of lines in the file = number of Airports to create
     */
    void createAirports();

    /**
     * Function that reads and creates all Flights
     * Time Complexity: O(L.A), which L is the number of lines in the file = number of Flights to create and A
     * is the number of Airports to the certain Flights
     */
    void createFlights();


public:

    /**
     * A default constructor of class
     */
    WorldAirspace();

    /**
     * A default destructor of class
     */
    ~WorldAirspace();

    /**
     * @Overload
     * Function that prints all path based on users input
     * Time Complexity: O(V), which V is the number of Nodes
     * @param departure - a string containing the code of certain departure airport
     * @param arrival - a string containing the name of certain arrival airport
     * @param airlines - an set containing the codes of certain airlines the user choice
     */
    void showPath(const string &departure, const string &arrival, set<string> &airlines);

    /**
     * @Overload
     * Function that prints all path based on users input
     * Time Complexity: O(V), which V is the number of Nodes
     * @param coordDeparture - a Coordinate struct containing the coordinate of certain departure airport
     * @param coordArrival - a Coordinate struct containing the coordinate of certain arrival airport
     * @param airlines - an set containing the codes of certain airlines the user choice
     */
    void showPath(const Coordinate &coordDeparture, const Coordinate &coordArrival, set<string> &airlines);

    /**
     * voos a partir de um dado aeroporto
     * @return número de voos
     */
    int countFlightsSourceAirport(string airport);

    /**
     * How many airlines in an airport
     * @return number of airlines
     */
    int countAirlinesAirport(string airport, string airline);

    /**
     * How many different targets from an airport
     * @return number of targets/airports
     */
    int countTargetsAirport(string airport);

    /**
     * How many different countries are reached from an airport
     * @return number of cities
     */
    int countCityTargetsAirport(string airport);

    /**
     * How many different countries are reached from an airport
     * @return number of countries
     */
    int countCountryTargetsAirport(string airport);

    /**
     * Given n max flights how many airports are reached
     * @return number of airports
     */
    int airportsReached(string airport, int n);

    /**
     * Given n max flights how many cities are reached
     * @return number of airports
     */
    int citiesReached(string airport, int n);

    /**
     * Given n max flights how many cities are reached
     * @return number of airports
     */
    int countriesReached(string airport, int n);

    /**
     * Function that disable all nodes in current Graph
     * Time Complexity: O(V), which V is the number of Nodes
     */
    void disableAllAirports();

    /**
     * Function that activates all nodes in current Graph
     * Time Complexity: O(V), which V is the number of Nodes
     */
    void activateAllAirports();
};


#endif //PROJETO2_WORLDAIRSPACE_H