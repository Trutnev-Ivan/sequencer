#pragma once
#include "JsonItem.h"

class FloatItem: public JsonItem<float>
{
public:
    FloatItem(float value):
        JsonItem<float>(value)
        {}
    virtual std::string toString() const override;
    friend std::ostream& operator<<(std::ostream& out, const FloatItem& floatItem);
    friend std::ostream& operator<<(std::ostream& out, const FloatItem* floatItem);
};