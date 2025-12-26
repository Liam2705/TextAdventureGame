#ifndef PLAYER_H

#include <string>

//Forward declarations
class Location;
class Item;

class Player {
private:
    std::string name;

    int health;
    int maxHealth;

    Item** inventory;       
    int inventoryCount;     
    int inventoryCapacity;  

    Location* currentLocation;  

    //Helper functions for inventory management
    void resizeInventory();
    void removeFromInventoryArray(int index); 

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
    bool dropItem(int inventoryIndex);       //Drop item to location
    Item* getInventoryItem(int index) const; //Get item from inventory

    //Display
    void look() const;              //Show the current location
    void showInventory() const;     //Show what the player is carrying
    void showStatus() const;        //Show player info
};

#endif 

