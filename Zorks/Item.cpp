#include "Item.h"

// Constructor
Item::Item(const std::string& name, const std::string& description, Entity* parent) :
    Entity(name, description, parent)
{
    this->type = EntityType::ITEM;
    this->item_type = ItemType::DEFAULT; // Default type
}

// Destructor
Item::~Item() {
    // Like in other entities, World is responsible for the 
    // memory management of all items in its main vector.
}