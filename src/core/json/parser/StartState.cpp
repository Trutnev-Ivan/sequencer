#include "StartState.h"

StartState::StartState(std::stack<MetaInfo*>* stack):
    JsonParserState(stack)
    {}

JsonParserState* StartState::next(char c)
{
    if (std::isspace(c))
        return this;

    if (c == '{')
    {
        this->parsingElement->push(new ObjectInfo);
        return new ObjectState(this->parsingElement);
    }
    else if (c == '[')
    {
        this->parsingElement->push(new ArrayInfo);
        return new ArrayState(this->parsingElement);
    }
    else
    {
        throw new std::runtime_error("Invalid start char: "+ c); // TODO: change exception
    }
};