#include "Stimpack.h"
#include "Player.h"
#include <iostream>

Stimpack::Stimpack(const std::string itemName,
					const std::string itemDesc,
					int healing)
	:Item(itemName, itemDesc, ItemType::CONSUMABLE, true), 
	healAmount(healing) {

}

//Uses the stimpack - heals player
bool Stimpack::use(Player* player, Location* location) {
    if (player == nullptr) {
        return false;
    }

    //Check if player needs healing
    if (player->getHealth() >= player->getMaxHealth()) {
        std::cout << "\nYou're already at full health!\n";
        return false;  //Don't consume the item
    }

    std::cout << "\nYou inject the neural stimpack.\n";
    std::cout << "Chemicals flood your system, accelerating cellular repair.\n";

    player->heal(healAmount);

    return true;  //Item is consumed
}

//Getter
int Stimpack::getHealAmount() const {
    return healAmount;
}