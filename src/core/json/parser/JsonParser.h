#pragma once

#include <iostream>

#include <stack>
#include <fstream>
#include "../meta/MetaInfo.h"

#include "../items/ArrayItem.h"
#include "../items/BoolItem.h"
#include "../items/FloatItem.h"
#include "../items/IntItem.h"
#include "../items/ObjectItem.h"
#include "../items/StringItem.h"

#include "StartState.h"

class JsonParser
{
protected:
    MetaInfo* topElement;
    std::stack<MetaInfo*>* parsingElement;
    ArrayItem* parseArray(MetaInfo* item);
    ObjectItem* parseObject(MetaInfo* item);
    void deleteObject(MetaInfo* object);
    void deleteArray(MetaInfo* array);
public:
    JsonParser(std::ifstream* file);
    JsonParser(std::string json);
    ~JsonParser();
    ArrayItem* getArray();
    ObjectItem* getObject();
    bool isObject();
    bool isArray();
};