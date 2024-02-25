#pragma once
#include "MetaInfo.h"
#include "ObjectItemInfo.h"
#include <vector>

class ObjectInfo: public MetaInfo
{
protected:
    std::vector<ObjectItemInfo*> items;
public:
    ObjectInfo(){};
    
    virtual PARSING_ELEMENT getType() override
    {
        return PARSING_ELEMENT::OBJECT;
    }

    void appendItem(ObjectItemInfo* item)
    {
        this->items.push_back(item);
    }

    std::vector<ObjectItemInfo*> getItems()
    {
        return this->items;
    }

    virtual std::string toString() override
    {
        std::string str = "{\n";

        for (ObjectItemInfo* item: this->items)
        {
            str += item->toString() + ",\n";
        }

        str += "}";

        return str;
    }
};