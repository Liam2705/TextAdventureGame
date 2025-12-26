#include "GameEngine.h"
#include "Player.h"
#include "Location.h"
#include "Item.h"
#include <iostream>
#include <limits>


GameEngine::GameEngine() : player(nullptr), isRunning(false) {
	std::cout << "Initializing Cyberpunk Adventure...\n";
	createWorld();
}

GameEngine::~GameEngine() {
	std::cout << "\n=== Cleaning Up Game ===\n";

	
	delete player;

	//Deleting all items
	std::cout << "Deleting " << allItems.size() << " items...\n";
	for (Item* item : allItems) {
		delete item;
	}

	//Deleting all locations
	std::cout << "Deleting " << allLocations.size() << " locations...\n";
	for (Location* location : allLocations) {
		delete location;
	}

	std::cout << "Game cleaned up successfully!\n";
}

/*
	Create World
	Used to create the games locations, items, and connections between locations
*/
void GameEngine::createWorld() {
	std::cout << "\nCreating cyberpunk world...\n\n";

    //DOWNTOWN DISTRICT (Area)
    Location* neonStreet = new Location(
        "Neon Street",
        "The main street pulses with holographic advertisements.\n"
        "Rain reflects neon signs in endless colors. Street vendors\n"
        "hawk synthetic food from steaming carts.",
        "Downtown District"
    );

    Location* ramenBar = new Location(
        "Ramen Bar",
        "A small establishment wedged between corporate towers.\n"
        "Steam rises from bowls of synthetic noodles. This is where\n"
        "runners meet their fixers.",
        "Downtown District"
    );

    Location* blackMarket = new Location(
        "Black Market",
        "Holographic vendors flicker in the shadows. Everything here\n"
        "is untraceable, off the grid. Credits talk, questions don't.",
        "Downtown District"
    );

    Location* apartment = new Location(
        "Your Apartment",
        "A cramped studio forty floors up. Your terminal hums quietly.\n"
        "Rain streaks down the window, blurring the neon outside.\n"
        "This is home, for what it's worth.",
        "Downtown District"
    );

    Location* transitDowntown = new Location(
        "Downtown Transit Station",
        "A grimy subway platform. Flickering lights illuminate transit\n"
        "maps. From here you can reach the Industrial Sector.",
        "Downtown District"
    );

    //Connecting Downtown locations
    neonStreet->setNorthExit(ramenBar);
    neonStreet->setEastExit(blackMarket);
    neonStreet->setWestExit(apartment);

    ramenBar->setSouthExit(neonStreet);
    blackMarket->setWestExit(neonStreet);
    blackMarket->setNorthExit(transitDowntown);
    apartment->setEastExit(neonStreet);

    transitDowntown->setSouthExit(blackMarket);

    //Adding Downtown locations to vector for memory management and cleanup later
    allLocations.push_back(neonStreet);
    allLocations.push_back(ramenBar);
    allLocations.push_back(blackMarket);
    allLocations.push_back(apartment);
    allLocations.push_back(transitDowntown);

    //INDUSTRIAL SECTOR
    Location* transitIndustrial = new Location(
        "Industrial Transit Station",
        "The platform reeks of oil and rust. This is the gateway to\n"
        "the Industrial Sector. You can return Downtown from here.",
        "Industrial Sector"
    );

    Location* factory = new Location(
        "Abandoned Factory",
        "Rusted machinery looms in the darkness. This factory has been\n"
        "abandoned for years. Vagrants and scavengers pick through the\n"
        "remains. Somewhere here is what you need.",
        "Industrial Sector"
    );

    Location* warehouse = new Location(
        "Corporate Warehouse",
        "Stacks of crates reach toward the ceiling. Corporate security\n"
        "patrols occasionally sweep through. The keycard you need is\n"
        "somewhere in here... if you can find it without being caught.",
        "Industrial Sector"
    );

    //Connecting Industrial locations
    transitIndustrial->setNorthExit(factory);
    transitIndustrial->setSouthExit(warehouse);

    factory->setSouthExit(transitIndustrial);
    factory->setWestExit(warehouse);

    warehouse->setNorthExit(transitIndustrial);
    warehouse->setEastExit(factory);

    //Adding Industrial locations to vector for memory management and cleanup
    allLocations.push_back(transitIndustrial);
    allLocations.push_back(factory);
    allLocations.push_back(warehouse);

    //Connecting transit locations to allow travel between areas
    transitDowntown->setEastExit(transitIndustrial);
    transitIndustrial->setWestExit(transitDowntown);


    //CORPORATE PLAZA
    Location* transitCorporate = new Location(
        "Corporate Transit Terminal",
        "A pristine transit hub serving the Corporate Plaza. Everything\n"
        "here is chrome and glass. Security is everywhere.",
        "Corporate Plaza"
    );

    Location* plazaEntrance = new Location(
        "Corporate Plaza Entrance",
        "Towering glass and steel reach into the smog. Corporate drones\n"
        "patrol silently. A security checkpoint blocks the main entrance.\n"
        "You'll need proper credentials to enter.",
        "Corporate Plaza"
    );

    Location* lobby = new Location(
        "Corporate Lobby",
        "Polished marble floors reflect harsh fluorescent lights.\n"
        "Security drones hover near the ceiling. The elevator to the\n"
        "server room is ahead. You're in enemy territory now.",
        "Corporate Plaza"
    );

    Location* serverRoom = new Location(
        "Server Room",
        "Banks of servers hum with data. Climate control keeps the\n"
        "room ice cold. The target data is here, behind layers of\n"
        "security. This is what you came for.",
        "Corporate Plaza"
    );

    //Connecting Corporate locations
    transitCorporate->setEastExit(plazaEntrance);
    plazaEntrance->setWestExit(transitCorporate);
    plazaEntrance->setNorthExit(lobby);
    lobby->setSouthExit(plazaEntrance);
    lobby->setNorthExit(serverRoom);
    serverRoom->setSouthExit(lobby);

    //Adding Corporate locations to vector for memory management and cleanup
    allLocations.push_back(transitCorporate);
    allLocations.push_back(plazaEntrance);
    allLocations.push_back(lobby);
    allLocations.push_back(serverRoom);

    //Connecting Corporate transit locations
    transitDowntown->setNorthExit(transitCorporate);
    transitCorporate->setSouthExit(transitDowntown);

    //CREATE ITEMS
    Item* credits = new Item("Credstick (500c)", "Untraceable digital currency");
    Item* hackingDevice = new Item("Military ICE Breaker", "High-grade hacking tool");
    Item* keycard = new Item("Security Keycard", "Corporate access card");
    Item* stimpack = new Item("Neural Stimpack", "Boosts reaction time and heals injuries");
    Item* dataChip = new Item("Encrypted Data Chip", "The target data");

    //Adding items to the vector for memory management and cleanup
    allItems.push_back(credits);
    allItems.push_back(hackingDevice);
    allItems.push_back(keycard);
    allItems.push_back(stimpack);
    allItems.push_back(dataChip);

    //Placing items in locations
    blackMarket->addItem(credits);
    blackMarket->addItem(stimpack);
    factory->addItem(hackingDevice);
    warehouse->addItem(keycard);
    serverRoom->addItem(dataChip);

    //Create player at starting location
    player = new Player("Runner", neonStreet);

    std::cout << "World created!\n";
}

