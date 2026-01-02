#include "ItemBuilder.h"
#include "Item.h"
#include "Stimpack.h"
#include "HackingTool.h"
#include "Keycard.h"
#include "Location.h"
#include <iostream>

std::vector<Item*> ItemBuilder::createAllItems() {
    std::cout << "Creating items...\n";

    std::vector<Item*> items;

    // Create all items
    items.push_back(new Item(
        "Credstick (500c)",
        "Untraceable digital currency",
        ItemType::MISC,
        false
    ));

    items.push_back(new HackingTool(
        "Military ICE Breaker",
        "High-grade hacking tool"
    ));

    items.push_back(new Keycard(
        "Security Keycard",
        "Corporate access card"
    ));

    items.push_back(new Stimpack(
        "Neural Stimpack",
        "Boosts reaction time and heals injuries",
        30
    ));

    items.push_back(new Item(
        "Encrypted Data Chip",
        "The target data",
        ItemType::KEY_ITEM,
        false
    ));

    std::cout << "Created " << items.size() << " items.\n";

    return items;
}

void ItemBuilder::placeItems(std::vector<Location*>& locations,
    std::vector<Item*>& items) {
    std::cout << "Placing items in world...\n";

    //Black Market: Credits and Stimpack
    locations[2]->addItem(items[CREDITS]);     
    locations[2]->addItem(items[STIMPACK]);

    //Factory: Hacking Device
    locations[6]->addItem(items[HACKING_DEVICE]); 

    //Warehouse: Keycard
    locations[7]->addItem(items[KEYCARD]);        

    //Server Room: Data Chip
    locations[11]->addItem(items[DATA_CHIP]);

    std::cout << "Items placed.\n";
}