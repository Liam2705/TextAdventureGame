#ifndef LOCATION_H
#define LOCATION_H

#include <string>

class Item;

class Location {
private:
    std::string name;
    std::string description;

    //Pointer Based Navigation System
    Location* northExit;
    Location* southExit;
    Location* eastExit;
    Location* westExit;

    //Dynamic Array for Items
    Item** items;  //Pointer to the array of item pointers
    int itemCount; //Number of Items in the array
    int itemCapacity; //Capacity of the array

    //Helper function to resize array
    void resizeItemArray();
    void removeFromItemArray(int index);

public:
    Location(const std::string& locationName, const std::string& locationDesc);

    //Destructor
    ~Location();

    //Getters
    std::string getName() const;
    std::string getDescription() const;
    int getItemCount() const;

    Location* getNorthExit() const;
    Location* getSouthExit() const;
    Location* getEastExit() const;
    Location* getWestExit() const;

    //Display info about a location
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

    //Item Management
    void addItem(Item* item);
    Item* removeItem(int index);
    Item* getItem(int index) const;
    void listItems() const;
};

#endif