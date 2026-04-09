#include "Container.h"

Container::Container(const std::string& name, const std::string& description, Entity* parent) :
    Item(name, description, parent) // calls Item class that it calls Entity class
{
    this->item_type = ItemType::CONTAINER;
}

Container::~Container() {}