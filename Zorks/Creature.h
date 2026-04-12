#ifndef CREATURE_H
#define CREATURE_H

#include "Entity.h"
#include "Room.h" // The criature is in a ROOM so it is necessary to add it

class Creature : public Entity {
public:
    // Constructor
    Creature(const std::string& name, const std::string& description, Entity* parent, int health_pts, int dmg);

    // Destructor (virtual because each kind of criature will have his own method)
    virtual ~Creature();

    // Where is the criature
    Room* location;

    virtual void Attack(Creature* target);
    virtual void TakeDamage(const int dmg);
    virtual int GetAttackDamage() const { return power; }
    virtual void RestoreHealth(int amount) { health = std::min(health + amount, max_health); }
    virtual bool Die();

    int GetHealth() const { return health; }

protected:
    int health;
    int max_health;
    int power;
};

#endif // CREATURE_H