#ifndef LOCATION_H
#define LOCATION_H

#include <string>

class Location {
private:
    std::string name;
    std::string description;

    //Pointer Based Navigation System
    Location* northExit;
    Location* southExit;
    Location* eastExit;
    Location* westExit;

public:
    Location(const std::string& locationName, const std::string& locationDesc);

    //Getters
    std::string getName() const;
    std::string getDescription() const;

    Location* getNorthExit() const;
    Location* getSouthExit() const;
    Location* getEastExit() const;
    Location* getWestExit() const;

    void display() const;

    //Responsible for setting where the exit points to
    void setNorthExit(Location* location);
    void setSouthExit(Location* location);
    void setEastExit(Location* location);
    void setWestExit(Location* location);

    //Functions to check if exits exist
    bool hasNorthExit() const;
    bool hasSouthExit() const;
    bool hasEastExit() const;
    bool hasWestExit() const;
};

#endif