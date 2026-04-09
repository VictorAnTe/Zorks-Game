#include "WeaponItem.h"

WeaponItem::WeaponItem(const std::string& name, const std::string& description, Entity* parent, int dmg) :
    Item(name, description, parent) // calls Item class that it calls Entity class
{
    this->item_type = ItemType::WEAPON;
    this->damage_bonus = dmg;
}

WeaponItem::~WeaponItem() {}