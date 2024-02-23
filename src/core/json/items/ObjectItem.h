#pragma once

#include <map>
#include <tuple>
#include "JsonItem.h"

class ObjectItem: public JsonItem<std::map<std::string, std::tuple<const std::type_info&, void*>>*>
{
public:
    ObjectItem():
    JsonItem<std::map<std::string, std::tuple<const std::type_info&, void*>>*>(
        new std::map<std::string, std::tuple<const std::type_info&, void*>>
    )
    {}
    ~ObjectItem();
};