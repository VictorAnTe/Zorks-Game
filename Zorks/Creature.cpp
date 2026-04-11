#include "Creature.h"
#include <iostream>

// Constructor
// We call the base Entity constructor. Casting location for the parent pointer
Creature::Creature(const std::string& name, const std::string& description, Entity* parent, int health_pts, int dmg) :
    Entity(name, description, parent)
{
    type = EntityType::CREATURE;
    this->health = health_pts;
    this->max_health = health_pts;
    this->power = dmg;
    this->location = (Room*)parent;
}

// Destructor
Creature::~Creature() {}

void Creature::Attack(Creature* target) {
    std::cout << name << " attacks you!" << std::endl;
    target->TakeDamage(GetAttackDamage());
}

void Creature::TakeDamage(const int dmg) {
    health -= dmg;
    if (health < 0) health = 0;

    std::cout << name << " takes " << dmg << " damage!" << std::endl;
}