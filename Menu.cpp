
#include "Menu.h"
#include "WorldAirspace.h"
#include "Utility.h"


using namespace std;

Menu::Menu(){
    this->menuState.push(MAIN_MENU);
    worldAirspace = WorldAirspace();
    getMenu();
}

void Menu::getMenu(){
    if (!menuState.empty()){
        switch (menuState.top()) {
            case 0: mainMenu(); break;
            case 1: searchMenu(); break;
            case 2: searchDefinitionsMenu(); break;
            case 3: infoAirportMenu(); break;
            case 4: coordMenu(); break;
            case 5: airportMenu(); break;
            case 6: cityMenu(); break;
            case 7: countryMenu(); break;
        }
    } else exit(0);
}

void Menu::mainMenu(){
    do {
        cout << "================|MENU|================" << endl;
        cout << "|                                    |" << endl;
        cout << "|    1-Encontrar voo                 |" << endl;
        cout << "|    2-Informacao sobre aeroporto    |" << endl;
        cout << "|    3-Sair                          |" << endl;
        cout << "|                                    |" << endl;
        cout << "======================================" << endl;
        cin >> option;
        if (option < 1 || option > 3) cout << "Opcao errada!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');

    } while (option < 1 || option > 3);

    switch (option) {
        case 1:
            menuState.push(SEARCH_DEFINITIONS_MENU);
            break;
        case 2:
            menuState.push(INFO_AIRPORT_MENU);
            break;
            case 3: default:
            menuState.pop();
            break;
    }
    getMenu();
}

void Menu::searchDefinitionsMenu(){
    do {
        cout << "========|Definicoes de procura|=======" << endl;
        cout << "|                                    |" << endl;
        cout << "|    1-Usar todas as companhias      |" << endl;
        cout << "|    2-Usar uma ou mais              |" << endl;
        cout << "|    3-Sair                          |" << endl;
        cout << "|                                    |" << endl;
        cout << "======================================" << endl;
        cin >> option;
        if (option < 1 || option > 3) cout << "Opcao errada!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');

    } while (option < 1 || option > 3);
    switch (option) {
        case 1: worldAirspace.activateAllAirports(); menuState.push(SEARCH_MENU); break;
        case 2: worldAirspace.activateAllAirports(); activateAirlineMenu(); menuState.push(SEARCH_MENU); break;
        case 3: menuState.pop(); break;
    }
    getMenu();
}

void Menu::searchMenu() {
    do {
        cout << "============|Encontrar voo|===========" << endl;
        cout << "|                                    |" << endl;
        cout << "|    1-Por cordenadas                |" << endl;
        cout << "|    2-Por aeroportos                |" << endl;
        cout << "|    3-Por cidades                   |" << endl;
        cout << "|    4-Por paises                    |" << endl;
        cout << "|    5-Sair                          |" << endl;
        cout << "|                                    |" << endl;
        cout << "======================================" << endl;
        cin >> option;
        if (option < 1 || option > 5) cout << "Opcao errada!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');

    } while (option < 1 || option > 5);
    switch (option) {
        case 1: menuState.push(COORDINATE_MENU); break;
        case 2: menuState.push(AIRPORT_MENU); break;
        case 3: menuState.push(CITY_MENU); break;
        case 4: menuState.push(COUNTRY_MENU); break;
        case 5: menuState.pop(); menuState.pop(); break;
    }

    getMenu();
}

void Menu::infoAirportMenu() {
    do {
        cout << "============|INFO AEROPORTO|===========" << endl;
        cout << "|                                     |" << endl;
        cout << "|    1-Total de voos                  |" << endl;
        cout << "|    2-Voos por companhia             |" << endl;
        cout << "|    3-Voos para destinos diferentes  |" << endl;
        cout << "|    4-Elaboracao de viagem com       |" << endl;
        cout << "|      Y voos                         |" << endl;
        cout << "|    5-Sair                           |" << endl;
        cout << "|                                     |" << endl;
        cout << "=======================================" << endl;
        cin >> option;
        if (option < 1 || option > 5) cout << "Opcao errada!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');

    } while (option < 1 || option > 5);

    switch (option) {
        case 1: flightsMenu(); break;
        case 2: airlineMenu(); break;
        case 3: airportsMenu(); break;
        case 4: routesByYFlightsMenu(); break;
        case 5: menuState.pop(); break;
    }

    getMenu();
}

void Menu::coordMenu(){

    double departureLatitude, departureLongitude,
           arrivalLatitude, arrivalLongitude;

    cout << "Insira as coordenadas de partida" << endl;
    cout << "Latitude: ";
    cin >> departureLatitude;
    cout << "Longitude: ";
    cin >> departureLongitude;

    cout << "Insira as coordenadas de chegada" << endl;
    cout << "Latitude: ";
    cin >> arrivalLatitude;
    cout << "Longitude: ";
    cin >> arrivalLongitude;

    Coordinate departureCoordinate = {departureLatitude, departureLongitude};
    Coordinate arrivalCoordinate = {arrivalLatitude, arrivalLongitude};
    worldAirspace.showPath(departureCoordinate,arrivalCoordinate, airlines);
    airlines.clear();

    cout << "Quer voltar ao menu principal(1) ou sair(2)? ";
    cin >> option;
    switch (option) {
        case 1:
            menuState.pop();
            menuState.pop();
            menuState.pop();
            break;
        case 2:
            menuState.pop();
            menuState.pop();
            menuState.pop();
            menuState.pop();
            break;
    }
    getMenu();
}

