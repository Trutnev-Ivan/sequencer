#pragma once

#include "JsonParserState.h"
#include <iostream>

namespace json
{
    class EndState: public JsonParserState
    {
    public:
        EndState(std::stack<MetaInfo*>* stack);
        virtual JsonParserState* next(char c) override;
    };
}