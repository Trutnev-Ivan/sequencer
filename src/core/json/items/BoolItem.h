#pragma once
#include "JsonItem.h"

class BoolItem: public JsonItem<bool>
{
public:
    BoolItem(bool value):
        JsonItem<bool>(&value)
        {}
    virtual std::string toString() override;
    friend std::ostream& operator<<(std::ostream& out, BoolItem boolItem);
    friend std::ostream& operator<<(std::ostream& out, BoolItem* boolItem);
};