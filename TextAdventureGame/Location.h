#ifndef LOCATION_H
#define LOCATION_H

#include <string>

//Forward Declarations
class Item;
class NPC;

class Location {
private:
    std::string name;
    std::string description;
    
    //Area - each area has multiple sub-locations
    std::string areaName;

    //Pointer Based Navigation System
    Location* northExit;
    Location* southExit;
    Location* eastExit;
    Location* westExit;    

    //Dynamic Array for Items
    Item** items;  //Pointer to the array of item pointers
    int itemCount; //Number of Items in the array
    int itemCapacity; //Capacity of the array

    //Dynamic array for NPCs
    NPC** npcs;
    int npcCount;
    int npcCapacity;

    //Helper function to resize array
    void resizeItemArray();
    void removeFromItemArray(int index);
    void resizeNPCArray();
    void removeFromNPCArray(int index);

public:
    //Constructor
    Location(const std::string& locationName, const std::string& locationDesc, const std::string& area);

    //Destructor
    ~Location();

    //Getters
    std::string getName() const;
    std::string getDescription() const;
    int getItemCount() const;
    int getNPCCount() const;

    std::string getAreaName() const;

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

    //NPC management
    void addNPC(NPC* npc);
    NPC* removeNPC(int index);
    NPC* getNPC(int index) const;
    void listNPCs() const;
};

#endif