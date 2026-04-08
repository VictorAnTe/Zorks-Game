#include "Player.h"
#include <iostream>

// Constructor
Player::Player(const std::string& name, const std::string& description, Room* location) :
    Creature(name, description, location)
{
    // Overriding the type to PLAYER so the World can identify the instance
    type = EntityType::PLAYER;

    max_health = 100;
    health = 100;
    power = 0;        // No weapon = No dmg
    equipped_weapon = nullptr;
    weapon_damage = 0;
}

// Destructor
Player::~Player() {
    // Parent class is the encarregated
}

void Player::EquipWeapon(Item* new_weapon, int new_dmg) {
    // We are using one weapon
    if (equipped_weapon != nullptr) {
        power -= weapon_damage;
        std::cout << "You unequipped the " << equipped_weapon->name << "." << std::endl;
    }

    // We equip the new weapon
    equipped_weapon = new_weapon;
    weapon_damage = new_dmg;
    power += weapon_damage;

    std::cout << "You have equipped the " << equipped_weapon->name << " (+ " << weapon_damage << " DMG)!" << std::endl;
    std::cout << "Your total attack power is now: " << power << std::endl;
}