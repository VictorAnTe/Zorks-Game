#ifndef WORLD_H
#define WORLD_H

#include <list>
#include <string>
#include "Entity.h"
#include "Player.h"
#include "Puzzle.h"

class World {
public:
    std::list<Entity*> entities; // The vector with all the instancies
    std::vector<Puzzle*> puzzles; // The vector with all the puzzles
    Player* player;                // Fast pointer to avoid searching the player all the time

    World();  // Constructor
    ~World(); // Destructor

    bool game_over = false;

    void Update(const std::string& input); // Decides which function is needed to call

private:
    // Helpers
    void Look(const std::string& target_name = "") const;
    void Go(const std::string& direction);
    void Take(const std::string& item_name);
    void Drop(const std::string& item_name);
    void Inventory() const;
    void Equip(const std::string& item_name);
    void Battle(const std::string& enemy_name);
    void Use(const std::string& item_name);
    void Solve(const std::string& riddle_answer);
    void Open(const std::string& target_name);
    

    // Utils
    Entity* FindEntity(const std::string& name) const;
    std::vector<std::string> ParseCommand(const std::string& input) const;
};

#endif // WORLD_H