#include "Player.h"
#include "Location.h"
#include "Item.h"
#include <iostream>

int main() {
    std::cout << "=== Testing Dynamic arrays for picking up and dropping items ===\n\n";

    //Create locations
    std::cout << "--- Creating Locations ---\n";
    Location* alley = new Location(
        "Dark Alley",
        "A shadowy corridor between neon-lit buildings.\n"
        "The perfect place for shady deals."
    );
    Location* downtown = new Location(
        "Neo-Tokyo Downtown",
        "Rain-slicked streets reflect neon advertisements.\n"
        "The air smells of synthetic ramen and ozone."
    );
    Location* market = new Location(
        "Black Market",
        "Holographic vendors hawk illegal cybernetics.\n"
        "Everything here is untraceable... for a price."
    );

    // Connect locations
    downtown->setEastExit(alley);
    alley->setWestExit(downtown);
    alley->setSouthExit(market);
    market->setNorthExit(alley);

    //Create some cyberpunk items
    std::cout << "\n--- Creating Items ---\n";
    Item* dataChip = new Item("Encrypted Data Chip", "Corporate secrets worth millions");
    Item* stimpack = new Item("Neural Stimpack", "Boosts reaction time temporarily");
    Item* credStick = new Item("Credstick", "Contains 500 credits");
    Item* hacker = new Item("Hacking Tool", "Military-grade ICE breaker");
    Item* implant = new Item("Cybernetic Implant", "Optic enhancement module");

    //Add items to locations
    std::cout << "\n--- Adding Items to Location ---\n";
    downtown->addItem(dataChip);
    downtown->addItem(credStick);

    alley->addItem(stimpack);

    market->addItem(hacker);
    market->addItem(implant);

    //Set starting location
    Location* startLocation = downtown;

    //GAME TEST
    // Create player
    std::cout << "=== Creating Player ===\n";
    Player* player = new Player("Liam", startLocation);
    std::cout << "\n";

    // Show starting location
    std::cout << "=== GAME START ===\n";
    player->look();

    // Demonstrate gameplay
    std::cout << "\n>> Picking up Encrypted Data Chip (item 0)...\n";
    player->pickUpItem(0);

    std::cout << "\n>> Picking up Credstick (now item 0)...\n";
    player->pickUpItem(0);

    std::cout << "\n>> Checking inventory...\n";
    player->showInventory();

    std::cout << "\n>> Moving EAST to Dark Alley...\n";
    player->moveEast();
    player->look();

    std::cout << "\n>> Picking up Neural Stimpack...\n";
    player->pickUpItem(0);

    std::cout << "\n>> Current inventory:\n";
    player->showInventory();

    std::cout << "\n>> Moving SOUTH to Black Market...\n";
    player->moveSouth();
    player->look();

    std::cout << "\n>> Trying to move SOUTH (no exit)...\n";
    player->moveSouth();  // Should fail

    std::cout << "\n>> Dropping Credstick (item 1) here...\n";
    player->dropItem(1);

    std::cout << "\n>> Looking around:\n";
    player->look();

    std::cout << "\n>> Final inventory:\n";
    player->showInventory();

    std::cout << "\n>> Player status:\n";
    player->showStatus();
    
    //Memory cleanup
    std::cout << "\n\n=== Memory Cleanup ===\n\n";

    //Delete all items
    std::cout << "--- Deleting Items ---\n";
    delete dataChip;
    delete stimpack;
    delete credStick;
    delete hacker;
    delete implant;

    //Delete location (destructor deletes the array)
    std::cout << "\n--- Deleting Location ---\n";
    
    delete downtown;
    delete alley;
    delete market;

    std::cout << "\nAll memory freed!\n";
}