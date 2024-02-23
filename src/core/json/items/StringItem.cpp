#include "StringItem.h"

std::string StringItem::toString()
{
    return this->getValue();
}

std::ostream& operator<<(std::ostream& out, StringItem jsonItem)
{
    out << jsonItem.toString();
    return out;
}

std::ostream& operator<<(std::ostream& out, StringItem* jsonItem)
{
    out << jsonItem->toString();
    return out;
}