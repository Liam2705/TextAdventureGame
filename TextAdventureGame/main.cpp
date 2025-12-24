#include "Location.h"
#include <iostream>

int main() {
    //Creating Locations
    Location downtown("Neo-Tokyo Downtown",
        "Neon signs flicker in the rain. Corporate towers\n"
        "loom overhead, their glass facades reflecting\n"
        "a thousand advertisements.");

    Location alley("Dark Alley",
        "A narrow passage between buildings. The smell\n"
        "of ozone and synthetic food fills the air.");

    Location market("Black Market",
        "Holographic vendors hawk illegal cybernetics.\n"
        "Everything here is untraceable... for a price.");

    // Printing memory addresses
    std::cout << "\nMemory addresses:\n";
    std::cout << "  Downtown is at: " << &downtown << "\n";
    std::cout << "  Alley is at:    " << &alley << "\n";
    std::cout << "  Market is at:   " << &market << "\n\n";

    //Connecting Locations with Pointers
    std::cout << "--- Connecting locations ---\n";

    // Downtown has exits to the east (alley) and north (market)
    downtown.setEastExit(&alley);
    downtown.setNorthExit(&market);  
    std::cout << "Downtown connected to Alley (east) and Market (north)\n";

    // Alley has an exit back west to downtown
    alley.setWestExit(&downtown);
    std::cout << "Alley connected to Downtown (west)\n";

    // Market has an exit back south to downtown
    market.setSouthExit(&downtown);
    std::cout << "Market connected to Downtown (south)\n\n";

    //Navigation Testing
    std::cout << "=== Navigation Test ===\n";

    // Start at downtown
    Location* currentLocation = &downtown;  // Store pointer to downtown
    std::cout << "\n>> Starting location:\n";
    currentLocation->display();

     // Try to go north
    std::cout << "\n>> Attempting to go NORTH...\n";
    if (currentLocation->hasNorthExit()) {
        std::cout << "Exit exists! Moving north...\n";
        currentLocation = currentLocation->getNorthExit();  // Follow the pointer!
        currentLocation->display();
    }
    else {
        std::cout << "✗ No exit in that direction!\n";
    }

    // Try to go east (should fail - we're at market)
    std::cout << "\n>> Attempting to go EAST...\n";
    if (currentLocation->hasEastExit()) {
        std::cout << "Exit exists! Moving east...\n";
        currentLocation = currentLocation->getEastExit();
        currentLocation->display();
    }
    else {
        std::cout << "No exit in that direction!\n";
    }

    // Go back south
    std::cout << "\n>> Going SOUTH...\n";
    if (currentLocation->hasSouthExit()) {
        std::cout << "Exit exists! Moving south...\n";
        currentLocation = currentLocation->getSouthExit();
        currentLocation->display();
    }
    else {
        std::cout << "No exit in that direction!\n";
    }

    // Go east to alley
    std::cout << "\n>> Going EAST...\n";
    if (currentLocation->hasEastExit()) {
        std::cout << "Exit exists! Moving east...\n";
        currentLocation = currentLocation->getEastExit();
        currentLocation->display();
    }
    else {
        std::cout << "No exit in that direction!\n";
    }

    std::cout << "\n\nPress Enter to exit...";
    std::cin.get();

    return 0;
}