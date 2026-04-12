#ifndef TROLL_H
#define TROLL_H

#include "Creature.h"

class Troll : public Creature {
public:
    Troll(const std::string& name, const std::string& description, Entity* parent);
    
    // We design his own attacks
    void Attack(Creature* target);
    bool Die() override;

private:
    void NormalSmash(Creature* target);
    void HeavySmash(Creature* target);
    void Regenerate();
};

#endif