#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"

class Player : public Creature {
public:
    // Constructor
    Player(const std::string& name, const std::string& description, Room* location);

    // Destructor
    virtual ~Player();

    // Adding functions such as:
    // void AttackNPC(const std::string& npc_name)
    // bool UseItem(const std::string& item_name)
    // string GetWeapon() const
    

    // private string weapon_name;
};

#endif // PLAYER_H