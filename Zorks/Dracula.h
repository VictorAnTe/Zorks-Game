#ifndef DRACULA_H
#define DRACULA_H

#include "Creature.h"

class Dracula : public Creature {
public:
    Dracula(const std::string& name, const std::string& description, Entity* parent);

    // We design his own attacks
    void Attack(Creature* target);

private:
    void VampiricBite(Creature* target);
    void ShadowBolt(Creature* target);
};

#endif