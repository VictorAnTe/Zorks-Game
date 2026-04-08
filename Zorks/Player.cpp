#include "Player.h"
#include <iostream>

// Constructor
Player::Player(const std::string& name, const std::string& description, Room* location) :
    Creature(name, description, location)
{
    // Overriding the type to PLAYER so the World can identify the instance
    type = EntityType::PLAYER;

    // Future variables will be initialize here
    // weapon_name = "None";
}

// Destructor
Player::~Player() {
    // Parent class is the encarregated
}