#pragma once

#include <iostream>

#include "JsonParserState.h"
#include "StringState.h"
#include "AppendState.h"
#include "../meta/ObjectItemInfo.h"
#include "../meta/StringInfo.h"

class ObjectItemState: public JsonParserState
{
protected:
    bool isFilledKey = false;
    bool isFilledValue = false;
    bool hasDelimiter = false;

    void parseKey(char c);
    void parseDelimiter(char c);
    JsonParserState* parseValue(char c);
    JsonParserState* parseEnd(char c);

public:
    ObjectItemState(std::stack<MetaInfo*>* stack):
        JsonParserState(stack)
        {
            ObjectItemInfo* objectItemInfo = static_cast<ObjectItemInfo*>(this->parsingElement->top());

            if (objectItemInfo->getValue() != nullptr)
            {
                isFilledKey = true;
                isFilledValue = true;
                hasDelimiter = true;
            }
        }

    virtual JsonParserState* next(char c) override
    {
        if (!isFilledKey)
        {
            parseKey(c);
            return this;
        }
        else if (!hasDelimiter)
        {
            parseDelimiter(c);
            return this;
        }
        else if (!isFilledValue)
        {
            return parseValue(c);
        }
        else
        {
            return parseEnd(c);
        }
    }
};