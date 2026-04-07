#include <iostream>
#include <sstream>
#include <algorithm>
#include "World.h"
#include "Room.h"
#include "Exit.h"
#include "Item.h"


// Constructor
World::World() {
    // Create rooms
    Room* house = new Room("House", "You are in a small but cozy house. There is a door at north.");
    Room* garden = new Room("Garden", "A garden plenty of flowers. At north you can see a forest and to the south is the house.");
    Room* forest = new Room("Forest", "A dense forest. You can only go to the south, back to the garden.");

    // Add to the global memory vector
    entities.push_back(house);
    entities.push_back(garden);
    entities.push_back(forest);

    // Create Exits
    // House -> Garden (North)
    Exit* ex1 = new Exit("north", "A wooden door", "north", garden);
    house->contains.push_back(ex1);
    entities.push_back(ex1);

    // Garden -> House (South)
    Exit* ex2 = new Exit("south", "The house entrance", "south", house);
    garden->contains.push_back(ex2);
    entities.push_back(ex2);

    // Garden -> Forest (North)
    Exit* ex3 = new Exit("north", "A narrow path", "north", forest);
    garden->contains.push_back(ex3);
    entities.push_back(ex3);

    // Forest -> Garden (South)
    Exit* ex4 = new Exit("south", "The way back", "south", garden);
    forest->contains.push_back(ex4);
    entities.push_back(ex4);

    // Creating Player
    player = new Player("Hero", "The main character of this story", house);
    entities.push_back(player);

    // Mensaje inicial
    std::cout << "--- WELCOME TO ZORKS ---\n" << std::endl;
    Look();
}


// Destructor
World::~World() {
    for (Entity* e : entities) {
        delete e;
    }
    entities.clear();
}


// Update
void World::Update(const std::string& input) {
    std::vector<std::string> args = ParseCommand(input);
    if (args.empty()) return;

    std::string action = args[0];

    if (action == "look") {
        if (args.size() > 1) {
            // With an argument: look sword, look hero, look north
            Look(args[1]);
        }
        else {
            // Without argument
            Look();
        }
    }
    else if (action == "go") {
        if (args.size() > 1) Go(args[1]);
        else std::cout << "Where do you wanna go?" << std::endl;
    }
    else if (action == "get") {
        if (args.size() > 1) Take(args[1]);
        else std::cout << "What do you wanna pick?" << std::endl;
    }
    else if (action == "drop") {
        if (args.size() > 1) Drop(args[1]);
        else std::cout << "What do you wanna drop?" << std::endl;
    }
    else if (action == "inventory") {
        Inventory();
    }
    else {
        std::cout << "This command is not registered. The options are:" << std::endl;
        std::cout << "   - look: To get information about the room you are." << std::endl;
        std::cout << "   - look {{item_name}}: To get information about that item." << std::endl;
        std::cout << "   - go {{cardinal direction}}: To move to the exit of the room in that direction." << std::endl;
        std::cout << "   - get {{item_name}}: To pick the object specified from the floor." << std::endl;
        std::cout << "   - drop {{item_name}}: To leave an object from your inventory." << std::endl;
        std::cout << "   - inventory: Shows all the items from the hero inventory." << std::endl;
    }
}



// PRIVATE METHODS

void World::Look(const std::string& target_name) const {
    if (target_name.empty()) {
        std::cout << "\n[" << player->location->name << "]" << std::endl;
        std::cout << player->location->description << std::endl;

        // List of exits
        std::cout << "Exits: ";
        for (Entity* e : player->location->contains) {
            if (e->type == EntityType::EXIT) {
                std::cout << "(" << ((Exit*)e)->direction << ") ";
            }
        }
        std::cout << "\n" << std::endl;

        // List of objects in the room
        std::cout << "Items here: ";
        bool itemsFound = false;
        for (Entity* e : player->location->contains) {
            if (e->type == EntityType::ITEM) {
                std::cout << "\n - A " << e->name << ": " << e->description;
                itemsFound = true;
            }
        }

        if (!itemsFound) {
            std::cout << "None.";
        }

        std::cout << "\n" << std::endl;
    }
    else {
        Entity* target = FindEntity(target_name);
        if (target != nullptr) {
            std::cout << target->description << std::endl;
        }
        else {
            std::cout << "You don't see any '" << target_name << "' here." << std::endl;
        }
    }
}


