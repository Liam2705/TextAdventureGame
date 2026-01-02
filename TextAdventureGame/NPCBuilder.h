#ifndef NPCBuilder_H
#define NPCBuilder_H

#include <vector>

//Forward declarations
class NPC;
class Location;

//Creates all NPCs and places them in locations
class NPCBuilder {
public:
    //Creates all NPCs in the game
    static std::vector<NPC*> createAllNPCs();

    //Places NPCs in their starting locations
    static void placeNPCs(std::vector<Location*>& locations,
        std::vector<NPC*>& npcs);

private:
    //NPC indices
    enum NPCIndex {
        FIXER = 0,
        VENDOR,
        GUARD,
        STREET_VENDOR,
        FACTORY_WORKER
    };
};

#endif