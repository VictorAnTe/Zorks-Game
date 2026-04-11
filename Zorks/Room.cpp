#include "Room.h"
#include "Exit.h"

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

std::vector<Exit*> Room::GetExits() const
{
    std::vector<Exit*> exits;

    for (Entity* e : this->contains) {
        if (e->type == EntityType::EXIT) {
            exits.push_back(static_cast<Exit*>(e));
        }
    }
    return exits;
}

