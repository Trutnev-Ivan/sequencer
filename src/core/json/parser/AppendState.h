#pragma once

#include "JsonParserState.h"
#include "ObjectItemState.h"
#include "ObjectState.h"
#include "../meta/ObjectItemInfo.h"
#include "../meta/ObjectInfo.h"

class AppendState: public JsonParserState
{
protected:
    JsonParserState* appendToObject(MetaInfo* metaInfo);
    JsonParserState* appendToObjectItem(MetaInfo* metaInfo);
public:
    AppendState(std::stack<MetaInfo*>* stack):
        JsonParserState(stack)
        {}

    virtual JsonParserState* next(char c) override
    {
        MetaInfo* metaInfo = this->parsingElement->top();
        this->parsingElement->pop();

        // TODO: добавить условие в массив

        switch (metaInfo->getType())
        {
            case PARSING_ELEMENT::OBJECT_ITEM:
                return this->appendToObject(metaInfo);
            default:
                return this->appendToObjectItem(metaInfo);
        }
    }
};