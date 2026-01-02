#include "Player.h"
#include "Location.h"
#include "Item.h"
#include "TextEffects.h"
#include <iostream>

const int INITIAL_INVENTORY_CAPACITY = 10;
const int STARTING_HEALTH = 100;
const int INDUSTRIAL_DAMAGE = 10;

//Constructor
Player::Player(const std::string & playerName, Location * startingLocation)
    : name(playerName),
    health(STARTING_HEALTH),
    maxHealth(STARTING_HEALTH),
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

int Player::getHealth() const { return health; }
int Player::getMaxHealth() const { return maxHealth; }

bool Player::isDead() const { return health <= 0; }

//Movement
bool Player::moveNorth() {
    if (currentLocation->hasNorthExit())
    {
        Location* nextLocation = currentLocation->getNorthExit();

        //Story Gates
        if (!checkLocationAccess(nextLocation)) {
            return false;
        }
        
        currentLocation = nextLocation;
        std::cout << "You move north.\n";
        if (currentLocation->getAreaName() == "Industrial Sector") {
            takeDamage(INDUSTRIAL_DAMAGE);
        }
        return true;
    }
    std::cout << "You can't go that way.\n";
    return false;
}

bool Player::moveSouth() {
    if (currentLocation->hasSouthExit()) {

        Location* nextLocation = currentLocation->getSouthExit();

        if (!checkLocationAccess(nextLocation)) {
            return false;
        }

        currentLocation = nextLocation;
        std::cout << "You move south.\n";
        if (currentLocation->getAreaName() == "Industrial Sector") {
            takeDamage(INDUSTRIAL_DAMAGE);
        }
        return true;
    }
    std::cout << "You can't go that way.\n";
    return false;
}

bool Player::moveEast() {
    if (currentLocation->hasEastExit()) {

        Location* nextLocation = currentLocation->getEastExit();

        if (!checkLocationAccess(nextLocation)) {
            return false;
        }

        currentLocation = nextLocation;
        std::cout << "You move east.\n";
        if (currentLocation->getAreaName() == "Industrial Sector") {
            takeDamage(INDUSTRIAL_DAMAGE);
        }
        return true;
    }
    std::cout << "You can't go that way.\n";
    return false;
}

bool Player::moveWest() {
    if (currentLocation->hasWestExit()) {

        Location* nextLocation = currentLocation->getWestExit();

        if (!checkLocationAccess(nextLocation)) {
            return false;
        }

        currentLocation = nextLocation;
        std::cout << "You move west.\n";
        if (currentLocation->getAreaName() == "Industrial Sector") {
            takeDamage(INDUSTRIAL_DAMAGE);
        }
        return true;
    }
    std::cout << "You can't go that way.\n";
    return false;
}

//Health Management
void Player::takeDamage(int damageAmount) {
    if (damageAmount <= 0) return;

    health -= damageAmount;

    if (health < 0) {
        health = 0;
    }

    std::cout << "\nYou take " << damageAmount << " damage! ";
    std::cout << "(Health: " << health << "/" << maxHealth << ")\n";

    if (isDead()) {
        std::cout << "\nYOU HAVE DIED\n";
        std::cout << "Your vision fades to black...\n";
        std::cout << "\nGAME OVER\n";
    }
    else if (health <= 20) {
        std::cout << "WARNING: Critical health! Find healing immediately!\n";
    }
    else if (health <= 50) {
        std::cout << "Your health is low.\n";
    }
}

void Player::heal(int healAmount) {
    if (healAmount <= 0) return;

    int oldHealth = health;
    health += healAmount;

    if (health > maxHealth) {
        health = maxHealth;
    }

    int actualHealed = health - oldHealth;

    std::cout << "\nHealed " << actualHealed << " health! ";
    std::cout << "(Health: " << health << "/" << maxHealth << ")\n";
}

void Player::setMaxHealth(int newMaxHealth) {
    if (newMaxHealth > 0) {
        maxHealth = newMaxHealth;

        //Heal to new max if current health exceeds it
        if (health > maxHealth) {
            health = maxHealth;
        }

        std::cout << "\nMax health increased to " << maxHealth << "!\n";
    }
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
    std::cout << "========================================\n";

    std::cout << "Health: " << health << "/" << maxHealth;

    if (health <= 20) {
        std::cout << " CRITICAL";
    }
    else if (health <= 50) {
        std::cout << " LOW";
    }
    else if (health >= maxHealth) {
        std::cout << " FULL";
    }

    std::cout << "\nItems carried: " << inventoryCount << "/" << inventoryCapacity << "\n";
    std::cout << "========================================\n";
}

//Use an item from inventory
bool Player::useItem(int inventoryIndex) {
    if (inventoryIndex < 0 || inventoryIndex >= inventoryCount) {
        std::cout << "\nInvalid inventory slot.\n";
        return false;
    }

    Item* item = inventory[inventoryIndex];

    if (item == nullptr) {
        std::cout << "\nNo item in that slot.\n";
        return false;
    }

    //Check if item is usable
    if (!item->getIsUsable()) {
        std::cout << "\nYou can't use that item.\n";
        return false;
    }

    //Try to use the item
    bool consumed = item->use(this, currentLocation);

    //If item was consumed (like a stimpack), remove it
    if (consumed) {
        std::cout << item->getName() << " was consumed.\n";
        delete item;  // Free the item's memory
        removeFromInventoryArray(inventoryIndex);
    }

    return true;
}

