#ifndef CONTAINER_H
#define CONTAINER_H
#include "Item.h"

class Container : public Item {
public:
    Container(const std::string& name, const std::string& description, Entity* parent = nullptr);
    virtual ~Container();

    void Put(Entity* item);
    Entity* Remove(const std::string& item_name);
};

#endif // CONTAINER_H