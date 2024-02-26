#pragma once

#include "JsonParserState.h"
#include "EndState.h"
#include "ObjectItemState.h"
#include "../meta/ObjectItemInfo.h"

class ObjectState: public JsonParserState
{
public:
    ObjectState(std::stack<MetaInfo*>* stack):
        JsonParserState(stack)
        {}

    virtual JsonParserState* next(char c) override;
};