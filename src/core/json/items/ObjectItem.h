#pragma once

#include <map>
#include <tuple>
#include "JsonItem.h"
#include "CommonItem.h"

class ObjectItem: public JsonItem<std::map<std::string, CommonItem>*>
{
public:
    ObjectItem():
    JsonItem<std::map<std::string, CommonItem>*>(
        new std::map<std::string, CommonItem>
    )
    {}
    ~ObjectItem();

    virtual std::string toString() const override;
    CommonItem get(std::string key);
    CommonItem operator[](std::string key);
    int getLength();
    bool contains(std::string key);
    std::map<std::string, CommonItem>::const_iterator begin();
    std::map<std::string, CommonItem>::const_iterator end();
    void erase(std::string key);
    friend std::ostream& operator<<(std::ostream& out, const ObjectItem& objectItem);
    friend std::ostream& operator<<(std::ostream& out, const ObjectItem* objectItem);

    template<class T>
    ObjectItem* push(std::string key, T* value)
    {
        CommonItem item;
        item.init<T>(value);
        this->value->insert({key, item});
        return this;
    }

    template<class T>
    T* cast(std::string key)
    {
        if (!this->isInstanceOfJsonItem<T>())
            throw new JsonCastTypeException;

        CommonItem item = this->get(key);
        return static_cast<T*>(item.getItem());
    }
};