#ifndef PROJETO2_MENU_H
#define PROJETO2_MENU_H

#include <iostream>
#include <stack>
#include "WorldAirspace.h"

#define MAIN_MENU 0
#define SEARCH_MENU 1
#define SEARCH_DEFINITIONS_MENU 2
#define INFO_AIRPORT_MENU 3
#define COORDINATE_MENU 4
#define AIRPORT_MENU 5
#define CITY_MENU 6
#define COUNTRY_MENU 7


using namespace std;

class Menu {
public:

    /**
     * Constructor for the menu class
     * */
    Menu();

private:

    /**
     * @var option - user main menu option
     */
    int option;

    /**
     * @var optionAirport - user airport option
     */
    string optionAirport;

    /**
     * @var menuState - stack used to navigate through the menu
     * */
    stack<short  int> menuState;

    /**
     * @var airlines - set used to keep usable airlines
     * */
    set<string> airlines;

    /**
     * @var worldAirspace - a WorldAirspace object containing the main graph and all methods to manipulate data
     */
    WorldAirspace worldAirspace;

    /**
     * Function that calls the top of the menuState stack
     */
    void getMenu();

    /**
     * Main menu that allows the user to choose between the search menu, airport menu or leave the program
     * */
    void mainMenu();

    /**
     * Menu that allows user to choose search definitions
     */
    void searchDefinitionsMenu();

    /**
     * Menu that allows the user to choose the type of search
     * */
    void searchMenu();

    /**
     * Menu that allows the user to choose between the search menu, airport menu or leave the program
     * */
    void infoAirportMenu();

    /**
     * Menu that allows user to choose airport's coordinates he would like to check
     */
    void coordMenu();

    /**
     * Menu that allows user to choose the airport's codes he would like to check
     */
    void airportMenu();

    /**
     * Menu that allows user to choose the cities he would like to check
     */
    void cityMenu();

    /**
     * Menu that allows user to choose the countries he would like to check
     */
    void countryMenu();

    /**
     * Menu that allows user to choose the airport's code he would like to check
     */
    void flightsMenu();

    /**
     * Menu that allows user to choose the airport's code he would like to check
     */
     void airlineMenu();

    /**
     * Menu that allows user to choose the airport's code he would like to check
     */
    void airportsMenu();

    /**
     * Menu that allows user to choose the airport's code he would like to check and number of flights
     */
    void routesByYFlightsMenu();

    /**
     * Menu that allows user to activate a airline for search
     */
    void activateAirlineMenu();
};


#endif
