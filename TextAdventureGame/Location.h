#ifndef LOCATION_H
#define LOCATION_H

#include <string>

class Location {
private:
    std::string name;
    std::string description;

public:
    Location(const std::string& locationName, const std::string& locationDesc);

    std::string getName() const;
    std::string getDescription() const;
    void display() const;
};

#endif