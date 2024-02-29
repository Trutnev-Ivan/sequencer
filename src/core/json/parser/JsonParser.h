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
    JsonParser(std::ifstream* file);
};