#include "WorldAirspace.h"


#define numberAirports 3019
#define numberFlights 63832


WorldAirspace::WorldAirspace() : graph(numberAirports){
    createAirports();
    createFlights();
}


WorldAirspace::~WorldAirspace() {
    graph.clear();
}


void WorldAirspace::createAirports() {

    ifstream file(AIRPORTS);
    if (file.is_open())
    {
        int n = 1;
        string lineAirport;
        getline(file,lineAirport);


        while(!file.eof()){
            string code,name,city,country,lat,lon;
            double latitude,longitude;


            getline(file, code, ',');
            getline(file,name, ',');
            getline(file, city, ',');
            getline(file, country, ',');
            getline(file,lat,',');latitude = stod(lat);
            getline(file,lon); longitude = stod(lon);
            Coordinate coo = {latitude, longitude};

            airports.insert(make_pair(code,n));
            Node airport {code, name, city, country, coo, false, {}};
            graph.addNode(airport, n);
            n++;
        }
    }

    else
    {
        cout << "The file " << AIRPORTS << " doesn't exist." << endl;
    }
    file.close();
}

void WorldAirspace::createFlights() {

    ifstream file(FLIGHTS);
    if(file.is_open())
    {

        string lineFlight;
        getline(file,lineFlight);

        while(!file.eof()){
            string source,target,airline;
            getline(file, source, ',');
            getline(file, target, ',');
            getline(file,airline);

            Flight flight = {source, target, airline};
            flights.push_back(flight);
            graph.addEdge(airports[source],airports[target],flight);
        }
    }
    else
    {
        cout << "The file " << FLIGHTS << " doesn't exist." << endl;
    }
    file.close();
}

void WorldAirspace::showPath(const Coordinate &coordDeparture, const Coordinate &coordArrival, set<string> &airlines) {
    showPath(graph.getNode(coordDeparture).code,graph.getNode(coordArrival).code, airlines);
}

/*
void WorldAirspace::showPathCountry(const string &countryDeparture, const string &countryArrival) {
    showPath(graph.getNode(countryDeparture).code,graph.getNode(countryArrival).code);
}
*/
void WorldAirspace::showPath(const string &departure, const string &arrival, set<string> &airlines) {

    auto itr1 = airports.find(departure);
    auto itr2 = airports.find(arrival);

    if (itr1 == airports.end() || itr2 == airports.end()){
        cout << "Aeroporto Invalido!" << endl;
        return;
    }

    vector<Node> nodes = graph.makePath(airports[departure], airports[arrival]);

    if(!airlines.empty())
        nodes = graph.makePath(airports[departure], airports[arrival], airlines);

    if(nodes.empty()) return;

    double lastDistance = 0;
    cout << "Do aeroporto " << nodes[nodes.size()-1].code << " (" << nodes[nodes.size()-1].name << "), cidade " << nodes[nodes.size()-1].city << ", pais " << nodes[nodes.size()-1].country << endl;
    for (size_t i = nodes.size() - 2 ; i != -1 ; i--) {

            cout << "ao aeroporto " << nodes[i].code << " (" << nodes[i].name << "), cidade " << nodes[i].city
                 << ", pais " << nodes[i].country << " com um percurso de " <<
                 nodes[i].customWeight.km - lastDistance << " km" << endl;
            cout << endl;
            cout << "Voo recomendado: " << endl;
            cout << nodes[i].currentFlight.departure << ", " << nodes[i].currentFlight.arrival << ", "
                 << nodes[i].currentFlight.airline << endl;
            cout << endl;
            lastDistance = nodes[i].customWeight.km;
    }

}

void WorldAirspace::disableAllAirports() {
    graph.disableAllAirports();
}

void WorldAirspace::activateAllAirports() {
    graph.activateAllAirports();
}

int WorldAirspace::countFlightsSourceAirport(string airport) {
    return graph.countFlightsSourceAirport(airport);
}

int WorldAirspace::countAirlinesAirport(string airport,string airline) {
    return graph.countAirlinesAirport(airport,airline);
}

int WorldAirspace::countTargetsAirport(string airport) {
    return graph.countTargetsAirport(airport);
}

int WorldAirspace::countCityTargetsAirport(string airport) {
    return graph.countCityTargetsAirport(airport);
}


int WorldAirspace::countCountryTargetsAirport(string airport) {
    return graph.countCountryTargetsAirport(airport);
}

int WorldAirspace::airportsReached(string airport, int flightsNum) {
    graph.disableAllAirports();
    return graph.airportsReached(airport, flightsNum);
}

int WorldAirspace::citiesReached(string airport, int flightsNum) {
    return graph.citiesReached(airport, flightsNum);
}

int WorldAirspace::countriesReached(string airport, int flightsNum) {
    return graph.countriesReached(airport, flightsNum);
}
