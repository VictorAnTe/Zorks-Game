#include "Dracula.h"
#include <iostream>
#include <ctime> // For rand()

Dracula::Dracula(const std::string& name, const std::string& description, Entity* parent)
    : Creature(name, description, parent, 100, 20)
{
    this->type = EntityType::CREATURE;
    std::srand(static_cast<unsigned int>(std::time(0)));
}

void Dracula::Attack(Creature* target)
{
    // Dracula health
    float healthPercent = (static_cast<float>(this->health) / this->max_health) * 100.0f;

    int roll = std::rand() % 100;       // Decides Bite vs Bolt
    int moveRoll = std::rand() % 100;   // Decides Hit vs Miss
    int biteThreshold;

    // If Dracula health is under 35% is more probable to use Vampiric Bite attack
    if (healthPercent < 35.0f) {
        // Desperation Mode: 80% chance to Bite (0-79)
        biteThreshold = 80;
        std::cout << "Dracula's eyes glow with a feral hunger as he weakens!" << std::endl;
    }
    else {
        // Normal Mode: 50% chance to Bite (0-49)
        biteThreshold = 50;
    }


    if (roll < biteThreshold) {
        if (moveRoll < 90) {
            VampiricBite(target);
        }
        else {
            std::cout << "Dracula lunges for your throat, but trips on his cloak! (MISS)" << std::endl;
        }
    }
    else {
        if (moveRoll < 50) {
            ShadowBolt(target);
        }
        else {
            std::cout << "Dracula hurls a bolt of darkness, but it shatters harmlessly against the wall! (MISS)" << std::endl;
        }
    }
}


// Helper methods to keep Attack() clean
void Dracula::VampiricBite(Creature* target)
{
    std::cout << "Dracula sinks his fangs into your neck, draining your vitality!" << std::endl;
    target->TakeDamage(this->power);

    int heal = this->power / 2;
    this->health = std::min(this->health + heal, this->max_health);
    std::cout << "Dracula heals for " << heal << " HP." << std::endl;
}

void Dracula::ShadowBolt(Creature* target)
{
    std::cout << "Dracula unleashes a bolt of pure darkness!" << std::endl;
    target->TakeDamage(static_cast<int>(this->power * 2.5));
}

bool Dracula::Die()
{
    std::cout << R"(
     ____________________________________________________
    |                                                    |
    |              Dracula turns into dust...            |
    |              The castle is free now!!!             |
    |                     Victory!!!                     |
    |____________________________________________________|)" << std::endl;

    return true;
}
