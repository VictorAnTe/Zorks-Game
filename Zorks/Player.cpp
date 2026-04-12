#include "Player.h"
#include <iostream>
#include <ctime> // For rand()


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

void Player::UnequipWeapon() {
    if (equipped_weapon != nullptr) {
        std::cout << "You unequipped the " << equipped_weapon->name << "." << std::endl;
        
        equipped_weapon = nullptr;
        weapon_damage = 0;

        std::cout << "Your total attack power is now: " << GetAttackDamage() << std::endl;
    }
    else {
        std::cout << "You don't have any weapon equipped" << std::endl; 
    }
}

void Player::EquipWeapon(Item* new_weapon, int new_dmg) {
    if (equipped_weapon != nullptr) {
        std::cout << "You unequipped the " << equipped_weapon->name << "." << std::endl;
    }

    equipped_weapon = new_weapon;
    weapon_damage = new_dmg;

    std::cout << "You have equipped the " << equipped_weapon->name << " (+ " << weapon_damage << " DMG)!" << std::endl;
    std::cout << "Your total attack power is now: " << GetAttackDamage() << " (" << GetWeapon() << ")." << std::endl;
}

std::string Player::GetWeapon() const
{
    if (equipped_weapon != nullptr) return equipped_weapon->name;
    return "Fists";
}


void Player::Attack(Creature* target) {
    int moveRoll = std::rand() % 100;   // Decides Hit vs Miss
    bool hit = false;

    if (equipped_weapon == nullptr) {
        if (moveRoll < 95) {
            std::cout << "You punch " << target->name << " in his face!" << std::endl;
            hit = true;
        }
        else {
            std::cout << target->name << " avoids your punch!" << std::endl;
        }
    }
    else if (equipped_weapon->name == "sword") {
        if (moveRoll < 85) {
            std::cout << "You stuck the sword in " << target->name << " chest!" << std::endl;
            hit = true;
        }
        else {
            std::cout << target->name << " moves and you cut through the air!" << std::endl;
        }
    }
    else {
        if (moveRoll < 80) {
            std::cout << "A bolt hits " << target->name << "!" << std::endl;
            hit = true;
        }
        else {
            std::cout << "The bolt hits the floor. " << target->name << " laughs at you!" << std::endl;
        }
    }
    if (hit) {
        target->TakeDamage(this->GetAttackDamage());
    }
}



void Player::RestoreHealth(int amount)
{
    health = std::min(health + amount, max_health);
}

bool Player::Die()
{
    std::cout << R"(
     ____________________________________________________
    |                                                    |
    |                 You have been slain...             |
    |                      GAME OVER                     |
    |____________________________________________________|
        
                You where not brave enough ...)" << std::endl;

    return true;
}
