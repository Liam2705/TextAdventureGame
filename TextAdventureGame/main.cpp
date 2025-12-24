#include "Location.h"
#include "Item.h"
#include <iostream>

int main() {
    std::cout << "=== Testing Dynamic Arrays for Items ===\n\n";

    //Create a location
    std::cout << "--- Creating Location ---\n";
    Location* alley = new Location(
        "Dark Alley",
        "A shadowy corridor between neon-lit buildings.\n"
        "The perfect place for shady deals."
    );

    //Create some cyberpunk items
    std::cout << "\n--- Creating Items ---\n";
    Item* dataChip = new Item("Encrypted Data Chip", "Corporate secrets worth millions");
    Item* stimpack = new Item("Neural Stimpack", "Boosts reaction time temporarily");
    Item* credStick = new Item("Credstick", "Contains 500 credits");
    Item* hacker = new Item("Hacking Tool", "Military-grade ICE breaker");
    Item* implant = new Item("Cybernetic Implant", "Optic enhancement module");

    //Add items to location
    std::cout << "\n--- Adding Items to Location ---\n";
    alley->addItem(dataChip);
    alley->addItem(stimpack);
    alley->addItem(credStick);

    //Display location (shows items)
    std::cout << "\n--- Displaying Location ---\n";
    alley->display();

    //Test array resizing by adding more items
    std::cout << "\n--- Testing Array Resize (capacity was 4) ---\n";
    alley->addItem(hacker);    // 4th item 
    alley->addItem(implant);   // 5th item - should trigger resize

    alley->display();

    //Remove an item
    std::cout << "\n--- Removing Item at Index 1 ---\n";
    Item* removed = alley->removeItem(1);
    if (removed != nullptr) {
        std::cout << "Removed: ";
        removed->display();
    }

    alley->display();

    //Access items by index
    std::cout << "\n--- Accessing Items by Index ---\n";
    std::cout << "Item at index 0: ";
    Item* item = alley->getItem(0);
    if (item != nullptr) {
        item->display();
    }

    std::cout << "Item at index 2: ";
    item = alley->getItem(2);
    if (item != nullptr) {
        item->display();
    }

    //Show item count
    std::cout << "\nTotal items in location: " << alley->getItemCount() << "\n";

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
    delete alley;

    std::cout << "\nAll memory freed!\n";
}