#include "Item.h"

// Constructor
Item::Item(const std::string& name, const std::string& description, Entity* parent, int dmg) :
    Entity(name, description, parent)
{
    this->type = EntityType::ITEM;
    this->damage_bonus = dmg;

    // Future variables initialization:
    // can_be_eaten = false;
    // can_be_equiped = false;
    // opens_door = {{name_door}};
}

// Destructor
Item::~Item() {
    // Like in other entities, World is responsible for the 
    // memory management of all items in its main vector.
}