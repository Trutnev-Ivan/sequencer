#pragma once
#include "MetaInfo.h"
#include "ObjectItemInfo.h"
#include <vector>

class ObjectInfo: public MetaInfo
{
protected:
    std::vector<ObjectItemInfo*> items;
public:
    virtual PARSING_ELEMENT getType() override;
    void appendItem(ObjectItemInfo* item);
    std::vector<ObjectItemInfo*> getItems();
    virtual std::string toString() override;
};