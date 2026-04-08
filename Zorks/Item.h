#ifndef ITEM_H
#define ITEM_H

#include "Entity.h"

class Item : public Entity {
public:
    // Parent can be a Room (on the floor) or a Player (in inventory)
    Item(const std::string& name, const std::string& description, Entity* parent = nullptr, int dmg = 0, int hp = 0);
    virtual ~Item();

    int damage_bonus;
    int hp_bonus;
};

#endif // ITEM_H