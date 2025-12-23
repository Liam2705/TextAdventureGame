#include "Location.h"
#include <iostream>

int main() {
    std::cout << "=== Step 1: Basic Location Class Test ===\n\n";

    Location downtown("Neo-Tokyo Downtown",
        "Neon signs flicker in the rain. Corporate towers\n"
        "loom overhead, their glass facades reflecting\n"
        "a thousand advertisements.");

    std::cout << "\n--- Testing display() function ---\n";
    downtown.display();

    std::cout << "\n--- Testing getter functions ---\n";
    std::cout << "Location name: " << downtown.getName() << "\n";
    std::cout << "Description: "
        << downtown.getDescription() << "...\n";

    std::cout << "\n\n--- Creating a second location ---\n";
    Location alley("Dark Alley",
        "A narrow passage between buildings. The smell\n"
        "of ozone and synthetic food fills the air.");

    alley.display();

    std::cout << "\n\nPress Enter to exit...";
    std::cin.get();

    return 0;
}