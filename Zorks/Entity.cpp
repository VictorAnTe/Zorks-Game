#include "Entity.h"

Entity::Entity(const std::string& name, const std::string& description, Entity* parent) :
    name(name), description(description), parent(parent) {
    type = EntityType::ENTITY; // Default type
}

Entity::~Entity() {}

void Entity::Update() {}