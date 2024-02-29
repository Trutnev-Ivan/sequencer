#pragma once
#include "MetaInfo.h"
#include "ArrayItemInfo.h"
#include <vector>

class ArrayInfo: public MetaInfo
{
protected:
    std::vector<ArrayItemInfo*> items;
public:
    virtual PARSING_ELEMENT getType() override;
    void append(ArrayItemInfo* item);
    virtual std::string toString() override;
};