void Menu::airportMenu() {

    string departureAirport, arrivalAirport;

    cout << "Insira o codigo do aeroporto de partida: ";
    cin >> departureAirport;
    allUpper(departureAirport);

    cout << "Insira o codigo do aeroporto de chegada: ";
    cin >> arrivalAirport;
    allUpper(arrivalAirport);
    cout << endl;

    worldAirspace.showPath(departureAirport,arrivalAirport, airlines);
    airlines.clear();

    cout << "Quer voltar ao menu principal(1) ou sair(2)? ";
    cin >> option;
    switch (option) {
        case 1:
            menuState.pop();
            menuState.pop();
            menuState.pop();
            break;
        case 2:
            menuState.pop();
            menuState.pop();
            menuState.pop();
            menuState.pop();
            break;
    }
    getMenu();
}


void Menu::cityMenu() {

    string departureCity, arrivalCity;

    cout << "Insira a cidade de partida: ";
    cin >> departureCity;

    cout << "Insira a cidade de chegada: ";
    cin >> arrivalCity;



    cout << "Quer voltar ao menu principal(1) ou sair(2)? ";
    cin >> option;
    switch (option) {
        case 1:
            menuState.pop();
            menuState.pop();
            menuState.pop();
            break;
        case 2:
            menuState.pop();
            menuState.pop();
            menuState.pop();
            menuState.pop();
            break;
    }
    getMenu();
}

void Menu::countryMenu() {

    string departureCountry, arrivalCountry;

    cout << "Insira o pais de partida: ";
    cin >> departureCountry;

    cout << "Insira o pais de chegada: ";
    cin >> arrivalCountry;

    //worldAirspace.showPathCountry();

    cout << "Quer voltar ao menu principal(1) ou sair(2)? ";
    cin >> option;
    switch (option) {
        case 1:
            menuState.pop();
            menuState.pop();
            menuState.pop();
            break;
        case 2:
            menuState.pop();
            menuState.pop();
            menuState.pop();
            menuState.pop();
            break;
    }
    getMenu();
}

void Menu::flightsMenu() {

    bool insert = false;
    string airport;

    while (!insert){

        cout << "Insira o codigo do aeroporto: ";
        cin >> airport;
        allUpper(airport);

        cout << worldAirspace.countFlightsSourceAirport(airport) << endl;

        cout << "Deseja ver outro aeroporto? (S - Sim, N - Nao): ";
        cin >> airport;
        allUpper(airport);
        if (airport == "N") insert = true;

    }
    worldAirspace.disableAllAirports();
}

void Menu::airlineMenu() {

    bool insert = false;
    string airport;
    string airline;

    while (!insert){

        cout << "Insira o codigo do aeroporto: ";
        cin >> airport;
        allUpper(airport);

        cout << "Insira o codigo da companhia: ";
        cin >> airline;
        allUpper(airline);

        cout << worldAirspace.countAirlinesAirport(airport,airline) << endl;

        cout << "Deseja ver outro aeroporto? (S - Sim, N - Nao): ";
        cin >> airport;
        allUpper(airport);
        if (airport == "N") insert = true;

    }
}

void Menu::airportsMenu(){
    bool insert = false;
    string airport;

    while (!insert){

        cout << "Insira o codigo do aeroporto: ";
        cin >> airport;
        allUpper(airport);

        cout << endl;
        cout << "Dos " << worldAirspace.countFlightsSourceAirport(airport) << " voos que partem de " << airport << ", " << worldAirspace.countTargetsAirport(airport)
        << " deles partem para aeroportos distintos, " << worldAirspace.countCityTargetsAirport(airport)
        << " deles para cidades distintas e " << worldAirspace.countCountryTargetsAirport(airport) << " para paises distintos." << endl ;
        cout << endl;

        cout << "Deseja ver outro aeroporto? (S - Sim, N - Nao): ";
        cin >> airport;
        allUpper(airport);
        if (airport == "N") insert = true;
    }
    worldAirspace.disableAllAirports();
}

void Menu::routesByYFlightsMenu() {

    bool insert = false;
    string airport;
    int flightsNum;

    while (!insert){

        cout << "Insira o codigo do aeroporto: ";
        cin >> airport;
        allUpper(airport);

        cout << "Insira o numero de voos: ";
        cin >> flightsNum;

        cout << endl;
        cout << "Dos " << worldAirspace.countFlightsSourceAirport(airport) << " voos que partem de " << airport << " e com um numero maximo de " << flightsNum
             << " voos, " << worldAirspace.airportsReached(airport, flightsNum)
             << " deles partem para aeroportos distintos, " << worldAirspace.citiesReached(airport, flightsNum)
             << " deles para cidades distintas e " << worldAirspace.countriesReached(airport, flightsNum) << " para paises distintos." << endl ;
        cout << endl;


        cout << "Deseja ver outro aeroporto? (S - Sim, N - Nao): ";
        cin >> airport;
        allUpper(airport);
        if (airport == "N" ) insert = true;

    }
    worldAirspace.disableAllAirports();
}

void Menu::activateAirlineMenu() {
    bool insert = false;
    string airline;

    while (!insert) {

        cout << "Insira o codigo da companhia aerea:" << endl;
        cin >> airline;
        allUpper(airline);

        airlines.insert(airline);

        cout << "Deseja voar com outra companhia aerea? (S - Sim, N - Nao):" << endl;
        cin >> airline;
        allUpper(airline);
        if (airline == "N") insert = true;
    }

}