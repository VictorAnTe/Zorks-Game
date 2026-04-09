#ifndef ITEM_H
#define ITEM_H

#include "Entity.h"

enum class ItemType {
    DEFAULT,
    CONSUMABLE,
    KEY,
    WEAPON
};

class Item : public Entity {
public:
    // Parent can be a Room (on the floor) or a Player (in inventory)
    Item(const std::string& name, const std::string& description, Entity* parent = nullptr);
    virtual ~Item();

    ItemType item_type = ItemType::DEFAULT;
};

#endif // ITEM_H