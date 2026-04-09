#ifndef KEYITEM_H
#define KEYITEM_H

#include "Item.h"

class Exit; // Forward declaration

class KeyItem : public Item {
public:
    KeyItem(const std::string& name, const std::string& description, Entity* parent = nullptr, Exit* opens = nullptr);
    virtual ~KeyItem();

    Exit* door_it_opens;
};

#endif //KEYITEM_H