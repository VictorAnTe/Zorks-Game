#ifndef CONTAINER_H
#define CONTAINER_H
#include "Item.h"

class Container : public Item {
public:
    Container(const std::string& name, const std::string& description, Entity* parent = nullptr);
    virtual ~Container();
};

#endif // CONTAINER_H