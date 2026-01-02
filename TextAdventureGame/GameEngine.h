#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <string>
#include <vector>
#include "WorldBuilder.h" 
#include "ItemBuilder.h"    
#include "NPCBuilder.h"

//Forward Declarations
class Player;
class Location;
class Item;
class NPC;

enum class MenuAction{
	LOOK,
	MOVE,
	TAKE_ITEM,
	DROP_ITEM,
	USE_ITEM,
	TALK_NPC,
	INVENTORY,
	STATUS,
	HELP,
	QUIT
};

class GameEngine {
private:
	Player* player;
	bool isRunning;
	bool shouldClearScreen; //Used to track is screen should clear before menu display

	//Tracks the act
	int currentAct;
	bool act2Triggered;
	bool act3Triggered;

	//Storing pointers for all game locations to help with memory management and cleanup
	std::vector<Location*> allLocations;
	std::vector<Item*> allItems;
	std::vector<NPC*> allNPCs;

	//Helper functions
	void displayMainMenu() const;
	void displayMoveMenu() const;
	void displayItemsAtLocation() const;
	void checkActProgression();
	void triggerAct2();
	void triggerAct3();

	//Helper functions for dynamic menu system
	std::vector<MenuAction> buildMenuOptions() const;
	void executeMenuAction(MenuAction action);

	bool shouldClearAfterAction(MenuAction action) const;

	void clearScreen();
	void waitForEnter();

	//Handles commands
	void handleLook();
	void handleMove();
	void handleTakeItem();
	void handleUseItem();
	void handleDropItem();
	void handleTalkToNPC();
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

