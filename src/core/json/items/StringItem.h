#pragma once

#include "JsonItem.h"

class StringItem: public JsonItem<std::string>
{
public:
    StringItem(std::string value):
        JsonItem<std::string>(value)
    {}
    virtual std::string toString() override;
    friend std::ostream& operator<<(std::ostream& out, StringItem jsonItem);
    friend std::ostream& operator<<(std::ostream& out, StringItem* jsonItem);
};