#pragma once

#include <string>
#include <iostream>
#include "../exceptions/JsonCastTypeException.h"
#include "../exceptions/JsonTypeException.h"

class StringItem;
class BoolItem;
class ObjectItem;
class ArrayItem;
class FloatItem;
class IntItem;

template<class T>
class JsonItem
{
protected:
    T value;
public:

    JsonItem(T value)
    {
        this->setValue(value);
    }

    virtual T getValue()
    {
        return this->value;
    }

    virtual void setValue(T value)
    {
        this->value = value;
    }

    virtual std::string toString() {return "";};

    template<class instanceType>
    bool isInstanceOfJsonItem()
    {
        return std::is_base_of_v<StringItem, instanceType>
        || std::is_base_of_v<BoolItem, instanceType>
        || std::is_base_of_v<ArrayItem, instanceType>
        || std::is_base_of_v<FloatItem, instanceType>
        || std::is_base_of_v<IntItem, instanceType>
        || std::is_base_of_v<ObjectItem, instanceType>;
    }
};
