#ifndef CONSUMABLEITEM_H
#define CONSUMABLEITEM_H

#include "Item.h"

class ConsumableItem : public Item {
public:
	ConsumableItem(const std::string& name, const std::string& description, Entity* parent = nullptr, int hp = 0);
	virtual ~ConsumableItem();
	int hp_bonus;
};

#endif // CONSUMABLEITEM_H