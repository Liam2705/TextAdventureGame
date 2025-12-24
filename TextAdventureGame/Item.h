#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

class Item{
private:
	std::string name;
	std::string description;

public:
	//Constructor
	Item(const std::string& itemName, const std::string& itemDesc);

	//Destructor
	~Item();

	//Getters
	std::string getName() const;
	std::string getDescription() const;

	//Display item info
	void display() const;

};

#endif

