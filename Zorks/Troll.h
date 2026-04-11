#ifndef TROLL_H
#define TROLL_H

#include "Creature.h"

class Troll : public Creature {
public:
    Troll(const std::string& name, const std::string& description, Entity* parent);

    // Each enemy has his own attack message
    void AttackMessage() const;
};

#endif