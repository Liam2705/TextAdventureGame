#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

//Forward declarations
class Location;
class Item;

class Player {
private:
    std::string name;

    int health;
    int maxHealth;

    std::vector<Item*> inventory;

    Location* currentLocation;  


    bool checkLocationAccess(Location* location);

public:
    //Constructor
    Player(const std::string& playerName, Location* startingLocation);

    //Destructor
    ~Player();

    //Getters
    std::string getName() const;
    Location* getCurrentLocation() const;

    int getInventoryCount() const;
    int getInventoryCapacity() const;

    int getHealth() const;
    int getMaxHealth() const;
    bool isDead() const;

    //Health management
    void takeDamage(int damageAmount);
    void heal(int healAmount);
    void setMaxHealth(int newMaxHealth);

    //Movement
    bool moveNorth();
    bool moveSouth();
    bool moveEast();
    bool moveWest();

    //Item Management
    bool pickUpItem(int locationItemIndex);  //Take item from location
    bool useItem(int invetoryIndex);         //Uses a compatible item
    bool dropItem(int inventoryIndex);       //Drop item to location
    Item* getInventoryItem(int index) const; //Get item from inventory
    bool hasItem(const std::string& itemName) const;  //Check if the player has an item

    //Display
    void look() const;              //Show the current location
    void showInventory() const;     //Show what the player is carrying
    void showStatus() const;        //Show player info
};

#endif 

