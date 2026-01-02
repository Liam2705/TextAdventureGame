#include "WorldBuilder.h"
#include "Location.h"
#include <iostream>

//Creates the all locations within the game
std::vector<Location*> WorldBuilder::createAllLocations() {
    std::cout << "Building world locations...\n";

    std::vector<Location*> locations;

    //Create the main areas
    createDowntownDistrict(locations);
    createIndustrialSector(locations);
    createCorporatePlaza(locations);

    std::cout << "Created " << locations.size() << " locations.\n";

    return locations;
}

//Connect all locations with their exits
void WorldBuilder::connectLocations(std::vector<Location*>& locations) {
    std::cout << "Connecting locations...\n";

    //DOWNTOWN DISTRICT connections
    Location* neonStreet = locations[NEON_STREET];
    Location* ramenBar = locations[RAMEN_BAR];
    Location* blackMarket = locations[BLACK_MARKET];
    Location* apartment = locations[APARTMENT];
    Location* transitDowntown = locations[TRANSIT_DOWNTOWN];

    neonStreet->setNorthExit(ramenBar);
    neonStreet->setEastExit(blackMarket);
    neonStreet->setWestExit(apartment);

    ramenBar->setSouthExit(neonStreet);

    blackMarket->setWestExit(neonStreet);
    blackMarket->setNorthExit(transitDowntown);

    apartment->setEastExit(neonStreet);

    transitDowntown->setSouthExit(blackMarket);

    //INDUSTRIAL SECTOR connections
    Location* transitIndustrial = locations[TRANSIT_INDUSTRIAL];
    Location* factory = locations[FACTORY];
    Location* warehouse = locations[WAREHOUSE];

    transitIndustrial->setNorthExit(factory);
    transitIndustrial->setSouthExit(warehouse);

    factory->setSouthExit(transitIndustrial);
    factory->setWestExit(warehouse);

    warehouse->setNorthExit(transitIndustrial);
    warehouse->setEastExit(factory);

    //CORPORATE PLAZA connections
    Location* transitCorporate = locations[TRANSIT_CORPORATE];
    Location* plazaEntrance = locations[PLAZA_ENTRANCE];
    Location* lobby = locations[LOBBY];
    Location* serverRoom = locations[SERVER_ROOM];

    transitCorporate->setEastExit(plazaEntrance);
    plazaEntrance->setWestExit(transitCorporate);
    plazaEntrance->setNorthExit(lobby);

    lobby->setSouthExit(plazaEntrance);
    lobby->setNorthExit(serverRoom);

    serverRoom->setSouthExit(lobby);

    //TRANSIT CONNECTIONS (between areas)
    transitDowntown->setEastExit(transitIndustrial);
    transitDowntown->setNorthExit(transitCorporate);

    transitIndustrial->setWestExit(transitDowntown);

    transitCorporate->setSouthExit(transitDowntown);

    std::cout << "Locations connected.\n";
}

//Create Downtown District locations
void WorldBuilder::createDowntownDistrict(std::vector<Location*>& locations) {
    locations.push_back(new Location(
        "Neon Street",
        "The main street pulses with holographic advertisements.\n"
        "Rain reflects neon signs in endless colors. Street vendors\n"
        "hawk synthetic food from steaming carts.",
        "Downtown District"
    ));

    locations.push_back(new Location(
        "Ramen Bar",
        "A small establishment wedged between corporate towers.\n"
        "Steam rises from bowls of synthetic noodles. This is where\n"
        "runners meet their fixers.",
        "Downtown District"
    ));

    locations.push_back(new Location(
        "Black Market",
        "Holographic vendors flicker in the shadows. Everything here\n"
        "is untraceable, off the grid. Credits talk, questions don't.",
        "Downtown District"
    ));

    locations.push_back(new Location(
        "Your Apartment",
        "A cramped studio forty floors up. Your terminal hums quietly.\n"
        "Rain streaks down the window, blurring the neon outside.\n"
        "This is home, for what it's worth.",
        "Downtown District"
    ));

    locations.push_back(new Location(
        "Downtown Transit Station",
        "A grimy subway platform. Flickering lights illuminate transit\n"
        "maps. From here you can reach the Industrial Sector.",
        "Downtown District"
    ));
}

//Create Industrial Sector locations
void WorldBuilder::createIndustrialSector(std::vector<Location*>& locations) {
    locations.push_back(new Location(
        "Industrial Transit Station",
        "The platform reeks of oil and rust. This is the gateway to\n"
        "the Industrial Sector. You can return Downtown from here.",
        "Industrial Sector"
    ));

    locations.push_back(new Location(
        "Abandoned Factory",
        "Rusted machinery looms in the darkness. This factory has been\n"
        "abandoned for years. Vagrants and scavengers pick through the\n"
        "remains. Somewhere here is what you need.",
        "Industrial Sector"
    ));

    locations.push_back(new Location(
        "Corporate Warehouse",
        "Stacks of crates reach toward the ceiling. Corporate security\n"
        "patrols occasionally sweep through. The keycard you need is\n"
        "somewhere in here... if you can find it without being caught.",
        "Industrial Sector"
    ));
}

//Create Corporate Plaza locations
void WorldBuilder::createCorporatePlaza(std::vector<Location*>& locations) {
    locations.push_back(new Location(
        "Corporate Transit Terminal",
        "A pristine transit hub serving the Corporate Plaza. Everything\n"
        "here is chrome and glass. Security is everywhere.",
        "Corporate Plaza"
    ));

    locations.push_back(new Location(
        "Corporate Plaza Entrance",
        "Towering glass and steel reach into the smog. Corporate drones\n"
        "patrol silently. A security checkpoint blocks the main entrance.\n"
        "You'll need proper credentials to enter.",
        "Corporate Plaza"
    ));

    locations.push_back(new Location(
        "Corporate Lobby",
        "Polished marble floors reflect harsh fluorescent lights.\n"
        "Security drones hover near the ceiling. The elevator to the\n"
        "server room is ahead. You're in enemy territory now.",
        "Corporate Plaza"
    ));

    locations.push_back(new Location(
        "Server Room",
        "Banks of servers hum with data. Climate control keeps the\n"
        "room ice cold. The target data is here, behind layers of\n"
        "security. This is what you came for.",
        "Corporate Plaza"
    ));
}