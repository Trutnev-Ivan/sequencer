#pragma once
#include "MetaInfo.h"
#include <vector>

class ArrayInfo: public MetaInfo
{
protected:
    std::vector<MetaInfo*> items;
public:
    virtual PARSING_ELEMENT getType() override 
    {
        return PARSING_ELEMENT::ARRAY;
    }

    void append(MetaInfo* item)
    {
        this->items.push_back(item);
    }

    virtual std::string toString() override
    {
        std::string str = "[";

        for (MetaInfo* item: this->items)
        {
            str += item->toString() + ", ";
        }

        str += "]";

        return str;
    }
};