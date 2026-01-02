#ifndef WORLDBUILDER_H
#define WORLDBUILDER_H

#include <vector>

//Forward declarations
class Location;

//Responsible for creating and connecting all game locations
class WorldBuilder {
public:
    //Creates all locations and returns them in a vector
    static std::vector<Location*> createAllLocations();

    //Connects locations with their exits (north, south, east, west)
    static void connectLocations(std::vector<Location*>& locations);

private:
    //Helper functions for creating specific areas
    static void createDowntownDistrict(std::vector<Location*>& locations);
    static void createIndustrialSector(std::vector<Location*>& locations);
    static void createCorporatePlaza(std::vector<Location*>& locations);

    //Indices for location access
    enum LocationIndex {
        NEON_STREET = 0,
        RAMEN_BAR,
        BLACK_MARKET,
        APARTMENT,
        TRANSIT_DOWNTOWN,
        TRANSIT_INDUSTRIAL,
        FACTORY,
        WAREHOUSE,
        TRANSIT_CORPORATE,
        PLAZA_ENTRANCE,
        LOBBY,
        SERVER_ROOM
    };
};

#endif
