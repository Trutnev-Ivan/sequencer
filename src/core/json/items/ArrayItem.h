#pragma once
#include "JsonItem.h"
#include <vector>
#include <tuple>

class ArrayItem: public JsonItem<std::vector<std::tuple<const std::type_info&, void*>>*>
{
public:
    ArrayItem():
        JsonItem<std::vector<std::tuple<const std::type_info&, void*>>*>(
            new std::vector<std::tuple<const std::type_info&, void*>>()
        )
        {}

    ~ArrayItem();

    std::tuple<const std::type_info&, void*> get(int index);
    const std::type_info& getType(int index);
    int getLength();
    virtual std::string toString() override;
    friend std::ostream& operator<<(std::ostream& out, ArrayItem arrayItem);
    friend std::ostream& operator<<(std::ostream& out, ArrayItem* arrayItem);

    template<class T>
    void push_back(T* value)
    {
        if (!this->isInstanceOfJsonItem<T>())
            throw new JsonTypeException;

        std::tuple<const std::type_info&, void*> tuple (typeid(T), static_cast<void*>(value));
        this->value->push_back(tuple);
    }

    template<class T>
    T* cast(int index)
    {
        std::tuple<const std::type_info&, void*> tuple = this->get(index);
        
       if (typeid(T).hash_code() != std::get<0>(tuple).hash_code())
        throw new JsonCastTypeException;

        return static_cast<T*>(std::get<1>(tuple));
    }

    template<class T>
    std::vector<std::tuple<const std::type_info&, void*>>* insert(int index, T value)
    {
        
        return this->value();
    }
};
