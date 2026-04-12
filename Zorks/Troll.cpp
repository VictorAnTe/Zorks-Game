#include "Troll.h"
#include <iostream>

Troll::Troll(const std::string& name, const std::string& description, Entity* parent)
    : Creature(name, description, parent, 50, 15) // Health: 75, Power: 15
{
    this->type = EntityType::CREATURE;
}

void Troll::Attack(Creature* target) {
    // Regenerative roll
    int regenRoll = std::rand() % 100;
    if (regenRoll < 30) {
        Regenerate();
    }
    else {
        // Attack logic
        int attackRoll = std::rand() % 100;

        if (attackRoll < 40) {
            // Massive Attack
            HeavySmash(target);
        }
        else if (attackRoll < 80) {
            // Normal Attack
            NormalSmash(target);
        }
        else {
            // Fallo: 20% de probabilidad
            std::cout << "The Troll roars and swings, but you easily step aside." << std::endl;
        }
    }
}

void Troll::Regenerate() {
    int healAmount = 15;
    this->health = std::min(this->health + healAmount, this->max_health);
    std::cout << "The Troll's disgusting green skin bubbles and knits together. It heals " << healAmount << " HP!" << std::endl;
}

void Troll::NormalSmash(Creature* target) {
    int hitRoll = std::rand() % 100;

    // The normal attack only hits a 80% of the times
    if (hitRoll < 80) {
        std::cout << "The Troll swings its massive fist at you!" << std::endl;
        target->TakeDamage(this->power);
    }
    else {
        std::cout << "The Troll smashes its club into the ground, narrowly missing you!" << std::endl;
    }
}

void Troll::HeavySmash(Creature* target) {
    int hitRoll = std::rand() % 100;

    // The heavy attack only hits a 40% of the times
    if (hitRoll < 40) {
        std::cout << "The Troll brings its heavy club down on you with a bone-crunching noise!" << std::endl;
        target->TakeDamage(static_cast<int>(this->power * 2.0));
    }
    else {
        std::cout << "The Troll smashes its club into the ground, narrowly missing you!" << std::endl;
    }
}

bool Troll::Die() {
    std::cout << "The massive troll collapses, shaking the ground!" << std::endl;
    if (location) {
        location->description = "A dark and scary forest where you defeated the massive troll.";
        location->contains.remove(this);
    }

    return false;
}