#pragma once

#include <iostream>

#include <stack>
#include <fstream>
#include "../meta/MetaInfo.h"

#include "StartState.h"

class JsonParser
{
protected:
    std::stack<MetaInfo*>* parsingElement;
public:
    JsonParser(std::ifstream* file)
    {
        this->parsingElement = new std::stack<MetaInfo*>;

        JsonParserState* state = new StartState(this->parsingElement);

        while (!file->eof())
        {
            char c = file->get();

            state = state->next(c);
        }

        std::cout << state->getTopElement()->toString() << std::endl;
        delete state;
    }
};