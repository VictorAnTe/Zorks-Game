#include "Container.h"

Container::Container(const std::string& name, const std::string& description, Entity* parent) :
    Item(name, description, parent) // calls Item class that it calls Entity class
{
    this->item_type = ItemType::CONTAINER;
}

Container::~Container() {}

void Container::Put(Entity* item) {
    if (item != nullptr) {
        contains.push_back(item);
        item->parent = this;
    }
}

Entity* Container::Remove(const std::string& item_name) {
    for (auto it = contains.begin(); it != contains.end(); ++it) {
        if ((*it)->name == item_name) {
            Entity* found = *it;
            contains.erase(it);
            found->parent = nullptr; // Item is now in user inventory
            return found;
        }
    }
    return nullptr;
}