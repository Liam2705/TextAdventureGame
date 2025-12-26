#include "Item.h"
#include "Player.h"
#include "Location.h"
#include <iostream>

//Constructor
Item::Item(const std::string& itemName, 
            const std::string& itemDesc, 
            ItemType itemType, 
            bool usable)
    : name(itemName), 
    description(itemDesc),
    type(itemType),
    isUsable(usable) {
    std::cout << "Item created: " << name << " at " << this << "\n";
}

//Destructor
Item::~Item() {
    std::cout << "Item destroyed: " << name << " at " << this << "\n";
}

//Getters
std::string Item::getName() const{ return name; }
std::string Item::getDescription() const { return description; }
ItemType Item::getType() const { return type; }
bool Item::getIsUsable() const { return isUsable; }


//Display item info
void Item::display() const {
    std::cout << "  [" << name << "] - " << description;

    //Shows the item type
    if (type == ItemType::CONSUMABLE) {
        std::cout << " (Consumable)";
    }
    else if (type == ItemType::TOOL) {
        std::cout << " (Tool)";
    }
    else if (type == ItemType::KEY_ITEM) {
        std::cout << " (Key Item)";
    }

    std::cout << "\n";
}

//Base use function - This is overided by derived classes
bool Item::use(Player* player, Location* location) {
    std::cout << "\nYou can't use this item.\n";
    return false;
}