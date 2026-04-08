#include "Room.h"

// Constructor
Room::Room(const std::string& name, const std::string& description) :
    Entity(name, description, nullptr)
{
    type = EntityType::ROOM;
}

// Destructor
Room::~Room() {
    // We don't delete entities in 'contains' here because 
    // the World's entities vector is responsible for all deletions.
}