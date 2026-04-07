#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <string>
#include "Entity.h"
#include "Player.h"

class World {
public:
    std::vector<Entity*> entities; // The vector with all the instancies
    Player* player;                // Fast pointer to avoid searching the player all the time

    World();  // Constructor
    ~World(); // Destructor

    void Update(const std::string& input); // Decides which function is needed to call

private:
    // Helpers
    void Look(const std::string& target_name = "") const;
    void Go(const std::string& direction);
    void Take(const std::string& item_name);
    void Drop(const std::string& item_name);
    void Inventory() const;

    // Utils
    Entity* FindEntity(const std::string& name) const;
    std::vector<std::string> ParseCommand(const std::string& input) const;
};

#endif