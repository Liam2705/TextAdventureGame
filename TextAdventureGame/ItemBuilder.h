#ifndef ITEMBUILDER_H
#define ITEMBUILDER_H

#include <vector>

//Forward declarations
class Item;
class Location;

//Creates all game items and places them in locations
class ItemBuilder {
public:
    //Creates all items in the game
    static std::vector<Item*> createAllItems();

    //Places items in their starting locations
    static void placeItems(std::vector<Location*>& locations,
        std::vector<Item*>& items);

private:
    //Item indices
    enum ItemIndex {
        CREDITS = 0,
        HACKING_DEVICE,
        KEYCARD,
        STIMPACK,
        DATA_CHIP
    };
};

#endif