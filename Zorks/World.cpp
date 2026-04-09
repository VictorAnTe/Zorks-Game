#include <iostream>
#include <sstream>
#include <algorithm>
#include "World.h"
#include "Room.h"
#include "Exit.h"
#include "Item.h"
#include "KeyItem.h"
#include "ConsumableItem.h"
#include "WeaponItem.h"
#include "Puzzle.h"


// Constructor
World::World() {
    // Create ROOMs
    Room* livingRoom = new Room("Livingroom", "A cozy living room. The start of your journey.");
    Room* bathroom = new Room("Bathroom", "A clean bathroom. You see some bandages here.");
    Room* garden = new Room("Garden", "A large garden. You can see the forest to the North.");
    Room* forest = new Room("Forest", "A dark and scary forest. A Troll blocks the way North!");
    Room* shed = new Room("Shed", "A small wooden shed. It's very quiet here.");
    Room* castleEntry = new Room("Castle Entry", "The massive gates of the castle stand before you.");
    Room* insideCastle = new Room("Inside Castle", "Dracula's throne room. There is no escape!");

    // Add ROOMs to the global memory vector
    entities.push_back(livingRoom);
    entities.push_back(bathroom);
    entities.push_back(garden);
    entities.push_back(forest);
    entities.push_back(shed);
    entities.push_back(castleEntry);
    entities.push_back(insideCastle);


    // Create EXITs
    // Livingroom -> Garden (North)
    Exit* ex1 = new Exit("north", "A wooden door", "north", garden);
    livingRoom->contains.push_back(ex1);
    entities.push_back(ex1);

    // Livingroom -> Bathroom (East)
    Exit* ex2 = new Exit("east", "A glass door", "east", bathroom);
    livingRoom->contains.push_back(ex2);
    entities.push_back(ex2);

    // Bathroom -> Livingroom (West)
    Exit* ex3 = new Exit("west", "The livingroom of the house", "west", livingRoom);
    bathroom->contains.push_back(ex3);
    entities.push_back(ex3);

    // Garden -> Forest (North)
    Exit* ex4 = new Exit("north", "A narrow path", "north", forest);
    garden->contains.push_back(ex4);
    entities.push_back(ex4);

    // Garden -> castleEntry (West)
    Exit* ex5 = new Exit("west", "A cobbled path", "west", castleEntry);
    garden->contains.push_back(ex5);
    entities.push_back(ex5);

    // Garden -> Livingroom (South)
    Exit* ex6 = new Exit("south", "The livingroom of the house", "south", livingRoom);
    garden->contains.push_back(ex6);
    entities.push_back(ex6);

    // Forest -> Shed (North)
    Exit* ex7 = new Exit("north", "A gloomy shed", "north", shed);
    forest->contains.push_back(ex7);
    entities.push_back(ex7);

    // Forest -> Garden (South)
    Exit* ex8 = new Exit("south", "The garden", "south", garden);
    forest->contains.push_back(ex8);
    entities.push_back(ex8);

    // Shed -> Forest (South)
    Exit* ex9 = new Exit("south", "The forest", "south", forest);
    shed->contains.push_back(ex9);
    entities.push_back(ex9);

    // CastleEntry -> InsideCastle (West)
    Exit* ex10 = new Exit("west", "The castle door", "west", insideCastle);
    castleEntry->contains.push_back(ex10);
    entities.push_back(ex10);

    // CastleEntry -> Garden (East)
    Exit* ex11 = new Exit("east", "The garden", "east", garden);
    castleEntry->contains.push_back(ex11);
    entities.push_back(ex11);
    

    // Blocking EXITs
    ex7->locked = true; // You need to defeat Troll and Wood_Key
    ex10->locked = true; // You need to solve a miniPuzzle


    // Create PUZZLE
    std::string dracula_riddle = "I live in a castle, but I am not a king.\n"
        "I drink red liquid, but I am not a nurse.\n"
        "I sleep in a coffin, but I am not dead.\n"
        "Who am I?";

    Puzzle* castle_puzzle = new Puzzle(dracula_riddle, "dracula", ex10);

    puzzles.push_back(castle_puzzle);


    // Create ITEMs

    // - Keys (Linked to their specific exits)
    Item* woodKey = new KeyItem("wood_key", "An old wooden key.", livingRoom, ex7);

    // - Consumables (Name, Description, Parent, HP_Bonus)
    Item* apple = new ConsumableItem("apple", "A crunchy red apple (+10 HP).", livingRoom, 10);
    Item* bandages = new ConsumableItem("bandages", "Medical bandages for healing (+40 HP).", bathroom, 40);

    // - Weapons (Name, Description, Parent, DMG_Bonus)
    Item* sword = new WeaponItem("sword", "A sharp steel sword (+15 DMG).", garden, 15);
    Item* spellsBook = new WeaponItem("spells_book", "A book glowing with ancient magic (+25 DMG).", shed, 25);

    // Add ITEMs to the global memory vector
    entities.push_back(woodKey);
    entities.push_back(apple);
    entities.push_back(bandages);
    entities.push_back(sword);
    entities.push_back(spellsBook);

    // Add ITEMs to contains list of ROOMs
    livingRoom->contains.push_back(woodKey);
    livingRoom->contains.push_back(apple);
    bathroom->contains.push_back(bandages);
    garden->contains.push_back(sword);
    shed->contains.push_back(spellsBook);


    // Create NPCs
    Creature* troll = new Creature("troll", "A massive and stinky troll blocking the way.", forest, 10);
    Creature* dracula = new Creature("dracula", "The ancient vampire lord.", insideCastle, 20);

    // Add NPCs to the global memory vector
    entities.push_back(troll);
    entities.push_back(dracula);

    // Add NPCs to contains list of ROOMs
    forest->contains.push_back(troll);
    insideCastle->contains.push_back(dracula);


    // Create Player
    player = new Player("Hero", "The main character of this story", livingRoom);
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

    for (Puzzle* p : puzzles) {
        delete p;
    }
    puzzles.clear();
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
        else std::cout << "You need to specify where do you want to go (north, east, south, east)" << std::endl;
    }
    else if (action == "get") {
        if (args.size() > 1) Take(args[1]);
        else std::cout << "You need to specify what do you want to pick" << std::endl;
    }
    else if (action == "drop") {
        if (args.size() > 1) Drop(args[1]);
        else std::cout << "You need to specify what do you want to drop?" << std::endl;
    }
    else if (action == "inventory") {
        Inventory();
    }
    else if (action == "equip") {
        if (args.size() > 1) Equip(args[1]);
        else std::cout << "You need to specify what do you want to equip?" << std::endl;
    }
    else if (action == "battle") {
        if (args.size() > 1) Battle(args[1]);
        else std::cout << "You need to specify who do you want to battle with" << std::endl;
    }
    else if (action == "use") {
        if (args.size() > 1) Use(args[1]);
        else std::cout << "You need to specify what do you want to use from hero inventory" << std::endl;
    }
    else if (action == "solve") {
        if (args.size() > 1) Solve(args[1]); // Answering the riddle
        else Solve(""); // Showing the riddle
    }
    else {
        std::cout << "This command is not registered. The options are:" << std::endl;
        std::cout << "   - look: To get information about the room you are." << std::endl;
        std::cout << "   - look {{item_name}}: To get information about that item." << std::endl;
        std::cout << "   - go {{cardinal direction}}: To move to the exit of the room in that direction." << std::endl;
        std::cout << "   - get {{item_name}}: To pick the object specified from the floor." << std::endl;
        std::cout << "   - drop {{item_name}}: To leave an object from your inventory." << std::endl;
        std::cout << "   - inventory: Shows all the items from the hero inventory." << std::endl;
        std::cout << "   - equip {{item_name}}: To equip something from the hero inventory." << std::endl;
        std::cout << "   - battle {{npc_name}}: To battle someone in the currently room." << std::endl;
        std::cout << "   - use {{item_name}}: To use something from the hero inventory." << std::endl;
        std::cout << "   - solve: To get information about the riddle from the currently room." << std::endl;
        std::cout << "   - solve {{riddle solution}}: To answer the riddle from the currently room." << std::endl;
        std::cout << "   - quit: To close the game." << std::endl;
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
    // Search if this direction exists in this room
    Entity* e = FindEntity(direction);

    // Validating that it is an EXIT
    if (e == nullptr || e->type != EntityType::EXIT) {
        std::cout << "You can't go '" << direction << "'. There is no exit there." << std::endl;
        return;
    }

    Exit* ex = (Exit*)e;

    // If there is an enemy you have to defeat it first
    for (Entity* roomEntity : player->location->contains) {
        if (roomEntity->type == EntityType::CREATURE && roomEntity != player) {
            std::cout << "The " << roomEntity->name << " blocks your way! You must defeat it first." << std::endl;
            return;
        }
    }

    // Block EXITs gestor
    if (ex->locked) {
        bool key_found = false;

        for (Entity* inv_item : player->contains) {
            // We try to convert the ITEM to a KEYITEM
            KeyItem* key = dynamic_cast<KeyItem*>(inv_item);

            // We verify if it is a key && if it opens a door
            if (key != nullptr && key->door_it_opens == ex) {
                std::cout << "You use the " << key->name << " to unlock the way!" << std::endl;
                ex->locked = false;
                key_found = true;
                break;
            }
        }

        if (!key_found) {
            if (ex->destination->name == "Inside Castle") {
                std::cout << "The castle gate is sealed by magic. You must solve the puzzle first!" << std::endl;
                // Here there is no key, unlock with "Solve" function
            }
            else {
                std::cout << "The way is locked and you don't have the right key." << std::endl;
            }
            return;
        }
    }

    // Moving the PLAYER
    // Remove from the currently ROOM
    player->location->contains.remove(player);

    // Adding to next ROOM
    player->location = ex->destination; 
    player->location->contains.push_back(player);

    // Look of the next room
    std::cout << "You walk towards the " << direction << "..." << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    Look();
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


void World::Equip(const std::string& item_name) {
    Entity* e = FindEntity(item_name);

    // We try to convert it to a Weapon ITEM
    WeaponItem* weapon = dynamic_cast<WeaponItem*>(e);

    if (weapon != nullptr) {
        player->EquipWeapon(weapon, weapon->damage_bonus);
    }
    else {
        std::cout << "The " << item_name << " is not a weapon you can equip!" << std::endl;
    }
}


void World::Battle(const std::string& enemy_name) {
    Creature* enemy = nullptr;

    // Search de NPCs in the currently ROOM
    for (Entity* e : player->location->contains) {
        if (e->type == EntityType::CREATURE && e->name == enemy_name) {
            enemy = (Creature*)e;
            break;
        }
    }

    if (enemy == nullptr || enemy == player) {
        std::cout << "There is no " << enemy_name << " here to attack." << std::endl;
        return;
    }

    // Turn by Turn combat
    std::cout << "\n--- COMBAT! ---" << std::endl;

    // Player attacks first
    std::cout << "You attack the " << enemy->name << " for " << player->GetPower() << " damage!" << std::endl;
    enemy->TakeDamage(player->GetPower());

    if (enemy->GetHealth() <= 0) {
        std::cout << "The " << enemy->name << " has been defeated!" << std::endl;

        //Dracula defeat logic: If you defeat Dracula, you win the game
        if (enemy->name == "dracula") {
            game_over = true;
            std::cout << "\n*** VICTORY! Dracula has fallen. The castle is free! ***" << std::endl;
        }

        // Delete enemy from the ROOM but not from entities to avoid memory problems
        player->location->contains.remove(enemy);
    }
    else {
        // Enemy attack
        std::cout << "The " << enemy->name << " counter-attacks! You lose " << enemy->GetPower() << " HP." << std::endl;
        player->TakeDamage(enemy->GetPower());

        if (player->GetHealth() <= 0) {
            game_over = true;
            std::cout << "You have been slain... GAME OVER." << std::endl;
        }
        else {
            std::cout << "Your HP: " << player->GetHealth() << " | " << enemy->name << " HP: " << enemy->GetHealth() << std::endl;
        }
    }
}


void World::Use(const std::string& item_name) {
    Entity* e = FindEntity(item_name);
    ConsumableItem* consumable = dynamic_cast<ConsumableItem*>(e);

    if (consumable != nullptr) {
        player->RestoreHealth(consumable->hp_bonus);
        std::cout << "You used the " << consumable->name << " and restored " << consumable->hp_bonus << " HP." << std::endl;

        // Memory cleaning
        player->contains.remove(consumable);
        entities.remove(consumable);
        delete consumable;
    }
    else {
        std::cout << "You can't eat/use the " << item_name << "!" << std::endl;
    }
}


void World::Solve(const std::string& riddle_answer) {
    // Si no hay puzzles en el mundo
    if (puzzles.empty()) {
        std::cout << "There is nothing to resolve here." << std::endl;
        return;
    }

    // In a game with more puzzles I will filter by ROOM
    Puzzle* current_puzzle = puzzles[0];

    if (riddle_answer.empty()) {
        std::cout << "\n--- THE CASTLE RIDDLE ---" << std::endl;
        std::cout << current_puzzle->GetQuestion() << std::endl;
        std::cout << "(Type: solve [answer])" << std::endl;
    }
    else {
        if (current_puzzle->CheckSolution(riddle_answer)) {
            std::cout << "\n[!] The magic seal shatters! The castle gates open slowly..." << std::endl;
        }
        else {
            std::cout << "That is not the correct answer. The shadows laugh at you..." << std::endl;
        }
    }
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