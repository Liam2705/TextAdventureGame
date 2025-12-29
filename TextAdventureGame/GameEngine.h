#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <string>
#include <vector>

//Forward Declarations
class Player;
class Location;
class Item;


class GameEngine {
private:
	Player* player;
	bool isRunning;

	//Tracks the act
	int currentAct;
	bool act2Triggered;
	bool act3Triggered;

	//Storing pointers for all game locations to help with memory management and cleanup
	std::vector<Location*> allLocations;
	std::vector<Item*> allItems;

	//Helper functions
	void displayMainMenu() const;
	void displayMoveMenu() const;
	void displayItemsAtLocation() const;
	void checkActProgression();
	void triggerAct2();
	void triggerAct3();

	void clearScreen();
	void waitForEnter();

	//Handles commands
	void handleLook();
	void handleMove();
	void handleTakeItem();
	void handleUseItem();
	void handleDropItem();
	void handleInventory();
	void handleStatus();
	void handleHelp();
	void handleQuit();

	//Get player input
	int getPlayerChoice(int min, int max);

public:
	//Constructor
	GameEngine();

	//Destructor
	~GameEngine();

	void run();

	//Creates the locations and items
	void createWorld();
};


#endif

