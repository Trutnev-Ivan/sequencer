#include "IntItem.h"

std::string IntItem::toString()
{
    return std::to_string(this->getValue());
}

std::ostream& operator<<(std::ostream& out, IntItem intItem)
{
    out << intItem.toString();
    return out;
}

std::ostream& operator<<(std::ostream& out, IntItem* intItem)
{
    out << intItem->toString();
    return out;
}