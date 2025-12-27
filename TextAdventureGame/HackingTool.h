#ifndef HACKINGTOOL_H
#define HACKINGTOOL_H

#include "Item.h"

class HackingTool : public Item {
public:
	//Constructor
	HackingTool(const std::string itemName,
		const std::string itemDesc);

	//Overiding the virtual use function
	bool use(Player* player, Location* location) override;

};

#endif // !HACKINGTOOL_H
