#ifndef KEYCARD_H
#define KEYCARD_H

#include "Item.h"

class Keycard : public Item {
public:
    //Constructor
    Keycard(const std::string& itemName,
        const std::string& itemDesc);

    //Overriding the virtual use function
    bool use(Player* player, Location* location) override;
};

#endif
