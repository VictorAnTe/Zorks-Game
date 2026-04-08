#include "Creature.h"

// Constructor
// We call the base Entity constructor. Casting location for the parent pointer
Creature::Creature(const std::string& name, const std::string& description, Room* location) :
    Entity(name, description, (Entity*)location),
    location(location)
{
    type = EntityType::CREATURE;
}

// Destructor
Creature::~Creature() {
    // I don't delete 'location' here, the Room is managed by the World 
    // entities vector so it is the responsable to delete it.
}