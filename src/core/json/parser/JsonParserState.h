#pragma once

#include <stack>
#include <cctype>
#include <stdexcept>
#include "../meta/MetaInfo.h"

class StartState;
class ObjectState;
class ObjectItemState;
class StringState;
class AppendState;
class EndState;

class JsonParserState
{
protected:
    std::stack<MetaInfo*>* parsingElement;
    MetaInfo* topElement;
public:
    JsonParserState(std::stack<MetaInfo*>* stack)
    {
        this->parsingElement = stack;
    }

    virtual JsonParserState* next(char c)
    {
        return nullptr;
    };

    MetaInfo* getTopElement()
    {
        return this->topElement;
    }
};