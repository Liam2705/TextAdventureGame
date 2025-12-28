#include "Keycard.h"
#include "Player.h"
#include "Location.h"
#include <iostream>

//Constructor
Keycard::Keycard(const std::string& itemName,
    const std::string& itemDesc)
    : Item(itemName, itemDesc, ItemType::KEY_ITEM, true) {
}

//Uses the keycard
bool Keycard::use(Player* player, Location* location) {
    if (player == nullptr || location == nullptr) {
        return false;
    }

    std::string locationName = location->getName();

    //Keycard works at Corporate Plaza Entrance
    if (locationName == "Corporate Plaza Entrance") {
        std::cout << "\nYou swipe the security keycard at the checkpoint.\n";
        std::cout << "The scanner beeps. Green light. Access granted.\n";
        std::cout << "The security barrier retracts. You're in.\n";
        return false;  //Key items aren't consumed
    }

    //Also works at Corporate Transit Terminal
    if (locationName == "Corporate Transit Terminal") {
        std::cout << "\nYou flash the keycard at the terminal security.\n";
        std::cout << "They wave you through without question.\n";
        return false;
    }

    std::cout << "\nThe keycard doesn't work here.\n";
    return false;  //Not consumed
}