#include "BoolItem.h"

std::string BoolItem::toString()
{
    if (this->getValue())
        return "true";

    return "false";
}

std::ostream& operator<<(std::ostream& out, BoolItem boolItem)
{
    out << boolItem.toString();
    return out;
}

std::ostream& operator<<(std::ostream& out, BoolItem* boolItem)
{
    out << boolItem->toString();
    return out;
}