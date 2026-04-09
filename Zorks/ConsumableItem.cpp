#include "ConsumableItem.h"

// Constructor
ConsumableItem::ConsumableItem(const std::string& name, const std::string& description, Entity* parent, int hp) :
    Item(name, description, parent)
{
    this->item_type = ItemType::CONSUMABLE;
    hp_bonus = hp;
}

// Destructor
ConsumableItem::~ConsumableItem() {
    // Like in other entities, World is responsible for the 
    // memory management of all items in its main vector.
}