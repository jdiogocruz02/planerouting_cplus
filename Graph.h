#ifndef PROJETO2_GRAPH_H
#define PROJETO2_GRAPH_H

#include <list>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <set>
#include <queue>
using namespace std;

/**
 * Definition of the largest number used in class bellow
 */
#define INF (INT_MAX/2)

/**
 * Struct that groups the departure and arrival airports of a flight as well as the airline
 */
struct Flight{
    /**
    * @var departure - departure airport code
    */
    string departure;

    /**
    * @var arrival - arrival airport code
    */
    string arrival;

    /**
    * @var airline - airline code
    */
    string airline;

};

/**
 * Struct that groups the two dimensions of the coordinate (latitude and longitude)
 */
struct Coordinate {

    /**
     * @var latitude - coordinates latitude, a double value
     */
    double latitude;

    /**
     * @var longitude - coordinates longitude, a double value
     */
    double longitude;
};

/**
 * Struct that groups the tree customizable weights for the Dijkstra Algorithm
 */
struct CustomWeight {

    /**
     * @var km - a double which contains the distance between current node and departure
     */
    double km;

    /**
     * @var numberOfFlights - an integer value that contains the number of distinct flights between current node and departure
     */
    int numberOfFlights;

    /**
     * @var numberOfCities - an integer value that contains the number of distinct cities between current node and departure
     */
    int numberOfCities;
};

/**
 * Struct that groups all characteristics of the edge that separates two nodes
 */
struct Edge {

    /**
     * @var dest - an integer value that represents the destination of current edge, based on node's index
     */
    int dest;

    /**
     * @var weight - a double value that represents the edge length in km
     */
    double weight;

    /**
     * @var flight - object that represents a flight(departure,arrival and airline)
     */
    Flight flight;

    /**
    * @var visited - bool that represents a flight(departure,arrival and airline)
    */
    bool visited;

};

/**
 * Struct that represents a Airport
 */
struct Node {

    /**
     * @var code - a string that represents airport code
     */
    string code;

    /**
     * @var name - a string that represents airport name
     */
    string name;

    /**
     * @var city - a string that represents the airports city
     */
    string city;

    /**
     * @var country - a string that represents the airports country
     */
    string country;

    /**
     * @var coordinate - a Coordinate struct type that represents airport coordinate
     */
    Coordinate coordinate;

    /**
     * @var available - a boolean attribute that represents the current state of airport
     */
    bool available;

    /**
     * @var adjacent - a list of Edges containing all possible paths from the current node
     */
    list<Edge> adjacent;

    /**
     * @var customWeight - a CustomWeight struct that includes all the distinct weights of current node
     */
    CustomWeight customWeight;

    /**
     * @var visited - a boolean attribute that indicates if the airport is active
     */
    bool visited;

    /**
     * @var parent - an integer value represents previous node index
     */
    int parent;

    /**
     * @var currentFlight - an object representing one of the several flights the node can be on
     */
    Flight currentFlight;

    /**
     * @var distance - an integer value containing the number of nodes between current node and origin
     */
    int distance;
};

/**
 * Class that represents a Graph and its entire structure
 */
class Graph {


    /**
     * @var nodes - a vector containing Node type struct that includes all nodes of current Graph
     */
    vector<Node> nodes;


    /**
     * @var n - number of nodes/airports
     */
    int n = 3019;



    /**
     * Function that returns the distance between two points with coordinates passed by parameter
     * Time Complexity: O(1)
     * @param lat1 - a double value represents the latitude of first point
     * @param lon1 - a double value represents the longitude of first point
     * @param lat2 - a double value represents the latitude of second point
     * @param lon2 - a double value represents the longitude of second point
     * @return a double value containing the distance between two points
     */
    double computeDistance(double lat1, double lon1, double lat2, double lon2);


public:

    /**
     * Main constructor of the class Graph
     * @param nodes integer number that represents the number of nodes that graph must have
     */
    explicit Graph(int nodes);

    /**
     * Function that clears all Nodes
     * Time Complexity: O(V), which V is the number of nodes
     */
    void clear();

    /**
     * Function that adds a new Node to the graph
     * Time Complexity: O(1)
     * @param node - Node struct that contains all characteristics of the stop
     * @param index - an integer value that represents the Stop index in vector
     */
    void addNode(const Node &node, int index);

