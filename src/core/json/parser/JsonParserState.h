#pragma once

#include <stack>
#include <cctype>
#include "../meta/MetaInfo.h"
#include "../exceptions/JsonAppendStateException.h"
#include "../exceptions/JsonParseException.h"
#include "../exceptions/JsonArrayItemStateException.h"
#include "../exceptions/JsonEmptyNextElementException.h"
#include "../exceptions/JsonNumberPointException.h"
#include "../exceptions/JsonObjectItemDelimiterException.h"
#include "../exceptions/JsonTopElementException.h"

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