//Check if the player has a specific item
bool Player::hasItem(const std::string& itemName) const {
    for (int i = 0; i < inventoryCount; i++) {
        if (inventory[i]->getName() == itemName) {
            return true;
        }
    }
    return false;
}

// Check if player can access a location (story gates)
bool Player::checkLocationAccess(Location* location) {
    if (location == nullptr) {
        return false;
    }

    std::string locationName = location->getName();

    // GATE 1: Corporate Plaza Entrance requires keycard
    if (locationName == "Corporate Plaza Entrance") {
        if (!hasItem("Security Keycard")) {
            std::cout << "\n================================================\n";
            std::cout << "            ACCESS DENIED                        \n";
            std::cout << "================================================\n";
            std::cout << "\nA security checkpoint blocks the entrance to the\n";
            std::cout << "Corporate Plaza. Armed guards watch the barriers.\n";
            std::cout << "Red light flashes on the scanner.\n\n";
            std::cout << "You need a SECURITY KEYCARD to enter.\n";
            std::cout << "\nHint: Check the Corporate Warehouse in the\n";
            std::cout << "   Industrial Sector.\n";
            std::cout << "================================================\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            TextEffects::waitForEnter();
            return false;
        }

        //Player has keycard - show success
        TextEffects::clearScreen();

        std::cout << "\n================================================\n";
        std::cout << "         SECURITY CHECKPOINT                     \n";
        std::cout << "================================================\n\n";

        TextEffects::typewriter("You approach the checkpoint.", TextSpeed::NORMAL);
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
        std::cout << "\n";

        TextEffects::typewriter("Guards in black tactical gear watch your every move.", TextSpeed::NORMAL);
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
        std::cout << "\n\n";

        TextEffects::typewriter("You produce the security keycard from your jacket...", TextSpeed::NORMAL);
        std::this_thread::sleep_for(std::chrono::milliseconds(600));
        std::cout << "\n\n";

        std::cout << "[SCANNING...]\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(800));

        std::cout << "\n";
        TextEffects::typewriter("BEEP. Green light.", TextSpeed::FAST);
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
        std::cout << "\n\n";

        TextEffects::typewriter("'Access granted. Welcome, Executive.'", TextSpeed::NORMAL);
        std::cout << "\n\n";

        TextEffects::typewriter("The reinforced barriers retract with a pneumatic hiss.", TextSpeed::NORMAL);
        std::cout << "\n";
        TextEffects::typewriter("The guards step aside. You're in.", TextSpeed::NORMAL);

        std::cout << "\n\n================================================\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(600));
    }

    //GATE 2: Server Room requires hacking device
    if (locationName == "Server Room") {
        if (!hasItem("Military ICE Breaker")) {
            std::cout << "\n================================================\n";
            std::cout << "           ENCRYPTION DETECTED                  \n";
            std::cout << "================================================\n";
            std::cout << "\nThe server room doors are locked behind layers of\n";
            std::cout << "military-grade encryption. Your basic tools won't\n";
            std::cout << "cut it. You need something more powerful.\n\n";
            std::cout << "You need a MILITARY ICE BREAKER to hack through.\n";
            std::cout << "\nHint: Check the Abandoned Factory in the\n";
            std::cout << "   Industrial Sector.\n";
            std::cout << "================================================\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            TextEffects::waitForEnter();
            return false;
        }

        //Player has hacking device - show success
        TextEffects::clearScreen();

        std::cout << "\n================================================\n";
        std::cout << "         SECURITY ENCRYPTION DETECTED            \n";
        std::cout << "================================================\n\n";

        TextEffects::typewriter("The server room entrance: a reinforced door with", TextSpeed::NORMAL);
        std::cout << "\n";
        TextEffects::typewriter("a glowing keypad. Military-grade encryption.", TextSpeed::NORMAL);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << "\n\n";

        TextEffects::typewriter("You pull out the Military ICE Breaker.", TextSpeed::NORMAL);
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
        std::cout << "\n";
        TextEffects::typewriter("Time to see if this hardware is worth the hype.", TextSpeed::NORMAL);
        std::this_thread::sleep_for(std::chrono::milliseconds(600));
        std::cout << "\n\n";

        std::cout << "[INITIATING INTRUSION COUNTERMEASURE ELECTRONICS]\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(600));

        std::cout << "[ANALYZING ENCRYPTION...]\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(800));

        std::cout << "[BYPASS ALGORITHMS DEPLOYED]\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(700));

        std::cout << "\n";
        TextEffects::typewriter("Code cascades across your display.", TextSpeed::FAST);
        std::cout << "\n";
        TextEffects::typewriter("Firewalls crumble. Encryption layers peel away.", TextSpeed::FAST);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << "\n\n";

        std::cout << "[ACCESS GRANTED]\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
        std::cout << "\n";

        TextEffects::typewriter("The door slides open with a hiss.", TextSpeed::NORMAL);
        std::cout << "\n";
        TextEffects::typewriter("Cold air rushes out. You're in.", TextSpeed::SLOW);

        std::cout << "\n\n================================================\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(600));
    }

    // Access granted
    return true;
}