#include "FloatItem.h"

std::string FloatItem::toString()
{
    return std::to_string(this->getValue());
}

std::ostream& operator<<(std::ostream& out, FloatItem floatItem)
{
    out << floatItem.toString();
    return out;
}

std::ostream& operator<<(std::ostream& out, FloatItem* floatItem)
{
    out << floatItem->toString();
    return out;
}