#pragma once

#include "JsonParserState.h"
#include "EndState.h"
#include "ObjectItemState.h"
#include "AppendState.h"
#include "../meta/ObjectItemInfo.h"

class ObjectState: public JsonParserState
{
public:
    ObjectState(std::stack<MetaInfo*>* stack);
    virtual JsonParserState* next(char c) override;
};