#include "Exit.h"

// Constructor
Exit::Exit(const std::string& name, const std::string& description, const std::string& direction, Room* destination) :
    Entity(name, description, nullptr),
    direction(direction),
    destination(destination)
{
    type = EntityType::EXIT;
}

// Destructor
Exit::~Exit() {
    // Like with other entities, we don't delete 'destination' here.
    // the World manages all Room pointers in its main entities vector.
}