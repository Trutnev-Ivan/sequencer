#pragma once

#include "JsonParserState.h"
#include <iostream>

class EndState: public JsonParserState
{
public:
    EndState(std::stack<MetaInfo*>* stack):
        JsonParserState(stack)
        {
            this->topElement = this->parsingElement->top();
            this->parsingElement->pop();
        }

    virtual JsonParserState* next(char c) override
    {
        if (std::isspace(c) || c == EOF)
            return this;

        throw new std::runtime_error("Invalid end char: " + c); // TODO: change error
    }
};