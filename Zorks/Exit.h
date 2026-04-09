#ifndef EXIT_H
#define EXIT_H

#include "Entity.h"
#include "Room.h"

class Exit : public Entity {
public:
    Exit(const std::string& name, const std::string& description, const std::string& direction, Room* destination);
    virtual ~Exit();

    std::string direction;
    Room* destination;

    bool locked = false;
};

#endif
