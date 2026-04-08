#include "Item.h"

// Constructor
Item::Item(const std::string& name, const std::string& description, Entity* parent, int dmg, int hp) :
    Entity(name, description, parent)
{
    this->type = EntityType::ITEM;
    this->damage_bonus = dmg;
    this->hp_bonus = hp;
}

// Destructor
Item::~Item() {
    // Like in other entities, World is responsible for the 
    // memory management of all items in its main vector.
}