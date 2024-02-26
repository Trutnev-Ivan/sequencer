#pragma once

#include "JsonParserState.h"
#include "ObjectState.h"
#include "../meta/ObjectInfo.h"
#include "../meta/ArrayInfo.h"

class StartState: public JsonParserState
{
public:
    StartState(std::stack<MetaInfo*>* stack):
        JsonParserState(stack)
        {}

    virtual JsonParserState* next(char c) override
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
            return nullptr;
            //TODO: добавить обработку массива
        }
        else
        {
            throw new std::runtime_error("Invalid start char: "+ c); // TODO: change exception
        }
    };
};