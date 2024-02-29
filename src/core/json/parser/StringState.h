#pragma once

#include "JsonParserState.h"
#include "AppendState.h"
#include "../meta/StringInfo.h"

class StringState: public JsonParserState
{
public:
    StringState(std::stack<MetaInfo*>* stack);
    virtual JsonParserState* next(char c) override;
};