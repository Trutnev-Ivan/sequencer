#pragma once

#include <stack>
#include <cctype>
#include <stdexcept>
#include "../meta/MetaInfo.h"

class StartState;
class ObjectState;
class ObjectItemState;
class ArrayState;
class ArrayItemState;
class StringState;
class AppendState;
class EndState;

class JsonParserState
{
protected:
    std::stack<MetaInfo*>* parsingElement;
    MetaInfo* topElement;
public:
    JsonParserState(std::stack<MetaInfo*>* stack);
    virtual JsonParserState* next(char c);
    MetaInfo* getTopElement();
};