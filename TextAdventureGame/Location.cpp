#include "location.h"
#include "Item.h"
#include "NPC.h"
#include <iostream>

//Starting capacity item array
const int INITIAL_CAPACITY = 4;

Location::Location(const std::string& locationName, const std::string& locationDesc, const std::string& area)
	: name(locationName), 
	description(locationDesc),
    areaName(area),
	northExit(nullptr),
	southExit(nullptr),
	eastExit(nullptr),
	westExit(nullptr),
    itemCount(0),
    itemCapacity(INITIAL_CAPACITY),
    npcCount(0),
    npcCapacity(INITIAL_CAPACITY) {

    //Allocating array of item pointers
    items = new Item * [itemCapacity];

    //Initialising all pointers to nullptr
    for (int i = 0; i < itemCapacity; i++)
    {
        items[i] = nullptr;
    }

    //Allocating array of NPC pointers
    npcs = new NPC * [npcCapacity];

    //Initialising all pointers to nullptr
    for (int i = 0; i < npcCapacity; i++) {
        npcs[i] = nullptr;
    }

	//Testing purposes
	std::cout << "Location created: " << name 
                << " (item capacity: " << itemCapacity << ")\n";
}

//Destructor
Location::~Location() {
    //Temporary message
    std::cout << "Location deleted: " << name << "\n";
    delete[] items;
}

//Removes item from Item array (helper function)
void Location::removeFromItemArray(int index) {
    // Validate index
    if (index < 0 || index >= itemCount) {
        return;
    }

    // Shift remaining items down
    for (int i = index; i < itemCount - 1; i++) {
        items[i] = items[i + 1];
    }

    // Clear last slot and decrease count
    items[itemCount - 1] = nullptr;
    itemCount--;
}


//Resizes the item array when it becomes full
void Location::resizeItemArray() {
    std::cout << "Resizing item array from " << itemCapacity;

    int newCapacity = itemCapacity * 2;
    std::cout << " to " << newCapacity << "\n";

    Item** newArray = new Item * [newCapacity];

    //Copy existing pointers to new array
    for (int i = 0; i < itemCount; i++) {
        newArray[i] = items[i];
    }

    //Initialize new slots to nullptr
    for (int i = itemCount; i < newCapacity; i++) {
        newArray[i] = nullptr;
    }

    //Delete the old array
    delete[] items;

    //Point to the new array
    items = newArray;
    itemCapacity = newCapacity;
}

//Resizes NPC array when full
void Location::resizeNPCArray() {
    int newCapacity = npcCapacity * 2;
    NPC** newArray = new NPC * [newCapacity];

    for (int i = 0; i < npcCount; i++) {
        newArray[i] = npcs[i];
    }

    for (int i = npcCount; i < newCapacity; i++) {
        newArray[i] = nullptr;
    }

    delete[] npcs;
    npcs = newArray;
    npcCapacity = newCapacity;
}

//Removes an NPC from the array
void Location::removeFromNPCArray(int index) {
    if (index < 0 || index >= npcCount) {
        return;
    }

    for (int i = index; i < npcCount - 1; i++) {
        npcs[i] = npcs[i + 1];
    }

    npcs[npcCount - 1] = nullptr;
    npcCount--;
}


//Getters
std::string Location::getName() const{ return name; }
std::string Location::getDescription() const { return description; }

std::string Location::getAreaName() const { return areaName; }

int Location::getItemCount() const { return itemCount; }
int Location::getNPCCount() const { return npcCount; }

Location* Location::getNorthExit() const { return northExit; }
Location* Location::getSouthExit() const { return southExit; }
Location* Location::getEastExit() const { return eastExit; }
Location* Location::getWestExit() const { return westExit; }


//Setters
void Location::setNorthExit(Location* location) { northExit = location; }
void Location::setSouthExit(Location* location) { southExit = location; }
void Location::setEastExit(Location* location) { eastExit = location; }
void Location::setWestExit(Location* location) { westExit = location; }


