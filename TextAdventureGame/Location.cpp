#include "location.h"
#include <iostream>

Location::Location(const std::string& locationName, const std::string& locationDesc)
	: name(locationName), description(locationDesc) {

	//Testing purposes
	std::cout << "Location created: " << name << std::endl;
}

std::string Location::getName() const{
	return name;
}

std::string Location::getDescription() const {
	return description;
}

void Location::display() const{
	std::cout << "\n==================================================\n";
	std::cout << "  " << name << "\n";
	std::cout << "==================================================\n";
	std::cout << description << "\n";
	std::cout << "==================================================\n";
}