    /**
     * @Overload
     * Function that returns one airport, based on his coordinate
     * Time Complexity: O(V), which V is the number of Nodes
     * @param coordinate - a Coordinate struct that represents the airport coordinate
     * @return a Node struct, representing the airport closest to the given coordinate
     */
    Node getNode(const Coordinate &coordinate);

    /**
     * Function that adds an Edge between two nodes
     * Time Complexity: O(1)
     * @param flight - an object passed by reference containing the details of one of the flights between 2 airports
     * @param departure - an string representing the departure airport
     * @param arrival - an string representing the arrival airport
     */
    void addEdge(int departure, int arrival, Flight &flight);


    /**
     * Breadth-first search to determinate the distance, in nodes, between two airports
     * Time Complexity: O(V + E), which V is the number of Nodes and E is the number of edges
     * @param departure - index of departure airport
     */
    void BFS(int departure);

    /**
     * Breadth-first search to determinate the distance, in nodes, between two airports
     * Time Complexity: O(V + E), which V is the number of Nodes and E is the number of edges
     * @param departure - index of departure airport
     * @param airlines - set of airlines the user want to use
     */
    void BFS(int departure,set<string> &airlines);


    /**
     * Function that returns a path based on users input
     * Time Complexity: O(V), which V is the number of Nodes
     * @param departure - index of departure airport
     * @param arrival - index of arrival airport
     * @return a vector of Node structs that containing all path between arrival and departure nodes
     */
    vector<Node> makePath(int departure, int arrival);

    /**
     * Function that returns a path based on users input
     * Time Complexity: O(V), which V is the number of Nodes
     * @param departure - index of departure airport
     * @param arrival - index of arrival airport
     * @param airlines - set of airlines the user want to use
     * @return a vector of Node structs that containing all path between arrival and departure nodes
     */
    vector<Node> makePath(int departure, int arrival, set<string> &airlines);

    /**
     * Function that disable a airport
     * Time Complexity: O(1)
     * @param airport - an integer value containing the index of airport
     */
    void activateAirport(int airport);

    /**
     * Function that disables all nodes in current Graph
     * Time Complexity: O(V), which V is the number of Nodes
     */
    void disableAllAirports();

    /**
     * Function that activates all nodes in current Graph
     * Time Complexity: O(V), which V is the number of Nodes
     */
    void activateAllAirports();

    /**
     * Function that activates all nodes in current Graph
     * Time Complexity: O(V*E), in which V is the number of Nodes and E is the number of Edges;
     */
    void activateAllAirlines();

    /**
    * Function that counts the number of flights of a given source airport
    * Time Complexity: O(V), which V is the number of Nodes
    */
    int countFlightsSourceAirport(string airport);

    /**
    * Function that counts the number of airlines operating on a given source airport
    * Time Complexity: O(V*E), in which V is the number of Nodes and E is the number of Edges;
    */
    int countAirlinesAirport(string airport, string airline);

    /**
    * Function that counts the number of different airport destinations of all flights on a given source airport
    * Time Complexity: O(V*E), in which V is the number of Nodes and E is the number of Edges;
    */
    int countTargetsAirport(string airport);

    /**
    * Function that counts the number of different city destinations of all flights on a given source airport
    * Time Complexity: O(V*E), in which V is the number of Nodes and E is the number of Edges;
    */
    int countCityTargetsAirport(string airport);

    /**
    * Function that counts the number of different country destinations of all flights on a given source airport
    * Time Complexity: O(V*E), in which V is the number of Nodes and E is the number of Edges;
    */
    int countCountryTargetsAirport(string airport);

    /**
    * Function that counts the number of different airport destinations of all flights on a given source airport and given a max number of possible flights
    * Time Complexity: O(V*E), in which V is the number of Nodes and E is the number of Edges;
    */
    int airportsReached(string airport, int n);


    /**
     * Function that counts the number of different city destinations of all flights on a given source airport and given a max number of possible flights
     * Time Complexity: O(V*E), in which V is the number of Nodes and E is the number of Edges;
     */
    int citiesReached(string airport, int n);


    /**
     * Function that counts the number of different country destinations of all flights on a given source airport and given a max number of possible flights
     * Time Complexity: O(V*E), in which V is the number of Nodes and E is the number of Edges;
     */
    int countriesReached(string airport, int n);


};


#endif //UNTITLED_GRAPH_H