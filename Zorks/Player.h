#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"
#include "Item.h"

class Player : public Creature {
public:
    // Constructor
    Player(const std::string& name, const std::string& description, Room* location);

    // Destructor
    virtual ~Player();

    void EquipWeapon(Item* new_weapon, int new_dmg);
    std::string GetWeapon() const { if(equipped_weapon != nullptr) return equipped_weapon->name; }

    // Adding functions such as:
    // void AttackNPC(const std::string& npc_name)
    // bool UseItem(const std::string& item_name)

    

private:
    Item* equipped_weapon = nullptr;
    int weapon_damage;
};

#endif // PLAYER_H