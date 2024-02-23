#pragma once
#include "JsonItem.h"

class IntItem: public JsonItem<int>
{
public:
    IntItem(int value):
        JsonItem(value)
        {}
    virtual std::string toString() override;
    friend std::ostream& operator<<(std::ostream& out, IntItem intItem);
    friend std::ostream& operator<<(std::ostream& out, IntItem* intItem);
};