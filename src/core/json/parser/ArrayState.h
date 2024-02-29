#pragma once
#include "JsonParserState.h"
#include "EndState.h"
#include "StringState.h"
#include "ObjectState.h"
#include "../meta/ArrayItemInfo.h"
#include "../meta/StringInfo.h"
#include "../meta/ObjectInfo.h"

class ArrayState: public JsonParserState
{
public:
    ArrayState(std::stack<MetaInfo*>* stack);
    virtual JsonParserState* next(char c) override;
};