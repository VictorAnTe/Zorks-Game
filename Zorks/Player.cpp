#include "Player.h"
#include <iostream>

// Constructor
Player::Player(const std::string& name, const std::string& description, Room* location) :
    Creature(name, description, location, 100, 5)
{
    // Overriding the type to PLAYER so the World can identify the instance
    type = EntityType::PLAYER;
    equipped_weapon = nullptr;
    weapon_damage = 0;
}

// Destructor
Player::~Player() {
    // Parent class is the encarregated
}

Item* Player::GetItem(const std::string& name)
{
    for (Entity* e : contains) {
        // Try to cast the Entity to an Item
        Item* item = dynamic_cast<Item*>(e);

        // Check if the cast succeeded && if the name matches
        if (item != nullptr && item->name == name) {
            return item;
        }
    }
    return nullptr;
}

void Player::EquipWeapon(Item* new_weapon, int new_dmg) {
    if (equipped_weapon != nullptr) {
        std::cout << "You unequipped the " << equipped_weapon->name << "." << std::endl;
    }

    equipped_weapon = new_weapon;
    weapon_damage = new_dmg;

    std::cout << "You have equipped the " << equipped_weapon->name << " (+ " << weapon_damage << " DMG)!" << std::endl;
    std::cout << "Your total attack power is now: " << GetAttackDamage() << std::endl;
}

std::string Player::GetWeapon() const
{
    if (equipped_weapon != nullptr) return equipped_weapon->name;
    return "Fists";
}

void Player::RestoreHealth(int amount)
{
    health = std::min(health + amount, max_health);
}
