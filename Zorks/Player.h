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

    Item* GetItem(const std::string& name);


    void UnequipWeapon();
    void EquipWeapon(Item* new_weapon, int new_dmg);
    std::string GetWeapon() const;
    void Attack(Creature* target);
    int GetAttackDamage() const override {
        return power + (equipped_weapon ? weapon_damage : 0);
    }
    void RestoreHealth(int amount) override; 
    bool Die() override;

private:
    Item* equipped_weapon = nullptr;
    int weapon_damage;
};

#endif // PLAYER_H