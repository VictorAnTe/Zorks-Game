#ifndef ITEM_H
#define ITEM_H

#include "Entity.h"

class Item : public Entity {
public:
    // Parent can be a Room (on the floor) or a Player (in inventory)
    Item(const std::string& name, const std::string& description, Entity* parent = nullptr);
    virtual ~Item();

    // Future functions:
    // bool can_be_eaten;
    // bool can_be_equiped;
    // string opens_door;
};

#endif // ITEM_H