//Main game loop
void GameEngine::run() {
    isRunning = true;

    std::cout << "\n";
    std::cout << "===============================================\n";
    std::cout << "     CYBERPUNK TEXT ADVENTURE                  \n";
    std::cout << "     Welcome to Neo-Tokyo, Runner              \n";
    std::cout << "===============================================\n";
    std::cout << "\n";

    //Show starting location
    handleLook();

    //Main game loop
    while (isRunning) {
        displayMainMenu();

        int choice = getPlayerChoice(1, 8);

        //Handle the choice
        switch (choice) {
        case 1:
            handleLook();
            break;
        case 2:
            handleMove();
            break;
        case 3:
            handleTakeItem();
            break;
        case 4:
            handleDropItem();
            break;
        case 5:
            handleInventory();
            break;
        case 6:
            handleStatus();
            break;
        case 7:
            handleHelp();
            break;
        case 8:
            handleQuit();
            break;
        }

        if (isRunning) {
            waitForEnter();
        }
    }

    std::cout << "\nThanks for playing!\n";
}

void GameEngine::displayMainMenu() const {
    std::cout << "\n===================================================\n";
    std::cout << "What do you want to do?\n";
    std::cout << "===================================================\n";
    std::cout << "1. Look around\n";
    std::cout << "2. Move to another location\n";
    std::cout << "3. Pick up an item\n";
    std::cout << "4. Drop an item\n";
    std::cout << "5. Check inventory\n";
    std::cout << "6. Check status\n";
    std::cout << "7. Help\n";
    std::cout << "8. Quit game\n";
    std::cout << "===================================================\n";
}

//Display movement menu
void GameEngine::displayMoveMenu() const {
    std::cout << "\nWhere do you want to go?\n";
    std::cout << "===================================================\n";

    int optionNum = 1;
    Location* current = player->getCurrentLocation();

    if (current->hasNorthExit()) {
        std::cout << optionNum++ << ". Go NORTH\n";
    }
    if (current->hasSouthExit()) {
        std::cout << optionNum++ << ". Go SOUTH\n";
    }
    if (current->hasEastExit()) {
        std::cout << optionNum++ << ". Go EAST\n";
    }
    if (current->hasWestExit()) {
        std::cout << optionNum++ << ". Go WEST\n";
    }

    std::cout << optionNum << ". Cancel\n";
    std::cout << "===================================================\n";
}

