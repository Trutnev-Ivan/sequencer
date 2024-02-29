#include "JsonParserState.h"

JsonParserState::JsonParserState(std::stack<MetaInfo*>* stack)
{
    this->parsingElement = stack;
}

JsonParserState* JsonParserState::next(char c)
{
    return nullptr;
};

MetaInfo* JsonParserState::getTopElement()
{
    return this->topElement;
}