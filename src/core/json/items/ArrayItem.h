#pragma once
#include "JsonItem.h"
#include "CommonItem.h"
#include <vector>
#include <tuple>

class ArrayItem: public JsonItem<std::vector<CommonItem>*>
{
public:
    ArrayItem():
        JsonItem<std::vector<CommonItem>*>(
            new std::vector<CommonItem>()
        )
        {}

    ~ArrayItem();

    CommonItem get(int index);
    std::type_index* getType(int index);
    int getLength();
    CommonItem pop();
    std::vector<CommonItem>::const_iterator begin();
    std::vector<CommonItem>::const_iterator end();
    void erase(int index);
    void erase(std::vector<CommonItem>::const_iterator iterator);
    void erase(int start, int end);
    void erase(
        std::vector<CommonItem>::const_iterator startIterator,
        std::vector<CommonItem>::const_iterator endIterator
        );
    virtual std::string toString() const override;
    CommonItem operator[](int index);
    friend std::ostream& operator<<(std::ostream& out, const ArrayItem& arrayItem);
    friend std::ostream& operator<<(std::ostream& out, const ArrayItem* arrayItem);

    template<class T>
    ArrayItem* push_back(T* value)
    {
        if (!this->isInstanceOfJsonItem<T>())
            throw new JsonTypeException;

        CommonItem item;
        item.init<T>(value);

        this->value->push_back(item);
        return this;
    }

    template<class T>
    T* cast(int index)
    {
        CommonItem item = this->get(index);
              
        if (typeid(T).hash_code() != item.getType()->hash_code())
            throw new JsonCastTypeException;

        return static_cast<T*>(item.getItem());
    }
    
    template<class T>
    ArrayItem* insert(int index, T* value)
    {
        if (!this->isInstanceOfJsonItem<T>())
            throw new JsonTypeException;

        CommonItem item;
        item.init<T>(value);
        this->value->insert(this->value->begin() + index, item);

        return this;
    }

    template<class T>
    T* pop()
    {
        if (!this->isInstanceOfJsonItem<T>())
            throw new JsonCastTypeException;

        T* item = this->cast<T>(this->getLength() - 1);
        this->value->pop_back();
        return item;
    }
};
