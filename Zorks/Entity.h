#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <list>
#include <vector>

// Enumeration to identify the type of entity without using expensive dynamic_cast
enum class EntityType {
    ENTITY,
    ROOM,
    EXIT,
    ITEM,
    CREATURE,
    PLAYER,
    NPC
};

class Entity {
public:
    // Constructor
    Entity(const std::string& name, const std::string& description, Entity* parent = nullptr);

    // Virtual destructor
    virtual ~Entity();

    // Basic attributes
    std::string name;
    std::string description;
    EntityType type;

    // Pointer to the location of the entity
    Entity* parent;

    // List of the Entities that are in this Entity (for ROOM and an ITEM that is use as a chest)
    std::list<Entity*> contains;

public:
    // Virtual method if they need specific update logic
    virtual void Update();
};

#endif // ENTITY_H
