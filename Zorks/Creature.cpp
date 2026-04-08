#include "Creature.h"
#include <iostream>

// Constructor
// We call the base Entity constructor. Casting location for the parent pointer
Creature::Creature(const std::string& name, const std::string& description, Room* location, int dmg) :
    Entity(name, description, (Entity*)location),
    location(location)
{
    type = EntityType::CREATURE;
    health = 100;      // default
    max_health = 100;  // default
    power = dmg;       // default
}

// Destructor
Creature::~Creature() {
    // I don't delete 'location' here, the Room is managed by the World 
    // entities vector so it is the responsable to delete it.
}

void Creature::RestoreHealth(const int hp_rest)
{
    health += hp_rest;

    // If health is greater than max_health we put health as the max_health value
    if (health > max_health) {
        health = max_health;
    }

    std::cout << name << " recovers health! Current HP: " << health << "/" << max_health << std::endl;
}
