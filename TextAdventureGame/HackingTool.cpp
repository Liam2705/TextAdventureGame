#include "HackingTool.h"
#include "Player.h"
#include "Location.h"
#include <iostream>

//Constructor
HackingTool::HackingTool(const std::string itemName,
						const std::string itemDesc)
	:Item(itemName, itemDesc, ItemType::TOOL, true) {


}

//Uses the hacking tool

bool HackingTool::use(Player* player, Location* location) {
	//Error handling
	if (player == nullptr || location == nullptr)
	{
		return false;
	}

    //Check if the player is in a location that can be hacked
    std::string locationName = location->getName();

    //Locations where hacking tool can be used - additional implementation and functionality will be added later

    //Server Room requires hacking
    if (locationName == "Server Room") {
        std::cout << "\nYou deploy the ICE breaker on the server terminal.\n";
        std::cout << "Encryption protocols crack and fall. Access granted.\n";
        std::cout << "The data is yours for the taking.\n";
        return false;  //Tool is reusable, not consumed
    }

    //Corporate Lobby - can hack security
    if (locationName == "Corporate Lobby") {
        std::cout << "\nYou hack into the security system.\n";
        std::cout << "Drone patrol patterns loop. You have a window.\n";
        return false;  //Tool is reusable
    }

    //Not a hackable location
    std::cout << "\nThere's nothing here that requires hacking.\n";
    return false;  //Not consumed
}