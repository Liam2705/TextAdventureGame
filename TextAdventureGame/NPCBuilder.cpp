#include "NPCBuilder.h"
#include "NPC.h"
#include "Location.h"
#include <iostream>

std::vector<NPC*> NPCBuilder::createAllNPCs() {
    std::cout << "Creating NPCs...\n";

    std::vector<NPC*> npcs;

    //1. FIXER - Quest giver at Ramen Bar
    NPC* fixer = new NPC("Jin \"The Fixer\" Yamamoto",
        "A grizzled netrunner in a worn leather jacket");
    fixer->addDialogue({
        "Runner. I've been expecting you.",
        "Word on the street is you're looking for work. Big work.",
        "I've got a job. Corporate data extraction. High risk, higher reward.",
        "You'll need proper equipment. A military-grade ICE breaker and a valid keycard.",
        "The Industrial Sector... dangerous place. But that's where you'll find what you need.",
        "Once you're ready, hit the Corporate Plaza. Their server room has what we're after.",
        "Get me that data chip, and you'll never worry about credits again."
        });
    npcs.push_back(fixer);

    //2. VENDOR - Black Market dealer
    NPC* vendor = new NPC("Kira",
        "A sharp-eyed vendor surrounded by contraband");
    vendor->addDialogue({
        "Looking to buy or sell? Everything's negotiable.",
        "Those stimpacks? Best you'll find. Corpo-grade medical tech, black market prices.",
        "Word of advice: Industrial Sector's no joke. Take healing items.",
        "And hey... if you find any rare tech, bring it back. I pay well."
        });
    npcs.push_back(vendor);

    //3. SECURITY GUARD - Corporate Plaza
    NPC* guard = new NPC("Corporate Security Officer",
        "A heavily augmented security guard");
    guard->addDialogue({
        "Halt. This is a restricted area.",
        "You'll need proper credentials to proceed. Security keycard, registered to the corporation.",
        "No keycard? Then turn around. This checkpoint is NOT negotiable.",
        "Move along, citizen."
        });
    npcs.push_back(guard);

    //4. STREET VENDOR - Neon Street
    NPC* streetVendor = new NPC("Street Food Vendor",
        "An old woman selling synthetic ramen");
    streetVendor->addDialogue({
        "Hungry? Best ramen in Neo-Tokyo, only 10 credits!",
        "You look like you're planning something big. Be careful out there, kid.",
        "Industrial Sector's been abandoned for years. Scavengers and worse.",
        "Whatever you're after, I hope it's worth it."
        });
    npcs.push_back(streetVendor);

    //5. FACTORY WORKER - Abandoned Factory
    NPC* worker = new NPC("Former Factory Worker",
        "A haggard man picking through the ruins");
    worker->addDialogue({
        "Lost my job when this place shut down. Now I scavenge.",
        "You're not the first runner to come through here looking for tech.",
        "Check the maintenance room. Military equipment sometimes gets left behind.",
        "Just... watch yourself. This sector damages more than just your pride."
        });
    npcs.push_back(worker);

    std::cout << "Created " << npcs.size() << " NPCs.\n";

    return npcs;
}

void NPCBuilder::placeNPCs(std::vector<Location*>& locations,
    std::vector<NPC*>& npcs) {
    std::cout << "Placing NPCs in world...\n";

    //Ramen Bar: Fixer
    locations[1]->addNPC(npcs[FIXER]); 

    //Black Market: Vendor
    locations[2]->addNPC(npcs[VENDOR]);     

    //Corporate Plaza Entrance: Guard
    locations[9]->addNPC(npcs[GUARD]);          

    //Neon Street: Street Vendor
    locations[0]->addNPC(npcs[STREET_VENDOR]);   

    //Factory: Factory Worker
    locations[6]->addNPC(npcs[FACTORY_WORKER]);  

    std::cout << "NPCs placed.\n";
}