//Displays true/false depending on whether a location has an exit
bool Location::hasNorthExit() const { return northExit != nullptr; }
bool Location::hasSouthExit() const { return southExit != nullptr; }
bool Location::hasEastExit() const { return eastExit != nullptr; }
bool Location::hasWestExit() const { return westExit != nullptr; }

/* 
    Adds an item pointer to the array.
    Resizes if the array is full.
*/
void Location::addItem(Item* item) {
    if (item == nullptr) {
        std::cout << "[WARNING] Tried to add nullptr item!\n";
        return;
    }

    //Resize if array is full
    if (itemCount >= itemCapacity) {
        resizeItemArray();
    }

    //Add item to array
    items[itemCount] = item;
    itemCount++;

    std::cout << "Added " << item->getName() << " to " << name << "\n";
}

/*
    Removes item at given index and returns pointer to it
    Shifts remaining items down to fill gap
 */
Item* Location::removeItem(int index) {
    //Bounds check
    if (index < 0 || index >= itemCount) {
        std::cout << "[WARNING] Invalid item index: " << index << "\n";
        return nullptr;
    }

    Item* removedItem = items[index];

    //Remove from array using helper function
    removeFromItemArray(index);

    std::cout << "Removed " << removedItem->getName()
        << " from " << name << "\n";

    return removedItem;
}

//Returns the pointer to an item without modifying it
Item* Location::getItem(int index) const {
    if (index < 0 || index >= itemCount) {
        return nullptr;
    }
    return items[index];
}


//Display all items in this location
void Location::listItems() const {
    if (itemCount == 0) {
        std::cout << "  (no items)\n";
        return;
    }

    for (int i = 0; i < itemCount; i++) {
        std::cout << "  [" << i << "] ";
        items[i]->display();
    }
}

//Display Information about a location
void Location::display() const {
    std::cout << "\n==================================================\n";
    std::cout << " [" << areaName << "] " << name << "\n";
    std::cout << "==================================================\n";
    std::cout << description << "\n\n";

    //Show items
    if (itemCount > 0) {
        std::cout << "Items here:\n";
        listItems();
        
    }

    //Show NPCs
    if (npcCount > 0) {
        std::cout << "People here:\n";
        listNPCs();
        std::cout << "\n";
    }

    //Show which exits are available based on the pointer
    std::cout << "\nExits: \n";
    bool hasAnyExit = false;
    if (northExit != nullptr) { std::cout << "[NORTH] " << northExit->getName() << "\n"; hasAnyExit = true; }
    if (southExit != nullptr) { std::cout << "[SOUTH] " << southExit->getName() << "\n"; hasAnyExit = true; }
    if (eastExit != nullptr) { std::cout << "[EAST] " << eastExit->getName() << "\n"; hasAnyExit = true; }
    if (westExit != nullptr) { std::cout << "[WEST] " << westExit->getName() << "\n"; hasAnyExit = true; }
    if (!hasAnyExit) { std::cout << "None"; }

    std::cout << "\n==================================================\n";
}

//Adds NPC to a location
void Location::addNPC(NPC* npc) {
    if (npc == nullptr) {
        return;
    }

    if (npcCount >= npcCapacity) {
        resizeNPCArray();
    }

    npcs[npcCount] = npc;
    npcCount++;
}

//Removes and return NPC
NPC* Location::removeNPC(int index) {
    if (index < 0 || index >= npcCount) {
        return nullptr;
    }

    NPC* removedNPC = npcs[index];
    removeFromNPCArray(index);

    return removedNPC;
}

//Gets NPC without removing
NPC* Location::getNPC(int index) const {
    if (index < 0 || index >= npcCount) {
        return nullptr;
    }
    return npcs[index];
}

//Lists all NPCs
void Location::listNPCs() const {
    if (npcCount == 0) {
        std::cout << "  (no one here)\n";
        return;
    }

    for (int i = 0; i < npcCount; i++) {
        std::cout << "  [" << i << "] ";
        npcs[i]->display();
    }
}

