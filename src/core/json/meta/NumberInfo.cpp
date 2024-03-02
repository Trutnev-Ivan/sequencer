#include "NumberInfo.h"

PARSING_ELEMENT NumberInfo::getType()
{
    return PARSING_ELEMENT::NUMBER;
}

void NumberInfo::appendChar(char c)
{
    if (!std::isdigit(c) && c != '.')
        throw JsonParseException(c);

    this->value += c;
}

std::string NumberInfo::getValue()
{
    return this->value;
}

std::string NumberInfo::toString()
{
    return this->getValue();
}