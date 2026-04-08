#ifndef CREATURE_H
#define CREATURE_H

#include "Entity.h"
#include "Room.h" // The criature is in a ROOM so it is necessary to add it

class Creature : public Entity {
public:
    // Constructor
    Creature(const std::string& name, const std::string& description, Room* location, int dmg = 0);

    // Destructor (virtual because each kind of criature will have his own method)
    virtual ~Creature();

    // Where is the criature
    Room* location;

    // Possible interesting methods
    void TakeDamage(const int dmg) { health = std::max(health - dmg, 0); }
    virtual void RestoreHealth(const int hp_rest);
    // virtual void Die();
    // virtual void MoveTo(Room* destination);

    int GetHealth() const { return health; }
    int GetPower() const { return power; }

protected:
    int health;
    int max_health;
    int power;
};

#endif // CREATURE_H