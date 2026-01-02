#include "HackingTool.h"
#include "Player.h"
#include "Location.h"
#include "TextEffects.h"
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
        std::cout << "\n================================================\n";
        std::cout << "         DEPLOYING ICE BREAKER                   \n";
        std::cout << "================================================\n\n";

        TextEffects::typewriter("You interface the ICE breaker with the terminal.", TextSpeed::NORMAL);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << "\n\n";

        std::cout << "[RUNNING INTRUSION PROTOCOLS...]\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(700));

        TextEffects::typewriter("Security barriers dissolve like ice in the sun.", TextSpeed::NORMAL);
        std::cout << "\n";
        TextEffects::typewriter("The data is yours for the taking.", TextSpeed::SLOW);

        std::cout << "\n\n================================================\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
        return false;  //Tool is reusable, not consumed
    }

    //Corporate Lobby - can hack security
    if (locationName == "Corporate Lobby") {
        std::cout << "\n================================================\n";
        std::cout << "         HACKING SECURITY SYSTEMS                \n";
        std::cout << "================================================\n\n";

        TextEffects::typewriter("You locate a security terminal on the wall.", TextSpeed::NORMAL);
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
        std::cout << "\n\n";

        std::cout << "[ACCESSING DRONE CONTROL NETWORK...]\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(800));

        std::cout << "[INJECTING LOOP PROTOCOL...]\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(700));

        std::cout << "\n";
        TextEffects::typewriter("The security drones overhead freeze mid-flight.", TextSpeed::NORMAL);
        std::cout << "\n";
        TextEffects::typewriter("Their patrol patterns loop endlessly.", TextSpeed::NORMAL);
        std::cout << "\n\n";
        TextEffects::typewriter("You have a window. Make it count.", TextSpeed::SLOW);

        std::cout << "\n\n================================================\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(400));

        return false;  //Tool is reusable
    }

    //Not a hackable location
    std::cout << "\nThere's nothing here that requires hacking.\n";
    return false;  //Not consumed
}