#include "Troll.h"
#include <iostream>

Troll::Troll(const std::string& name, const std::string& description, Entity* parent)
    : Creature(name, description, parent, 50, 15) // Health: 75, Power: 15
{
    this->type = EntityType::CREATURE;
}

void Troll::AttackMessage() const {
    std::cout << "The Troll swings its rotting club with devastating force!" << std::endl;
}