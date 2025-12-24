#include "Item.h"

//Constructor
Item::Item(const std::string& itemName, const std::string& itemDesc)
    : name(itemName), description(itemDesc) {
    std::cout << "Item created: " << name << " at " << this << "\n";
}

//Destructor
Item::~Item() {
    std::cout << "Item destroyed: " << name << " at " << this << "\n";
}

//Getters
std::string Item::getName() const{ return name; }
std::string Item::getDescription() const { return description; }

//Display item info
void Item::display() const {
    std::cout << "  [" << name << "] - " << description << "\n";
}