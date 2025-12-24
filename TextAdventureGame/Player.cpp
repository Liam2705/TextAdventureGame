#include "Player.h"
#include "Location.h"
#include "Item.h"
#include <iostream>

const int INITIAL_INVENTORY_CAPACITY = 10;

//Constructor
Player::Player(const std::string& playerName, Location* startingLocation)
    : name(playerName),
    inventoryCount(0),
    inventoryCapacity(INITIAL_INVENTORY_CAPACITY),
    currentLocation(startingLocation) {

    //Allocate inventory array
    inventory = new Item * [inventoryCapacity];

    //Initialise items to nullptr
    for (int i = 0; i < inventoryCapacity; i++) {
        inventory[i] = nullptr;
    }

    std::cout << "Player CREATED: " << name
        << " (inventory capacity: " << inventoryCapacity << ")\n";
}

//Destructor
Player::~Player() {
    std::cout << "Player DESTROYED: " << name << "\n";

    //Delete the array of pointers (doesn't include the items)
    delete[] inventory;
}

//Remove from Inventory (helper function)
void Player::removeFromInventoryArray(int index) {
    //Bounds check
    if (index < 0 || index >= inventoryCount) {
        return;
    }

    //Shift remaining items down to fill the gap
    for (int i = index; i < inventoryCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }

    //Clear the last slot and decrease the count
    inventory[inventoryCount - 1] = nullptr;
    inventoryCount--;
}

//Resize Inventory
void Player::resizeInventory() {
    std::cout << "Resizing inventory from " << inventoryCapacity;

    int newCapacity = inventoryCapacity * 2;
    std::cout << " to " << newCapacity << "\n";

    Item** newInventory = new Item * [newCapacity];

    //Copy existing pointers
    for (int i = 0; i < inventoryCount; i++) {
        newInventory[i] = inventory[i];
    }

    //Initialise new slots as null pointers
    for (int i = inventoryCount; i < newCapacity; i++) {
        newInventory[i] = nullptr;
    }

    //Delete old array and update
    delete[] inventory;
    inventory = newInventory;
    inventoryCapacity = newCapacity;
}

//Getters
std::string Player::getName() const { return name; }
Location* Player::getCurrentLocation() const { return currentLocation; }
int Player::getInventoryCount() const { return inventoryCount; }
int Player::getInventoryCapacity() const { return inventoryCapacity; }

//Movement
bool Player::moveNorth() {
    if (currentLocation->hasNorthExit())
    {
        currentLocation = currentLocation->getNorthExit();
        std::cout << "You move north.\n";
        return true;
    }
    std::cout << "You can't go that way.\n";
    return false;
}

bool Player::moveSouth() {
    if (currentLocation->hasSouthExit()) {
        currentLocation = currentLocation->getSouthExit();
        std::cout << "You move south.\n";
        return true;
    }
    std::cout << "You can't go that way.\n";
    return false;
}

bool Player::moveEast() {
    if (currentLocation->hasEastExit()) {
        currentLocation = currentLocation->getEastExit();
        std::cout << "You move east.\n";
        return true;
    }
    std::cout << "You can't go that way.\n";
    return false;
}

bool Player::moveWest() {
    if (currentLocation->hasWestExit()) {
        currentLocation = currentLocation->getWestExit();
        std::cout << "You move west.\n";
        return true;
    }
    std::cout << "You can't go that way.\n";
    return false;
}

//Item mangement
bool Player::pickUpItem(int locationItemIndex) {
    
    if (currentLocation->getItemCount() == 0)
    {
        std::cout << "There are no items here.\n";
        return false;
    }

    //Bounds check
    if (locationItemIndex < 0 || locationItemIndex >= currentLocation->getItemCount())
    {
        std::cout << "Invalid item number.\n";
        return false;
    }

    //Resizing inventory if full (temp feature)
    if (inventoryCount >= inventoryCapacity)
    {
        resizeInventory();
    }

    //Removing the item from the location and returns a pointer to that item
    Item* item = currentLocation->removeItem(locationItemIndex);

    if (item == nullptr)
    {
        std::cout << "Failed to pickup item.\n";
        return false;
    }

    //Add to player inventory
    inventory[inventoryCount] = item;
    inventoryCount++;

    std::cout << "You picked up " << item->getName() << "\n";
    return true;
}

bool Player::dropItem(int inventoryIndex) {

    if (inventoryCount == 0)
    {
        std::cout << "Your inventory is empty.\n";
        return false;
    }

    //Bounds check
    if (inventoryIndex < 0 || inventoryIndex >= inventoryCapacity)
    {
        std::cout << "Invalid inventory slot.\n";
        return false;
    }

    //Get item from inventory
    Item* item = inventory[inventoryIndex];

    if (item == nullptr) {
        std::cout << "No item in that slot.\n";
        return false;
    }

    //Remove from inventory
    removeFromInventoryArray(inventoryIndex);
    //Add to current location
    currentLocation->addItem(item);

    std::cout << "You dropped: " << item->getName() << "\n";
    return true;
}

//Access an item without removing or modifying it
Item* Player::getInventoryItem(int index) const {
    if (index < 0 || index >= inventoryCount) {
        return nullptr;
    }
    return inventory[index];
}

//Displays the current location
void Player::look() const {
    currentLocation->display();
}

//Displays the players inventory
void Player::showInventory() const {
    std::cout << "\n========================================\n";
    std::cout << "  INVENTORY\n";
    std::cout << "========================================\n";

    if (inventoryCount == 0) {
        std::cout << "You aren't carrying anything.\n";
    }
    else {
        std::cout << "You are carrying:\n";
        for (int i = 0; i < inventoryCount; i++) {
            std::cout << "  [" << i << "] ";
            inventory[i]->display();
        }
    }

    std::cout << "\nCapacity: " << inventoryCount << "/" << inventoryCapacity << "\n";
    std::cout << "========================================\n";
}

//Displays the players current information
void Player::showStatus() const {
    std::cout << "\n========================================\n";
    std::cout << "  PLAYER STATUS\n";
    std::cout << "========================================\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Location: " << currentLocation->getName() << "\n";
    std::cout << "Items carried: " << inventoryCount << "/" << inventoryCapacity << "\n";
    std::cout << "========================================\n";
}