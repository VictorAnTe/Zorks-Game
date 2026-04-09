#include "KeyItem.h"
#include "Exit.h"

KeyItem::KeyItem(const std::string& name, const std::string& description, Entity* parent, Exit* ex) :
    Item(name, description, parent)    
{
    this->item_type = ItemType::KEY;
    door_it_opens = ex;
}

KeyItem::~KeyItem() {}