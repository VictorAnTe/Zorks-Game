#ifndef WEAPONITEM_H
#define WEAPONITEM_H

#include "Item.h"

class WeaponItem : public Item {
public:
    WeaponItem(const std::string& name, const std::string& description, Entity* parent = nullptr, int dmg = 0);
    virtual ~WeaponItem();

    int damage_bonus;
};

#endif