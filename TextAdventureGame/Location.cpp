#include "location.h"
#include <iostream>

Location::Location(const std::string& locationName, const std::string& locationDesc)
	: name(locationName), 
	description(locationDesc),
	northExit(nullptr),
	southExit(nullptr),
	eastExit(nullptr),
	westExit(nullptr) {

	//Testing purposes
	std::cout << "Location created: " << name << std::endl;
}

//Getters
std::string Location::getName() const{
	return name;
}

std::string Location::getDescription() const {
	return description;
}

Location* Location::getNorthExit() const {
    return northExit;
}

Location* Location::getSouthExit() const {
    return southExit;
}

Location* Location::getEastExit() const {
    return eastExit;
}

Location* Location::getWestExit() const {
    return westExit;
}

//Setters
void Location::setNorthExit(Location* location) {
    northExit = location;
}

void Location::setSouthExit(Location* location) {
    southExit = location;
}

void Location::setEastExit(Location* location) {
    eastExit = location;
}

void Location::setWestExit(Location* location) {
    westExit = location;
}

//Displays true/false depending on whether a location has an exit
bool Location::hasNorthExit() const {
    return northExit != nullptr;
}

bool Location::hasSouthExit() const {
    return southExit != nullptr;
}

bool Location::hasEastExit() const {
    return eastExit != nullptr;
}

bool Location::hasWestExit() const {
    return westExit != nullptr;
}

//Display Information about a location
void Location::display() const {
    std::cout << "\n==================================================\n";
    std::cout << "  " << name << "\n";
    std::cout << "==================================================\n";
    std::cout << description << "\n\n";

    // Show which exits are available based on the pointer
    std::cout << "Exits: ";
    bool hasAnyExit = false;

    if (northExit != nullptr) {
        std::cout << "[NORTH] ";
        hasAnyExit = true;
    }
    if (southExit != nullptr) {
        std::cout << "[SOUTH] ";
        hasAnyExit = true;
    }
    if (eastExit != nullptr) {
        std::cout << "[EAST] ";
        hasAnyExit = true;
    }
    if (westExit != nullptr) {
        std::cout << "[WEST] ";
        hasAnyExit = true;
    }

    if (!hasAnyExit) {
        std::cout << "None (dead end)";
    }

    std::cout << "\n==================================================\n";
}