#ifndef STIMPACK_H
#define	STIMPACK_H

#include "Item.h"

class Stimpack : public Item {
private:
	int healAmount;

public:
	//Constructor
	Stimpack(const std::string itemName,
			const std::string itemDesc,
			int healing = 30);

	//Overides the virtual use function from the item class
	bool use(Player* player, Location* location) override;

	//Getter
	int getHealAmount() const;
};

#endif // !STIMPACK_H