//Handlers for commands

void GameEngine::handleLook() {
    player->look();
}

void GameEngine::handleMove() {
    Location* current = player->getCurrentLocation();

    //Check if there are any exits
    if (!current->hasNorthExit() && !current->hasSouthExit() &&
        !current->hasEastExit() && !current->hasWestExit()) {
        std::cout << "\nThere are no exits from here! (This shouldn't happen)\n";
        return;
    }

    displayMoveMenu();

    //Count available directions
    int numDirections = 0;
    if (current->hasNorthExit()) numDirections++;
    if (current->hasSouthExit()) numDirections++;
    if (current->hasEastExit()) numDirections++;
    if (current->hasWestExit()) numDirections++;

    int choice = getPlayerChoice(1, numDirections + 1);

    //If they chose cancel
    if (choice == numDirections + 1) {
        std::cout << "\nYou stay where you are.\n";
        return;
    }

    //Map choice to direction
    int currentOption = 1;

    if (current->hasNorthExit()) {
        if (choice == currentOption++) {
            player->moveNorth();
            player->look();
            return;
        }
    }
    if (current->hasSouthExit()) {
        if (choice == currentOption++) {
            player->moveSouth();
            player->look();
            return;
        }
    }
    if (current->hasEastExit()) {
        if (choice == currentOption++) {
            player->moveEast();
            player->look();
            return;
        }
    }
    if (current->hasWestExit()) {
        if (choice == currentOption++) {
            player->moveWest();
            player->look();
            return;
        }
    }
}

void GameEngine::handleTakeItem() {
    Location* current = player->getCurrentLocation();

    if (current->getItemCount() == 0) {
        std::cout << "\nThere are no items here to pick up.\n";
        return;
    }

    displayItemsAtLocation();
    std::cout << current->getItemCount() << ". Cancel\n";

    int choice = getPlayerChoice(0, current->getItemCount());

    if (choice == current->getItemCount()) {
        std::cout << "\nYou decide not to take anything.\n";
        return;
    }

    player->pickUpItem(choice);
}

void GameEngine::handleDropItem() {
    if (player->getInventoryCount() == 0) {
        std::cout << "\nYou're not carrying anything to drop.\n";
        return;
    }

    std::cout << "\nYour inventory:\n";
    player->showInventory();
    std::cout << "\nWhich item do you want to drop? (or "
        << player->getInventoryCount() << " to cancel): ";

    int choice = getPlayerChoice(0, player->getInventoryCount());

    if (choice == player->getInventoryCount()) {
        std::cout << "\nYou decide to keep everything.\n";
        return;
    }

    player->dropItem(choice);
}

void GameEngine::handleInventory() {
    player->showInventory();
}

void GameEngine::handleStatus() {
    player->showStatus();
}

void GameEngine::handleHelp() {
    std::cout << "\n===================================================\n";
    std::cout << "                    HELP                             \n";
    std::cout << "===================================================\n";
    std::cout << "\nThis is a text adventure game set in a cyberpunk world.\n";
    std::cout << "\nYour goal: Explore Neo-Tokyo, collect items, and\n";
    std::cout << "survive in the neon-lit streets.\n";
    std::cout << "\nTips:\n";
    std::cout << "- Look around to see your surroundings\n";
    std::cout << "- Pick up items that might be useful\n";
    std::cout << "- Explore all locations\n";
    std::cout << "- Check your inventory often\n";
    std::cout << "\nGood luck, Runner!\n";
}

void GameEngine::handleQuit() {
    std::cout << "\nAre you sure you want to quit?\n";
    std::cout << "1. Yes\n";
    std::cout << "2. No\n";

    int choice = getPlayerChoice(1, 2);

    if (choice == 1) {
        isRunning = false;
        std::cout << "\nExiting game...\n";
    }
    else {
        std::cout << "\nContinuing game...\n";
    }
}


int GameEngine::getPlayerChoice(int minChoice, int maxChoice) {
    int choice;

    while (true) {
        std::cout << "\nEnter your choice (" << minChoice << "-" << maxChoice << "): ";
        std::cin >> choice;

        //Error handling
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        //Check if the choice is in range
        if (choice >= minChoice && choice <= maxChoice) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return choice;
        }

        std::cout << "Invalid choice! Please choose between "
            << minChoice << " and " << maxChoice << ".\n";
    }
}

void GameEngine::waitForEnter() {
    std::cout << "\nPress Enter to continue...";
    std::cin.get();
}

void GameEngine::clearScreen() {
    //Windows
    #ifdef _WIN32
    system("cls");
    //Unix/Linux/Mac
    #else
    system("clear");
    #endif
}

//Display the items at current location
void GameEngine::displayItemsAtLocation() const {
    Location* current = player->getCurrentLocation();

    std::cout << "\nItems here:\n";
    current->listItems();
}