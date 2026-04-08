#ifndef ROOM_H
#define ROOM_H

#include "Entity.h"

class Room : public Entity {
public:
    // Constructor
    Room(const std::string& name, const std::string& description);

    // Destructor
    virtual ~Room();

    // In a future new version of the game the Room class could be the one who shows which
    // are their own exits to avoid World having to search all the exits of a ROOM when doing Look() function
    // void GetExits() const;
};

#endif // ROOM_H
