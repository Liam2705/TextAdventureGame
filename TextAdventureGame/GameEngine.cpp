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

	//Creating locations
    Location* downtown = new Location(
        "Neo-Tokyo Downtown",
        "Neon signs flicker in the perpetual rain. Corporate towers\n"
        "loom overhead, their glass facades reflecting advertisements.\n"
        "The air smells of synthetic ramen and ozone."
    );

    Location* alley = new Location(
        "Dark Alley",
        "A narrow passage between buildings. Water drips from rusty\n"
        "fire escapes above. This is where real deals go down."
    );

    Location* market = new Location(
        "Black Market",
        "Holographic vendors hawk illegal cybernetics and stolen data.\n"
        "Everything here is untraceable... for a price."
    );

    Location* corpo = new Location(
        "Corporate Plaza",
        "Gleaming chrome and polished marble. Security drones patrol\n"
        "silently. The corporate elite move through without seeing you."
    );

    //Adding locations to vector for memory management and cleanup later
    allLocations.push_back(downtown);
    allLocations.push_back(alley);
    allLocations.push_back(market);
    allLocations.push_back(corpo);

    //Connect locations
    downtown->setNorthExit(corpo);
    downtown->setEastExit(alley);

    alley->setWestExit(downtown);
    alley->setSouthExit(market);

    market->setNorthExit(alley);

    corpo->setSouthExit(downtown);

    //Creating items
    Item* dataChip = new Item("Encrypted Data Chip", "Corporate secrets worth millions");
    Item* stimpack = new Item("Neural Stimpack", "Boosts reaction time temporarily");
    Item* credstick = new Item("Credstick (500c)", "Untraceable credits");
    Item* hacker = new Item("ICE Breaker", "Military-grade hacking tool");
    Item* implant = new Item("Optic Implant", "Enhanced vision cybernetics");

    //Store items for cleanup and memory management
    allItems.push_back(dataChip);
    allItems.push_back(stimpack);
    allItems.push_back(credstick);
    allItems.push_back(hacker);
    allItems.push_back(implant);

    //Place items in locations
    downtown->addItem(dataChip);
    downtown->addItem(credstick);
    alley->addItem(stimpack);
    market->addItem(hacker);
    market->addItem(implant);

    //Create player at starting location
    player = new Player("Runner", downtown);

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

    std::cout << "\nItems here:\n";
    current->listItems();
    std::cout << (current->getItemCount()) << ". Cancel\n";

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