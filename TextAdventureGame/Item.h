#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

//Forward Declarations
class Player;
class Location;

enum class ItemType {
	CONSUMABLE,     //Used once and destroyed (stimpack)
	TOOL,           //Reusable tool (hacking device)
	KEY_ITEM,       //Quest/story item (keycard, data chip)
	MISC            //Can't be used (temporarily credits)
};

class Item {
private:
	std::string name;
	std::string description;
	ItemType type;
	bool isUsable;

public:
	//Constructor
	Item(const std::string& itemName, 
		const std::string& itemDesc,
		ItemType itemType = ItemType::MISC,
		bool usable = false);

	//Destructor
	virtual ~Item();

	//Getters
	std::string getName() const;
	std::string getDescription() const;
	ItemType getType() const;
	bool getIsUsable() const;

	//Display item info
	void display() const;

	virtual bool use(Player* player, Location* location);

};

#endif