void World::Go(const std::string& direction) {
    // We search if this direction exists in this room
    Entity* e = FindEntity(direction);

    // If it is not null and is and exit type it means
    // that it is a real exit of the room
    if (e != nullptr && e->type == EntityType::EXIT) {
        Exit* ex = (Exit*)e;
        player->location = ex->destination;
        Look();
        return;
    }

    // If it isn't an exit or it doesn't exists
    std::cout << "You can't go to the " << direction << ", there is no exit." << std::endl;
}


void World::Take(const std::string& item_name) {
    // Use FindEntity to see if the object exists
    Entity* item = FindEntity(item_name);

    // It doesn't exists in the room
    if (item == nullptr) {
        std::cout << "There is no '" << item_name << "' here." << std::endl;
        return;
    }

    // It is not an item so it can't be pick up
    if (item->type != EntityType::ITEM) {
        std::cout << "You cannot pick up the " << item_name << "!" << std::endl;
        return;
    }

    // Check if the item is already in the "inventory" of the player
    for (Entity* e : player->contains) {
        if (e == item) {
            std::cout << "You are already carrying the " << item_name << "." << std::endl;
            return;
        }
    }

    // If we reach here it means the item is in the room, so I erase 
    // from the room and add to the player "inventory"
    for (auto it = player->location->contains.begin(); it != player->location->contains.end(); ++it) {
        if (*it == item) {
            player->location->contains.erase(it); // Remove from room
            player->contains.push_back(item);     // Add to player
            std::cout << "You pick up the " << item_name << "." << std::endl;
            return;
        }
    }
}


void World::Drop(const std::string& item_name) {
    // Use FindEntity to see if the object exists
    Entity* item = FindEntity(item_name);

    // It doesn't exists in the player "inventory" or the room
    if (item == nullptr) {
        std::cout << "You don't have any '" << item_name << "'." << std::endl;
        return;
    }

    // It is not an item so it can't be dropped
    if (item->type != EntityType::ITEM) {
        std::cout << "You cannot drop that!" << std::endl;
        return;
    }

    // We have to see if the object is in the player "inventory" to
    // erase it and add to the room "contains" list
    for (auto it = player->contains.begin(); it != player->contains.end(); ++it) {
        if (*it == item) {
            // 4. Move the pointer from player to the current room
            player->contains.erase(it);
            player->location->contains.push_back(item);

            std::cout << "You drop the " << item_name << " on the floor." << std::endl;
            return;
        }
    }

    // If we reach here, it means FindEntity found it in the room, not the "inventory"
    std::cout << "You are not carrying the " << item_name << ". It is already on the floor." << std::endl;
}


void World::Inventory() const {
    std::cout << "Inventory: ";

    // If the player doesn't have items
    if (player->contains.empty()) {
        std::cout << "Your inventory is empty." << std::endl;
        return;
    }

    // The first is to avoid putting a ',' before first item name
    bool first = true;
    for (Entity* e : player->contains) {
        if (e->type == EntityType::ITEM) {
            if (!first) std::cout << ", ";
            std::cout << e->name;
            first = false;
        }
    }
    std::cout << std::endl;
}



// HELPERS METHODS

Entity* World::FindEntity(const std::string& name) const {
    // Is in the room??
    for (Entity* e : player->location->contains) {
        if (e->name == name) {
            return e;
        }
    }

    // Is in the player "inventory"???
    for (Entity* e : player->contains) {
        if (e->name == name) {
            return e;
        }
    }

    // Is the own player (in case of "look hero")
    if (player->name == name) {
        return player;
    }

    // The object doesn't exists
    return nullptr;
}


std::vector<std::string> World::ParseCommand(const std::string& input) const {
    std::vector<std::string> tokens;
    std::stringstream ss(input);
    std::string temp;
    while (ss >> temp) {
        // Convert to lowercase to easy comparation
        std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        tokens.push_back(temp);
    }
    return tokens;
}