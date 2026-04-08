#ifndef CREATURE_H
#define CREATURE_H

#include "Entity.h"
#include "Room.h" // The criature is in a ROOM so it is necessary to add it

class Creature : public Entity {
public:
    // Constructor
    Creature(const std::string& name, const std::string& description, Room* location);

    // Destructor (virtual because each kind of criature will have his own method)
    virtual ~Creature();

    // Where is the criature
    Room* location;

    // Possible interesting methods
    // virtual void Die();
    // virtual void MoveTo(Room* destination);
};

#endif // CREATURE_H