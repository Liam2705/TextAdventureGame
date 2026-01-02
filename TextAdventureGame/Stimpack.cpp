#include "Stimpack.h"
#include "Player.h"
#include "TextEffects.h"
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

    std::cout << "\n================================================\n";
    std::cout << "         NEURAL STIMPACK ACTIVATED               \n";
    std::cout << "================================================\n\n";

    TextEffects::typewriter("You press the stimpack against your neck.", TextSpeed::NORMAL);
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
    std::cout << "\n";

    TextEffects::typewriter("HISS. The injection is instant.", TextSpeed::FAST);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "\n\n";

    TextEffects::typewriter("Nanobots flood your bloodstream, accelerating", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("cellular repair at the molecular level.", TextSpeed::NORMAL);
    std::this_thread::sleep_for(std::chrono::milliseconds(600));
    std::cout << "\n\n";

    TextEffects::typewriter("Pain fades. Wounds knit together.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::cout << "================================================\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(300));

    player->heal(healAmount);

    return true;  //Item is consumed
}

//Getter
int Stimpack::getHealAmount() const {
    return healAmount;
}